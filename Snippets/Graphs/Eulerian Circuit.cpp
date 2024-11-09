/* Eulerian Circuit (directed) */
// Hierholzer’s Algorithm
vector<int> indeg(n), outdeg(n);
vector<vector<int>> g(n);
for(i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    outdeg[--u]++; indeg[--v]++;
    g[u].push_back(v);
}
bool bad = false;
for(i = 1; i < n-1; i++)
    bad |= outdeg[i] ^ indeg[i];
bad |= outdeg[0]-indeg[0] ^ 1;
bad |= indeg[n-1]-outdeg[n-1] ^ 1;
if(bad)
    // IMPOSSIBLE
vector<int> tour;
tour.reserve(m+1);
Y([&](auto dfs, int v) -> void {
    while(outdeg[v]-- > 0)
        dfs(g[v][outdeg[v]]);
    tour.push_back(v);
})(0);      // dfs(0);

for(i = 0; i < n; i++)
    if(outdeg[i] > 0)
        // IMPOSSIBLE
reverse(tour.begin(), tour.end());

/* Eulerian Circuit (undirected) */
// Hierholzer’s Algorithm
struct edge_t {
    int u{-1}, v{-1}; bool done{false};
    edge_t() = default;
    edge_t(int u, int v) : u(u), v(v) {}
};
vector<int> deg(n);
vector<edge_t> edges;
edges.reserve(m);
vector<vector<edge_t*>> g(n);
for(i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    deg[--u]++; deg[--v]++;
    edges.emplace_back(u, v);
    g[u].push_back(&edges.back());
    g[v].push_back(&edges.back());
}
bool bad = false;
for(i = 0; i < n; i++)
    bad |= deg[i] & 1;
if(bad)
    // IMPOSSIBLE
vector<int> tour;
tour.reserve(m+1);
Y([&](auto dfs, int v) -> void {
    while(deg[v]-- > 0) {
        auto e = g[v][deg[v]];
        if(!e->done)
            e->done = true, dfs(e->u ^ e->v ^ v);
    } tour.push_back(v);
})(0);      // dfs(0);
for(i = 0; i < n; i++)
    if(deg[i] > 0)
        // IMPOSSIBLE
reverse(tour.begin(), tour.end());