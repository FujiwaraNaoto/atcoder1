/*
AC
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
   int N,C;
   cin>>N>>C;
   vector<int>T(N),A(N);

   vector<int> bit0(31,0);//最初すべて 000000...000
   vector<int> bit1(31,1);//最初すべて 1111...111
    vector<int>bitC(31);

  
    for(int i=0;i<N;i++){
        cin>>T[i]>>A[i];

         //2進数で桁が大きい程, bitC[i]のiが大きい
        for(int digit=0;digit<30;digit++){
            bitC[digit] = (C>>digit)&1;
        }

        for(int digit=0;digit<30;digit++){
            //A[i]の最低位から考える bit0[j]でjが小さいほど
            //A[i]の2進数で表した際のdigit桁目を考える.
            int x=(A[i]>>digit)&1;
            vector<int> f={0,1};
            if(T[i]==1){
                f[0]=0&x;
                f[1]=1&x;

            }
            if(T[i]==2){
                f[0]=0|x;
                f[1]=1|x;
                
            }
            if(T[i]==3){
                f[0]=0^x;
                f[1]=1^x;
            }
            bit0[digit]=f[bit0[digit]];//ここで剛性関数を用いる. f(今までの関数の結果)
            bit1[digit]=f[bit1[digit]];
        }


        int tmp=0;
        for(int digit=0;digit<30;digit++){//
            
            if(bitC[digit]==0){//C のbit が0の場合
                tmp|=bit0[digit]<<digit;
            }else{
                tmp|=bit1[digit]<<digit;
            }
        }

        cout<<tmp<<endl;
        C=tmp;

    }
}