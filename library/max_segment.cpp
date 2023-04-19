/*
最大値を求める
https://atcoder.jp/contests/dp/tasks/dp_t
Q flowersから抜粋
*/
#include<vector>
#include<iostream>
typedef long long ll;

// segment_tree a(n) みたいに呼び出す
class segment_tree{
    public:
        
        std::vector<ll> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = std::vector<ll>(2*n-1,0);// 0,1,2,...,2*n-1,2*n-2
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



// segment_tree<ll,op,e> a(n) みたいに呼び出す
// Typeにはソートの基準が必要


Type op(Type x, Type y){
    //(x,y)を比較する任意の演算子.今回はmaxとした
    return max(x,y);
}

Type e(){
    //initialize value
    return 0;
}


template<class Type,
    Type (*op)(Type,Type),
    Type (*e)()
    > class segment_tree{
    
    public:
        
        std::vector<Type> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = std::vector<Type>(2*n-1,e());// 0,1,2,...,2*n-1,2*n-2
        }

        ~segment_tree(){
            std::vector<Type>().swap(dat);
        }

        void set(int k,Type a){
            update(k,a);
        }


        void update(int k,Type a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=op(dat[2*k+1],dat[2*k+2]);
            }
        }

        //[a,b)
        Type query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return e();
            if(a<=l && r<=b) return dat[k];
            else{

                Type vl = query(a,b,2*k+1,l,(l+r)/2);
                Type vr = query(a,b,2*k+2,(l+r)/2,r);
                return op(vl,vr);
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

        Type get(int idx){
            index += n-1;
            return dat[index];
        }
};



