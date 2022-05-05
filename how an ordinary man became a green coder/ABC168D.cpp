/*
部屋1(修正で部屋0)から各部屋への距離が最短となるようにする問題
AC
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>P;
const int INF = 1<<30;

vector<vector<int>> G;
int N,M;//部屋の数N と通路の数M
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

vector<int>  BFS(int start){

    vector<int> distance(N,INF);
    vector<int> room(N,-1);//-1の時は部屋0から到達が無理
    queue<P> que;

    que.push(P(0,start));//部屋start 距離0
    distance[start]=0;
    while(!que.empty()){

        auto [dis,now] = que.front(); que.pop();

        for(int to:G[now]){//今の部屋nowからtoへ行く
            if(distance[to]>(dis+1)){//距離の更新がある場合
                room[to] = now;//toへ行くには直前にnowを通過するのが良い
                distance[to] = dis+1;
                que.push(P(dis+1,to));
            }
        }
    }

    for(int i=1;i<N;i++){
        if(room[i]==-1){
            room.clear();
            break;
        }
    }

    return room;
}


int main(){
    
    cin>>N>>M;
    G = vector<vector<int>>(N,vector<int>{});
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;//0からに補正
        add_edge(a,b);
    }

    vector<int> nextroom = BFS(0);//部屋1
    if(nextroom.size()==0){
        cout<<"No"<<endl;
        
    }else{
        cout<<"Yes"<<endl;
        for(int i=1;i<N;i++){
            //部屋番号0から始まるのを　部屋1からに補正
            cout<<nextroom[i]+1<<endl;
        }
        
    }

    return 0;

}