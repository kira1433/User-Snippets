//Check if Bit is set
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}

//Check if n is divisible by 2^k
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}

//Check if n is a power of 2
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

//Clear the right most set bit
n&(n-1)

//Count set bits in n -> Brian Kernighan's algorithm
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

//Clear all trailing ones
n&(n+1)

//Sets the last cleared bit
n|(n+1)

//Extracts the last set bit
n&-n

//Built in functions
__builtin_popcount(unsigned int) returns the number of set bits (__builtin_popcount(0b0001'0010'1100) == 4)
__builtin_ffs(int) finds the index of the first (most right) set bit (__builtin_ffs(0b0001'0010'1100) == 3)
__builtin_clz(unsigned int) the count of leading zeros (__builtin_clz(0b0001'0010'1100) == 23)
__builtin_ctz(unsigned int) the count of trailing zeros (__builtin_ctz(0b0001'0010'1100) == 2)
__builtin_parity(x) the parity (even or odd) of the number of ones in the bit representation

//Iterating through all masks with their submasks. Complexity O(3^n)
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
 ... s and m ...