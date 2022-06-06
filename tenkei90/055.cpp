/*
AC
ギリギリ間に合う
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N,P,Q;
    cin>>N>>P>>Q;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];

    int cnt=0;    
    for(int i=0;i<N;i++){
        
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                for(int l=k+1;l<N;l++){
                    for(int m=l+1;m<N;m++){
                        ll q = A[i]*A[j]%P*A[k]%P*A[l]%P*A[m]%P;
                        if(q==Q){ cnt++;}

                    }
                }
            }
        }
    }

    cout<<cnt<<endl;

}