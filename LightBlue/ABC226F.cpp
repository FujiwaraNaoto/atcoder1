/*
    map
    firstが lcm(最小公倍数)
    secondが サイクルの大きさ
 
    dp[i][j] = (i個つかって lcmがjとなる組み合わせの総数)
 
    */
#include<iostream>
#include<map>
#include<numeric>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1LL<<60;
const ll MOD=998244353;




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


ll gcd(ll x,ll y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}


struct combination{
    //typedef long long ll;
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

combination comb(52);


int main(){
    ll N,K;
    cin>>N>>K;

    vector<map<int,ll>> dp(N+1);//d[i][j]=i人で周期jのときの通り数
    //dp[1][1]=N;//0人で周期1は1通り//これは無理
    dp[0][1]=1;//0人で周期1は1通り
    for(int i=0;i<=N;i++){//
        
        for(int j=1;j+i<=N;j++){
            for(auto [l,x]:dp[i]){    
                // N-i C j
                //dp[i+j][lcm(l,j)]=( dp[i+j][lcm(l,j)]+ ( (x*comb(N-i-1,j-1))%MOD*comb.fact[j-1] )%MOD )%MOD;
                dp[i+j][lcm(l,j)]+= ( (x*comb(N-i-1,j-1))%MOD*comb.fact[j-1] )%MOD;
                dp[i+j][lcm(l,j)]%=MOD;
            }
        }
    }

    ll ans=0;
    for(auto [l,num]:dp[N]){
        //cout<<"l="<<l<<"num="<<num<<endl;
        //m^K がnum個ある
        ans+=mod_pow(l,K,MOD)*num%MOD;
        ans%=MOD;

    }
    
    cout<<ans<<endl;
    

}