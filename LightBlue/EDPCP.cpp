/*
AC 木DP
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int black=1;
const int white=0;

vector<vector<int>> G;

vector<vector<ll>> dp;

void dfs(int now,int pre){

    dp[now][white]=1;
    dp[now][black]=1;
    for(int to:G[now]){
        if(to==pre) continue;
        dfs(to,now);
        dp[now][white]*=(dp[to][black]+dp[to][white])%MOD;
        dp[now][white]%=MOD;

        dp[now][black]*=dp[to][white];
        dp[now][black]%=MOD;
    }


}


int main(){
    int N;
    cin>>N;
    G=vector<vector<int>>(N,vector<int>{});
    dp=vector<vector<ll>>(N,vector<ll>(2,0));

    int x,y;
    for(int i=0;i<N-1;i++){
        cin>>x>>y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(0,-1);

    cout<<(dp[0][white]+dp[0][black])%MOD<<endl;


}