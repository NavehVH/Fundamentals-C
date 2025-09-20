// dijkstra.cpp
#include "dijkstra.h"
#include <iostream>

// ----- Relax(u, v) -----
// If dist[v] > dist[u] + w(u,v), update dist[v] and parent[v] = u.
static inline bool relax(int u, int v, Weight w_uv,
                         std::vector<Weight>& dist,
                         std::vector<int>& parent) {
    if (dist[u] != DIJKSTRA_INF && dist[v] > dist[u] + w_uv) {
        dist[v] = dist[u] + w_uv;
        parent[v] = u;
        return true;
    }
    return false;
}

// ----- Dijkstra (min-heap) -----
DijkstraResult dijkstra(const Graph& g, int s) {
    const int n = static_cast<int>(g.size());
    std::vector<Weight> dist(n, DIJKSTRA_INF);
    std::vector<int> parent(n, -1);
    std::vector<bool> processed(n, false); // S in the lectures

    dist[s] = 0;

    using Node = std::pair<Weight,int>; // (currentDist, node)
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (processed[u]) continue;      // already finalized
        if (du != dist[u]) continue;     // stale heap entry

        processed[u] = true;             // add u to S

        // Relax all outgoing edges (u -> v)
        for (const auto& e : g[u]) {
            // Optional safety:
            // if (e.w < 0) throw std::logic_error("Negative edge in Dijkstra");
            if (relax(u, e.to, e.w, dist, parent)) {
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return {std::move(dist), std::move(parent)};
}

// ----- Reconstruct path s -> t using parent (π) -----
std::vector<int> reconstruct_path(int s, int t, const std::vector<int>& parent) {
    std::vector<int> path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    std::reverse(path.begin(), path.end());
    if (path.empty() || path.front() != s) return {}; // unreachable
    return path;
}

// ----- Self test (no main here) -----
void dijkstra_self_test() {
    // Build a directed graph with 5 nodes: 0..4
    Graph g(5);
    auto add_edge = [&](int u, int v, Weight w) {
        g[u].push_back({v, w});
        // For undirected graphs, also do: g[v].push_back({u, w});
    };

    // Example edges (non-negative weights)
    add_edge(0, 1, 2);
    add_edge(0, 2, 5);
    add_edge(1, 2, 1);
    add_edge(1, 3, 2);
    add_edge(2, 3, 1);
    add_edge(3, 4, 3);

    int s = 0;
    auto res = dijkstra(g, s);

    for (int v = 0; v < static_cast<int>(g.size()); ++v) {
        if (res.dist[v] == DIJKSTRA_INF) {
            std::cout << "δ(" << s << "," << v << ") = INF\n";
        } else {
            std::cout << "δ(" << s << "," << v << ") = " << res.dist[v] << " ; path: ";
            auto path = reconstruct_path(s, v, res.parent);
            if (path.empty()) {
                std::cout << "(none)\n";
            } else {
                for (size_t i = 0; i < path.size(); ++i) {
                    if (i) std::cout << " -> ";
                    std::cout << path[i];
                }
                std::cout << "\n";
            }
        }
    }
}
