/*
AC
距離の偶奇性がポイント
*/
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int INF=1<<30;
typedef pair<int,int> P;

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<vector<int>> G(N,vector<int>{});
    int a,b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N,INF);
    queue<P> que;
    que.push(P{0,0});
    while(!que.empty()){
        auto [d,v]=que.front();
        que.pop();

        if(dist[v]<d) continue;

        dist[v]=d;

        for(int to:G[v]){
            if(dist[to]>(dist[v]+1)){
                que.push(P{(dist[v]+1),to});
            }
        }
    }
    int c,d;
    for(int q=0;q<Q;q++){
        cin>>c>>d;
        c--;d--;
        int dis=abs(dist[c]-dist[d]);
        if(dis%2==0){
            cout<<"Town"<<endl;
        }else{
            cout<<"Road"<<endl;
        }
    }



}