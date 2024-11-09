const int MOD = 1e9 + 7;
// O(logp)
int mod_expo(int x, int p, int mod = MOD) {
    int res = 1; x = ((x % mod) + mod) % mod;
    while (p > 0) {
        if (p & 1) res = (1LL * res * x) % mod;
        x = (1LL * x * x) % mod; p /= 2;
    }
    return res;
}
//for mod-2 for prime modulo, for coprime use phi(mod) - 1
inline int mod_inv(int x, int mod = MOD) { return mod_expo(x, mod - 2, mod); }