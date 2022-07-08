#include<iostream>
#include<vector>
typedef long long ll;

//xのy乗
int mod_pow(int x,int y,int mod){
    int power=x;
    int ret = 1;

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
    std::vector<int> fact,ifact;
    combination(int n): fact(n+1),ifact(n+1){
        fact[0]=1;//0!=1通り
        for(int i=1;i<=n;i++) fact[i] = fact[i-1]*i%MOD;
        //ifact[n] = fact[n].inv();
        
        // n!の逆元がifact[n]
        ifact[n] = mod_pow(fact[n],MOD-2,MOD);// n!を(mod-2)乗した後でmodであまりをとった
        for(int i=n;i>=1;i--) ifact[i-1] = ifact[i]*i%MOD;
    }

    int operator()(int n,int k){
        if(k<0 || k>n) return 0;
        // n!/( k!*(n-k)! )
        return (fact[n]*ifact[k])%MOD*ifact[n-k]%MOD;
    }

};

combination c(55);



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
