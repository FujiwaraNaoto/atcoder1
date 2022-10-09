/*
ベルマンフォード法に似ている
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll INF=1LL<<60;

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<ll> dp(N,INF);
    vector<int> A(M),B(M),C(M);
    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;B[i]--;
    }
    dp[0]=0;
    vector<int> E(K);
    for(int i=0;i<K;i++){
        cin>>E[i];
        E[i]--;
        int e=E[i];
        dp[B[e]]=min(dp[A[e]]+C[e],dp[B[e]]);
    } 

    cout<<(dp[N-1]==INF? -1 : dp[N-1])<<endl;

}