/*
最適な方法を思いつくことが難しい
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll INF=1LL<<60;

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        ll R,G,B;
        cin>>R>>G>>B;
        vector<ll> ball={R,G,B};
        sort(ball.begin(),ball.end());
        R=ball[0];
        G=ball[1];
        B=ball[2];
        ll ans=INF;
        //R<=G<=B
        if((B-G)%3==0){
            ans=min(ans,B);
        }
        if((G-R)%3==0){
            ans=min(ans,G);
        }
        if((B-R)%3==0){
            ans=min(ans,B);
        }


        cout<<(ans==INF?-1:ans)<<endl;
       
    }

}
