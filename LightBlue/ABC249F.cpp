/*
AC

空のときに注意

*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<set>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;


int main(){
    
    
    int N,K;
    cin>>N>>K;
    vector<int> t(N+1);
    vector<ll> y(N+1);
    t[0]=1,y[0]=0;
    for(int i=1;i<=N;i++){
        cin>>t[i]>>y[i];
    }

    //t=1の場合を無視することを考える
    //t=1を採用すると,それまでの結果がすべて無になる


    priority_queue<ll> heapS;//最大値 無視する加算操作の集合 
    //priority_queue<int,vector<int>,greater<int>> heapT;//最小値

    ll tmp=0;
    ll ans=-INF;

    int n=0;//無視する代入集合
    for(int i=N;i>=0;i--){
        if(t[i]==1){
           
            int S=heapS.size();
            
            ans=max(ans,tmp+y[i]);

            //このnを考えてしまうとS > (K-np)となってしまう場合
            if(S==K-n){
                if(heapS.empty()){
                    break;
                }
                ll v=heapS.top();heapS.pop();//Sの最大値を除き,
                //heapT.push(v);
                tmp+=v;//Tの要素
            }

            

            n++;
        }else{
            //t[i]==2の場合
            if(y[i]>=0){
                //heapT.push(y[i]);//足すべき数 つまり無視しない足し算
                tmp+=y[i];

            }else{
                heapS.push(y[i]);
                int S=heapS.size();//
                if(S>K-n){
                    
                    if(heapS.empty()) break;


                    ll v=heapS.top();
                    heapS.pop();//Sの最大値を除き,
                    //heapT.push(v);
                    tmp+=v;
                }
            }
        }


       
    }

    cout<<ans<<endl;


}