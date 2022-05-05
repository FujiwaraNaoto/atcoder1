//世事象を考える問題
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = (1e+9)+7;

ll mod_pow(ll x,ll y){
    ll ret=1;
    while(y>0){
        
        if(y&1){
            ret = ret*x%mod;
        }

        x=x*x%mod;
        y>>=1;
    }

    return ret;
}


int main(){
    int N;
    cin>>N;
    
    // 0~9   1~9 1~8  1~8
    ll ans = (( (mod_pow(10,1LL*N) - mod_pow(9,1LL*N) +mod)%mod - mod_pow(9,1LL*N) + mod )%mod  + mod_pow(8,1LL*N) )%mod;
    cout<<ans<<endl;
}
