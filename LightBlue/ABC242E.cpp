/*
AC
境界の文字列を作成することが無難
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll kaibun4(int n,string str){
    ll ans=0;
    

    //nの偶奇に関係ないようにした
    for(int i=0;i<=(n-1)/2;i++){
            ans*=26;
            ans%=MOD;
            ans+=(str[i]-'A');
            ans%=MOD;    
    }
    string test=str;//境界の条件test
    int p=0,q=n-1;
    while(p<q){
        test[q]=test[p];
        p++;
        q--;
    }
    bool flag=true;
    
    ans+=1;//境界が満たすと仮定する
    ans%=MOD;
    if(test>str){//実際は境界が条件を満たさなかった場合.
        ans-=1;
        ans+=MOD;
        ans%=MOD;
    }

    return ans;

}




int main(){
    int T;
    cin>>T;
    int N;
    string S;
    //Nの総和は10^6をこえないので
    vector<ll> ans(T);
    for(int i=0;i<T;i++){
        cin>>N;
        cin>>S;
        ans[i]=kaibun4(N,S);
    }
    for(int i=0;i<T;i++){
        cout<<ans[i]<<endl;
    }
}