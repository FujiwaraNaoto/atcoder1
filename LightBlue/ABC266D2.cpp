#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
//const ll MOD=998244353;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<int, P> PP;

int main(){
    int N;
    cin>>N;
    vector<PP> sunuke(N);
    vector<int> X(N),T(N);
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>T[i]>>X[i]>>A[i];
        sunuke[i]=PP{T[i],P{X[i],A[i]}};
    }

    vector<vector<ll>> dp(N+1,vector<ll>(5,-INF));
    dp[0][0]=0;//最初は高橋君はx=0にいる.
    
    int t=0;
    for(int i=0;i<N;i++){
      
        for(int x=0;x<=4;x++){

            if(x==X[i]){
                for(int tx=0;tx<=4;tx++){//txからx(=X[i])へ移動する
                    if(abs(X[i]-tx)<=(T[i]-t)){
                        dp[i+1][x]=max(dp[i+1][x],A[i]+dp[i][tx]);

                    }
                }
            }else{
                for(int tx=0;tx<=4;tx++){//txからxへ移動する
                    if(abs(x-tx)<=(T[i]-t)){
                        dp[i+1][x]=max(dp[i+1][x],dp[i][tx]);

                    }
                }


            }

        }

        t=T[i];
    }

    ll ans=0;
    for(int x=0;x<=4;x++){
        ans=max(dp[N][x],ans);
    }

    cout<<ans<<endl;


}