#ifndef _PETERSON_H_
#define _PETERSON_H_

#define N_PETERSON_LOCKS 64

struct petersonlock {
  volatile int flag[2];
  volatile int turn;
  volatile int active;
};

extern struct petersonlock peterson_locks[N_PETERSON_LOCKS];

void initpeterson(void);
int  peterson_create(void);
int  peterson_acquire(int lock_id, int role);   // role: 0 or 1
int  peterson_release(int lock_id, int role);   // role: 0 or 1
int  peterson_destroy(int lock_id);

/* tiny built-in test so you can just call from main */
int peterson_demo(void); 

#endif
