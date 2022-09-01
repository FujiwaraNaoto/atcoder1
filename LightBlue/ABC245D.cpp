/*
AC
模範解答がすごくきれい
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> A(N+1);
    vector<int> C(N+M+1);
    vector<int> B(M+1);
    for(int i=0;i<=N;i++)cin>>A[i];
    for(int i=0;i<=N+M;i++)cin>>C[i];

    B[M]=C[N+M]/A[N];

    for(int i=1;i<=M;i++){
        int tmp=C[N+M-i];
        for(int j=0;j<i;j++){
            if(N-i+j<0) continue;
            tmp-=B[M-j]*A[N-i+j];//N-i+j + M-j = N-i+M
        }
        B[M-i]=tmp/A[N];
    }

    for(int i=0;i<=M;i++){
        cout<<B[i]<<(i==M?'\n':' ');
    }

}