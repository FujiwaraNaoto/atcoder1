/*
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<ll> A(N);
    vector<ll> sum(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());

    sum[0]=A[0];
    for(int i=1;i<N;i++){
        sum[i]=sum[i-1]+A[i];
    }
    
    ll X;
    for(int i=0;i<Q;i++){
        cin>>X;
        ll ans=0;
        
        int num=lower_bound(A.begin(),A.end(),X)-A.begin();
        //被ったとしても問題ない.
        if(num-1>=0){
            ans+=num*X-sum[num-1];
        }
        if(num-1>=0){//X がaよりも大きいとき,ここの結果は0になる
            ans+=sum[N-1]-sum[num-1] - (N-num)*X;
        }else{
             ans+=sum[N-1] - (N-num)*X;
        }
        


        /*
        int num1= upper_bound(A.begin(),A.end(),X-1)-A.begin();//Xよりも小さいもの達の個数
        
        int num3=upper_bound(A.begin(),A.end(),X) - A.begin();//N-num3で Xより大きい者たちの個数
        ll ans=0;
        //cout<<"num1="<<num1<<",num3="<<num3<<endl;
        if(num1>=1){
        ans += num1*X-sum[num1-1];
        }
        if(num3>=1){
        ans += (sum[N-1]-sum[num3-1])-(N-num3)*X;
        }else{
            ans+=sum[N-1] - N*X;
        }
        */
        cout<<ans<<endl;
    }
   


}