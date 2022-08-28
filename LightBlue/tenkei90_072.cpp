/*
AC
再帰を使うため難しい.
bitでどうおこなうのか?
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

vector<vector<char>> mp;
int H,W;
vector<vector<bool>> used;

int dfs(int nowx,int nowy,int goalx,int goaly){

    if(nowx==goalx && nowy==goaly && used[nowy][nowx]){
        //最初はここの部分が機能しない.
        //used[nowy][nowx]=falseになっているから
        return 0;
    } 

    used[nowy][nowx]=true;//一度通った部分
    int ret=-1<<20;

    for(int k=0;k<4;k++){
        int nx=nowx+dx[k];
        int ny=nowy+dy[k];
        //ゴールでない　かつ　used[ny][nx]==true(つまり,すでに通ってしまった場合)
        //次の行先がゴールの場合, 通してしまう
        
        if(nx<0 || W<=nx || ny<0 || H<=ny ||
         mp[ny][nx]=='#' ||
         ( !(nx==goalx && ny==goaly) && used[ny][nx])) continue;
        ret=max(ret,dfs(nx,ny,goalx,goaly)+1);
    }

    used[nowy][nowx]=false;
    return ret;

}



int main(){
    
    cin>>H>>W;
    mp = vector<vector<char>>(H,vector<char>(W));
    used = vector<vector<bool>>(H,vector<bool>(W,false));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>mp[i][j];
        }
    }

    int ans=0;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(mp[y][x]=='#')continue;
            ans=max(ans,dfs(x,y,x,y));
        }
    }

    if(ans<=2)ans=-1;

    cout<<ans<<endl;


}