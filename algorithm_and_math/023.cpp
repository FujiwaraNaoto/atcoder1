#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> B(N),R(N);
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    for(int i=0;i<N;i++){
        cin>>R[i];
    }
    double wa=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            wa+=(B[i]+R[j]);
        }
    }

    wa/=(N*N);

    printf("%.10f\n",wa);

}