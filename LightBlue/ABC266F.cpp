
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<int> root;

void dfs(int now,int pre){
    root[now]=root[pre];
    for(int to:G[now]){
        if(to==pre)continue;
        //この先は葉に向かっていくのみ
        dfs(to,now);
    }
}

int main(){
    int N;
    cin>>N;
    G = vector<vector<int>>(N,vector<int>{});
    vector<int> deg(N,0);
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;    
        deg[a]++;
        deg[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    int Q;
    cin>>Q;
    vector<int> x(Q),y(Q);
    for(int i=0;i<Q;i++){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
    }

    vector<bool> is_cycle(N,true);

    queue<int> que;
    for(int v=0;v<N;v++){
        if(deg[v]==1){
            que.push(v);
        }
    }
    
    while(!que.empty()){
        int v=que.front();
        is_cycle[v]=false;//頂点vはサイクルの一部ではないことがわかる
        que.pop();
        deg[v]--;//これで次数が0になり,除かれることになる

        for(int to:G[v]){
            deg[to]--;//vについている辺の個数を1減らす.
            if(deg[to]==1){
                que.push(to);
            }
        }

    }
   
    root=vector<int>(N,-1);
    for(int v=0;v<N;v++){
        if(is_cycle[v]){
            root[v]=v;
            for(int to:G[v]){
                
                if(!is_cycle[to]){//頂点toがcycleの一部でない場合
                    // root[v]=v; ここではないことに注意
                    dfs(to,v);
                }
            }
        }
    }

    //cout<<"test2"<<endl;

    for(int i=0;i<Q;i++){
        cout<<(root[x[i]]==root[y[i]]?"Yes":"No")<<endl;
    }








}