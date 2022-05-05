//遅延セグメント木
// Atcoder典型90
// 029 Long Bricks


//1からインデックスが始まることに注意
class segment_tree {
private:
	int sz;
	std::vector<int> seg;
	std::vector<int> lazy;
	void push(int k) {
		if (k < sz) {
			lazy[k * 2] = max(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
		}
		seg[k] = max(seg[k], lazy[k]);
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k);
			return;
		}
		update(a, b, x, k * 2, l, (l + r) >> 1);
		update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
	}
	int range_max(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k];
		int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
		int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
		return max(lc, rc);
	}
public:
	segment_tree() : sz(0), seg(), lazy() {};
	segment_tree(int N) {
		sz = 1;
		while (sz < N) {
			sz *= 2;
		}
		seg = std::vector<int>(sz * 2, 0);
		lazy = std::vector<int>(sz * 2, 0);
	}
	void update(int l, int r, int x) {
		update(l, r, x, 1, 0, sz);
	}
	int range_max(int l, int r) {
		return range_max(l, r, 1, 0, sz);
	}
};



/*
https://atcoder.jp/contests/dp/submissions/3963076
*/

template<class V, int NV> struct LazySegTree { // [L,R)
    vector<V> dat, lazy;
    LazySegTree() {
        dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); 
    }
    void update(int a, int b, V v, int k, int l, int r) {
        push(k, l, r); 
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            setLazy(k, v); push(k, l, r); 
        } else {
            update(a, b, v, k * 2 + 1, l, (l + r) / 2);
            update(a, b, v, k * 2 + 2, (l + r) / 2, r);
            dat[k] = comp(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    V get(int a, int b, int k, int l, int r) {
        push(k, l, r); 
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return dat[k];
        auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return comp(x, y);
    }
    void update(int a, int b, V v) { update(a, b, v, 0, 0, NV); }
    V get(int a, int b) { return get(a, b, 0, 0, NV); }

    // ---- Template ---------------------------------------------------------------------------------
    
    // 区間add, 区間max
    const V def = 0, ldef = 0;
    V comp(V l, V r) { return max(l, r); }

    void setLazy(int i, V v) { lazy[i] += v; }
    void push(int k, int l, int r) {
        dat[k] += lazy[k];
        if (r - l > 1) {
            setLazy(k * 2 + 1, lazy[k]);
            setLazy(k * 2 + 2, lazy[k]); 
        }
        lazy[k] = ldef;
    }
};