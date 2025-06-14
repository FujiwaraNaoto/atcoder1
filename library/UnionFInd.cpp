#include<iostream>
#include<map>
#include<numeric>
#include<vector>

class UnionFind{

public:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> sz;//sz[i]で,頂点iが含まれているグループのサイズ
    std::vector<int> root;

    UnionFind(int size){
        rank=std::vector<int>(size+1,0);
        
        par = std::vector<int>(size+1,0);
        std::iota(par.begin(),par.end(),0);//#include<numeric>
        sz = std::vector<int>(size+1,1);
        root=std::vector<int>(size+1);
        std::iota(root.begin(),root.end(),0);
    }  

    

    ~UnionFind(){
        std::vector<int>().swap(rank);
        std::vector<int>().swap(par);
        std::vector<int>().swap(sz);
        std::vector<int>().swap(root);
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

       
        if(rank[u]<rank[v]) std::swap(u,v);
        //uの傘下へvが入る
        
        //rank[u]>=rank[v]
        par[v]=u;
        sz[u]+=sz[v];
        if(rank[u]==rank[v])rank[u]++;

    }
    

    int size(int u){//頂点uが属すグループの大きさを表す.
        u=find(u);
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




class UnionFind{
    //マージテクを用いたUnionFind

public:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> sz;//sz[i]で,頂点iが含まれているグループのサイズ
    std::vector<int> root;

    UnionFind(int size){
        rank=std::vector<int>(size+1,0);
        
        par = std::vector<int>(size+1,0);
        std::iota(par.begin(),par.end(),0);//#include<numeric>
        sz = std::vector<int>(size+1,1);
        root=std::vector<int>(size+1);
        std::iota(root.begin(),root.end(),0);
    }  

    

    ~UnionFind(){
        std::vector<int>().swap(rank);
        std::vector<int>().swap(par);
        std::vector<int>().swap(sz);
        std::vector<int>().swap(root);
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

        if(this->size(u)<this->size(v)){
            std::swap(u,v);
        }
        //size(ua)>=size(ub)
        //uの傘下へvが入る
        par[v]=u;
        sz[u]+=sz[v];
        if(rank[u]==rank[v])rank[u]++;

    }
    

    int size(int u){//頂点uが属すグループの大きさを表す.
        u=find(u);
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
