//AC
#include<iostream>
#include<vector>
using namespace std;
const int INF=1<<30;

int main(){
    int N,X,Y;
    cin>>N;
    cin>>X>>Y;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++)cin>>A[i]>>B[i];

    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(X+1,vector<int>(Y+1,INF)));

    dp[0][0][0]=0;

    for(int i=0;i<N;i++){
        for(int x=0;x<=X;x++){
            for(int y=0;y<=Y;y++){
                if(dp[i][x][y]!=INF){
                    //購入すると購入しないの2通りがある
                    dp[i+1][min(X,x+A[i])][min(Y,y+B[i])]
                        =min(dp[i+1][min(X,x+A[i])][min(Y,y+B[i])],dp[i][x][y]+1);
                    dp[i+1][x][y]=min(dp[i+1][x][y],dp[i][x][y]);
                }
            }
        }
    }

    cout<<(dp[N][X][Y]==INF?-1:dp[N][X][Y])<<endl;

}