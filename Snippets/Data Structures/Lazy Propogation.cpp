template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int lx, int rx) {
            if (rx == lx) {
                info[p] = init_[lx];
                return;
            }
            int m = (lx + rx) / 2;
            build(2 * p + 1, lx, m);
            build(2 * p + 2, m + 1, rx);
            pull(p);
        };
        build(0, 0, n - 1);
    }
    void pull(int p) {
        info[p] = info[2 * p + 1] + info[2 * p + 2];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p + 1, tag[p]);
        apply(2 * p + 2, tag[p]);
        tag[p] = Tag();
    }
    void update(int p, int lx, int rx, int x, const Info &v) {
        if (rx == lx) {
            info[p] = v;
            return;
        }
        int m = (lx + rx) / 2;
        push(p);
        if (x <= m) {
            update(2 * p + 1, lx, m, x, v);
        } else {
            update(2 * p + 2, m + 1, rx, x, v);
        }
        pull(p);
    }
    void update(int p, const Info &v) {
        update(0, 0, n - 1, p, v);
    }
    Info query(int p, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) {
            return Info();
        }
        if (l <= lx && rx <= r) {
            return info[p];
        }
        int m = (lx + rx) / 2;
        push(p);
        return query(2 * p + 1, lx, m, l, r) + query(2 * p + 2, m + 1, rx, l, r);
    }
    Info query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void rangeUpdate(int p, int lx, int rx, int l, int r, const Tag &v) {
        if (lx > r || rx < l) {
            return;
        }
        if (l <= lx && rx <= r) {
            apply(p, v);
            return;
        }
        int m = (lx + rx) / 2;
        push(p);
        rangeUpdate(2 * p + 1, lx, m, l, r, v);
        rangeUpdate(2 * p + 2, m + 1, rx, l, r, v);
        pull(p);
    }
    void rangeUpdate(int l, int r, const Tag &v) {
        return rangeUpdate(0, 0, n - 1, l, r, v);
    }
    template<class F>
    int findFirst(int p, int lx, int rx, int l, int r, F pred) {
        if (lx > r || rx < l || !pred(info[p])) {
            return -1;
        }
        if (rx == lx) {
            return lx;
        }
        int m = (lx + rx) / 2;
        push(p);
        int res = findFirst(2 * p + 1, lx, m, l, r, pred);
        if (res == -1) {
            res = findFirst(2 * p + 2, m + 1, rx, l, r, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(0, 0, n - 1, l, r, pred);
    }
    template<class F>
    int findLast(int p, int lx, int rx, int l, int r, F pred) {
        if (lx > r || rx < l || !pred(info[p])) {
            return -1;
        }
        if (rx == lx) {
            return lx;
        }
        int m = (lx + rx) / 2;
        push(p);
        int res = findLast(2 * p + 2, m + 1, rx, l, r, pred);
        if (res == -1) {
            res = findLast(2 * p + 1, lx, m, l, r, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(0, 0, n - 1, l, r, pred);
    }
};
 
struct Tag {
    int add = 0;

    Tag() {}
    Tag(int s) : add(s) {}

    void apply(const Tag &t) {
        add += t.add;
    }
};
 
struct Info {
    int sum = 0;

    Info() {}
    Info(int s) : sum(s) {}

    void apply(const Tag &t) {
        sum += t.add;
    }
};
 
Info operator+(const Info &a, const Info &b) {
    Info c{a.sum + b.sum};
    return c;
}