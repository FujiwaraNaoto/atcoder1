/*
最小コストの流量を調べる
*/
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;

const ll INF;

class min_cost_flow{

    private:

        struct edge{
            int from;
            int to;
            ll cap;
            ll flow;//どれだけ流したのか 一番最初は0
            ll cost;//どれだけのコストがかかるか
            int rev;//逆辺
        };
        typedef pair<int,int> P;

        set<P> fromto;//順辺のみ記録
        //頂点数がV 
        vector<ll> h;
        vector<ll> dist;
        vector<int> prevv;//prevv[v]はvの直前の頂点
        vector<int> preve;//preve[v]はvの直前の逆辺のindex
        vector<vector<edge>> G;

    public:
        int V;//頂点数
        



        //constructor
        min_cost_flow(int v):V(v){
            G = vector<vector<edge>>(V,vector<edge>{});
            prevv = vector<int>(V,-1);
            preve = vector<int>(V,-1);
            h=vector<ll>(V,0);//initialize h //potential h
        }


        void add_edge(int from,int to,int cap,ll cost){
            //from, to, cap,flow,cost,rev
            G[from].push_back( (edge){from,   to,cap, 0LL,     cost,(int)G[to].size()} );
            //逆辺の場合は一度流してしまうと考えてflowを考慮する
            G[to].push_back(   (edge){  to, from,  0, 1LL*cap,-cost,(int)G[from].size()-1});        
            fromto.insert(P(from,to));//順辺を記録しておく

        }

        vector<edge> edges(){
            vector<edge> ret;//vector instance edges
             //辺を入れていく.
            //ただし逆辺は入れない 順辺のみを入れる.
            for(int i=0;i<V;i++){
                for(edge &e:G[i]){
                    if(fromto.find(P(e.from,e.to)) != fromto.end() ){
                        ret.push_back(e);
                    }
                }
            }

            return ret;
        }



    ll flow(int start,int goal,ll f){
    

        //流す量がf
        ll res=0;

        while(f>0){

            priority_queue<P,vector<P>, greater<P>> que; 

            dist = vector<ll>(V,INF);
            dist[start]=0;
            que.push(P(0,start));//頂点番号start 最短距離0

            while(!que.empty()){
                P p= que.top(); que.pop();
                int v = p.second;
                
                if(dist[v]<p.first) continue;

                for(int i=0;i<(int)G[v].size();i++){
                //for(edge &e: G[v]){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        que.push( P(dist[e.to],e.to) );   
                    }
                }
            }

            if(dist[goal]==INF){
                return -1;
            }

            for(int v=0;v<V;v++){
                h[v]+=dist[v];
            }

            ll d = f;
            //goalから逆にたどっていく
            for(int v=goal;v!=start;v = prevv[v]){
                d = min(d,G[prevv[v]][preve[v]].cap);
            }

            f-=d;
            res += d*h[goal];
            for(int v=goal;v!=start;v=prevv[v]){
                edge &e = G[prevv[v]][preve[v]];//prevv[v]->preve[v]に流量dを流す.
                e.cap -= d;
                e.flow +=d;//辺eにdを追加で流す
                G[v][e.rev].cap += d;
                G[v][e.rev].flow -=d;
            }
        }
        return res;
    }


};