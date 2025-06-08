#include <iostream>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<numeric>
#include<queue>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<ll,P> PP;
const ll MOD=998244353;



template <class T>
class PotentialUnionFind{

public:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> sz;//sz[i]で,頂点iが含まれているグループのサイズ
    std::vector<int> root;
    std::vector<T> diff_weight;

    PotentialUnionFind(int size){
        rank=std::vector<int>(size+1,0);
        
        par = std::vector<int>(size+1,0);
        std::iota(par.begin(),par.end(),0);//#include<numeric>
        sz = std::vector<int>(size+1,1);
        root=std::vector<int>(size+1);
        diff_weight=std::vector<T>(size+1,0);

        std::iota(root.begin(),root.end(),0);
    }  

    

    ~PotentialUnionFind(){
        std::vector<int>().swap(rank);
        std::vector<int>().swap(par);
        std::vector<int>().swap(sz);
        std::vector<int>().swap(root);
        std::vector<T>().swap(diff_weight);
       
    }  

    std::pair<int,T> find(int x){
        if(par[x]==x)return {x,0};
        else{
            auto [p,val]=find(par[x]);
            par[x]=p;

            //par[x] = find(par[x],d+diff_weight[x]);
            diff_weight[x]+=val;
            //帰り値で子に伝播させる
            return {par[x],diff_weight[x]};
        
        }
    }

    //同じ連結成分にあるかどうか
    bool issame(int u,int v){
        return find(u).first==find(v).first;
        
    }

    T weight(int v){
        find(v);
        return diff_weight[v];
    }

    //X[v]-X[u]の値を返す
    // rootからX[v] の値と　rootからX[u]の値 
    T diff(int u,int v){
     
        return weight(v)  - weight(u);
    }

    //X[v]-X[u]=weight
    //->X[v]=X[u]+w
    void merge(int u,int v,ll w){

        w+=weight(u);//ここ重要
        w-=weight(v);

        u = find(u).first;
        v = find(v).first;
        if(u==v) return;

        if(this->size(u) < this->size(v)){
            std::swap(u,v);
            w*=(-1);
        }
    
        //uの傘下へvが入る    
        //rank[u]>=rank[v]
        par[v]=u;
        sz[u]+=sz[v];


        //->X[v]=X[u]+weightより
        //親ノードよりも自分のほうがweight多い
        diff_weight[v]+=w;//uが親vが子
        if(rank[u]==rank[v])rank[u]++;

    }
    

    int size(int u){//頂点uが属すグループの大きさを表す.
        u=find(u).first;
        return sz[u];
    }

    std::map<int,std::vector<int>> element(){
        std::map<int,std::vector<int>> mp;
        for(int i=0;i<par.size();i++){
            root[i]=find(i);
            mp[root[i]].push_back(i);
        }
        return mp;

    }
};




