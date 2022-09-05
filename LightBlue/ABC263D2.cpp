/*
AC
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll L,R;
    cin>>N>>L>>R;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    ll ans=R*N;
    ll sumA=0,sumB=0;
    ll maxb=0;
    for(int r=1;r<=N;r++){
        //0~r-1を考える
        // [0,r-1]を A[i]とLが混じる領域
        // r~N-1がRのみの領域
        // sumB=sum(A[i]-L)
        // min(sumA -sumB)
        //これは sumBがmaxのときがお得.
        sumA+=A[r-1];
        sumB+=(A[r-1]-L);

        maxb=max(maxb,sumB);
        ll tmp=0;
        tmp+=sumA-maxb;
        tmp+=R*(N-r);
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;

}