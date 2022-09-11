/*
意外と難しい
オーバーフローに気を付ける部分が難しい
AC
*/
#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;
const ll MOD=998244353;

//x^y
ll mod_pow(ll x,ll y,ll mod){
    ll ret=1;

    while(y>0){
        if(y&1){
            ret*=x;
            ret%=mod;
        }

        x=x*x%mod;
        y/=2;
    }

    return ret;

}

int main(){
    ll N,K,M;
    cin>>N>>K>>M;
    
    if(M%MOD==0){
        //MがMODで割り切れてしまう場合
        cout<<0<<endl;
        return 0;
    }
    K%=(MOD-1);

    ll r = mod_pow(K,N,MOD-1);//K^N
    M%=MOD;
    ll ans=mod_pow(M,r,MOD);//M^p

    cout<<ans<<endl;
    

}