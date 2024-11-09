class Trie {
public:
    Trie* children[26];
    bool check;
    Trie() {
        for(int i=0;i<26;i++)children[i]=NULL;
        check = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(auto i:word){
            if(!cur->children[i-'a']) cur->children[i-'a'] = new Trie();
            cur = cur->children[i-'a'];
        }
        cur->check = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(auto i:word){
            if(!cur->children[i-'a']) return false;
            cur = cur->children[i-'a'];
        }
        return cur->check;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(auto i:prefix){
            if(!cur->children[i-'a']) return false;
            cur = cur->children[i-'a'];
        }
        return true;
    }
};