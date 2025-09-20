// dijkstra.h
#pragma once

#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <utility>

// ----- Types -----
using Weight = long long;
constexpr Weight DIJKSTRA_INF = std::numeric_limits<Weight>::max();

struct Edge {
    int to;
    Weight w; // edge weight w(u,v) >= 0
};

using Graph = std::vector<std::vector<Edge>>;

struct DijkstraResult {
    std::vector<Weight> dist;   // dist[v] = δ(s,v) or INF if unreachable
    std::vector<int>    parent; // parent[v] = π(v) in the shortest-path tree, or -1
};

// ----- API -----
// Dijkstra (min-heap). Precondition: all edge weights are non-negative.
DijkstraResult dijkstra(const Graph& g, int s);

// Reconstruct path from s to t using parent (π). Returns empty if unreachable.
std::vector<int> reconstruct_path(int s, int t, const std::vector<int>& parent);

// A tiny self-test you can call from your main() later.
// It builds a small graph, runs dijkstra, and prints distances + paths.
void dijkstra_self_test();
