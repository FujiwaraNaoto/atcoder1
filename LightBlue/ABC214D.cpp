/*
AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

class UnionFind{

public:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> sz;//sz[i]で,頂点iが含まれているグループのサイズ

    UnionFind(int size){
        rank=std::vector<int>(size+1,0);
        
        par = std::vector<int>(size+1,0);
        iota(par.begin(),par.end(),0);//#include<numeric>
        sz = std::vector<int>(size+1,1);
    }  

    

    ~UnionFind(){
        std::vector<int>().swap(rank);
        std::vector<int>().swap(par);
        std::vector<int>().swap(sz);
    }  


    int find(int x){
        if(par[x]==x)return x;
        else return par[x] = find(par[x]);
    }

    bool issame(int u,int v){
        return find(u)==find(v);
    }


    void merge(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        
        if(rank[u]>rank[v]){
            par[v]=u;
            //uの傘下へvが入る
            sz[u]+=sz[v];
        }else{
            par[u]=v;
            //vの傘下へuが入る
            sz[v]+=sz[u];
            if(rank[u]==rank[v]) rank[v]++;

        }
    }

    int size(int u){
        u=find(u);
        return sz[u];
    }

};


vector<vector<P>> G;


int main(){
    int N;
    cin>>N;
    
    G=vector<vector<P>>(N,vector<P>{});

    vector<PP> weight;
    int u,v,w;
    for(int i=0;i<N-1;i++){
        cin>>u>>v>>w;
        u--;v--;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
        weight.emplace_back(w,P{u,v});
    }

    sort(weight.begin(),weight.end());

    UnionFind uf(N);
    ll ans=0;
    for(auto [w,p]:weight){
        
        auto [u,v]=p;
        ans+=1LL*w*uf.size(u)*uf.size(v);
        uf.merge(u,v);
    }
    cout<<ans<<endl;


}