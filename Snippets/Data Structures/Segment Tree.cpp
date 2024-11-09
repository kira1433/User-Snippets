template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
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
    void update(int p, int lx, int rx, int x, const Info &v) {
        if (rx == lx) {
            info[p] = v;
            return;
        }
        int m = (lx + rx) / 2;
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
        if (lx >= l && rx <= r) {
            return info[p];
        }
        int m = (lx + rx) / 2;
        return query(2 * p + 1, lx, m, l, r) + query(2 * p + 2, m + 1, rx, l, r);
    }
    Info query(int l, int r) {
        return query(0, 0, n - 1, l, r);
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

struct Info {
    int sum = 0;

    Info() {}
    Info(int s) : sum(s) {}
};

Info operator+(Info a, Info b) {
    return Info(a.sum + b.sum);
}