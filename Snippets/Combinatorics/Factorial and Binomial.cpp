//Factorial with mod
const int N = 2*1e6;
factorial[0] = 1;
for (int i = 1; i <= N; i++) {
    factorial[i] = factorial[i - 1] * i % m;
}

//You are given two numbers n and k. Find the largest power of k x such that n! is divisible by k^x.
//For Prime k
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}
//For Non-Prime k
//Represent k = k_1^p_1 ... k_m^p_m and then ans is min(i=1..m) a_i/p_i where a_i is fact_pow(n,k_1)

//Binomial Using Precalculated Factorial and inverse_Factorial using Mod inverse for Array
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}