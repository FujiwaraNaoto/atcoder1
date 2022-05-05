//3重ループでTLE
#include<iostream>
#include<vector>
using namespace std;
const int INF=1<<30;

int main(){
    int N,M;
    cin>>N>>M;
      
    vector<vector<bool>> d(N,vector<bool>(N,false));
    for(int i=0;i<M;i++){
        int from,to;
        cin>>from>>to;
        from--;to--;//0からに補正
        
        d[from][to]=true;//経路が存在する
    }

    for(int i=0;i<N;i++) d[i][i]=true;//自分自身から自分自身は当然いける

    for(int k=0;k<N;k++){//途中でkを経由する
        for(int u=0;u<N;u++){
            for(int v=0;v<N;v++){
                if(u==v) continue;
                //uからkへ行くことが可能　かつ kからvへ行くことが可能
                if(d[u][k] && d[k][v]){
                    d[u][v]=true;
                }
            }
        }
    }

    int ans=0;
    for(int u=0;u<N;u++){
        for(int v=0;v<N;v++){
            if(d[u][v]){
                ans++;
                //cout<<"u="<<u<<",v="<<v<<endl;
            }
        }
    }
    cout<<ans<<endl;


}