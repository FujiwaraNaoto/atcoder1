/*
AC
ソートとUnionFindがポイント
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;


class UnionFind{

public:
    std::vector<int> par;
    std::vector<int> rank;

    UnionFind(int size){
        rank=std::vector<int>(size+1,0);
        
        par = std::vector<int>(size+1,0);
        iota(par.begin(),par.end(),0);//#include<numeric>
    }  

    

    ~UnionFind(){
        std::vector<int>().swap(rank);
        std::vector<int>().swap(par);
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
    int N;
    cin>>N;
    vector<ll>x(N),y(N);
    vector<pair<ll,int>> px(N),py(N);
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
        px[i]=make_pair(x[i],i);
        py[i]=make_pair(y[i],i);
    }
    sort(px.begin(),px.end());//xでソート
    sort(py.begin(),py.end());//yでソート

    vector<pair<ll,ll>> con;
    for(int i=0;i+1<N;i++){
        con.emplace_back( 1LL*abs(px[i].first-px[i+1].first), 1LL*px[i].second*N+px[i+1].second);
        con.emplace_back( 1LL*abs(py[i].first-py[i+1].first), 1LL*py[i].second*N+py[i+1].second);
    }

    sort(con.begin(),con.end());

    UnionFind uf(N);
    ll ans=0;
    for(auto [dis,p]:con){
        int i=p/N;
        int j=p%N;

        if(!uf.issame(i,j)){
            ans+=dis;
            uf.merge(i,j);
        }
    }

    cout<<ans<<endl;

}


