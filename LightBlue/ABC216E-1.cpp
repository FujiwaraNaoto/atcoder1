/*
等差数列
AC
*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
 
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N+1);//A[N]=0
    int a;
    for(int i=0;i<N;i++){
        cin>>A[i];
     
    }
    //A.push_back(0);//これ,ポイント
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    ll ans=0;
    for(int i=0;i<N;i++){//Aの要素数は N+1個になる
        ll num=A[i]-A[i+1];
        ll tousa_sum = num*(A[i]+(A[i+1]+1))/2*(i+1);
        if((K-1LL*num*(i+1))>=0){
            K-=1LL*num*(i+1);
            ans+=tousa_sum;
        }else{
            ll d=K/(i+1);
            ll m=K%(i+1);
            ans+=(i+1)*(A[i]+ A[i]+(-1)*(d-1))*d/2;
            ans += (A[i]-d)*m;
            K=0;
        }

    }
    cout<<ans<<endl;


}
