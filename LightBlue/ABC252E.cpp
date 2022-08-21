/*
直前にきた部分を記録しておくべき
AC
ダイクストラ法の応用
*/
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<ll,pair<int,int>> edge;


int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<P>> G(N,vector<P>{});
    vector<int> A(M),B(M),C(M);
    vector<edge> edges(M);

    map<P,int> mp;

    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;B[i]--;
        mp[P(A[i],B[i])]=i;
        mp[P(B[i],A[i])]=i;

        G[A[i]].emplace_back(B[i],C[i]);
        G[B[i]].emplace_back(A[i],C[i]);

    }

    //スタートからその辺に来るまでのコストと直前に来た頂点
    priority_queue<edge,vector<edge>,greater<edge>> que;

    vector<int> path(N,-1);
    vector<bool> used(N,false);
    vector<ll> dist(N,INF);

    que.push((edge){0,P{0,0}});//コスト0 今の辺0 直前の辺0

    while(!que.empty()){

        auto [d,p]=que.top();
        que.pop();
        
        auto [now,pre]=p;//今の頂点nowと直前の頂点pre
        if(dist[now]<=d) continue;

        path[now]=pre;//nowに来るにはpreを通るべし
        used[now]=true;//確定させる頂点のフラグ
        dist[now]=d;//確定させる

        for(auto [to,c]:G[now]){
            if(used[to] || dist[to]<=dist[now]+c)continue;

            que.push((edge){dist[now]+c,P{to,now}});
        }

    }

    vector<int> ans;
    for(int i=1;i<N;i++){
        ans.push_back(mp[P(path[i],i)]);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<(i==ans.size()-1?'\n':' ');
    }





}