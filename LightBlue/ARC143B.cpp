/*
少なくとも一つで包除原理
AC

*/
/*
少なくともひとつ=両方を満たさない場合を考える.


全体の並べ方 (N^2)! 通りから,

マスN^2 個から一つ選ぶ　
残りの 2N-1個を選ぶ
行 N-1 個の数字の並べ方
列 N-1 個の数字の並べ方

残りの数字 N^2-(2N-1) = (N-1)^2 の並べ方

comb(N^2,1) * comb(N^2,2N-1)*  ((N-1)!)

*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;


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

//x!
ll factorial(ll x,ll mod){
    ll ret=1;
    for(ll i=1;i<=x;i++){
        ret=ret*i%mod;
    }

    return ret;
}

combination comb(501*501);

int main(){
    ll N;
    cin>>N;
    // (N^2)! - (N^2 * comb(N^2,2N-1) * (N-1)! * (N-1)! * ((N-1)^2)! )
  
    ll ans2 =((((N*N*comb(N*N,2*N-1)%MOD)*comb.fact[N-1]%MOD)*comb.fact[N-1]%MOD)*comb.fact[(N-1)*(N-1)]%MOD);
    ll ans3=comb.fact[N*N];

    ll ans = (ans3-ans2+MOD)%MOD;

    cout<<ans<<endl;


}