#include<cmath>
#include<queue>
#include<iostream>
#include<set>
#include<vector>
#include<map>
typedef long long ll;
using namespace std;
const ll INF = 1LL<<60;

int main(){
    int N;
    cin>>N;
    vector<ll> x(N),y(N),P(N);
    for(int i=0;i<N;i++) cin>>x[i]>>y[i]>>P[i];

    ll ub=1LL*4*1e9;//必ず成功
    ll lb=0;//必ず失敗

    while((ub-lb)>1){
        ll mid=(ub+lb)/2;

        bool flag=false;//すべてを訪れることができないとする

        for(int start=0;start<N;start++){
            //始点を決めてしまう
            set<int> is_visit;
            //vector<bool> is_visit(N,false);
            queue<int> que;
            que.push(start);
            is_visit.insert(start);

            while(!que.empty()){
                int now=que.front();
                que.pop();


                for(int to=0;to<N;to++){
                    
                    if(is_visit.count(to) || to==now) continue;//ここでもto==nowのときにはじく
                    ll dis=1LL*abs(x[to]-x[now]) + 1LL*abs(y[to]-y[now]);

               
                    if(P[now]*mid>=dis){
                        is_visit.insert(to);//ここで省く
                        que.push(to);
                    }
                }
            }
            
            if(is_visit.size()==N)flag=true;

        }

        if(flag){
            ub=mid;//緩めてみる
        }else{
            lb=mid;
        }

    }

    cout<<ub<<endl;

}