/*
典型問題
AC
*/
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
const int INF = 1<<30;

int main(){
    int N;
    cin>>N;
    //dp[i]=i番目までの足場にたどり着くまでのコストのmin
    vector<int> dp(N,INF);
    vector<int> h(N);
    for(int i=0;i<N;i++) cin>>h[i];
    
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);//足場0から足場1へはコストabs(h[1]-h[0])
    
    //もらうDP iまで行くのに i-1から行くか,i-2から行くか
    for(int i=2;i<N;i++){
        dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));
    }

    cout<<dp[N-1]<<endl;
    

}