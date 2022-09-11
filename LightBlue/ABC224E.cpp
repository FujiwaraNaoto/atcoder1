/*
mapで管理することのうまさ
*/
#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;
const ll INF=1LL<<60;
typedef pair<int,int>P;
typedef pair<int,P>PP;

int main(){
    int H,W,N;
    cin>>H>>W>>N;
    vector<int> r(N),c(N),a(N);
    map<int,vector<int>> masu;

    for(int i=0;i<N;i++){
        cin>>r[i]>>c[i]>>a[i];
        masu[-a[i]].push_back(i);//a[i]が正のほうに大きい程早く取り出される
    }

 
   vector<int> dp(N);
   map<int,int> mp_r,mp_c;
   //vが前後で同じ値の場合に困る
    

    for(auto [tv,idx] :masu){//tvは使わない
        for(int t:idx){
            dp[t]=max(mp_r[r[t]],mp_c[c[t]]);
        }

        for(int t:idx){
            mp_r[r[t]]=max(mp_r[r[t]],dp[t]+1);
            mp_c[c[t]]=max(mp_c[c[t]],dp[t]+1);
        }

    }
    

    for(int i=0;i<N;i++){
        cout<<dp[i]<<endl;
    }


}