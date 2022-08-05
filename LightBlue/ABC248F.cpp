/*
AC

dp[i][j][k]=j本を切る. kは 頂点iと頂点N+iの成分が連結している(ちょっと誤解ある)なら0 そうでないならば1

*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll P;
    cin>>N>>P;

    vector<vector<vector<ll>>> dp(N+2,vector<vector<ll>>(N+3,vector<ll>(2,0)));
    
    dp[1][0][0]=1;//頂点1とN+1が連結してる
    dp[1][1][1]=1;//頂点1とN+1が連結していない

    for(int i=1;i<N;i++){
        //インターフェースは 頂点i, N+iの二つ.
        //頂点i+1, N+i+1をつなぐことを考える
        //
        
        for(int j=0;j<N;j++){
            ll d0=dp[i][j][0];
            ll d1=dp[i][j][1];

            dp[i+1][j][0]+=d0;//(i,i+1) (i+1,N+i+1) (N+i,N+i+1)
            dp[i+1][j][0]%=P;

            dp[i+1][j+1][0]+=d0;//(i,i+1) (i+1,i+N+1)
            dp[i+1][j+1][0]%=P;

            dp[i+1][j+1][0]+=d0;//(N+i+1,i+1) (i+1,N+i+1)
            dp[i+1][j+1][0]%=P;

            dp[i+1][j+1][0]+=d0;//(i,i+1) (N+i,N+i+1)
            dp[i+1][j+1][0]%=P;

            dp[i+1][j+2][1]+=d0;//(N+i,N+i+1)
            dp[i+1][j+2][1]%=P;

            dp[i+1][j+2][1]+=d0;//(i,i+1)
            dp[i+1][j+2][1]%=P;

            dp[i+1][j][0]+=d1;//(i,i+1) (i+1,N+i+1) (N+i,N+i+1)
            dp[i+1][j][0]%=P;

            dp[i+1][j+1][1]+=d1;//(i,i+1) (N+i,N+i+1)をつなぐ
            dp[i+1][j+1][1]%=P;
        }
    }
    for(int k=1;k<N;k++){
        cout<<dp[N][k][0]<<(k==N-1?'\n':' ');
    }


}