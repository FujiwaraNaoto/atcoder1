/*
xorが足し算のように振る舞うことがポイント?

*/
#include<iostream>
#include<vector>
using namespace std;


//template<typename Type>でもどちらでもいいみたい
//binary_indexed_tree<ll> bit;

/*
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
            bit[x] =bit[x]^a;
            x += x&-x;
        }
    }
    Type sum(int x){
        x++;//1から始まることに注意
        Type ret=0;
        //for(int i=x; i>0; i-=(i&-i)) ret = addition(ret,bit[i]);
        while(x>0){
            ret = ret^bit[x];//xor
            x -= x&-x;
        }
        
        return ret;
    }

    //[l,r]の範囲
    Type get(int l,int r){
        if(r>N) return 0;//配列の外へのアクセス
        if(l>r) return 0;//本来は l<=r となるのでおかしい
        if(l==0) return sum(r);//[0,r]//ここでoutなわけか
        else return (sum(r)+(~sum(l-1)+1));
    }
};
*/




class segment_tree{
    public:
        
        vector<ll> dat;
        int n=1;
        segment_tree(int n_){    
            while(n < n_){
                n*=2;
            }
            dat = vector<int>(2*n-1,INF);// 0,1,2,...,2*n-1,2*n-2
        }


        void update(int k,int a){
            k+=n-1;
            dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                dat[k]=dat[2*k+1]^dat[2*k+2];
            }
        }

        //[a,b)
        ll query(int a,int b,int k,int l,int r){
            if(r<=a || b<=l) return 0;
            if(a<=l && r<=b) return dat[k];
            else{

                ll vl = query(a,b,2*k+1,l,(l+r)/2);
                ll vr = query(a,b,2*k+2,(l+r)/2,r);
                return vl^vr;
            }
        }

        //[a,b)の範囲でのmin
        ll query(int a,int b){
            return query(a,b,0,0,n);
        }

        ll operator[](int index){
            index += n-1;
            return dat[index];
        }
};




int main(){
    int N,Q;
    cin>>N>>Q;
    binary_indexed_tree<int> bit;
    
    bit.init(N);

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        bit.add(i,A[i]);
    }


    for(int i=0;i<Q;i++){
        int t,x,y;
        x--;y--;//0から始めるように調節
        cin>>t>>x>>y;
        if(t==1){
            A[x]=A[x]^y;
            bit.add(x,A[x]);

        }else{//t==2
            int ans = bit.get(x,y);

            cout<<ans<<endl;
        }
    }


}