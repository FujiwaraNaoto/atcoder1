/*
これは簡単.AC
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<char>> a(H,vector<char>(W));
    vector<vector<ll>> dp(H,vector<ll>(W,0));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a[i][j];
        }
    }

    dp[0][0]=1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i+1<H && a[i+1][j]=='.'){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }

            if(j+1<W && a[i][j+1]=='.'){
                dp[i][j+1]+=dp[i][j];
                dp[i][j+1]%=MOD;
            }
        }
    }

    cout<<dp[H-1][W-1]<<endl;

}