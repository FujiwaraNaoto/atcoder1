/*
AC
binary treeを用いて高速化
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

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
    int N,K;
    cin>>N>>K;
    vector<int> a(N);
    for(int i=0;i<N;i++)cin>>a[i];

    
    // vector<vector<ll>> dp(N+1,vector<ll>(K+1,0));
    // dp[0][K]=1;

    // for(int i=0;i<N;i++){
    //     for(int x=K;x>=0;x--){
    //         for(int j=0;j<=min(x,a[i]);j++){
                
    //             dp[i+1][x-j]+=dp[i][x];
    //             dp[i+1][x-j]%=MOD;

    //         }
    //     }
    // }
    // cout<<dp[N][0]<<endl;


    // vector<vector<ll>> dp(N+1,vector<ll>(K+1,0));
    // dp[0][K]=1;

    // for(int i=0;i<N;i++){
    //     for(int x=K;x>=0;x--){
    //         for(int j=0;x+j<=min(K,x+a[i]);j++){
                
    //             dp[i+1][x]+=dp[i][x+j];
    //             dp[i+1][x]%=MOD;

    //         }
    //     }
    // }
    // cout<<dp[N][0]<<endl;

    
    binary_indexed_tree bit(K+1);
    bit.add(K,1);

    for(int i=0;i<N;i++){
        binary_indexed_tree next(K+1);
        for(int x=K;x>=0;x--){
            ll tmp_sum=bit.get(x,min(x+a[i],K));
            next.add(x,tmp_sum);

            // for(int j=0;x+j<=min(K,x+a[i]);j++){
                
            //     dp[i+1][x]+=dp[i][x+j];
            //     dp[i+1][x]%=MOD;

            // }
        }
        bit=next;
    }
    cout<<bit.get(0,0)<<endl;

    
}