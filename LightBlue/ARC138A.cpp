/*
AC
難しい

iを固定して(i>=K)で条件を満たすもの　ではうまくいきそうになかった.
*/
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    vector<int> tmp=A;

   sort(tmp.begin(),tmp.end());
   reverse(tmp.begin(),tmp.end());


    ll tmpsum=0;
    for(int i=0;i<K;i++){
        tmpsum+=tmp[i];
    }
    //cout<<"tmpsum="<<tmpsum<<endl;
    for(int i=0;i<K;i++){
        tmpsum-=A[i];
    }
    if(tmpsum==0){
        //cout<<"tmpsum="<<tmpsum<<endl;
        cout<<-1<<endl;
        return 0;
    }

   
    vector<P> idx_pair(N);
    for(int i=0;i<N;i++){
        idx_pair[i]=P{A[i],-i};
    }
    //Aの小さい順に処理する.
    sort(idx_pair.begin(),idx_pair.end());

    int ans=1<<30;
    int max_i=-(1<<30);
    for(auto [v,u]:idx_pair){
        int i=-u;//vのインデックスi
        if(i<K){
            max_i=max(max_i,i);//max_i<K
        }else{
            //i>=Kのとき
            ans=min(ans,i-max_i);
        }
    }

    cout<<ans<<endl;

    

}