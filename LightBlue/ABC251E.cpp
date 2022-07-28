/*
模範解答
dp[n][j][nk] = (jが予言 nkが直前の状態, nk=1なら動物nに餌あり, nk=0なら動物iに餌無し)

j=0なら最初に餌を与えない(動物0と1になし)
j=1なら最初に餌を与える(動物0と1に与える)

0-1-2-3-4-5-....-(N-1)-0
とするために配列の大きさで nは N+1としている


遷移
dp[i+1][j][1]=min({dp[i][0][1],dp[i][0][0],dp[i][1][0],dp[i][1][1]}+A[i])
dp[i+1][j][0]=min(dp[i][0][1],dp[i][1][1])

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(2,vector<ll>(2,INF)));
    

    dp[0][0][0]=0,dp[0][1][1]=0;

    for(int i=0;i<N;i++){//dp[i][j][k]
        for(int j=0;j<2;j++){//最初の予言
            for(int k=0;k<2;k++){//動物iに餌が与えられた状態かどうか
                
                if(k==1){//動物iに餌が与えられたときのみ, A[i]を与えないという選択ができる
                    dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][k]);//nk=0
                }

                dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][k]+A[i]);//動物iに餌が与えられた状態
            }
        }
    }

    ll ans=min(dp[N][0][0],dp[N][1][1]);
    cout<<ans<<endl;
}