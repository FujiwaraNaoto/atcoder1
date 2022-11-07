/*
4方向で別々のグループを使用.
模範解答みたいにしても良い.
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<numeric>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<ll,ll> P;
typedef pair<int,P> PP;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};



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
    
    int H,W;
    cin>>H>>W;
    vector<vector<char>> C(H,vector<char>(W));
    string input;
    P start;
    for(int y=0;y<H;y++){
        cin>>input;
        for(int x=0;x<W;x++){
            C[y][x]=input[x];
            if(C[y][x]=='S'){
                start=P{y,x};
            }
        }
    }

    auto id=[&](int y,int x){
        return y*W+x;
    };

    auto revId = [&](int nowxy){
        return make_pair(nowxy/W,nowxy%W);
    };

    //vector<vector<bool>>

    UnionFind uf(H*W+4);
    queue<P> que;

    for(int k=0;k<4;k++){
        int nx=start.second+dx[k];
        int ny=start.first+dy[k];
        if(nx<0 || W<=nx || ny<0 || H<=ny) continue;
        if(C[ny][nx]=='#')continue;

        que.push(P{id(ny,nx),H*W+k});
    }

    int base=H*W;
    while(!que.empty()){

        auto [nowxy,groupId]=que.front();
        que.pop();
        if(uf.issame(nowxy,groupId))continue;

        uf.merge(nowxy,groupId);
        auto [nowy,nowx]=revId(nowxy);//今の場所

        for(int k=0;k<4;k++){
            int nx=nowx+dx[k];
            int ny=nowy+dy[k];
            if(nx<0 || W<=nx || ny<0 || H<=ny) continue;
            if(C[ny][nx]=='#') continue;
            
            if(C[ny][nx]=='.' &&  !uf.issame(id(ny,nx),groupId)){
                que.push(P{id(ny,nx),groupId});
            }
        }
    }

    vector<int> StartGoal;

    for(int k=0;k<4;k++){
        int nx=start.second+dx[k];
        int ny=start.first+dy[k];
        if(nx<0 || W<=nx || ny<0 || H<=ny) continue;
        if(C[ny][nx]=='#')continue;

        StartGoal.push_back(id(ny,nx));
    }

    bool ans=false;
    for(int other:StartGoal){
        for(int theOther:StartGoal){
            if(other==theOther) continue;
            ans |= uf.issame(other,theOther);

        }
    }

    cout<<(ans?"Yes":"No")<<endl;

    
}