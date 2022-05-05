/*
典型的なナップサック問題
ただし　もらうDPで考える際は注意が必要
*/

#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N,W;
    cin>>N>>W;

    vector<int> weight(N);
    vector<ll> value(N);

    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i];
    }

    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));

    //dp[i][w]i番目の品物を見て, 重さがwの時  価値のmax  

    for(int i=0;i<N;i++){

        for(int w=0;w<=W;w++){
            if(w+weight[i]<=W){
                dp[i+1][w+weight[i]]= max(dp[i][w]+value[i],dp[i][w+weight[i]]);
            }
            dp[i+1][w]=max( dp[i+1][w],dp[i][w]);
        }
    }

    ll ans=0;
    for(int w=0;w<=W;w++){
        ans = max(ans,dp[N][w]);
    }

    cout<<ans<<endl;

}