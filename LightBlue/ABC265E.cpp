/*
AC

g++ に -O2 をつけるべし

aの個数 bの個数 cの個数
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=998244353;

int main(){
    int N,M;
    cin>>N>>M;
    ll A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    vector<ll> X(M),Y(M);
    set<P> st;
    for(int i=0;i<M;i++){
        cin>>X[i]>>Y[i];
        st.insert(P{X[i],Y[i]});
    }

    map<P,ll> mp;
    mp[P{0,0}]=1;
    for(int i=0;i<N;i++){

        map<P,ll> mp2;
        for(auto [p,num]:mp){
           auto [x,y]=p;
           ///なぜ mp2=mp+numではないのか 配るDPだからそれはないな
           // N回目の操作でちょうどたどり着く場所の場合の数を考えている故.
           
            if(!st.count(P{x+A,y+B})){
                mp2[P{x+A,y+B}]+=num;
                mp2[P{x+A,y+B}]%=MOD;
            }
            
            if(!st.count(P{x+C,y+D})){
                mp2[P{x+C,y+D}]+=num;
                mp2[P{x+C,y+D}]%=MOD;
                
            }
            if(!st.count(P{x+E,y+F})){
                mp2[P{x+E,y+F}]+=num;
                mp2[P{x+E,y+F}]%=MOD;
            }
        }
        //swap(mp,mp2);
        mp=mp2;//これでも可

        

    }

    ll ans=0;
    for(auto [p,num]:mp){
        ans+=num;
        ans%=MOD;
    }

    cout<<ans<<endl;


}