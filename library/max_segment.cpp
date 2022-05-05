/*
最大値を求める
https://atcoder.jp/contests/dp/tasks/dp_t
Q flowersから抜粋
*/

// segment_tree a(n) みたいに呼び出す
class segment_tree{
    public:
        
        vector<ll> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = vector<ll>(2*n-1,0);// 0,1,2,...,2*n-1,2*n-2
        }


        void update(int k,ll a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=max(dat[2*k+1],dat[2*k+2]);
            }
        }

        //[a,b)
        ll query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return 0;
            if(a<=l && r<=b) return dat[k];
            else{

                ll vl = query(a,b,2*k+1,l,(l+r)/2);
                ll vr = query(a,b,2*k+2,(l+r)/2,r);
                return max(vl,vr);
            }
        }

        //[a,b)の範囲でのmax
        ll query(int a,int b){
            return query(a,b,0,0,n);
        }

        ll operator[](int index){
            index += n-1;
            return dat[index];
        }
};


// segment_tree<ll> a(n) みたいに呼び出す

// Typeにはソートの基準が必要
template<class Type> class segment_tree{
    public:
        
        vector<Type> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = vector<Type>(2*n-1,0);// 0,1,2,...,2*n-1,2*n-2
        }


        void update(int k,Type a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=max(dat[2*k+1],dat[2*k+2]);
            }
        }

        //[a,b)
        Type query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return 0;
            if(a<=l && r<=b) return dat[k];
            else{

                ll vl = query(a,b,2*k+1,l,(l+r)/2);
                ll vr = query(a,b,2*k+2,(l+r)/2,r);
                return max(vl,vr);
            }
        }

        //[a,b)の範囲でのmax
        Type query(int a,int b){
            return query(a,b,0,0,n);
        }

        Type operator[](int index){
            index += n-1;
            return dat[index];
        }
};





