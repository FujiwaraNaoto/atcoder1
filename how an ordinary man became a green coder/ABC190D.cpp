//AC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    
    ll ans=0;
    // 初項n　項数がxの時 nx + x*(x-1)/2 となる temp/x=nとなる
    for(ll x=1;; x++){
        ll temp = N-x*(x-1)/2;
        if(temp<=0) break;

        if(temp%x==0) ans+=2;//nが存在すると分かった時,マイナスとプラスの分で2つ存在

    }
    cout<<ans<<endl;



}