/*
セグ木使うとTLE 愚直に計算が早い
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 1<<30;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
  
    for(int i=0;i<N;i++){
        cin>>A[i];
       
    }


    int ans=0;
    
    //[ l,r];
    for(int l=0;l<N;l++){
        
        int orange = INF;
        for(int r=l;r<N;r++){
            orange = min(A[r],orange);
            
            ans = max(ans, orange*(r-l+1) );

        }

    }
    cout<<ans<<endl;
    



}
