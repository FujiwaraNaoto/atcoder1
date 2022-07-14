/*
愚直シミュレーション
ac
*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int N,M;
    cin>>N>>M;
    vector<queue<int>> que(M);
    int k,a;
    for(int i=0;i<M;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            que[i].push(a);
        }
    }
    //cout<<"*"<<endl;

    vector<vector<int>> color(N+1,vector<int>{});
    queue<P> order;  
    for(int i=0;i<M;i++){
        int v=que[i].front();//それぞれの筒の先頭のみを考える
        color[v].push_back(i);
        if(color[v].size()==2){
            order.push(P{color[v][0],color[v][1]});
            color[v].pop_back();
            color[v].pop_back();   
        }
    }

    while(!order.empty()){
        //cout<<"*"<<endl;
        auto [u,v]=order.front();
        order.pop();

        que[u].pop();//筒uの先頭を取り出す
        que[v].pop();//筒vの先頭を取り出す
    
        if(que[u].size()>0){
            int nu=que[u].front();
            color[nu].push_back(u);
            if(color[nu].size()==2){
                order.push(P{color[nu][0],color[nu][1]});
                color[nu].pop_back();
                color[nu].pop_back();  
            }
        }
        
        if(que[v].size()>0){
            int nv=que[v].front();
            color[nv].push_back(v);
            if(color[nv].size()==2){
                order.push(P{color[nv][0],color[nv][1]});
                color[nv].pop_back();
                color[nv].pop_back();  
            }
        }
    }

    bool flag=true;
    for(int i=0;i<M;i++){
        if(que[i].size()>0){
            flag=false;
            
        }
    }

    cout<<(flag?"Yes":"No")<<endl;


}