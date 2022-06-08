/*
dp[i]=i自身を含めて自分の下に何個の頂点を含むか
AC 木DP 

全体の貢献度を考える問題
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<vector<int>> G;
vector<int> dp;

int N;
ll ans=0;

void dfs(int now,int pre){

    for(int to:G[now]){
        if(to==pre) continue;
        dfs(to,now);
        dp[now]+=dp[to];
    }

    dp[now]+=1;

    ans+=1LL*(N-dp[now])*dp[now];

}


int main(){
    
    cin>>N;
    dp = vector<int>(N,0);
    G = vector<vector<int>>(N,vector<int>{});

    int a,b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1);
    cout<<ans<<endl;

}
