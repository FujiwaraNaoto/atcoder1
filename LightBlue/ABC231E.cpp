/*
AC
dp[i][j]=i桁目まできめて,下に繰り下がりが(ある場合j=1)(ない場合 j=0)

*/
#include<iostream>
#include<map>
#include<numeric>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1LL<<60;

int main(){
    int N;
    ll X;
    cin>>N>>X;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    vector<ll> d(N,INF);//d[N-1]桁目は存在しないので
    //i=N-2まで
    for(int i=0;i+1<N;i++)d[i]=A[i+1]/A[i];

    vector<ll> x(N);
    for(int i=N-1;i>=0;i--){
        x[i]=X/A[i];
        X%=A[i];
    }

    vector<vector<ll>> dp(N+1,vector<ll>(2,INF));

    dp[0][1]=INF;//最初で繰り上がりを考慮している. これはあり得ないのでINF
    dp[0][0]=0;//1桁目(0-index)最初はどこからも借りられる(受け身)ことはない
   /*
    
    iよりも高い位から貸してもらう場合,nj*d[i]
    i桁目が(i+1)桁目から貸される側の場合がjに相当.
    A[i]-j+nj*d[i]-B[i]=X[i]
    min(A[i]+B[i])なので, X[i]+j-nj*d[i]を考えるのみでよい

   */
    for(int i=0;i<N;i++){//下の位から決めていく
        for(int j=0;j<2;j++){
            for(int nj=0;nj<2;nj++){
                if(i+1<N){
                    dp[i+1][nj]=min(dp[i+1][nj],dp[i][j]+abs(x[i]+j-nj*d[i]));
                }
                else{//i==N-1
                    dp[i+1][nj]=min(dp[i+1][nj],dp[i][j]+abs(x[i]+j));

                }
            }
        }
    }

    //下の位に貸し出しているなら1 そうでないならば0
    cout<<min(dp[N][0],dp[N][1])<<endl;




}