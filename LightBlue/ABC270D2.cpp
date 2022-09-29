/*
g++ ABC270D3.cpp -o p -o2

AC

*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1<<30;

int main(){
    int N;
    int K;
    vector<int> A(K);
    cin>>N>>K;
    for(int i=0;i<K;i++){
        cin>>A[i];
    }

    vector<int> dp(N+1,0);
    dp[0]=0;
    for(int n=0;n<=N;n++){
        for(int i=0;i<K;i++){
            if(n-A[i]>=0){

                dp[n]=max(dp[n],A[i]+(n-A[i])-dp[n-A[i]]);
            }
        }
    }
    /*
    //ここでエラーになる
    int ans=-INF;
    for(int n=0;n<=N;n++){
        ans=max(ans,dp[n]);
    }

    cout<<ans<<endl;
    */
    cout<<dp[N]<<endl;
}
