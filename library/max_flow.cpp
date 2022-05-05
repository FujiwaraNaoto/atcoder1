/*
ABC225から抜粋
*/


ll level[(MAX_H+1)*(MAX_W+1)+2];
ll iter[(MAX_H+1)*(MAX_W+1)+2];
 

struct edge{int to;  ll cap; int rev;};
vector<edge> G[(MAX_H+1)*(MAX_W+1)+2];
 
 
void add_edge(int from,int to,ll cap){
    G[from].push_back((edge){to,cap,G[to].size()} );
    G[to].push_back((edge){from,0LL,G[from].size()-1});
}
 
 
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
 
        int p = que.front();que.pop();
 
        for(int i=0;i<(int)G[p].size();i++){
            edge e = G[p][i];//頂点pに繋がっている頂点が e.to
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[p]+1;
                que.push(e.to);
            }
        }
    }
}
 
ll dfs(int v,int t,ll f){
    if(v==t) return f;
    for(ll &i=iter[v]; i<(ll)G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            ll d = dfs(e.to, t, min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
 
    return 0;
}
 
 
ll max_flow(int s, int t){
    ll flow=0;
    while(1){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0 ){
            flow += f;
        }
    }
}




/*
外部からは
FLOW<ll> graph(頂点番号数);
で呼び出す
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
typedef long long ll;
typedef pair<int,int> P;
const int INF=1<<29;


template<class T> class FLOW{
    //intになるかlong long になるか
    public:
    struct edge{int from; int to;  T cap; T flow; int rev;};    
    vector<T> level;
    vector<T> iter;
    vector<vector<edge> > G;
    typedef struct pair<int,int> P;
    set<P> st;
    int numV=0;

    //constructor
    FLOW(int V){
        numV=V;
        G = vector<vector<edge>>(V+1,vector<edge>{});
        //G[0],G[1],...,G[V]を作る
        
        level = vector<T>(V+1,0);
        iter  = vector<T>(V+1,0);
    }

    void add_edge(int from,int to,T cap){
        // from to cap flow rev
        
        G[from].push_back((edge){from,to,cap,0,(int)G[to].size()} );
        st.insert(P(from,to));//順辺のみに興味がある


        G[to].push_back((edge){to,from,0,cap,(int)G[from].size()-1});
    }
 
 
    void bfs(int s){
        level = vector<T>(numV+1,-1);//-1に初期化

        queue<int> que;
        level[s]=0;
        que.push(s);
        while(!que.empty()){
    
            int p = que.front();que.pop();
            for(int i=0;i<(int)G[p].size();i++){
                edge e = G[p][i];//頂点pに繋がっている頂点が e.to
                if(e.cap>0 && level[e.to]<0){
                    level[e.to] = level[p]+1;
                    que.push(e.to);
                }
            }
        }
    }
 
    T dfs(int v,int t,T f){
        if(v==t) return f;
        for(T &i=iter[v]; i<(int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap>0 && level[v]<level[e.to]){
                T d = dfs(e.to, t, min(f,e.cap));
                if(d>0){
                    e.cap -= d;
                    e.flow += d;//capが減った分,今,流す量が増えた


                    G[e.to][e.rev].cap += d;
                    G[e.to][e.rev].flow -= d;//逆辺を考えた分,今流している量が減った.
                    return d;
                }
            }
        }
 
        return 0;
    }
 
 
    T max_flow(int s, int t){
        T flow=0;
        while(1){
            bfs(s);
            if(level[t]<0) return flow;
            iter = vector<T>(numV+1,0);//0に初期化

            T f;
            while((f=dfs(s,t,INF))>0 ){
                flow += f;
            }
        }
    }

    //auto edges = (FLOW instance).edges();で受けるしかないかな
    vector<edge> edges(){
        vector<edge> ret;
        for(int from=0;from<=numV;from++){
            for(const edge &e:G[from]){
                if( st.find(P(from,e.to))!=st.end() ){
                    ret.push_back(e);
                }
            }
        }
        return ret;
    }

};


 


//https://kaage.hatenablog.com/entry/2021/05/15/194407
#include <cfloat>
#include <climits>
#include <iostream>
#include <queue>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define REP(i, n) for (int i = 1; i <= int(n); i++)

using lint = long long;
using IP = std::pair<int, int>;

constexpr int INF = INT_MAX / 2;
constexpr lint LINF = LLONG_MAX / 2;

class Dinic {
    class edge {
      public:
        int to;
        lint cap;
        int rev, id;
    };
    int N, idx = 0;
    std::vector<std::vector<edge>> vec;
    std::vector<int> iter, level;
    bool bfs(int s, int t) {
        level.assign(N, -1);
        level[s] = 0;
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (const auto& i : vec[node]) {
                if (i.cap > 0 && level[i.to] == -1) {
                    level[i.to] = level[node] + 1;
                    que.push(i.to);
                }
            }
        }
        return level[t] != -1;
    }
    lint dfs(int node, int t, lint f) {
        if (node == t) return f;
        for (int& i = iter[node]; i < vec[node].size(); i++) {
            edge& e = vec[node][i];
            if (e.cap > 0 && level[node] < level[e.to]) {
                lint d = dfs(e.to, t, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    vec[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
  public:
    Dinic(int n) : N(n) {
        vec.resize(N);
        level.resize(N);
        iter.resize(N);
    }
    void add_edge(int from, int to, lint cap) {
        vec[from].push_back({to, cap, (int)vec[to].size(), -1});
        vec[to].push_back({from, 0, (int)vec[from].size() - 1, idx++});
    }
    lint max_flow(int s, int t) {
        lint res = 0;
        while (true) {
            bfs(s, t);
            if (level[t] < 0) return res;
            iter.assign(N, 0);
            lint f;
            while ((f = dfs(s, t, LINF)) > 0) res += f;
        }
    }
};

 