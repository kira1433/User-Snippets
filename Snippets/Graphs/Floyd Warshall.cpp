int n,m,q;
cin>>n>>m>>q;
int adj[n+1][n+1]={};
REP0(i,m){
    int x,y,z;cin>>x>>y>>z;
    if(adj[x][y]==0)
    adj[x][y]=z;
    else
    ckmin(adj[x][y],z);

    if(adj[y][x]==0)
    adj[y][x]=z;
    else
    ckmin(adj[y][x],z);
}
int distance[n+1][n+1]={};
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == j) distance[i][j] = 0;
        else if (adj[i][j]) distance[i][j] = adj[i][j];
        else distance[i][j] = 4e18;
    }
}
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            distance[i][j] = min(distance[i][j],
            distance[i][k]+distance[k][j]);
        }
    }
}
while(q--){
    int x,y;cin>>x>>y;
    if(distance[x][y]>=4e18){
        cout<<-1<<nl;
    }
    else
        cout<<distance[x][y]<<nl;
}