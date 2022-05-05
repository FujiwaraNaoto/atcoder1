#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//継承を用いたパターン
class SCC{

    public:
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
/*
まず基本クラスのコンストラクタ 次に 派生クラスのコンストラクタ
*/

//本当はpublicでは良くないかもしれない
class TwoSAT: public SCC{
    
    public:
        
        int N;//見掛け状の頂点数 SCCではこの2倍の数の頂点がある

        TwoSAT(int v):SCC(2*v),N(v){
            //2倍の数の頂点が必要
            //SCC scc(2*v);
            //constructor 
            //N=v;   
        }


        bool istrue(){
            //全体が真になるかどうか
            for(int i=0;i<N;i++){
                if(cmp[i]==cmp[N+i]){
                    return false;
                }
            }
            return true;
        }

        vector<bool> whichtrue(){

            vector<bool> ret(N);
            
            for(int i=0;i<N;i++){
                ret[i]=cmp[i]>cmp[N+i];
                
            }
            return ret;
        }
};





//委譲を用いたパターン
//強連結成分分解
class SCC{

    public:
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
/*
まず基本クラスのコンストラクタ 次に 派生クラスのコンストラクタ
*/

//本当はpublicでは良くないかもしれない
class TwoSAT{
    
    public:
        
        int N;//見掛け状の頂点数 SCCではこの2倍の数の頂点がある
        SCC& sc;

        TwoSAT(SCC& sc):sc(sc){
            //instanceを引き継ぐ
            
            //2倍の数の頂点が必要
            //constructor 
            N=sc.V/2; 

        }


        void add_edge(int from,int to){
            sc.add_edge(from,to);
        }

        int scc(){
            return sc.scc();
        }

        bool istrue(){
            //全体が真になるかどうか
            for(int i=0;i<N;i++){
                if(sc.cmp[i]==sc.cmp[N+i]){
                    return false;
                }
            }
            return true;
        }

        vector<bool> whichtrue(){

            vector<bool> ret(N);
            
            for(int i=0;i<N;i++){

                ret[i] = sc.cmp[i]>sc.cmp[N+i];
                /*
                if(sc.cmp[i]>sc.cmp[N+i]){
                    ret[i]=true;
                }else{
                    ret[i]=false;
                } 
                */
            }
            return ret;
        }

};




