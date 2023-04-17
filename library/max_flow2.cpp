/*
ABC225をもとに作りました.
*/

//ABC247Gのコード
//ACコード
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cmath>
#include<functional>
#include<numeric>
#include<string>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> P;
//const ll INF=1LL<<60;
//const ll INF=1LL<<30;
const ll INF=1e12;

using namespace std;


template<class Cap,class Cost>
    class mincost_flow{

    private:

        struct edge{
            int from;
            int to;
            Cap cap;
            Cap flow;//どれだけ流したのか 一番最初は0
            Cost cost;//どれだけのコストがかかるか
            int rev;//逆辺

            edge(int from_,int to_,Cap cap_,Cap flow_,Cost cost_,int rev_):from(from_),to(to_),cap(cap_),flow(flow_),cost(cost_),rev(rev_){};
        };
        //typedef std::pair<int,int> P;

        std::set<pair<int,int>> fromto;//順辺のみ記録
        //頂点数がV 
        std::vector<Cost> h;
        std::vector<Cost> dist;
        std::vector<int> prevv;//prevv[v]はvの直前の頂点
        std::vector<int> preve;//preve[v]はvの直前の逆辺のindex
        std::vector<std::vector<edge>> G;

    public:
        int V;//頂点数
        



        //constructor
        mincost_flow(int v):V(v){
            G = std::vector<std::vector<edge>>(V,std::vector<edge>{});
            //このhはflow関数のwhile(f>0){}で使いまわされる
            h=std::vector<Cost>(V,0);//initialize h //potential h

        }


        void add_edge(int from,int to,Cap cap,Cost cost){
            //from, to, cap,flow,cost,rev
            G[from].emplace_back(from,   to,cap, 0,     cost,(int)G[to].size() );
            //逆辺の場合は一度流してしまうと考えてflowを考慮する
            G[to].emplace_back( to, from,  0, cap,-cost,(int)G[from].size()-1);     
           
            fromto.insert(std::make_pair(from,to));//順辺を記録しておく

        }

        std::vector<edge> edges(){
            std::vector<edge> ret;//vector instance edges
             //辺を入れていく.
            //ただし逆辺は入れない 順辺のみを入れる.
            for(int i=0;i<V;i++){
                for(edge &e:G[i]){
                    if(fromto.find(std::make_pair(e.from,e.to)) != fromto.end() ){
                        ret.push_back(e);
                    }
                }
            }

            return ret;
        }


    //流れた量fと最小コストres
    std::pair<Cap,Cost> flow(int start,int goal,Cap f){
        
        //f流すことを目的とする
        Cap maxflow=f;
       
        Cost mincost=0;
        //hをいちいち初期化しない


        while(f>0){

            std::priority_queue<std::pair<Cost,int>,vector<std::pair<Cost,int>>, greater<std::pair<Cost,int>>> que; 
            
            prevv = std::vector<int>(V,-1);
            preve = std::vector<int>(V,-1);
            dist = std::vector<Cost>(V,INF);
        
            dist[start]=0;
            que.push(std::make_pair(0,start));//頂点番号start 最短距離0

            while(!que.empty()){
                auto p= que.top(); que.pop();
                int v = p.second;
                
               
                if(dist[v]<p.first) continue;
                
              

                for(int i=0;i<(int)G[v].size();i++){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        que.push( std::make_pair(dist[e.to],e.to) );   
                    }
                }
            }

            
            que= decltype(que)();

            if(dist[goal]==INF){
                
                //maxflowすべてを流すことが無理
                
                //return make_pair(-1,mincost);
                
                //これでもOK
                //とりあえず,流すことができた量を答える
                return make_pair(maxflow-f,mincost);

            }

            for(int v=0;v<V;v++){
                h[v]+=dist[v];
            }

            Cap d = f;
            //goalから逆にたどっていく
            for(int v=goal;v!=start;v = prevv[v]){
                d = min(d,G[prevv[v]][preve[v]].cap);
            }

            f-=d;
            mincost += d*h[goal];
            for(int v=goal;v!=start;v=prevv[v]){
                edge &e = G[prevv[v]][preve[v]];//prevv[v]->preve[v]に流量dを流す.
                e.cap -= d;//辺eにdを追加で流す
                e.flow +=d;//辺eにdを追加で流す
                G[v][e.rev].cap += d;
                G[v][e.rev].flow -=d;
            }
        }

        
        //流れた量(maxflow-f)と最小コストminres
        
        return make_pair(maxflow-f,mincost);
    }


};

int main(){
    int N;
    cin>>N;

    //mincost_flow<ll> graph(150+150+10);
    mincost_flow<int,ll> graph(150+150+10);

    //1~150が大学
    // 151~300が得意分野
    vector<int> A(N),B(N);
    vector<ll> C(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i]>>C[i];
        //void add_edge(int from,int to,Type cap,Type cost){
        graph.add_edge(A[i],150+B[i],1,INF-C[i]);
    }
    int source=0, sink= 301;
    //
    for(int univ=1;univ<=150;univ++){
        graph.add_edge(source,univ,1,0);
    }

    for(int sp=1;sp<=150;sp++){
        graph.add_edge(150+sp,sink,1,0);
    }


    vector<ll> ans;
   
    ll res=0;
    for(int k=1;k<=150;k++){
        //流量1ずつ増やすことを流すことを考える
        auto [maxflow,mincost]=graph.flow(source,sink,1);
        res+=mincost;
        if(maxflow<1){
            break;
        }
        
        ans.push_back(INF*k-res);
    }

    cout<<ans.size()<<endl;
    for(ll v:ans){
        cout<<v<<endl;
    }

}