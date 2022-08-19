/*
AC グラフのいい問題
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const ll MOD=998244353;
vector<vector<int>> G;
vector<bool> used;
vector<ll> T;
ll ans=0;

void dfs(int now){

    if(used[now]) return;


    //はじめて訪れる場合
    ans+=T[now];
    used[now]=true;

    for(int to:G[now]){
        dfs(to);
    }
}


void bfs(int now){
    queue<int> que;
    que.push(now);
    while(!que.empty()){
        int now=que.front();
        que.pop();
        if(used[now]) continue;//すでに訪れた場合

        used[now]=true;
        ans+=T[now];

        for(int to:G[now]){
            if(used[to])continue;

            que.push(to);
        }

    }
}




int main(){
    int N;
    cin>>N;
    G=vector<vector<int>>(N,vector<int>{});

    T=vector<ll>(N,0);
    int K;
    for(int i=0;i<N;i++){
        cin>>T[i]>>K;
        int a;
        for(int j=0;j<K;j++){
            cin>>a;
            a--;
            G[i].push_back(a);//技iを覚えるために技aが必要
        }
    }

    
    used=vector<bool>(N,false);
    //dfs(N-1);
    bfs(N-1);

    cout<<ans<<endl;

}