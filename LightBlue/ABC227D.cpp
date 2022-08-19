/*
AC
かなり難しい
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N,K;
    cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    ll ub=INF;//INF個のプロジェクトは作ることが無理
    ll lb=0;//0このプロジェクトは必ず作れる

    while((ub-lb)>1){
        ll mid = (lb+ub)/2;
        
        ll tmpsum=0;
        for(int i=0;i<N;i++){
            tmpsum+=min(mid,A[i]);
        }
        // tmpsum>=K*x が本望 オーバーフロー対策
        if(tmpsum/K>=mid){
            lb=mid;
        }else{
            ub=mid;
        }
    }

    cout<<lb<<endl;

}