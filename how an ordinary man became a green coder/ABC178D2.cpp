//AC
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = (1e+9)+7;

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
    vector<ll> fact,ifact;
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

combination comb(2000+3);



int main(){

    int S;
    cin>>S;

    //alpha個の仕切りを追加
    // グループ数は alpha+1　個になる

    ll ans=0;
    for(int alpha=0;S-2*(alpha+1)>0;alpha++ ){
        int a = S-2*(alpha+1);

        //a-1個の隙間から alpha個選ぶ
        ans = (ans + comb(a-1,alpha))%MOD;// a C alpha
    }

    cout<<ans<<endl;
    
}