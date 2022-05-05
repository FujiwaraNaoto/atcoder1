/*
ダイクストラ法
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
typedef pair<ll,int> P;

struct train{
    int B,T,K;
};


int main(){
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;

    vector<vector<train>> trains(N+1,vector<train>{});

    for(int i=0;i<M;i++){
        int a,b,t,k;
        cin>>a>>b>>t>>k;
        trains[a].push_back((train){b,t,k});//aからb
        trains[b].push_back((train){a,t,k});//bからa
    }

    priority_queue<P,vector<P>,greater<P>> que;

    vector<ll> destination(N+1,INF);

    que.push(P(0,X));//Xにはスタート地点なので0でいける

    while(!que.empty()){

        //今の場所city 現在時刻time
        auto [time,city] = que.top();que.pop(); 

        if(destination[city]<time) continue;



        destination[city]=time;
       

        for(auto [b,t,k]:trains[city]){
            
            //bへ辿り着く時刻 が arrivetime
            //所要時間t
            // (time+K-1)/K*K でtime後の最小のKの倍数の時間
            ll arrivetime =  1LL*(time+k-1)/k*k + t ;
            
            if(destination[b]<arrivetime) continue;//bにはより短い時間でたどり着けるため

            que.push(P(arrivetime,b));
        }
    }

    if(destination[Y]==INF) destination[Y]=-1;
    cout<<destination[Y]<<endl;





}