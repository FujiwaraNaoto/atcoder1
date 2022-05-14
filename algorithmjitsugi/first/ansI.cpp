/*

dp[S][i] = 部品がSの状態 i番目の商品を見ている

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N,M;
    cin>>N>>M;
    string S;
    ll C;
    vector<pair<int,ll>> commodity(M);
    for(int i=0;i<M;i++){
        cin>>S>>C;

        int st=0;
        for(int i=0;i<N;i++){
            if(S[i]=='Y'){
                st|= (1<<i);
            }
        }
        commodity[i]=make_pair(st,C);
    }

    /*
    //これでもいい
    vector<vector<ll>> dp(M+1,vector<ll>(1<<N,INF));
    for(int i=0;i<=M;i++){
        //0この商品なので 0円
        dp[i][0]=0;
    }

    //配列を使いまわす
    for(int i=0;i<M;i++){
        
        for(int S=0;S<(1<<N);S++){
            dp[i+1][S] = dp[i][S];//コピー
        }

        auto [st,cst] = commodity[i];
        for(int S=0;S<(1<<N);S++){
            // dp[i+1][S|st] = min(dp[i][S]+cst, dp[i][S|st]);ではない
            dp[i+1][S|st] = min(dp[i][S]+cst, dp[i+1][S|st]);
        }

    }

    cout<<(dp[M][(1<<N)-1]==INF?-1:dp[M][(1<<N)-1])<<endl;
    */

    //これでも良い
    vector<ll> dp(1<<N,INF);
    dp[0]=0;//0この商品なので 0円

    //配列を使いまわす
    for(int i=0;i<M;i++){
        auto p = dp;
        auto [st,cst] = commodity[i];
        for(int S=0;S<(1<<N);S++){
            dp[S|st] = min(p[S]+cst, dp[S|st]);
        }

    }

    cout<<(dp[(1<<N)-1]==INF?-1:dp[(1<<N)-1])<<endl;
    

}