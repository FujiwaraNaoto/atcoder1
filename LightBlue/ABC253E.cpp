#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=998244353;


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
    int N,M,K;
    cin>>N>>M>>K;
    //K==0のときは例外

    vector<vector<ll>> dp(N+1,vector<ll>(M+1,0));

    // dp[i][j]=i番目の値がj
    for(int j=1;j<=M;j++)dp[0][j]=1;

    
    for(int i=0;i<N;i++){//N-1項目が答え
        binary_indexed_tree bit(M+2);
        
        for(int x=1;x<=M;x++){
            bit.add(x,dp[i][x]);//bitのx番目
        }
       

        for(int x=1;x<=M;x++){
            //x-K<0のときとか 要素にアクセスできない故
            if(K==0){
                dp[i+1][x]=bit.get(1,M);
            }else{
            //1~x-Kの和 //x+K~Mの和
            dp[i+1][x]=(bit.get(1,x-K)+bit.get(x+K,M))%MOD;
            }
        

        }
        
    }

    /*
    for(int i=0;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j];
        }
        cout<<endl;
    }
    */
    

    ll ans=0;
    for(int j=1;j<=M;j++){
        ans+=dp[N-1][j];
        ans%=MOD;
    }
    cout<<ans<<endl;
}