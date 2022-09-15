/*
なかなか難しい問題
解説を見てAC
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int INF=1<<30;


int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    vector<int> ans(N,0);
    for(int i=0;i+1<N;i++){
        if(A[i]>A[i+1]){
            ans[i]^=1;
            ans[i+1]^=1;
        }
    }

    for(int t:ans){
        cout<<t<<' ';
    }


}