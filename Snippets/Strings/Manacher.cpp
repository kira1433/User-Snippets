vector<int> manacher(string s) {
    string t = "#";
    for(auto c: s) {
        t += c + string("#");
    }
    int n = t.size();
    
    vector<int> res(n);
    for(int i = 0, j = 0; i < n; i++) {
        if(2*j - i >= 0 && j + res[j] > i) {
            res[i] = min(res[2*j - i], j + res[j] - i);
        }
        while(i - res[i] >= 0 && i + res[i] < n && t[i - res[i]] == t[i + res[i]]) {
            res[i] += 1;
        }
        if(i + res[i] > j + res[j]) {
            j = i;
        }
    }
    return res;
}

// both l and r are inclusive
// res is return vector of manacher
bool checkPalindrome(int l, int r, vector<int>& res) {
    return res[l + r + 1] >= (r - l + 1);
}