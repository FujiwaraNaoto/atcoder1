/*
制約からbit DPがあり得るかも
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;


int main(){
    int N;
    cin>>N;
    vector<vector<ll> > a(N,vector<ll>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }



    for(int S=0;S<(1<<N);S++){

        for(int i=0;i<N;i++){
            if( (S>>i)&1 == 0){//iがまだSに入っていない
                for(int j=0;j<N;j++){
                    if( (S>>j)&1 ){//jはすでに集合に入っている
                        dp[S|1<<i] = max(dp[S] + a[i][j], dp[S|1<<i]);
                    }
                }
            }
            
            // iが単独で S U i となる場合 
            dp[S|1<<i] = max(dp[S] + a[i][i], dp[S|1<<i]);

        }

    }

    cout<<dp[(1<<N)-1]<<endl;



}
