/*
トポロジカルソート
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int INF=1<<30;
typedef pair<int,int> P;
vector<vector<int>> G;

//vector<int> memo;
map<int,int> memo;


int dfs(int now){
    if(memo.count(now))return memo[now]; 
    int ret=0;
    for(int to:G[now]){

        ret=max(ret,dfs(to)+1); 
    }
    return memo[now] = ret;
}


int main(){
    int N,M;
    cin>>N>>M;
    //memo = vector<int>(N,0);
    G = vector<vector<int>>(N,vector<int>{});
    vector<int> x(M),y(M);
    vector<int> deg(N,0);
    for(int i=0;i<M;i++){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
        G[x[i]].push_back(y[i]);
        deg[y[i]]++;//x->y
    }//連結とは限らない

    vector<int> st;
    for(int v=0;v<N;v++){
        if(deg[v]==0){//次数が0のものがポイント
            st.push_back(v);
        }
    }

    vector<int> dp(N,0);

    int max_len=0;
    for(int start:st){

        max_len=max(max_len,dfs(start));
    

    }

    cout<<max_len<<endl;

}