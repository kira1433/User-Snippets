int cost = 0;
sort(edges.begin(), edges.end(),[&](array<int,3> a,array<int,3> b){
    return a[2]<b[2];
});
for (auto e : edges) {
    if (find_set(e[0]) != find_set(e[1])) {
        cost += e[2];
        result.push_back(e);
        union_sets(e[0], e[1]);
    }
}