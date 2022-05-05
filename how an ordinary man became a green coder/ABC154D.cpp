/*
AC
全体の期待値 = 各期待値の和
*/
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> p(N);
    for(int i=0;i<N;i++) cin>>p[i];

    
        /*
        目の和 = pi*(pi+1)/2
        期待値  =目の和/全事象 =  (pi+1)/2;
        */

    double tempsum=0;

    for(int i=0;i<K;i++){
        tempsum += 0.5*(p[i]+1);//0~K-1個のサイコロについての期待値の和
    }

    double ans = tempsum;
    for(int i=0;i+K<N;i++){
        tempsum +=0.5*(p[i+K]+1);
        tempsum -= 0.5*(p[i]+1);
        ans = max(ans,tempsum);
    }

    printf("%.10f\n",ans);
    
}