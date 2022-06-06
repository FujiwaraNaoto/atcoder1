/*
木DPを使用するが,遷移が難しい
AC 
色はaの時 1
bの時0とする
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 +7;
vector<vector<int>> G;
vector<int> color;

vector<vector<ll>> dp;

void dfs(int now,int pre){

    ll num=1,num2=1;

    for(int child:G[now]){
        if(child==pre) continue;
        dfs(child,now);
        if(color[now]==0){
            //nowの色がaだった場合
            //num=(num*(dp[child][0]+dp[child][2])%MOD )%MOD;
            num*=(dp[child][0]+dp[child][2])%MOD;
        }else{
            //nowの色がbだった場合
            //num=(num*(dp[child][1]+dp[child][2])%MOD)%MOD;
            num*=(dp[child][1]+dp[child][2])%MOD;
        }
        
        num2 *= (dp[child][0]+dp[child][1] + 2*dp[child][2])%MOD;

        num%=MOD;
        num2%=MOD;   
    }

    if(color[now]==0){
        dp[now][0]=num;
        dp[now][2]=(num2 - num+MOD)%MOD;
        
    }else{
        dp[now][1]=num;
        dp[now][2]=(num2 - num+MOD)%MOD;
    }


}


int main(){
    int N;
    cin>>N;
    color = vector<int>(N,-1);
    char c;
    for(int i=0;i<N;i++){
        cin>>c;
        if(c=='a') color[i]=0;
        else color[i]=1;
    }
    G = vector<vector<int>>(N,vector<int>{});
    dp = vector<vector<ll>>(N,vector<ll>(3,0));

     for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;//0からにする
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1);
    cout<<dp[0][2]<<endl;

    


}
