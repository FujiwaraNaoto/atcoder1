/*
AC
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const ll MOD=998244353;
vector<vector<int>> G;
vector<bool> used;
vector<int> deg;

int cntE,cntV;//辺の数と頂点の数

void dfs(int now){
    cntV++;
    cntE+=deg[now];
    used[now]=true;
    for(int to:G[now]){
        if(used[to]) continue;
        
       
        dfs(to);
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> U(M),V(M);
    deg = vector<int>(N,0);
    used = vector<bool>(N,false);
    G=vector<vector<int>>(N,vector<int>{});

    for(int i=0;i<M;i++){
        cin>>U[i]>>V[i];
        U[i]--;V[i]--;
        deg[U[i]]++;
        deg[V[i]]++;
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    ll ans=1;
    for(int start=0;start<N;start++){
        if(used[start]) continue;//startが既に使われていた場合


        cntE=0; cntV=0;
        dfs(start);
        
        if(cntE/2 ==cntV){ //辺の数を2回ダブりでカウントしているので. cntE=cntV*2でも可  
            ans*=2;
            ans%=MOD;
        }else{
            ans*=0;
        }
    }

    cout<<ans<<endl;




}