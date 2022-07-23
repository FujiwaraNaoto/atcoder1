#include<iostream>
#include<vector>
using namespace std;
vector<int> P,I,Iinv;
vector<int> ansR,ansL;

bool dfs(int s,int t,int S,int T){

    int now=P[s];//今見ている頂点
    int r=P[s+1];//頂点nowの左の子
    int p=Iinv[now];

    if(p<S || T<p) return false;
    // S<=p <=T
    
    if(p-S>0){
        ansL[now]=P[s+1];
        if(!dfs(s+1,s+p-S,S,p-1)) return false;
    }

    if(T-p>0){
        //ansR[now]=I[p-1];//これは無理
        ansR[now]=P[s+p-S+1];
        if(!dfs(s+p-S+1,t,p+1,T)) return false;
    }


    return true;
}



int main(){
    int N;
    cin>>N;

    P=vector<int>(N+1);
    I=vector<int>(N+1);
    Iinv=vector<int>(N+1);
    ansR=vector<int>(N+1);//答えの格納場所
    ansL=vector<int>(N+1);

    for(int i=1;i<=N;i++){
        cin>>P[i];//行きがけ順   
    }

    for(int i=1;i<=N;i++){
        cin>>I[i];    
    }

    for(int i=1;i<=N;i++){
        Iinv[I[i]]=i;
    }


    if(P[1]==1 && dfs(1,N,1,N) ){

        for(int i=1;i<=N;i++){
            cout<<ansL[i]<<' '<<ansR[i]<<endl;
        }

    }else{
        cout<<-1<<endl;
    }






}