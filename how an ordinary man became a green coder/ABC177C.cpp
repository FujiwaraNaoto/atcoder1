#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=(1e+9)+7;

ll mod_pow(ll x,ll y){
    ll ret=1;

    while(y>0){
        if(y&1){
            ret= ret*x%MOD;
        }
        x = x*x%MOD;
        y >>=1;
    }
    return ret;
}

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    ll sumA=0,squareA=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sumA = (sumA + A[i])%MOD;
        squareA = (squareA + A[i]*A[i]%MOD)%MOD;
    }

    ll ans = (sumA*sumA%MOD - squareA + MOD)%MOD*mod_pow(2,MOD-2)%MOD;

    cout<<ans<<endl;
}