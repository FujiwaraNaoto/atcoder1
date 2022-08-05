/*
これは?
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int N,C;
    cin>>N>>C;
    vector<int> T(N),A(N);
    for(int i=0;i<N;i++)cin>>T[i]>>A[i];

    vector<int> bit0(30,0);//最初は0
    vector<int> bit1(30,1);

    for(int i=0;i<N;i++){
        for(int k=0;k<30;k++){
            int bitA=(A[i]>>k)&1;//A[i]のk bit目
            auto tmp=vector<int>{0,1};
            if(T[i]==1){
                tmp[0]=0&bitA;
                tmp[1]=1&bitA;
            }else if(T[i]==2){
                tmp[0]=0|bitA;
                tmp[1]=1|bitA;

            }else{
                tmp[0]=0^bitA;
                tmp[1]=1^bitA;
            }
            bit0[k]=tmp[bit0[k]];
            bit1[k]=tmp[bit1[k]];
        }
        int tmp=0;
        for(int k=0;k<30;k++){
            if((C>>k)&1){
                tmp|= (bit1[k]<<k);
            }else{
                tmp|= (bit0[k]<<k);
            }
        }

        cout<<tmp<<endl;
        C=tmp;

    }



}