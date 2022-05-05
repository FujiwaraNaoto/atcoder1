/*
AC

(c+1)^5 - c^5 =5*c^4 これは c<10^3までを考えれば良いことを意味する
*/
#include<iostream>
using namespace std;
typedef long long ll;


int main(){
    ll X;
    cin>>X;

   for(ll A=-1000;A<=1000;A++){
       for(ll B=-1000;B<=1000;B++){
           ll powA = A*A*A*A*A;
           ll powB = B*B*B*B*B;
           if(powA-powB==X){
               cout<<A<<' '<<B<<endl;
               return 0;
           }
       }
   }


    

}