/*
工夫
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<ll> dist;
vector<int> cnt;//部下に何人いるか
vector<ll> ans;
int N;

//根からnowまでの距離がdis
ll dfs(int now,int pre,int dis){

    ll ret=0;
    for(int to:G[now]){
        if(to==pre) continue;

        ret+=dfs(to,now,dis+1);
    }
    ret+=dis;
    dist[now]=dis;//根からnowまでの距離
    return ret;
}

//根からカウントしたときに, 自分を含めて自分の部下に何人いるか
void cntdfs(int now,int pre){
    
    int ret=0;
    for(int to:G[now]){
        if(to==pre) continue;
        cntdfs(to,now);
        ret+=cnt[to];
    }
    cnt[now]=ret+1;//自分自身も含める

}

void dfs2(int now,int pre){
   
    for(int to:G[now]){

        if(to==pre) continue;
        
       ans[to]=1LL*ans[now]+N-2LL*cnt[to];//ここうまい　
       ans[to]=1LL*ans[now]+1LL*(N-cnt[to])-cnt[to];//ここうまい
        dfs2(to,now);
    }



}


int main(){
   
    cin>>N;
    G=vector<vector<int>>(N,vector<int>{});
    dist=vector<ll>(N,0);
    vector<int> u(N-1),v(N-1);
    cnt=vector<int>(N,0);
    

    for(int i=0;i<N-1;i++){
        cin>>u[i]>>v[i];
        u[i]--;v[i]--;
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    
    ll ret=dfs(0,-1,0);//根が0
    //cout<<"ret="<<ret<<endl;

    cntdfs(0,-1);
/*
    for(int i=0;i<N;i++){
        cout<<"dist["<<i<<"]="<<dist[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<"cnt["<<i<<"]="<<cnt[i]<<' ';
    }
    cout<<endl;
*/
    
    ans=vector<ll>(N,0);
    ans[0]=ret;

    dfs2(0,-1);
    for(int i=0;i<N;i++){
        cout<<ans[i]<<endl;    
    }



}