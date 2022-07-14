/*
ABC225
*/
#include<iostream>
#include<vector>
#include<queue>
//using namespace std;
typedef long long ll;
const ll INF=1LL<<59;

//ABC205 grid and tokens
template<class T> //intになるかllになるか
class FLOW{
    public:
    struct edge{int from; int to;  T cap; int rev;};    
    std::vector<T> level;
    std::vector<T> iter;
   
    std::vector<std::vector<edge> > G{};//vector

    int numV=0;

    //constructor
    FLOW(int v_):numV(v_){
        
        G.resize(V+1);//G[0],G[1],...,G[V]を作る
        level = vector<T>(numV+1,0);
        iter  = vector<T>(numV+1,0);
    }
    
    ~FLOW(){
        std::vector<T>().swap(level);
        std::vector<T>().swap(iter);
        
    }

    void add_edge(int from,int to,T cap){
        G[from].push_back((edge){from,to,cap,(int)G[to].size()} );
        G[to].push_back((edge){to,from,0,(int)G[from].size()-1});
    }
 
 
    void bfs(int s){
        //memset(level,-1,sizeof(level));
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
        for(T &i=iter[v]; i<(T)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap>0 && level[v]<level[e.to]){
                T d = dfs(e.to, t, min(f,e.cap));
                if(d>0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
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
            //memset(iter,0,sizeof(iter));
            iter = vector<T>(numV+1,0);//0に初期化

            T f;
            while((f=dfs(s,t,INF))>0 ){
                flow += f;
            }
        }
    }


    std::vector<edge> edges(){
        std::vector<edge> ret;
        for(int i=0;i<=numV;i++){
            for(auto e: G[i]){//二部グラフの場合cap==0の時にその経路を通ったということ
                ret.push_back(e);
            }
        }
        return ret;
    }
    
};


int main(){
    int H,W,C;
    cin >> H >> W >> C;
    FLOW<ll> graph(H*W+2);

    vector<vector<int> > A(H,vector<int>(W));
    /*
    rep(i,0,H){
        rep(j,0,W) cin >> A[i][j];
    }
    */
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];
        }
    }
    
    
    
    int sz = H*W;
    /*
    rep(i,0,H){
        rep(j,0,W){
            int now = i*W+j;
            graph.add_edge(sz,now,A[i][j]);
        }
    }
    */
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int now = i*W+j;
            graph.add_edge(sz,now,A[i][j]);
        }
    }
    /*
    rep(i,0,H){
        rep(j,0,W){
            int now = i*W+j;
            if(0 < i && 0 < j){
                int next = (i-1)*W+(j-1);
                graph.add_edge(now,sz+1,0);
                graph.add_edge(now,next,C);
            }
            else{
                graph.add_edge(now,sz+1,C);
            }
        }
    }
    */
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int now = i*W+j;
            if(0 < i && 0 < j){
                int next = (i-1)*W+(j-1);
                graph.add_edge(now,sz+1,0);
                graph.add_edge(now,next,C);
            }
            else{
                graph.add_edge(now,sz+1,C);
            }
        }
    }


    /*
    rep(i,0,H){
        rep(j,0,W){
            int now = i*W+j;
            if(0 < i && j+1 < W){
                int next = (i-1)*W+(j+1);
                graph.add_edge(now,sz+1,0);
                graph.add_edge(now,next,C);
            }
            else{
                graph.add_edge(now,sz+1,C);
            }
        }
    }
    */
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int now = i*W+j;
            if(0 < i && j+1 < W){
                int next = (i-1)*W+(j+1);
                graph.add_edge(now,sz+1,0);
                graph.add_edge(now,next,C);
            }
            else{
                graph.add_edge(now,sz+1,C);
            }
        }
    }


    ll ans = 0;
    /*
    rep(i,0,H){
        rep(j,0,W) ans += A[i][j];
    }
    */
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans += A[i][j];
        }
    }


    ans -= graph.max_flow(sz,sz+1);
    cout << ans << endl;
}