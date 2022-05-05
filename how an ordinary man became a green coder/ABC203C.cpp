/*
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    int N;
    ll K;
    cin>>N>>K;    

    //村の番号が小さくなるようにする
    priority_queue<P,vector<P>,greater<P>> fri;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;//村a お金b
        
        fri.push(P(a,b));
    }

    ll now=0;//今の自分の村番号
    while(K>0){
        now+=K;//一旦Kを全て移動に使ってしまう
        K=0;
        while(!fri.empty()){

            auto [village,money] = fri.top();
            if(village<=now){//この友達のお金を使う 村の番号が今いるnowよりも小さい場合は今まで出会った友達となる
                K+=money;
                fri.pop();//
            }else{//village>now
                break;
            }

        }
    }

    cout<<now<<endl;

}