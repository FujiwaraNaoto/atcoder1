/*
https://atcoder.jp/contests/abc221/editorial/2718
https://blog.hamayanhamayan.com/entry/2019/01/12/150046
https://atcoder.jp/contests/dp/tasks/dp_t
*/

#include<iostream>
#include<vector>
using namespace std;
//typedef long long ll;

//最大値を求める
//long long もしくはIntを想定している
template<class Type> class BinaryIndexTree{
public:
    int bitsize;
    std::vector<Type> bit;

    BinaryIndexTree(int bitsize_):bitsize(bitsize_+1){
      bit=std::vector<Type>(bitsize+2,0);
    }
   ~BinaryIndexTree(){
     std::vector<Type>().swap(bit);
   }
    
    //i番目の要素を更新　iは0から
    void update(int i,Type x){
        i+=1;//ここ大事 インデックスを1からに補正する
      while(i<bitsize){
        bit[i]=max(x,bit[i]);
        i+= i&-i;
      }
    }

    /*
    Type& operator[](int i){
        //代入の場合
        update()
        return bit[i+1];
    }

    const Type&
    */
   
   //0~iまでの中で最大値
    Type get(int i){
     Type ans=-INF;
     i+=1;
     while(i>0){
        ans=max(ans,bit[i]);
        i -= i&-i;
     }

     return ans;

    }
};


//binary_indexed_tree bit;
struct binary_indexed_tree{
    int N;
    vector<ll> bit;
    
    //binary_indexed_tree(){};//ただのコンストラクタ
    
    binary_indexed_tree(int n){
        bit = vector<ll>(n+1,0);
        N=n+1;
    }

    ~binary_indexed_tree(){
        vector<ll>().swap(bit);
    }



    ll addition(ll x, ll y){
        return (x+y)%MOD;
    }
    void add(int x,ll a){
        x++;//1から始めるための補正
        //for(int i=x; i<=N; i+=(i&-i)) bit[i] = addition(bit[i],a);
        while(x<=N){
            bit[x] = addition(bit[x],a);
            x += x&-x;
        }
    }
    ll sum(int x){
        x++;//1から始まることに注意
        ll ret=0;
        //for(int i=x; i>0; i-=(i&-i)) ret = addition(ret,bit[i]);
        while(x>0){
            ret = addition(ret,bit[x]);
            x -= x&-x;
        }
        
        return ret;
    }

    //[l,r]の範囲
    ll get(int l,int r){
        if(r>N) return 0;//配列の外へのアクセス
        if(l>r) return 0;//本来は l<=r となるのでおかしい
        if(l==0) return sum(r);//[0,r]//ここでoutなわけか
        else return (sum(r) - sum(l-1)+MOD)%MOD;
    }


    
};




//template<typename Type>でもどちらでもいいみたい
//binary_indexed_tree<ll> bit;


template<class Type> struct binary_indexed_tree{
    int N;
    vector<Type> bit;
    
    binary_indexed_tree(){};//ただのコンストラクタ

    void init(int n){
        bit = vector<Type>(n+1,0);
        N=n+1;
    }

    void add(int x,Type a){
        x++;//1から始めるための補正
        //for(int i=x; i<=N; i+=(i&-i)) bit[i] = addition(bit[i],a);
        while(x<=N){
            //bit[x] = addition(bit[x],a);
            bit[x] =bit[x]+a;
            x += x&-x;
        }
    }
    Type sum(int x){
        x++;//1から始まることに注意
        Type ret=0;
        //for(int i=x; i>0; i-=(i&-i)) ret = addition(ret,bit[i]);
        while(x>0){
            ret = ret+bit[x];
            x -= x&-x;
        }
        
        return ret;
    }

    //[l,r]の範囲
    Type get(int l,int r){
        if(r>N) return 0;//配列の外へのアクセス
        if(l>r) return 0;//本来は l<=r となるのでおかしい
        if(l==0) return sum(r);//[0,r]//ここでoutなわけか
        else return (sum(r) - sum(l-1));
    }
};



template<class Type> struct binary_indexed_tree{
    int N;
    vector<Type> bit;
    
  

    binary_indexed_tree(int n):N(n+1){
        bit = vector<Type>(n+1,0);
        N=n+1;
    }



    void add(int x,Type a){
        x++;//1から始めるための補正
        //for(int i=x; i<=N; i+=(i&-i)) bit[i] = addition(bit[i],a);
        while(x<=N){
            //bit[x] = addition(bit[x],a);
            bit[x] =bit[x]+a;
            x += x&-x;
        }
    }

    
    Type sum(int x){
        x++;//1から始まることに注意
        Type ret=0;
        //for(int i=x; i>0; i-=(i&-i)) ret = addition(ret,bit[i]);
        while(x>0){
            ret = ret+bit[x];
            x -= x&-x;
        }
        
        return ret;
    }

    //[l,r]の範囲
    // rはN-1以下
    Type get(int l,int r){
        if(r>N) return 0;//配列の外へのアクセス
        if(l>r) return 0;//本来は l<=r となるのでおかしい
        if(l==0) return sum(r);//[0,r]//ここでoutなわけか
        else return (sum(r) - sum(l-1));
    }
};