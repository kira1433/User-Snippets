/* st[i][j]: answer for range [j, j + 2^i - 1] (both inclusive)
 * so [j, j+2^i-1] splits into [j, j+2^(i-1)-1] and [j+2^(i-1), j+2^i-1]
 */
int st[K + 1][MAXN];		// K >= __lg(MAXN)
std::copy(array.begin(), array.end(), st[0]);
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
     // st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))]; for sum query
// find answer for query
long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}

struct RMQ{
    vector<vector<int>> pre; 
    int n;
    void init(int _n){
        n = _n;
        pre.resize(n+1,vector<int>((int)log2(n)+1,0));
    }
    void init(vector<int> &a){
        init(a.size());
        build(a);
    }
    void build(vector<int> &a){
        for(int i=0;i<n;i++){
            pre[i][0] = a[i];
        }
        for(int j=1;j<=log2(n);j++){
            for(int i=0; (i+(1ll<<j)-1)<=n ; i++){
                pre[i][j]=min(pre[i][j-1],pre[i + (1ll<<(j-1))][j-1]);
            }
        }
    }
    int calc(int x,int y){
        if(x==y)return pre[x-1][0];
        int j = log2(y-x);
        return min(pre[x-1][j],pre[y- (1ll<<j)][j]);
    }

};
