/*
AC
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;


int main(){
    int N;
    cin>>N;
    vector<int> a(N);
    vector<bool> is_read(N+2,false);//1~N+1巻を読む
    is_read[0]=true;//0巻は読むことができる
    int sz=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(a[i]>N) sz++;//頑張ってもN巻までしか読めない
        else{
            if(is_read[a[i]]){
                sz++;
            }else{
                is_read[a[i]]=true;
            }
        }
    }

    int L=0,R=N+1;//L-1が答え　N+1巻は必ず読めない
    //R巻は読むことが無理
    while(L<R){
        //cout<<"L="<<L<<",R="<<R<<endl;
        while(is_read[L])L++;//L巻を読むことが可能な場合.次の巻へ
      
        //cout<<"L2="<<L<<",R2="<<R<<endl;

        //漫画Lを読むことが無理
        //漫画Rをよむことができる
        if(sz>=2){
            is_read[L]=true;
            sz-=2;

        }else{
            if(R!=0 && is_read[R]){
                //漫画Rを読まなくさせる
                sz+=1;
                is_read[R]=false;
            }else{
                R--;
            }
        }
    }
    cout<<L-1<<endl;

}