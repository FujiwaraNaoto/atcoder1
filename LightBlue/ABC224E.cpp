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


// int main(){
//     int H,W,N;
//     cin>>H>>W>>N;
//     vector<PP> vec;
//     vector<int> r(N),c(N);
//     vector<int> a(N);
//     //vector<points>
//     map<int,vector<P>> mp;
//     for(int i=0;i<N;i++){
//         cin>>r[i]>>c[i]>>a[i];
//         mp[-a[i]].emplace_back(r[i],c[i]);//値が大きいマスから考えるべき
//     }

//     map<int,int> dp_r,dp_c;
//     map<P,int> ans;

//     for(auto [_,vec]:mp){//aが同じ値のときのための対策.
//         vector<PP> tmp;
//         for(auto [y,x]:vec){
//             int cnt=max(dp_r[y],dp_c[x]);
//             tmp.emplace_back(cnt,P{y,x});
//         }
//         //同じaに対しての処理.
//         for(auto [cnt,p]:tmp){
//             auto [y,x]=p;
//             ans[p]=cnt;
//             dp_r[y]=max(dp_r[y],cnt+1);//更新
//             dp_c[x]=max(dp_c[x],cnt+1);
//         }
//         vector<PP>().swap(tmp);

//     }

//     for(int i=0;i<N;i++){
//         //cin>>r[i]>>c[i]>>a[i];
//         cout<<ans[P{r[i],c[i]}]<<endl;
//     }



    


// }