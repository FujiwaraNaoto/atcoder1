/*
dp[i][j]= (i,j)にくるまでのコストの最小値
x[i][j]=(i-1,j)もしくは(i,j-1)からきて, (i,j)に駅を立てる際のコストの最小値

*/
#include<iostream>
#include<map>
#include<numeric>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF = 1LL<<60;

int main(){
    int H,W;
    ll C;
    cin>>H>>W>>C;
    vector<vector<ll>> A(H,vector<ll>(W));
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            cin>>A[y][x];
        }
    }

ll ans=INF;

    for(int k=0;k<2;k++){


        vector<vector<ll>> dp(H,vector<ll>(W,INF));
        dp[0][0]=A[0][0];
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                    
                if(i==0 && j>0){
                    dp[i][j]=min(A[i][j],dp[i][j-1]+C);

                }else if(i>0 && j==0){
                    dp[i][j]=min(A[i][j],dp[i-1][j]+C);

                }else if(i>0 && j>0){
                
                //dp[i][j]に (i,j)が終点とする
                //(i,j)が始まりかもしれない
                dp[i][j]=min({dp[i-1][j]+C,dp[i][j-1]+C,A[i][j]});
                }
                

            }
        }
        
        vector<vector<ll>> X(H,vector<ll>(W,INF));
        X[0][0]=INF;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
              
                if(i==0 && j>0){
                
                    X[i][j]=min(X[i][j],dp[i][j-1]+C+A[i][j]);
                    
                }
                else if(i>0 && j==0){
                
                    X[i][j]=min(X[i][j],dp[i-1][j]+C+A[i][j]);
                  
                }
                else if(i>0 && j>0){
                
                    X[i][j]=min(dp[i][j-1]+C+A[i][j],dp[i-1][j]+C+A[i][j]);
                    
                }

            }
        }


    
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                ans=min(ans,X[i][j]);
            }
        }

        for(int i=0;i<H;i++){
            reverse(A[i].begin(),A[i].end());
        }

       
        
    }


    cout<<ans<<endl;






}