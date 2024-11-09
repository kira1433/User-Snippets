int n,m;
vector<vector<pair<int,int>>> adj(n+1);
int st=1,ed=n;
priority_queue<pair<int,int>> q;
int dist[n+1];
int cnt[n+1]={};
int mn[n+1]={};
int mx[n+1]={};
bool visited[n+1]={};
for(int i=0;i<=n;i++){
    dist[i]=4e18;
}
q.push({0,st});
dist[st]=0;   
cnt[st]=1;
while(!q.empty()){  
    int x=q.top().SS;
    q.pop();
    if(visited[x])continue;
    visited[x]=true;
     // cout<<x+1<<sp<<dist[x]<<nl;
    for(auto i:adj[x]){
        if(dist[x]+i.SS == dist[i.FF]){
            cnt[i.FF]= (cnt[x]+cnt[i.FF])%mod;
            ckmin(mn[i.FF],mn[x]+1);
            ckmax(mx[i.FF],mx[x]+1);
        }
        else if(dist[x]+i.SS < dist[i.FF]){
            cnt[i.FF]= cnt[x];
            mn[i.FF]=mn[x]+1;
            mx[i.FF]=mx[x]+1;
            dist[i.FF]=dist[x]+i.SS; 
            q.push({-dist[i.FF],i.FF});
        }
    }
}
cout<<dist[ed]<<sp<<cnt[ed]<<sp<<mn[ed]<<sp<<mx[ed]<<nl;