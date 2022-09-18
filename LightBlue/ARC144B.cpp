/*
AC
二分探索で処理.
*/
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int N,a,b;
    cin>>N>>a>>b;
    vector<ll> A(N);
    
    ll ub=0;
    ll lb=1LL<<40;
    ll sumA=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        lb=min(lb,A[i]);
        ub=max(ub,A[i]);
    }
    
    //lbは必ず満たす
    //Xにできるかどうか
    while(ub-lb>1){
        ll X=(ub+lb)/2;
        ll mid=X;
        ll cntplus=0;//bを足す回数
        ll cntminus=0;//aを引く回数
        for(int i=0;i<N;i++){
            if(A[i]>=X){
                //bを (A[i]-x)/b回,引かせてもらう
                cntplus += (A[i]-X)/b;

            }else{//X>A[i] A[i]がXより小さい
                // a回引く操作の回数.
                cntminus+=(X-A[i]+a-1)/a;
            
            }
        }

    
        if(cntplus>=cntminus){
            lb=mid;
        }else{
            ub=mid;
        }

    }

    cout<<lb<<endl;
    

}