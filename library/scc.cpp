
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
後の頂点であればあるほど,強連結成分の番号が小さい
*/

class SCC{

    //後の頂点であればあるほど,強連結成分の番号が小さい
    private:
        //SCC
        int V,M;//頂点と辺数
        vector<vector<int>> G,rG;
        vector<bool> used;
        vector<int> cmp;
        vector<int> vs;
        vector<vector<int>> group;


        void dfs(int v){
            used[v]=true;
            for(int to:G[v]){

                if(!used[to]){
                    dfs(to);
                }
            }
            vs.push_back(v);

        }

        void rdfs(int v,int k){
            used[v]=true;
            cmp[v]=k;
            //group[k].push_back(v);
            for(int to:rG[v]){
                if(!used[to]){
                    rdfs(to,k);
                }
            }
        }

    public:

        //constructor
        //頂点数0~nのNこ
        //辺数 m個
        SCC(int v,int m):V(v),M(m){
            G = vector<vector<int>>(V,vector<int>{});
            rG = vector<vector<int>>(V,vector<int>{});
            cmp = vector<int>(V,0);//グループ
        }

        SCC(int v):V(v){
            G = vector<vector<int>>(V,vector<int>{});
            rG = vector<vector<int>>(V,vector<int>{});
            cmp = vector<int>(V,0);//グループ
        }

        void add_edge(int from,int to){
            G[from].push_back(to);
            rG[to].push_back(from);
        }

        vector<vector<int>> sccgroup;//scc[k]でグループkに属している頂点たち

        int scc(){
            
            used = vector<bool>(V,false);

            vs.clear();
            for(int v=0;v<V;v++){
                if(!used[v]) dfs(v);
            }
            used = vector<bool>(V,false);
            int k=0;
            
            reverse(vs.begin(),vs.end());
        
        
            for(int to:vs){
                if(!used[to]) rdfs(to,k++);//rdfsが終わった後でインクリメント
            }

            sccgroup = vector<vector<int>>(k,vector<int>{});
            for(int v=0;v<V;v++){//全ての頂点を一つずつみていく
                //頂点v
                sccgroup[cmp[v]].push_back(v);//
            }
            return k;
        }

};