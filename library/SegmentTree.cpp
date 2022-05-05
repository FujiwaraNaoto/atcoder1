/*
https://atcoder.jp/contests/dp/
W


*/
template<class V, int NV> struct LazySegTree { 

    
    // [L,R)
    vector<V> dat, lazy;
    LazySegTree() {
        dat.resize(NV * 2,0);//全て0で初期化
        lazy.resize(NV * 2,0); 
    }
    void update(int a, int b, V v, int k, int l, int r) {
        push(k, l, r); 
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            setLazy(k, v);
            push(k, l, r);
        } else {
            update(a, b, v, k * 2 + 1, l, (l + r) / 2);
            update(a, b, v, k * 2 + 2, (l + r) / 2, r);
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    V get(int a, int b, int k, int l, int r) {
        push(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];
        auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(x, y);
    }

    void update(int a, int b, V v){
        update(a, b, v, 0, 0, NV);
    }
    V get(int a, int b) {
        return get(a, b, 0, 0, NV);
    }
    // ---- Template ---------------------------------------------------------------------------------
    
    // 区間add, 区間max
    void setLazy(int i, V v) { lazy[i] += v; }
    void push(int k, int l, int r) {
        dat[k] += lazy[k];
        if (r - l > 1) {
            setLazy(k * 2 + 1, lazy[k]);
            setLazy(k * 2 + 2, lazy[k]);
        }
        lazy[k] = 0;
    }
};



int main(){
    int N,M;
    cin>>N>>M;
    
    /*
    vector<P> R[N];
    LazySegTree dp(N,0);
    */
    vector<P> R[201010];
    //LazySegTree dp(1<<18,0);
    LazySegTree<ll,1<<18> dp;


    for(int i=0;i<M;i++){
        int l,r,a;
        cin>>l>>r>>a;
        l--;r--;//0から始めるように補正
        R[r].push_back(P(l,a));

    }

    for(int r=0;r<N;r++){
        ll opt = dp.get(0,r);//dp[0]~dp[r-1]の中のmax
        //ll opt = dp.query(0,r);
        //ll opt = dp.range_max(0,r);
        dp.update(r,r+1,opt);
        for(auto [l,a]: R[r]){
            dp.update(l,r+1,a);
        }
    }

    ll ans = dp.get(0,N);
    //ll ans = dp.query(0,N);
    //ll ans = dp.range_max(0,N);
    
    cout<<ans<<endl;


}





//これおすすめ
template<class T> class LazySegTree{
    private:

    vector<T> data, lazy;
    int n;

    void eval(int k,int l,int r){
        if(lazy[k]==0) return;
        data[k]+=lazy[k];
        if(r-l>1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k]=0;
    } 



    void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r); 
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            //setLazy(k, v);
            lazy[k]+=v;
            eval(k, l, r);
        } else {
            update(a, b, v, k * 2 + 1, l, (l + r) / 2);
            update(a, b, v, k * 2 + 2, (l + r) / 2, r);
            data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    T range_max(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return data[k];
        T x = range_max(a, b, k * 2 + 1, l, (l + r) / 2);
        T y = range_max(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(x, y);
    }




    public:
        LazySegTree(int sz) {
            n=1;
            while(n<=sz) n*=2;

            data=vector<T>(n * 2,0);//全て0で初期化
            lazy=vector<T>(n * 2,0); 
        }

        void update(int a, int b, T v){
            update(a, b, v, 0, 0, n);
        }

        
        T range_max(int a, int b) {
            return range_max(a, b, 0, 0, n);
        }

};
