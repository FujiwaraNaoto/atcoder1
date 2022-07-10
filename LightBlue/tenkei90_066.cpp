/*
期待値の線形性
AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;


int main(){
    int N;
    cin>>N;
    vector<int> L(N),R(N);
    for(int i=0;i<N;i++)cin>>L[i]>>R[i];
    double ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int cnt=0;
            for(int xi=L[i];xi<=R[i];xi++){
                for(int xj=L[j];xj<=R[j];xj++){
                    if(xi>xj){
                        cnt++;
                    }
                }
            }

            ans+=1.0*cnt/(R[i]-L[i]+1)/(R[j]-L[j]+1);
        }
    }
    printf("%.10f\n",ans);


}