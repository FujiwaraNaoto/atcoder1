/*
AC
制約Nが小さいので全探索
包除原理で解けないかな?
*/
#include<iostream>
using namespace std;

bool check(int x){
    int temp=x;

    bool flag=false;

    while(temp>0){
        flag |= (temp%10==7);
        temp/=10;
    }

    temp = x;
    while(temp>0){
        flag |= (temp%8==7);
        temp/=8;
    }

    return flag;

}


int main(){
    int N;
    cin>>N;

    int ans=0;
    for(int i=1;i<=N;i++){
        if(!check(i)){
            //falseの時 カウント
            ans++;
        }
    }
    cout<<ans<<endl;
}