#include <iostream>
#include <functional>
#include <cassert>
#include <cstring>
#include<string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    ll ans=0;
    if(N<A){
        ans=0;//そもそもAliceは一度も石をとれない
    }
    else if(A<=B){
        ans= N-(A-1);//1,2,...,A-1個　以外ではAliceが勝てる
    }else{
        //A>B
        // [1,N) でAの倍数の個数
        ans = (N-(A-1))/A*B;

        if((N-(A-1))%A>0){
            ans += min( (N-(A-1))%A-1, B-1 )+1;
        }

    }
    cout<<ans<<endl;
    

}

/*
	ll n,a,b; cin >> n >> a >> b;
	ll ans;
 
	if(n<min(a,b)) ans = 0;
	else if(n<a) ans = 0;
	else if(a<=b) ans = n-(a-1);
	else ans = (n/a-1)*b + min(n%a,b-1) + 1; 
	cout << ans;



      cin>>n>>a>>b;
  ll ans=0;
  if(a<=b) ans=max(0LL, n-a+1);
  else{
    if(n>=a){
        // (n-(a-1))/aで,n未満([1,n) = [1,n-1]の範囲)でaの倍数の個数.
      ans+=(n-a+1)/a*b;
      if((n-a+1)%a>0){
        ans+=min((n-a+1)%a, b); //0,1,2,3,..b-1のb個　もしくは 0,1,2,..,((n-a+1)%a-1) の(n-a+1)%a個
      }
    }
  }
*/