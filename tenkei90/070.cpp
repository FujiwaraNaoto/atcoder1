/*
AC
中央値がポイント
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
const int  INF = 1<<30;

int main(){
    int N;
    cin>>N;
    vector<int> x(N),y(N);
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    
    int midx,midy;//中央値

    if(N%2==0){
        midx=(x[N/2]+x[N/2-1])/2;
        midy=(y[N/2]+y[N/2-1])/2;
    }
    else{
        midx=x[(N-1)/2];
        midy=y[(N-1)/2];
    }

    ll ans=0;
    for(int i=0;i<N;i++){
        ans += 1LL*abs(midx-x[i])+ 1LL*abs(midy-y[i]);
    }
    cout<<ans<<endl;

}