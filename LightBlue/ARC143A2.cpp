/*
A,B,C (A<=B<=C)

A,B-1,C-1 (Aのみの値を増やすことができる　と考えることが可能)

A-1,B-1,C-1 


Cは単調現象.A->C にして,B->C とする回数は (A-C)+(B-C)

この回数はC以内に収める必要がある.


*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll A,B,C;
    cin>>A>>B>>C;
    if(A>B) swap(A,B);//A<=Bとなるようにする
    if(B>C) swap(B,C);//A<=B<=Cとなるようにする
    
    if( C<=(A+B)  ){
        cout<<C<<endl;
    }else{
        cout<<-1<<endl;
    }
}