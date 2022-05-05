//AC
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int N,M;
    cin>>N>>M;
    priority_queue<ll> que;//値の大きい順から

    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        que.push(a);
    }

    for(int i=0;i<M;i++){
        int v = que.top(); que.pop();
        v/=2;
        que.push(v);
    }

    ll ans=0;
    while(!que.empty()){
        ll v = que.top();
        que.pop();
        
        ans += v;
    }

    cout<<ans<<endl;

}
