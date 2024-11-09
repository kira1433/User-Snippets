struct matrix {
    int n,m;
    vector<vector<int>> mat;
    matrix(int n,int m){
        this->n = n;
        this->m = m;
        mat.resize(n,vector<int>(m,0));
    }
    matrix(int n) : matrix(n,n){}
    void identity(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j)mat[i][j] = 1;
            }
        }
    }
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c(a.n,b.m);
        for (int i = 0; i < a.n; i++) {
          for (int j = 0; j < b.m; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < b.n; k++) {
                  (c.mat[i][j] += a.mat[i][k] * b.mat[k][j])%=mod;
              }
          }
        }
        return c;
    }
};
matrix matpow(matrix base, long long n) {
    matrix ans(base.n);
    ans.identity();
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}