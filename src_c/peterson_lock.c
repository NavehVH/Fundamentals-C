#include <stdio.h>
#include <sched.h>           // sched_yield()
#include <pthread.h>
#include "peterson_lock.h"

struct petersonlock peterson_locks[N_PETERSON_LOCKS];

void initpeterson(void) {
  for (int i = 0; i < N_PETERSON_LOCKS; i++) {
    peterson_locks[i].flag[0] = 0;
    peterson_locks[i].flag[1] = 0;
    peterson_locks[i].turn    = 0;
    peterson_locks[i].active  = 0;
  }
}

/* grab a free slot; mark it active */
int peterson_create(void) {
  for (int i = 0; i < N_PETERSON_LOCKS; i++) {
    if (__sync_lock_test_and_set(&peterson_locks[i].active, 1) == 0) {
      peterson_locks[i].flag[0] = 0;
      peterson_locks[i].flag[1] = 0;
      peterson_locks[i].turn    = 0;
      __sync_synchronize();     // full barrier
      return i;
    }
  }
  return -1; // no free lock
}

int peterson_acquire(int lock_id, int role) {
  if (lock_id < 0 || lock_id >= N_PETERSON_LOCKS || (role != 0 && role != 1))
    return -1;

  struct petersonlock *l = &peterson_locks[lock_id];
  if (!l->active) return -1;

  int other = 1 - role;

  l->flag[role] = 1;
  __sync_synchronize();
  l->turn = other;
  __sync_synchronize();

  while (l->flag[other] && l->turn == other) {
    __sync_synchronize();
    sched_yield();             // be nice to scheduler while spinning
  }
  return 0;
}

int peterson_release(int lock_id, int role) {
  if (lock_id < 0 || lock_id >= N_PETERSON_LOCKS || (role != 0 && role != 1))
    return -1;

  struct petersonlock *l = &peterson_locks[lock_id];
  if (!l->active) return -1;

  l->flag[role] = 0;
  __sync_synchronize();
  return 0;
}

int peterson_destroy(int lock_id) {
  if (lock_id < 0 || lock_id >= N_PETERSON_LOCKS)
    return -1;
  peterson_locks[lock_id].active = 0;
  __sync_synchronize();
  return 0;
}

static void* _demo_worker(void* arg) {
    int role = *(int*)arg;     // 0 or 1
    int lock_id = 0;           // use lock 0 created in peterson_demo()
    for (int i = 0; i < 5; i++) {
        peterson_acquire(lock_id, role);

        if (role == 0)
            printf("Parent-thread in critical section (iteration %d)\n", i);
        else
            printf("Child-thread  in critical section (iteration %d)\n", i);

        peterson_release(lock_id, role);
        sched_yield();         // let the other thread run
    }
    return NULL;
}

int peterson_demo(void) {
    initpeterson();
    int lock_id = peterson_create();
    if (lock_id < 0) {
        fprintf(stderr, "peterson_demo: failed to create lock\n");
        return 1;
    }

    pthread_t child;
    int r0 = 0, r1 = 1;

    if (pthread_create(&child, NULL, _demo_worker, &r1) != 0) {
        perror("pthread_create");
        return 1;
    }

    // “parent” work on main thread
    _demo_worker(&r0);

    pthread_join(child, NULL);

    if (peterson_destroy(lock_id) < 0) {
        fprintf(stderr, "peterson_demo: failed to destroy lock\n");
        return 1;
    }

    printf("Parent: destroyed lock\n");
    return 0;
}