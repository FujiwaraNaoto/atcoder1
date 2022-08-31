/*

dp[l][r]=両端閉区間区間[l,r]
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<ll,int> P;

int main(){
    int N;
    cin>>N;
    vector<ll> A(2*N);
    for(int i=0;i<2*N;i++) cin>>A[i];

    vector<vector<ll>> dp(2*N,vector<ll>(2*N,INF));

    //i=2N-1でおわり

    for(int i=0;i<2*N;i++) dp[i][i]=0;
    for(int i=0;i+1<2*N;i++) dp[i][i+1]=abs(A[i]-A[i+1]);
    
    // dp[0][2N-1] =[0,2N-1]
    //w=2のときはとおらないのでw=3でも可
    for(int w=2;w<2*N;w++){
        for(int l=0;l+w<2*N;l++){

            int r=l+w;
            for(int m=l+1;m+1<r;m++){
                //[l,m][m+1,r]
                dp[l][r]=min(dp[l][r],dp[l][m] + dp[m+1][r]);
            }

            if(l+1<r-1){
                dp[l][r]=min(dp[l][r],dp[l+1][r-1]+abs(A[l]-A[r]));
            }
        }
    }

    //[0,2N-1]
    cout<<dp[0][2*N-1]<<endl;


}