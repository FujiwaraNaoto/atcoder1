/*
AC
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N;
    cin>>N;
    vector<ll> C(N+1);
    ll min_odd=INF;//奇数の方の最小枚数
    ll min_even=INF;//偶数の方の最小枚数
    for(int i=1;i<=N;i++){
        cin>>C[i];
        if(i%2==1){
            min_odd = min(min_odd,C[i]);
        }else{
            min_even = min(min_even,C[i]);
        }
    }

    int Q;
    cin>>Q;
    int t,x;
    ll a;
    ll offset_odd=0;//カード番号が奇数の場合　何枚ひかれたかの記録
    ll offset_all=0;//全てのカードが何枚引かれたか

    ll ans=0;
    for(int i=0;i<Q;i++){
        cin>>t;
        if(t==1){
            cin>>x>>a;

            ll tmpcx = C[x] - offset_all;//実際のC[x]のカード枚数がtmpcx

            //C[x]-=offset_all;
            //offset_all=0;

            if(x%2==1){
                tmpcx-=offset_odd;
                //C[x]-=offset_odd;
                //offset_odd=0;
            }

            if(tmpcx<a) continue;
            else{
                C[x]-=a;//aのみ,c[x]に影響すると考える
                ans+=a;
                tmpcx-=a;

                if(x%2==1){//更新がある場合に備える
                    min_odd = min(tmpcx,min_odd);
                }else{
                    min_even = min(tmpcx,min_even);
                }

            }

        }else if(t==2){
            cin>>a;

            if(min_odd<a) continue;
            else{
                min_odd -= a;
                offset_odd+=a;
                ans += (N/2 + N%2)*a;//奇数のみa枚
            }

        }else{
            cin>>a;
            if(min(min_odd,min_even)<a){
                continue;

            }else{
                min_odd-=a;
                min_even-=a;
                offset_all+=a;//全てからa枚ずつ引く
                ans += N*a;//N種類全てa枚ずつ
            }
        }
        //debug用の表示
        //cout<<"ans="<<ans<<",offset_all="<<offset_all<<",offset_odd="<<offset_odd<<endl;

    }

    cout<<ans<<endl;

}
