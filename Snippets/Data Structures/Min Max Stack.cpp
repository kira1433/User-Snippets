struct mxstack{
    vector<int> s1,s1min={LLONG_MAX},s1max={LLONG_MIN};
    vector<int> s2,s2min={LLONG_MAX},s2max={LLONG_MIN};
    void push(int x){
        s2.push_back(x);
        s2min.push_back(::min(x,s2min.back()));
        s2max.push_back(::max(x,s2max.back()));
    }
    int pop(){
        if(s1.empty()){
            while(!s2.empty()){
                s1min.push_back(::min(s1min.back(),s2.back()));
                s2min.pop_back();
                s1max.push_back(::max(s1max.back(),s2.back()));
                s2max.pop_back();
                s1.push_back(s2.back());
                s2.pop_back();
            }
        }
        int res = s1.back();
        s1.pop_back();
        s1min.pop_back();
        s1max.pop_back();
        return res;
    }
    bool empty(){
        return s1.empty()&&s2.empty();
    }
    int min(){
        return ::min(s1min.back(),s2min.back());
    }
    int max(){
        return ::max(s1max.back(),s2max.back());
    }
};