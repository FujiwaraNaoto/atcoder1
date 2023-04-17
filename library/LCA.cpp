//最近共通祖先
/*
https://atcoder.jp/contests/typical90/tasks/typical90_ai
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;


class LCA{

    public:
        int N;//頂点数
        
        vector<vector<int>> G;
        vector<int> depth;//rootから頂点への深さ
        vector<vector<int>> par;
        vector<int> order;//深さ優先探索の際に訪れた順番

        LCA(int n):N(n){//constructor
            G=vector<vector<int>>(N,vector<int>{});
            depth = vector<int>(N);
            bits=0;

            while( (1<<bits) < N ) bits++;
            
            par =vector<vector<int>>(bits,vector<int>(N));

            id=0;
            order = vector<int>(N);

        }

        void add_edge(int u,int v){
            G[u].push_back(v);
            G[v].push_back(u);
        }

        void build_tree(int root){//実際に呼び出すのはこちら
            //深さ優先探索で行う
            depth[root]=0;
            build_tree(root,root);

            doubling();
        }
        
        
        //vaとvbの共通祖先
        int lca(int va,int vb){

            if(depth[va]<depth[vb]) swap(va,vb);
            //depth[va] >= depth[vb] となるようにする

            for(int k=bits-1;k>=0;k--){
                if( (depth[va]-depth[vb])>=(1<<k) ){
                    va = par[k][va];
                }
            }

            if(va==vb) return va;

            for(int k=bits-1;k>=0;k--){
                if(par[k][va]!=par[k][vb]){
                    va = par[k][va];
                    vb = par[k][vb];
                }
            }

            return par[0][va];//共通の祖先
        };

       
        int distance(const int &va, const int &vb){
            return depth[va]+depth[vb] - 2*depth[ lca(va,vb) ];
        }


    private:

        int bits;
        int id;
        void build_tree(int pos,int pre){    
            order[pos]=id++;
            par[0][pos]=pre;
            for(int to:G[pos]){
                if(to==pre) continue;
                //nowの一つ前がto
                
                depth[to]=depth[pos]+1;
                build_tree(to,pos);
            }
        }

        void doubling(){
            for(int k=1;k<bits;k++){
                for(int j=0;j<N;j++){
                    par[k][j] = par[k-1][par[k-1][j]];
                }
            }
        }


};




class LCA{

public:

    
    int V;//頂点のサイズ
    std::vector<std::vector<int>> G;

    std::vector<int> depth;
    std::vector<std::vector<int>> parent;

    int rootV=-1;

    int MAX_LOGV;

    LCA(const std::vector<std::vector<int>>& graph_,int maxlogv=31):G(graph_),MAX_LOGV(maxlogv){
        V=G.size();
        depth=std::vector<int>(V,0);
        parent=std::vector<std::vector<int>>(MAX_LOGV,std::vector<int>(V,-1));
    }


    void dfs(int now,int pre,int d){
        parent[0][now]=pre;
        depth[now]=d;
        for(int to:G[now]){
            if(to!=pre) dfs(to,now,d+1);
        }
    }

    void initLCA(){
        initLCA(0);
    }

    void initLCA(int root_){
        rootV=root_;
        dfs(rootV,-1,0);
        for(int k=0;k+1<30;k++){
            for(int v=0;v<V;v++){
                if(parent[k][v]<0) parent[k+1][v]=-1;
                else parent[k+1][v]=parent[k][parent[k][v]];
            }
        }        
        return;
    }
   


    int operator()(int u,int v){
        return lca(u,v);
    }

    int lca(int u,int v){
        if(depth[u]>depth[v]) swap(u,v);

        for(int k=0;k<30;k++){
            if((depth[v]-depth[u])>>k &1 ){
                v=parent[k][v];
            }
        }

        if(u==v) return u;

        for(int k=30-1;k>=0;k--){
            if(parent[k][u]!=parent[k][v]){
                u=parent[k][u];
                v=parent[k][v];
            }
        }
        return parent[0][u];

    }



};