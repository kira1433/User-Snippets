class SCC{
public:
    int N; vector<vector<int>> adj, radj;
    vector<int> todo, comps, comp; vector<bool> vis;
    SCC(int _N) { N = _N;
        adj.resize(N), radj.resize(N), comp = vector<int>(N,-1), vis.resize(N); }
    void add(int x, int y) { adj[x].PB(y), radj[y].PB(x); }
    void dfs(int x) {
        vis[x] = 1; for(auto y:adj[x]) if (!vis[y]) dfs(y);
        todo.PB(x); }
    void dfs2(int x, int v) {
        comp[x] = v;
        for(auto y:radj[x]) if (comp[y] == -1) dfs2(y,v); }
    void gen() {
        for(int i=0;i<N;i++) if (!vis[i]) dfs(i);
        reverse(all(todo));
        for(auto x:todo) if (comp[x] == -1) {
            dfs2(x,x); comps.PB(x); }
    }
};