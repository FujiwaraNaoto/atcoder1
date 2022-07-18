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
    vector<ll> A(N);
    ll maxA=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        maxA=max(maxA,A[i]);
    }

    ll ub=2000000000+1;//答え f(ub)<K<=f(lb)
    //ll ub=maxA;
    ll lb=-1;

    while((ub-lb)>1){
        ll mid=(ub+lb)/2;//midにしたら無理

        ll times=0;
        for(int i=0;i<N;i++){//(mid,A]
            times+=max(A[i]-mid,0LL);
        }

        if(K>=times){
            //まだ余裕がある場合
            //つまり,まだK回まで行かない場合
            // midを下げることを考える
            ub=mid;
        }else{
            //K<times
            lb=mid;//midが大きすぎる　小さくすることを考える
        }
    }
    //cout<<"ub="<<ub<<endl;

    //lbのどこかで終わる
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ll diff=max(A[i]-ub+1,0LL);//減らせることができる回数
        K-=diff;
        ans+=diff*(ub+A[i])/2;
    }
    //のこりK回行うことができる
    ans+=K*ub;

    cout<<ans<<endl;





}