/*
AC
こちらのほうがわかりやすい
累積和がポイント
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int INF=1<<30;

int main(){
    int N;
    cin>>N;
    vector<int> A(N+1);
    vector<int> sumA(N+1,0);
    vector<int> revA(N+1);
    vector<int> revsumA(N+1);

    for(int i=1;i<=N;i++){
        cin>>A[i];
        sumA[i]=sumA[i-1]+A[i];
        revA[i]=1-A[i];
    }
    for(int i=1;i<=N;i++){
        revsumA[i]=revsumA[i-1]+revA[i];
    }

    int tmp=0;
    int maxans=-(1<<30);//最大値
    for(int r=0;r<=N;r++){
        //[r+1,N] + rev[l,r]
        int tmpans=(sumA[N]-sumA[r])+(revsumA[r]-tmp);
        tmp=min(tmp,-sumA[r]+revsumA[r]);
        maxans=max(maxans,tmpans);
    }
    //次に最小値を探す.


   
    tmp=0;
    int minans=(1<<30);//最小値を探す
    for(int r=0;r<=N;r++){
        //[r+1,N] + rev[l,r] + [1,l-1]
        int tmpans=(sumA[N]-sumA[r])+(revsumA[r]-tmp);
        tmp=max(tmp,-sumA[r]+revsumA[r]);//引く数を最大にする
        //cout<<"r="<<r<<",tmpans="<<tmpans<<endl;
        minans=min(minans,tmpans);
    }
   

    int ans=maxans-minans+1;//[minans,maxans]


    cout<<ans<<endl;



}