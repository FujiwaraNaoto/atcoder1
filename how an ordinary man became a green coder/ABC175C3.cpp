//AC むずい
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<61;

int main(){
    ll X,K,D;
    cin>>X>>K>>D;
    if(X<0) X=-X;//正の値にしておく
    
    if(K<=X/D){//すでに回数を使い切った場合
        cout<<X-K*D<<endl;    
        return 0;
    }else{
        K=K-X/D;//X/D はX/D 以下の最大の整数
        ll A = X-(X/D)*D;
        if(K%2==0){
            cout<<A<<endl;
        }else{
            cout<<abs(A-D)<<endl;
        }
    return 0;
    }


}