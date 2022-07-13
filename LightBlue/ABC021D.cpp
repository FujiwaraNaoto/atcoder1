/*
AC
重複組み合わせ

n-1個の仕切りと k個のa を考える.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;


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

    ~combination(){
        std::vector<ll>().swap(fact);
        std::vector<ll>().swap(ifact);

    }

};

int main(){
    ll n,k;
    cin>>n;
    cin>>k;

    //n-1+k C k

    combination c(n+k);

    cout<<c(n-1+k,k)<<endl;


}