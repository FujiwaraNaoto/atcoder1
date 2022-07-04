#include<iostream>
#include<map>
#include<numeric>
#include<vector>

class UnionFind{

public:
    vector<int> par;
    vector<int> rank;

    UnionFind(int size){
        rank=vector<int>(size+1,0);
        
        par = vector<int>(size+1,0);
        iota(par.begin(),par.end(),0);//#include<numeric>
    }  

    

    ~UnionFind(){
        vector<int>().swap(rank);
        vector<int>().swap(par);
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
        
        if(rank[u]>rank[v]) par[v]=u;
        else{
            par[u]=v;
            if(rank[u]==rank[v]) rank[v]++;
        }
    }


};


//ABC238
//https://atcoder.jp/contests/abc238/editorial/3360
//union_find_tree
struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};




