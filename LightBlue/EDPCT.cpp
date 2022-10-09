#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD =1e9+7;



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





int main(){
    int N;
    cin>>N;
    string s;
    cin>>s;

    binary_indexed_tree bit(N+1);

    for(int less=0;less<N;less++){
        //dp[0][less]=1
        bit.add(less,1);//まだ何もおいてない状態
    }

    for(int i=0;i<N-1;i++){
        // (more or equal) + less = N-i
        // i項目の値より小さい個数がless個ある
        binary_indexed_tree bit_next(N+1);
        for(int less=0;less<N-i-1;less++){
            //less=0~N-i-2
            //i=0のときは less=0 ~ N-2
            //i = 1のときは less=0 ~ N-3
            // i=N-2のときは less=0 ~ 0
            if(s[i]=='<'){
                //i項目　[0,less]からlessへいく
                bit_next.add(less,bit.get(0,less));//こっちに境界を含むことに注意　lessとおりの遷移先なので.
            }else{
                //s[i]=='>'
                //[less+1, N-1]からlessへいく
                bit_next.add(less,bit.get(less+1,N-1));

            }
        
        }

        bit = bit_next;//O(N)

    }

    cout<<bit.get(0,0)<<endl;
}