/*
木の直径を使う問題
一つWAが出る
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1<<30;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
typedef pair<int,int> P;

vector<vector<int>> G;

void add_edge(int from,int to){
    G[from].push_back(to);
}


P BFS(int start,int numV){//幅優先探索
    
    
    vector<int> distance(numV,INF);

    queue<int> que;
    que.push(start);
    distance[start]=0;
    while(!que.empty()){
        
        int v = que.front(); que.pop();


        for(int to:G[v]){
            if(distance[to]>(distance[v]+1)){
                distance[to]=(distance[v]+1);
                que.push(to);
            }  
        }
    }

    int ansdistance = 0,ansv=start;

    //startから一番遠い頂点
    for(int i=0;i<numV;i++){
        if(distance[i]!=INF && ansdistance<distance[i]){
            ansdistance=distance[i];
            ansv=i;
        }
    }

    return P(ansv,ansdistance);

}


/*
//ダイクストラだと TLE一つ と WA1つ WAは一緒 
P BFS(int start,int numV){//幅優先探索
    
    
    vector<int> distance(numV,INF);

    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,start));
    //distance[start]=0;
    while(!que.empty()){
        
        //int v = que.front(); que.pop();
        auto [dis,v] = que.top(); que.pop();     
        if(distance[v]<dis) continue; 
        distance[v]=dis;


        for(int to:G[v]){
            if(distance[to]>(distance[v]+1)){
                que.push(P((distance[v]+1),to));
                //distance[to]=(distance[v]+1);
                //que.push(to);
            }  
        }
    }

    int ansdistance = 0,ansv=start;

    //startから一番遠い頂点
    for(int i=0;i<numV;i++){
        if(distance[i]!=INF && ansdistance<distance[i]){
            ansdistance=distance[i];
            ansv=i;
        }
    }
    return P(ansv,ansdistance);
}
*/


int main(){
    int H,W;
    cin>>H>>W;

    vector<vector<char>> maze(H,vector<char>(W));//迷路

    for(int i=0;i<H;i++){
        string str;
        cin>>str;
        for(int j=0;j<W;j++) maze[i][j]=str[j];
    }

    G = vector<vector<int>>(H*W,vector<int>{});

    int start;//後のBFSでも使用する
    for(int y=0;y<H;y++){  
        for(int x=0;x<W;x++){
            if(maze[y][x]=='.'){
                
                start=y*W+x;
                //add_edge(start,start);//自分自身

                for(int i=0;i<4;i++){
                    int tox = x+dx[i];
                    int toy = y+dy[i];
                    if(0<=tox && tox<W && 0<=toy && toy<H && maze[toy][tox]=='.'){
                        int to = toy*W+tox;
                        add_edge(start,to);//startからtoへ辺をはる
                    }else{
                        continue;
                    }
                }


            }
        }
    }

    auto [nextstart,temp] = BFS(start,H*W);//startは '.'の座標でなければならない
    auto [_,ans] = BFS(nextstart,H*W);

    cout<<ans<<endl;




}