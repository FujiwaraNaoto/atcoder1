//AC
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<61;

int main(){
    ll X,K,D;
    cin>>X>>K>>D;
    
    if(X<0) X=(-1)*X;

    ll ans;
    ll times = X/D;
    if(times>=K){
        //K回全て消費しても負の領域にいくことが無理
        ans = X-K*D; 
    
    }else{
        times = K-X/D;
        ll nowx = X-(X/D)*D;

        if(times%2==0){
            ans = nowx;
        }else{
            ans = abs(nowx-D);
        }

    }

    cout<<ans<<endl;




}