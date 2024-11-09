/* Author: kira1433
* The Man Who Will Become the Pirate King!
**/
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "bits/stdc++.h"
 
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
const int mod = 1e9+7;
const int mod2 = 998244353;

//Template
void solve(){
    
}

int32_t main_() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}
