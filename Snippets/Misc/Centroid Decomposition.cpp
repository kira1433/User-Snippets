int n,k;
vector<int> adj[n];
int sub[n] = {};
int rem[n] = {};
function<void(int,int)> get_subtree =[&] (int u,int p){
    sub[u] = 1;
    for(auto v:adj[u]){
        if(v==p || rem[v])continue;
        get_subtree(v,u);
        sub[u] += sub[v];
    }
};
function<int(int,int,int)> get_centroid =[&] (int u,int p,int sz){
    for (int v:adj[u]) {
        if(v==p ||rem[v])continue;
        if(sub[v]*2 > sz) {
            return get_centroid(v,u,sz);
        }
    }
    return u;
};
function<void(int,int,vector<int>&,int)> dfs = [&](int u,int p,vector<int>& sep,int l){
    sep.push_back(l);
    for (int v:adj[u]) {
        if(v==p ||rem[v])continue;
        dfs(v,u,sep,l+1);
    }
};
int ans = 0;
function<void(int)> centroid_decomp = [&](int u){
    get_subtree(u,-1);
    int centroid = get_centroid(u,-1,sub[u]);
    vector<vector<int>> st;
    for(auto v:adj[centroid]){
        if(rem[v])continue;
        vector<int> sep;
        dfs(v,centroid,sep,1);
        st.push_back(sep);
    }

    int sz = sub[u]+1;
    int mp[sz] = {};
    for(auto i:st){
        for(auto j:i)mp[j]++;
    }
    int sol = 0;
    for(auto i:st){
        for(auto j:i)mp[j]--;
        for(auto j:i)if(k-j>=0 && k-j<sz) sol += mp[k-j];
        for(auto j:i)mp[j]++;
    }
    sol/=2;
    ans+=sol;
    if(k<sz)ans+=mp[k];

    rem[centroid] = 1;
    for(auto v:adj[centroid]){
        if(rem[v])continue;
        centroid_decomp(v);
    }
};  
centroid_decomp(0);
cout<<ans<<endl;