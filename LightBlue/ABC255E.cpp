/*
AC 難しいが,時間をかければ解ける問題
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int N,M;
    cin>>N>>M;
    vector<ll> S(N-1);//S[0]~S[N-2]
    vector<ll> X(M);
    for(int i=0;i<N-1;i++)cin>>S[i];
    for(int i=0;i<M;i++)cin>>X[i];

    vector<ll> B(N);
    B[0]=0;
    for(int i=1;i<=N-1;i++){
        B[i]=-B[i-1]+S[i-1];
    }

    map<ll,ll> mp;//A[0]の出現回数をカウント
    

    for(int i=0;i<M;i++){
        
        ll x=X[i];//xとなる回数
        for(int k=0;k<=N-1;k++){
            if(k%2==1){
                mp[B[k]-x]++;
            }else{
                mp[x-B[k]]++;    
            }
        }
    }
    
    ll ans=0;
    for(auto [_,num]:mp){
        ans=max(ans,num);
    }
    
    cout<<ans<<endl;   

}