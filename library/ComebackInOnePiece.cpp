/*
競プロ典型 021
*/
#include<iostream>
#include<vector>
#include<algorithm>


class SCC{

    //後の頂点であればあるほど,強連結成分の番号が小さい
    private:
        //SCC
        int V,M;//頂点と辺数
        std::vector<std::vector<int>> G,rG;
        std::vector<bool> used;
        std::vector<int> cmp;
        std::vector<int> vs;
        std::vector<std::vector<int>> group;


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
            G = std::vector<std::vector<int>>(V,std::vector<int>{});
            rG = std::vector<std::vector<int>>(V,std::vector<int>{});
            cmp = std::vector<int>(V,0);//グループ
        }

        SCC(int v):V(v){
            G = std::vector<std::vector<int>>(V,std::vector<int>{});
            rG = std::vector<std::vector<int>>(V,std::vector<int>{});
            cmp = std::vector<int>(V,0);//グループ
        }

        ~SCC(){
            
            std::vector<std::vector<int>>().swap(G);
            std::vector<std::vector<int>>().swap(rG);
            std::vector<int>().swap(cmp);
        }

        void add_edge(int from,int to){
            G[from].push_back(to);
            rG[to].push_back(from);
        }

        std::vector<std::vector<int>> sccgroup;//scc[k]でグループkに属している頂点たち

        int scc(){
            
            used = std::vector<bool>(V,false);

            vs.clear();
            for(int v=0;v<V;v++){
                if(!used[v]) dfs(v);
            }
            std::vector<bool>().swap(used);
            used = std::vector<bool>(V,false);
            int k=0;
            
            reverse(vs.begin(),vs.end());
        
        
            for(int to:vs){
                if(!used[to]) rdfs(to,k++);//rdfsが終わった後でインクリメント
            }

            sccgroup = std::vector<std::vector<int>>(k,std::vector<int>{});
            for(int v=0;v<V;v++){//全ての頂点を一つずつみていく
                //頂点v
                sccgroup[cmp[v]].push_back(v);//
            }
            std::vector<bool>().swap(used);

            return k;
        }

};




/*
//継承を用いたパターン
class SCC{

    public:
    
        //SCC
        int V,M;//頂点と辺数
        std::vector<std::vector<int>> G,rG;
        std::vector<bool> used;
        std::vector<int> cmp;
        std::vector<int> vs;
        std::vector<std::vector<int>> group;


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
            cmp[v]=k;//のちのクラスでcmpを仕様するので
            //group[k].push_back(v);
            for(int to:rG[v]){
                if(!used[to]){
                    rdfs(to,k);
                }
            }
        }

    //public:
        //constructor
        //頂点数0~nのNこ
        //辺数 m個
        SCC(int v,int m):V(v),M(m){
            G = std::vector<std::vector<int>>(V,std::vector<int>{});
            rG = std::vector<std::vector<int>>(V,std::vector<int>{});
            cmp = std::vector<int>(V,0);//グループ
        }

        SCC(int v):V(v){
            G = std::vector<std::vector<int>>(V,std::vector<int>{});
            rG = std::vector<std::vector<int>>(V,std::vector<int>{});
            cmp = std::vector<int>(V,0);//グループ
        }



        void add_edge(int from,int to){
            G[from].push_back(to);
            rG[to].push_back(from);
        }

        std::vector<std::vector<int>> sccgroup;//scc[k]でグループkに属している頂点たち

        int scc(){
            
            used = std::vector<bool>(V,false);

            vs.clear();
            for(int v=0;v<V;v++){
                if(!used[v]) dfs(v);
            }
            used = std::vector<bool>(V,false);
            int k=0;
            
            reverse(vs.begin(),vs.end());
        
        
            for(int to:vs){
                if(!used[to]) rdfs(to,k++);//rdfsが終わった後でインクリメント
            }

            sccgroup = std::vector<std::vector<int>>(k,std::vector<int>{});
            for(int v=0;v<V;v++){//全ての頂点を一つずつみていく
                //頂点v
                sccgroup[cmp[v]].push_back(v);//
            }
            return k;
        }

};
*/
/*
まず基本クラスのコンストラクタ 次に 派生クラスのコンストラクタ
*/

/*
//protected派生
//SCCでのpublicはこちらではprotectedになる
class TwoSAT: protected SCC{
    
    public:
        
        int N;//見掛け状の頂点数 SCCではこの2倍の数の頂点がある

        TwoSAT(int v_):SCC(2*v_),N(v_){
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

        std::vector<bool> whichtrue(){

            std::vector<bool> ret(N);
            
            for(int i=0;i<N;i++){
                ret[i]=cmp[i]>cmp[N+i];
                
            }
            return ret;
        }

    //using SCC::add_edge;//権限をprotectedに移行
    //using SCC::scc;
};
*/




using namespace std;
typedef long long ll;

int main(){
    int N;
    int M;
    cin>>N>>M;
    vector<int> A(M),B(M);

    SCC scc(N,M);//頂点数
    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        scc.add_edge(A[i],B[i]);//A[i]からB[i]へ辺を張る    
    }

    int num_group = scc.scc();//できるグループ数
    //cout<<"num_group="<<num_group<<endl;
    
    ll ans=0;
    for(int idx=0;idx<num_group;idx++){
        int n = scc.sccgroup[idx].size();
        ans+=1LL*n*(n-1)/2;
    }
    cout<<ans<<endl;



}