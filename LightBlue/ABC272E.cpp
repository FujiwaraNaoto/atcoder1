/*
やっとAC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N,M;
    cin>>N>>M;

    vector<ll> a(N+1);//1-indexedで考え始めることにする
    for(int i=1;i<=N;i++) cin>>a[i];

    vector<vector<ll>> flows(M+1,vector<ll>{});

    for(int i=1;i<=N;i++){
        // a[i]+i*lft>0
        ll lft = (a[i]>=0 ? 1: (-a[i]+i-1)/i );
        //a[i]が負の数の場合,lft回　i　を足すことでようやく正の数になる
        

        ll rht = min(1LL*M,1LL*(N-a[i])/i);//rht+1回 iを足すと範囲を超えてしまう


        for(int j=lft;j<=rht;j++){
            // 1<= a[i]+i*j  <=N
            flows[j].push_back( a[i]+i*j );
        }
    }

    for(int i=1;i<=M;i++){
        int sz=flows[i].size();
        vector<bool> exi(sz+2,false);
        for(ll x:flows[i]){
            if(x<=sz){
                exi[x]=true;
            }
        }

        ll ans=0;
        while(exi[ans])ans++;

        cout<<ans<<endl;

    }



}
