/*
模範解答
AC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N;
    ll L,R;
    cin>>N>>L>>R;
    vector<ll> A(N+1,0);
    vector<ll> cum(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    
    for(int i=1;i<=N;i++){
        cum[i]=cum[i-1]+A[i];
    }

    vector<ll> minxy(N+1,INF);//minxy[x]で x<=y<=Nでの最小値
    ll tmpmin=INF;
    for(int x=N;x>=0;x--){
        //x==Nのときは y=Nしかむり
        //x=N-1のときは y=N,N-1がとれる　みたいな感じ
        tmpmin=min(tmpmin,cum[x]-R*x);
        minxy[x]=tmpmin;
    }

    ll ans=INF;
    for(int x=0;x<=N;x++){
        ans=min(ans,R*N + L*x-cum[x]+minxy[x]);
    }

    cout<<ans<<endl;





}