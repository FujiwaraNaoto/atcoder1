/*
端っこから埋めていく
BFSだととおる
priority_queueだとTLE
AC
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int MAX_N=1e7;
const ll INF=1LL<<60;
typedef pair<ll,int> P;

vector<vector<P>> edge;

int main(){
    int N,M;
    cin>>N>>M;
    edge = vector<vector<P>>(N,vector<P>{});
    vector<int> A(M),B(M);
    vector<ll> C(M);

    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;
        B[i]--;
        edge[A[i]].emplace_back(C[i],B[i]);
        edge[B[i]].emplace_back(C[i],A[i]);
    } 

    vector<ll> dist1(N,INF);
    vector<ll> distN(N,INF);
    //priority_queue<P,vector<P>> que;
    queue<P> que;
    que.push(P{0,0});//実際は頂点0からゆえ

    while(!que.empty()){
        //auto [c,v]=que.top();
        auto [c,v]=que.front();
        que.pop();
        if(dist1[v]<=c) continue;

        //dist1[v]>c
        dist1[v]=c;
        for(auto [cost,to]:edge[v]){
            if(dist1[to]<=cost+c) continue;
            que.push(P{cost+c,to});
        }
    }


    que.push(P{0,N-1});//実際は頂点N-1からゆえ

    while(!que.empty()){
        //auto [c,v]=que.top();
        auto [c,v]=que.front();
        que.pop();
        if(distN[v]<=c) continue;


        distN[v]=c;
        for(auto [cost,to]:edge[v]){
            if(distN[to]<=cost+c) continue;
            que.push(P{cost+c,to});
        }
    }

    for(int k=0;k<N;k++){
        cout<<dist1[k]+distN[k]<<endl;

    }

    



}