/*
模範解答
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll bit_zen(int N,int Q,vector<int> x,vector<int> y,vector<int> z,vector<int> w){
    ll ways=0;
   
    for(int mask=0;mask<(1<<N);mask++){
        
        bool flag=true;
        for(int j=0;j<Q;j++){
            //bitのx[j]番目　bitのy[j]番目 bitのz[j]番目　Wのi桁目
            if( (( (mask>>x[j])&1 | (mask>>y[j])&1 ) | (mask>>z[j])&1 ) != w[j] ) flag=false;
        }

        //Q個の条件をすべて満たすならばways+=1
        if(flag) ways++;
       
    }

    return ways;
}

int main(){
    int N,Q;
    cin>>N>>Q;

    vector<ll> X(Q),Y(Q),Z(Q),W(Q);
    //input
    for(int i=0;i<Q;i++){
        cin>>X[i]>>Y[i]>>Z[i]>>W[i];
        X[i]--;//0index 調節
        Y[i]--;
        Z[i]--;

    }

    ll ans=1;

    for(int i=0;i<60;i++){//Wのi桁目 まずは桁のみを固定してそこのみ考える

        vector<int> x(Q),y(Q),z(Q),w(Q);
        for(int j=0;j<Q;j++){//Qこのクエリについてそれぞれ
            x[j]=X[j];y[j]=Y[j];z[j]=Z[j];
            w[j]=(W[j]>>i)&1;//W[j]の2^iの位
        }

        ll ret=bit_zen(N,Q,x,y,z,w);//i桁のみを考えた際に何通りあるか
        ans*=ret;
        ans%=MOD;
    }

    cout<<ans<<endl;

}
