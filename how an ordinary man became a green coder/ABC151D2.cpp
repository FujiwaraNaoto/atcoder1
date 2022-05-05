/*
(y,x)として全探索なら通る
AC
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

    //後のBFSでも使用する
    for(int y=0;y<H;y++){  
        for(int x=0;x<W;x++){
            if(maze[y][x]=='.'){
                
               int start=y*W+x;

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

    int ans=0;
    for(int y=0;y<H;y++){  
        for(int x=0;x<W;x++){

            if(maze[y][x]=='.'){
                int start = y*W+x;
                auto [_,len] = BFS(start,H*W);
                ans = max(ans,len);
            }
        }
    }

    cout<<ans<<endl;

}