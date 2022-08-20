/*
ドーナツにならないかどうかにUFを用いる.

6*6として,　真ん中の4*4をもちいる

AC
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
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
    int a=0,na;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>na;
            a |= na<<(i*4+j); 
        }
    }

    int ans=0;
    for(int S=0;S<(1<<16);S++){//Sのbitが立っている場所がお濠の中
        if((S&a) == a){//家の場所とお濠の内側が一致する場合

            //Sが連結になっているか
            UnionFind uf(6*6);
            vector<vector<int>> x(6,vector<int>(6,0));
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(S>>(i*4+j)&1){
                        x[i+1][j+1]=1;
                    }
                }
            }


            for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                   
                    if(i+1<6 && x[i][j]==x[i+1][j]) uf.merge(i*6+j,(i+1)*6+j);
                    if(j+1<6 && x[i][j]==x[i][j+1]) uf.merge(i*6+j,i*6+(j+1));

                }
            }

            int cnt=0;
            for(int i=0;i<6*6;i++){
                if(uf.find(i)==i)cnt++;
                
            }
            if(cnt==2) ans++;

        }
    }
    cout<<ans<<endl;

}