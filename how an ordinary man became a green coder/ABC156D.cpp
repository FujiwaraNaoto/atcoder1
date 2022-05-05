#include<vector>
#include<iostream>
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

//nの制約上,こうせざるを得ない
ll nCr(ll n,ll r){
    ll ans=1;
    
    for(ll x=n-r+1;x<=n;x++){
        ans=(ans*x)%MOD;
    }
    ll div=1;
    for(ll x=1;x<=r;x++){
        div = (div*x)%MOD;
    }
    // r! の逆元
    div = mod_pow(div,MOD-2,MOD);
    ll ret = ans*div%MOD;
    return ret;
}



int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll all = (mod_pow(2,n,MOD)-1+MOD)%MOD;// 0本の1通りを退けている

    ll coma = nCr(n,a);
    ll comb = nCr(n,b);
    ll ans =  ( (all - coma+MOD)%MOD - comb + MOD)%MOD;

    cout<<ans<<endl;
}