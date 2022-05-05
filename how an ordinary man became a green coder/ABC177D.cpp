/*
AC

UFがポイント
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
using namespace std;


class UnionFind{

public:
    vector<int> par;
    vector<int> rank;

/*
    UnionFind(int size){
        rank=vector<int>(size+1,0);
        
        for(int i=0;i<=size;i++){
            par.push_back(i);
        }
    }  
*/
    UnionFind(int size){
        rank=vector<int>(size+1,0);
        
        par = vector<int>(size+1,0);
        iota(par.begin(),par.end(),0);//#include<numeric>
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

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> A(M),B(M);
    UnionFind uf(N);

    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;//0からに補正
        uf.merge(A[i],B[i]);
    } 
    
    map<int,vector<int>> mp;

    for(int i=0;i<N;i++){
        mp[uf.find(i)].push_back(i);
    }

    int ans=0;
    for(auto [id,vec]:mp){
        ans = max(ans,(int)vec.size());//人数が一番多いところに依存する
    }
    cout<<ans<<endl;

}