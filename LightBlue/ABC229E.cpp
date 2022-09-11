#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
#include<numeric>
typedef long long ll;
using namespace std;
const ll MOD=998244353;

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

    int size(int u){//頂点uが属すグループの大きさを表す.
        u=find(u);
        return sz[u];
    }
};



int main(){
    int N,M;
    cin>>N>>M;
    vector<int> A(M),B(M);
    vector<vector<int>> edge(N,vector<int>{});
    for(int i=0;i<M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        if(A[i]>B[i]){
            swap(A[i],B[i]);
        }
        //A[i]<B[i]になるようにしている
        edge[A[i]].push_back(B[i]);
    }

    UnionFind uf(N);
    vector<int> ans;
    int cnt=0;
    ans.push_back(cnt);

    //頂点 N-1から追加していくことを考える
    for(int v=N-1;v>=0;v--){

       cnt++;//頂点を新しく追加

        if(!edge[v].empty()){
            for(int to:edge[v]){
                if(!uf.issame(to,v)){
                    //toとvが同じ連結成分でない
                    cnt--;//つなげることで連結成分がへる
                }else{
                    //すでに同じ連結成分
                    // do nothing
                }

                uf.merge(to,v);//toとvをつなぐ
                
            }
        }
        if(v!=0){
        ans.push_back(cnt);
        }
    }

    reverse(ans.begin(),ans.end());
    for(int x:ans){
        cout<<x<<endl;
    }





}