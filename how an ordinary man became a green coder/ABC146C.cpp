/*
値段の単調性から二分探索を疑う
AC
*/
#include<iostream>
using namespace std;
typedef long long ll;

ll digit(ll x){

    ll ret=0;
    while(x>0){
        ret++;
        x/=10;
    }
    return ret;
}

int main(){
    ll X,A,B;
    cin>>A>>B>>X;

    ll ub=(1e+9)+1;
    ll lb=0;

    //lbが必ず条件を満たすとする
    while(ub-lb>1){
        ll mid = (ub+lb)/2;

        ll price=A*mid + B*digit(mid);//midを購入可能
        if(price<=X){
            lb=mid;//midを購入することが可能

        }else{
            //price>X
            ub=mid;
        }

    }
    cout<<lb<<endl;

}