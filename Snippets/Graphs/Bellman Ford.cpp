int n,m;
cin>>n>>m;
vector<tuple<int,int,int>> edges(m);
vector<vector<int>> adj(n+1);
for(auto &i:edges){
    int x,y,z;cin>>x>>y>>z;
    i=make_tuple(x,y,z);
    adj[y].PB(x);
}

int distance[n+1]={};
int visited[n+1]={};

for (int i = 1; i <= n; i++) distance[i] = LLONG_MAX;
    distance[1] = 0;
    for (int i = 1; i <= n-1; i++){
    for (auto e : edges) {
    int a, b, w;
    tie(a, b, w) = e;
    if (distance[a] != LLONG_MAX && distance[a] + w < distance[b])
        distance[b] = distance[a]+w;
    }
}

for (auto e : edges) {
    int a, b, w;
    tie(a, b, w) = e;
    if (distance[a] != LLONG_MAX && distance[a] + w < distance[b])
    {  
        cout<<"CYCLE"<<nl;
    }
}

cout<<distance[n]<<nl;