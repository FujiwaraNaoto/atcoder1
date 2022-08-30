/*
AC
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<int, P> PP;
const int dx[3]={-1,0,1};

int main(){
    int N;
    cin>>N;
    map<int,P> mp;
    vector<int> T(N),X(N);
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>T[i]>>X[i]>>A[i];
        mp[T[i]]=P{X[i],A[i]};
    }

    vector<vector<ll>> dp(100000+2,vector<ll>(5,-INF));
    dp[0][0]=0;

    

    for(int t=1;t<=100000;t++){
    
        for(int x=0;x<=4;x++){
            for(int d:dx){
                if(0<=d+x && d+x<=4){
                    dp[t][x]=max(dp[t][x],dp[t-1][d+x]);
                }            
            }
        }

        
        if(mp.count(t)){
            auto [xx,aa]=mp[t];
            dp[t][xx]+=aa;
        }
        
    }

    ll ans=0;
    for(int x=0;x<=4;x++){
        ans=max(ans,dp[100000][x]);
    }
    cout<<ans<<endl;
}