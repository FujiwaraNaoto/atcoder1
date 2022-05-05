#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll X,K,D;
    cin>>X>>K>>D;
    ll nowx;
    if(X>0 && (X/K-D)>0){// X-K*D>0 ずっと負の方向に移動していく
        nowx = abs(X-D*K);
    }else if(X<0 && (D+X/K)<0){// X+K*D<0 ずっと正の方向に移動していく
        nowx = abs(X+D*K);
    }
    else{
        //途中で切り返しがある場合

        
        ll times = abs(X/D);
        if(X>0){
        
            ll nowx1 = abs(X-times*D);
            ll nowx2 = abs(X-times*D-D);
            if(abs(nowx1)>abs(nowx2)){
                times++;//nowx2のほうが座標の絶対値が小さい

                times = K-times;
                
                if(times%2==0){
                    nowx = nowx2;
                }else{
                    nowx = nowx1;
                }

            }else if(abs(nowx1)<abs(nowx2)){

                times=K-times;
                if(times%2==0){
                    nowx = nowx1;
                }else{
                    nowx = nowx2;
                }
            }else{
                //now1==now2==0の場合
                times = K-times;
                if(times%2==0){
                    nowx = 0;
                }else{
                    nowx = D;
                }

            }

        }else if(X<0){

            ll nowx1 = abs(X+times*D);
            ll nowx2 = abs(X+times*D+D);

            if(abs(nowx1)>abs(nowx2)){
                times++;//nowx2のほうが座標の絶対値が小さい

                times = K-times;
                
                if(times%2==0){
                    nowx = nowx2;
                }else{
                    nowx = nowx1;
                }

            }else if(abs(nowx1)<abs(nowx2)){
                times=K-times;
                 if(times%2==0){
                    nowx = nowx1;
                }else{
                    nowx = nowx2;
                }
            }else{
                //now1==now2==0の場合
                times = K-times;
                if(times%2==0){
                    nowx = 0;
                }else{
                    nowx = D;
                }

            }


        }else{
            //X==0
            times = K-times;
            if(times%2==0){
                nowx=0;
            }else{
                nowx=D;
            }
        }
    
    }

    cout<<nowx<<endl;




}