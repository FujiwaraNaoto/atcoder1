/*
街vから訪れることができる街を全て列挙する
AC
O(N^2 logN)
*/
#include<iostream>
#include<vector>
#include<numeric>
#include<set>
#include<queue>
using namespace std;

vector<vector<int>> G;
//都市uをスタートとした時に訪れることができる都市を全て把握
vector<set<int>> st;

void BFS(int start){
//startからたどり着ける街を全て調べる
    
    set<int> tempst;
    queue<int> que;

    que.push(start);
    

    while(!que.empty()){

        int now = que.front();
        que.pop();
        
        tempst.insert(now);

        for(int to:G[now]){
            if(tempst.find(to)!=tempst.end()){
                continue;
            }
            //まだtoが要素にない場合
            que.push(to);
        }
    }

    st[start]=tempst;

}




int main(){
    int N,M;
    cin>>N>>M;
    G = vector<vector<int>>(N,vector<int>{});
    st = vector<set<int>>(N);

    for(int i=0;i<M;i++){
        int from,to;
        cin>>from>>to;
        from--;to--;//0からに補正
        G[from].push_back(to);
    }

    for(int start=0;start<N;start++){
        BFS(start);
    }

    int ans=0;

    for(int v=0;v<N;v++){
        //vから訪れることができる頂点数
        ans += st[v].size();
    }

    cout<<ans<<endl;

}