/*
AC
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;

//stringを long long 
ll to_digit(string S){
    int n=S.size();
    ll tmp=0;
    for(int i=0;i<n;i++){
        tmp*=10;
        tmp+=(S[i]-'0');
    }
    return tmp;
}




int main(){
    string sN,sK;
    cin>>sN>>sK;

    ll K=to_digit(sK);
    ll N=to_digit(sN);

    string rsK=sK;//sKのreverse
    reverse(rsK.begin(),rsK.end());

    
    ll rK=to_digit(rsK);
    if(rK<K){
        //必ず無理
        cout<<0<<endl;
        return 0;
    }
    

    // Kのあとに0をつけていったものは必ずOK
    // K=1111とかみたいな revK=Kとなる場合は注意(コーナーケース)
    string tmpsK=sK;


    set<ll> st;
    while(true){
        if(to_digit(tmpsK)<=N){
            st.insert(to_digit(tmpsK));
            tmpsK=tmpsK+'0';//次に0をつけた者をかんがえてみる

        }else{
            break;
        }
    }

    //rKのあとに0をつけていったものは必ずOK
    tmpsK=rsK;
    while(true){
        if(to_digit(tmpsK)<=N){
            st.insert(to_digit(tmpsK));
            tmpsK=tmpsK+'0';
        }else{
            break;
        }
    }

    cout<<st.size()<<endl;



}