/*
模範解答2 こちらが王道
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD=998244353;

int main(){
    int n,d;
    cin>>n>>d;
    vector<ll> f(n+1),g(n+1);//f[i]で

    vector<ll> two(n+1);
    two[0]=1;//2^0
    for(int i=0;i+1<=n;i++){
        two[i+1]=2*two[i];
        two[i+1]%=MOD;
    }

    ll ans=0;
    for(int i=0;i<=d;i++){
        int j=d-i;
        
        if(i>=n) continue;
        if(j>=n) continue;
        ll now=two[n-max(i,j)]-1;//どの頂点を折り返し(もしくは基準点)に選ぶことができるか
        now=(now+MOD)%MOD;
        now*=two[max(i-1,0)];
        now%=MOD;
        now*=two[max(j-1,0)];
        now%=MOD;
        ans+=now;
        ans%=MOD;

    }
    ans*=2;
    ans%=MOD;

    cout<<ans<<endl;   

}