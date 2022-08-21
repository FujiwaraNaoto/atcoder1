/*
AC
実装はそこまで難しくない
*/
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,ll> P;
typedef pair<ll,pair<int,int>> edge;

int main(){
    int N;
    ll L;
    cin>>N>>L;
    vector<ll> A(N);
    ll sumA=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sumA+=A[i];
    }
    if(L-sumA>0){
        N++;
        A.push_back(L-sumA);//あまりがある場合
    }

    
    priority_queue<ll,vector<ll>,greater<ll>> que;
    for(int i=0;i<N;i++){
        que.push(A[i]);
    }
    ll ans=0;
    while(que.size()>1){
        ll l1=que.top();
        que.pop();
        ll l2=que.top();
        que.pop();

        ans+=(l1+l2);
        que.push(l1+l2);
    }

    cout<<ans<<endl;


}