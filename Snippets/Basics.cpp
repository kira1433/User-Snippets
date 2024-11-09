//Fast IO
ios::sync_with_stdio(false);
cin.tie(nullptr);cout.tie(nullptr);

//File open and close
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

//Floating Point - rounded to six decimal places (rounding half to even)
ans*=1e7;
int res = ans;
if(res==ans && res/10 ==5){
    res/=10;
    if(res%2)res++;
    res*=10;
}
ans = res/1e7;
cout<<fixed<<setprecision(6)<<ans;

//Remove Duplicates
vector<int> vec{1, 1, 1, 2, 3, 3};
sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());

//Lambda Comparators
/* Sets, priority queues & sorting vectors with custom comparators */
vector<pair<int, int>> v;
sort(v.begin(), v.end(), [](const auto& A, const auto& B) {
    // ...
    // for pairs
    return A.second == B.second?
                A.first < B.first : A.second < B.second;
});
// STL set and priority_queue comparators
auto cmp = [](const auto& A, const auto& B) {
    return A < B;
};
set<T, decltype(cmp)> s(cmp);
priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

/* GP hash table, an alternative to unordered_map w/ custom hash */
#include <ext/pb_ds/assoc_container.hpp>
namespace Hashing {
    using hash_t = pair<int, uint64_t>;
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    // Custom hash using splitmix64 (https://codeforces.com/blog/entry/62393)
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            return splitmix64(x + FIXED_RANDOM);
        }
        size_t operator()(const hash_t& x) const {
            return splitmix64(FIXED_RANDOM + x.second)
                    ^ (splitmix64(FIXED_RANDOM + x.first) << 1);
        }
    };

    // gp_hash_table benchmarks vs unordered_map (https://codeforces.com/blog/entry/60737)
    template<typename K, typename V, typename Hash = custom_hash>
    using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

    template<typename K, typename Hash = custom_hash>
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
}

/* Policy Based Data Structures - ordered_set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0

ordered_set<int> os;
ordered_set<pair<int, int>> os;
ordered_set<int, int> o_map;
ordered_set<int, null_type, std::greater<int>> os_greater;

