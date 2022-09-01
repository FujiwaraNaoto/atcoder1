/*
ソートしてdp 
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<int,P> PP;

int main(){
    int N;
    cin>>N;
    vector<int> D(N),C(N);
    vector<ll> S(N);
    vector<PP> task(N);
    for(int i=0;i<N;i++){
        cin>>D[i]>>C[i]>>S[i];
        task[i]=PP{D[i],P{C[i],S[i]}};
    }

    sort(task.begin(),task.end());

    vector<ll> dp(5000+1,0);

    for(auto [d,p]:task){
        auto [c,s]=p;//締め切りが小さい順に見ていく.
        vector<ll> new_dp=dp;
        for(int j=1;j<=5000;j++){
            if(j-c>=0 && j<=d){
            new_dp[j]=max(dp[j],dp[j-c]+s);
            }
        }
        dp =new_dp;
    }

    ll ans=0;
    for(int j=1;j<=5000;j++){
        ans=max(ans,dp[j]);
    }
    cout<<ans<<endl;



}