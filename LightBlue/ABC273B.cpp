/*
ちょっと難しいAC
*/
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<tuple>
using namespace std;
typedef long long ll;

int main(){
    ll X;
    int K;
    cin>>X>>K;

    for(int i=0;i<K;i++){


        ll tmpX=(X/(ll)pow(10,i));//Xを10^iで割ったときの1の位
        
        ll d = tmpX%10;//Xを10^iで割ったときの1の位

        if(0<=d && d<5){
            X = (tmpX/10)*(ll)pow(10,i+1);

        }else{// 5<=d <=9
            X=tmpX*pow(10,i);
            for(int t=0;t+d<10;t++){
                X+=(ll)pow(10,i);
            }
        }

        //cout<<X<<endl;

    }

    cout<<X<<endl;

}