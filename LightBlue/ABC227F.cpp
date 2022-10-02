/*
AC

dp[H+1][W+1][H+W+1]
H+W+1にすることがポイント

dp[i][j][k]=(i,j)にいる.一番大きいものからk番目に大きいものまでをたした際の合計のmin
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const ll INF=1LL<<60;

int main(){
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<ll>> A(H,vector<ll>(W));
    vector<vector<bool>> on(H,vector<bool>(W,false));
    vector<P> masu;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];
            masu.emplace_back(i,j);
        }
    }

    sort(masu.begin(),masu.end(),
    [&](const P& lhs,const P& rhs){
        //値が大きいほうから試していく
        return A[lhs.first][lhs.second]>A[rhs.first][rhs.second];
    });

    ll ans=INF;
    for(int idx=0;idx<H*W;idx++){
        auto [vy,vx]=masu[idx];
        
        on[vy][vx]=true;//X以上
        vector<vector<vector<ll>>> dp(H,vector<vector<ll>>(W,vector<ll>(H+W+1,INF)));
        

        if(on[0][0]) dp[0][0][1]=A[0][0];
        else  dp[0][0][0]=0;
       
        for(int k=0;k<=K;k++){
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){

                    if(0<=i-1){
                        if(on[i][j]){
                            dp[i][j][k+1]=min(dp[i][j][k+1],dp[i-1][j][k]+A[i][j]);
                        }else{
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
                        }
                    }

                    if(0<=j-1){
                        if(on[i][j]){
                            dp[i][j][k+1]=min(dp[i][j][k+1],dp[i][j-1][k]+A[i][j]);
                        }else{
                            dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k]);
                        }
                    }

                }
            }

        
        }
       
        ans=min(ans,dp[H-1][W-1][K]);
        


       

    }

    cout<<ans<<endl;
    







}