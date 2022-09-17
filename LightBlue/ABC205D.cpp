/*
AC
間隔を考える.
*/
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int INF=1<<30;
typedef long long ll;
typedef pair<int,ll> P;

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<ll> A(N+1);
    A[0]=0;//便宜上入れておく
    vector<ll> idx(N+1,0);

    for(int i=1;i<=N;i++){
        cin>>A[i];
        
    }
    
    vector<ll> sumA(N+1,0);
    for(int i=0;i+1<=N;i++){
        // (A[i],A[i+1])の間にある数　開区間
        idx[i+1]=A[i+1]-A[i]-1;
    }
    for(int i=1;i<=N;i++){
        sumA[i]=sumA[i-1]+idx[i];
    }
    
    /*
    for(int i=0;i<=N;i++){
        cout<<"sumA["<<i<<"]="<<sumA[i];
    }
    cout<<endl;
    */
    
    for(int q=0;q<Q;q++){
        ll K;
        cin>>K;
        int num = lower_bound(sumA.begin(),sumA.end(),K)-sumA.begin();
        //cout<<"num="<<num<<endl;
        cout<<A[num-1]+K-sumA[num-1]<<endl;
    }
    

}