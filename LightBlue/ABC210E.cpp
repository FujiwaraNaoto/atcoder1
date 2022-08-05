/*
AC
Kruscalのアルゴリズムの高速化をおこなう
UnionFindはもちいない.
*/
#include<iostream>
#include<map>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

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

    int size(int u){
        u=find(u);
        return sz[u];
    }
};

ll gcd(ll x,ll y){
    if(y==0)return x;
    else return gcd(y,x%y);
}


int main(){
    ll N;
    int M;
    cin>>N>>M;
    vector<ll> C(M),A(M);

    vector<P> edges;
    for(int i=0;i<M;i++){
        cin>>A[i]>>C[i];
        edges.emplace_back(C[i],A[i]);
    }

    sort(edges.begin(),edges.end());
    //N<10^5 とかなら O(NlogN)でおとせるけどね

    ll cur=N;

    ll ans=0;
    for(auto [c,a]:edges){
        ll tmp=gcd(cur,a);
        
        ans+=1LL*c*(cur-tmp);

        cur=tmp;
        //if(tmp==1LL) break;
    }

    if(cur!=1LL){
        ans=-1;
    }

    cout<<ans<<endl;
}