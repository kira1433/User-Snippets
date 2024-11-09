pair<int,int> fib(int n){
    // return fib(n) and fib(n+1)
    if(n==0)return {0,1};
    auto [i,j] = fib(n/2);
    int c = (i * ((2*j - i+mod)%mod))%mod;
    int d = ((i *i%mod) + (j*j%mod))%mod;
    if(n%2)return {d,(c+d)%mod};
    return {c,d};
}
