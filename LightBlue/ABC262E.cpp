/*
赤い頂点に選ぶ場合,次数が奇数の頂点が偶数個のときである
ことがわかる
AC

*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
//vector<vector<int>> G;



//xのy乗
ll mod_pow(ll x,ll y,ll mod){
    ll power=x;
    ll ret = 1;
    while(y>0){
        if(y&1){
           ret = ret*power%mod;
        }
        power = power*power%mod;
        y = y>>1;
    }
    return ret;

}



struct combination{
    typedef long long ll;
    std::vector<ll> fact,ifact;
    combination(ll n): fact(n+1),ifact(n+1){
        fact[0]=1;//0!=1通り
        for(ll i=1;i<=n;i++) fact[i] = fact[i-1]*i%MOD;
        //ifact[n] = fact[n].inv();
        
        // n!の逆元がifact[n]
        ifact[n] = mod_pow(fact[n],MOD-2,MOD);// n!を(mod-2)乗した後でmodであまりをとった
        for(ll i=n;i>=1;i--) ifact[i-1] = ifact[i]*i%MOD;
    }

    ll operator()(ll n,ll k){
        if(k<0 || k>n) return 0;
        // n!/( k!*(n-k)! )
        return (fact[n]*ifact[k])%MOD * ifact[n-k]%MOD;
    }

};

combination comb(200000+5);


int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<int> U(M),V(M);
    vector<int> deg(N);
    for(int i=0;i<M;i++){
        cin>>U[i]>>V[i];
        U[i]--;V[i]--;
        deg[U[i]]++;
        deg[V[i]]++;
    }


    ll odd_cnt=0;
    for(int i=0;i<N;i++){
        if(deg[i]%2==1){
            odd_cnt++;
        }
    }
    ll ans=0;
    for(int k=0;k<=odd_cnt;k+=2){
        if(odd_cnt>=k && K-k<=N-odd_cnt){
            ans+=comb(odd_cnt,k)*comb(N-odd_cnt,K-k)%MOD;
            ans%=MOD;
        }
    }

    cout<<ans<<endl;

}