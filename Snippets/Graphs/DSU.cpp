class unf{
    public :
    vector<int> link;
    vector<int> size;
    int comp=0;
    unf(int n = -1){
        link.assign(n+1,-1);
        size.assign(n+1,1);
        comp=n;
    }   
    int find(int x){
        return link[x]==-1?x:find(link[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return ;
        if(size[x]<size[y])swap(x,y);
        size[x]+=size[y];
        link[y]=x;
        comp--;
    }

};