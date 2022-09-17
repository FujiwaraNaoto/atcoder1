/*
模範解答
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
    vector<ll> A(N);
    vector<ll> idx(N+1,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    vector<ll> c(N,0);
    for(int i=0;i<N;i++){
        //c[i]= [1,A[i]]までで,のける数の総数.
        c[i]=A[i]-i-1;
    }
  
    
    for(int q=0;q<Q;q++){
        ll K;
        cin>>K;

        // c[r-1]< K <=c[r] となるrを探す.
        int r = lower_bound(c.begin(),c.end(),K)-c.begin();
        //cout<<"num="<<num<<endl;
        ll ans;
        if(r==0){
            ans=K;
        }else{
            ans=A[r-1]+(K-c[r-1]);
        }

        cout<<ans<<endl;
        
    }
    

}