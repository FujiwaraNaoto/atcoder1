/*
AC
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
    vector<ll> T(N);
    for(int i=0;i<N;i++)cin>>T[i];
    vector<ll> A(N);

    
    A[0]=1LL<<T[0];
    for(int i=1;i<N;i++){
        if(T[i-1]>T[i]){
            A[i]=A[i-1]|(1LL<<T[i]);
        }else{
            //ここがポイント
            ll tmp=(A[i-1]>>T[i]);
            tmp+=1;
            A[i]=(tmp|1)<<T[i];
            
        }

    }
    /*
    for(int i=0;i<N;i++){
        cout<<"A["<<i<<"]="<<A[i]<<endl;
    }
    */
    cout<<A[N-1]<<endl;

}