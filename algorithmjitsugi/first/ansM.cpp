//AC
/*
xと決め打ちしてから二分探索法

1e-7の誤差になれば正解
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long  ll;
const ll INF = 1LL<<60; 

int main(){
    int N,M;
    cin>>N>>M;
    vector<double> A(N),B(N),C(M),D(M);

    for(int i=0;i<N;i++) cin>>A[i]>>B[i];
    for(int i=0;i<M;i++) cin>>C[i]>>D[i];

    double ub=INF;
    double lb=0;// 必ず成立

    while( abs(ub-lb)>1e-7 ){

        double mid = (ub+lb)/2;
        
        vector<double> monster(N),helper(M);

        for(int i=0;i<N;i++) monster[i]=(B[i]-mid*A[i]);
        for(int i=0;i<M;i++) helper[i]=(D[i]-mid*C[i]);

        sort(monster.begin(),monster.end(),
        [](const double &lhs,const double &rhs){
            return lhs>rhs;
        });

        sort(helper.begin(),helper.end(),
        [](const double &lhs,const double &rhs){
            return lhs>rhs;
        });
        
        double temp1=0,temp2=0;
        for(int i=0;i<5;i++){
            temp1+=monster[i];
        }
        temp2+=helper[0];
        for(int i=0;i<4;i++){
            temp2+=monster[i];
        }

        if(max(temp1,temp2)>1e-10){
            //もう少しmidをあげてみる
            lb=mid;
        }else{
            ub=mid;
        }

    }
    printf("%.10f\n",lb);
    
}