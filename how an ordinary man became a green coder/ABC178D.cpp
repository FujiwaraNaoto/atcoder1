//動的計画法だとTLE WA
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = (1e+9)+7;

int main(){

    int S;
    cin>>S;

    vector<vector<ll>> dp(S+1,vector<ll>((S+3-1)/3 ,0));
    dp[0][0]=1;//0個で仕切り0こ

    for(int x=0;x<=S;x++){

        for(int i=0;i<=S/3;i++){
            for(int y=x+3;y<=S;y++){
                //仕切りを一つ増やすことを考える
                dp[y][i+1] = (dp[y][i+1] +  dp[x][i])%mod;
            }
        }
    }

    ll ans=0;
    for(int i=0;i<=S/3;i++){
        ans = (ans + dp[S][i])%mod;
    }
    cout<<ans<<endl;
    
}