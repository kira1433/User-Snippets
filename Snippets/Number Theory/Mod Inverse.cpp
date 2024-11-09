//Quick Mod inverse O(50)
int mod_inv(int a,int mod = mod) {
    return a <= 1 ? a : mod - (long long)(mod/a) * mod_inv(mod % a) % mod;
}

//Quick Mod inverse with DP (1...N)
const int N = 1e6;
vector<int> inv_dp(N+1);
int mod_inv(int a,int mod = mod) {
    if(inv_dp[a])return inv_dp[a];
    return inv_dp[a] = a <= 1 ? a : mod - (long long)(mod/a) * mod_inv(mod % a) % mod;
}

//Finding Mod Inverse for Array of integers in O(n)
std::vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    gcd(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}