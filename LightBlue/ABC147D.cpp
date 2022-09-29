#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
//const int INF=1<<30;
const ll MOD=1e9+7;

ll mod_pow(ll x,ll y,ll mod){
    ll ret=1;
    while(y>0){
        if(y&1){
            ret*=x;
            ret%=mod;
        }
        x*=x;
        x%=mod;
        y/=2;
    }
    return ret;
    
}

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    ll ans=0;
    for(int k=0;k<60;k++){
        ll cnt_one=0;
        for(int i=0;i<N;i++){
            cnt_one+=(A[i]&1);
            A[i]/=2;
        }
        //xorが1になるのは　0-1の組み合わせぶんある.
        ans+=((mod_pow(2,k,MOD)*cnt_one)%MOD*(N-cnt_one)%MOD);
        ans%=MOD;
    }

    cout<<ans<<endl;

}