/*
AC 良問
累積和
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
    vector<int> S(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>A[i];
        if(A[i]==0){S[i]=1;}
        else{S[i]=-1;}
    }
    
    for(int i=1;i<=N;i++){
        S[i]=S[i]+S[i-1];
    }
    
    
    
    int maxSl=0;
    int minans=INF;
    //区間　累積和のmaxとminを探す.
    for(int r=0;r<=N;r++){//rを固定.S[l]-S[r]
        minans= min(S[r]-maxSl,minans);

        maxSl=max(maxSl,S[r]);
    }

    int maxans=0;

    int minSl=0;
    for(int r=0;r<=N;r++){
        maxans=max(S[r]-minSl,maxans);
        minSl=min(minSl,S[r]);
    }

    //cout<<"maxans="<<maxans<<endl;
    //cout<<"minans="<<minans<<endl;

    cout<<maxans-minans+1<<endl;




}