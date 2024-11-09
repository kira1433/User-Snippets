//Number of permutations without Fixed points
const int N = 1e6;
vector<int> dearrange_dp(N+1);
int dearrange(int x){
    if(dearrange_dp[0]!=0)return dearrange_dp[x];
    dearrange_dp[0] = 1;
    dearrange_dp[1] = 0;

    for(int i=2;i<=N;i++){
        dearrange_dp[i] = ((i-1)*(dearrange_dp[i-1] +dearrange_dp[i-2]))%mod;
    }
    return dearrange_dp[x];
}
// Also we can do n! * (1-1/1! + 1/2! - 1/3! + ... +- 1/n!) ~ n!/e