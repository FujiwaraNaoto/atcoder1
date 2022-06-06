/*
f(m)を　ヒューリスティック的に探す
隙間と丸を考えると
20 C 10通りしかない

AC
*/
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

/*
今の桁数 len

*/

set<ll> f;

void func(int x,ll str,int len){
    if(len==11){
        //cout<<str<<endl;
        ll num=1;
        
        while(str>0){
            num*=(str%10);
            str/=10;
        }
        
        f.insert(num);
        return;//ここで終わり
    }

    for(int k=x;k>=0;k--){//必ず k<=xとなる　位に書かれた数字が降順
       
        func(k,str*10+k,len+1);

    }


}

int main(){
    ll N,B;
    cin>>N>>B;
    
    func(9,0,0);

    //cout<<"*"<<endl;

    ll ans=0;
    for(ll fm: f){
        //cout<<"fm="<<fm<<endl;
        ll m = fm+B;
        if(m<1 || N<m)continue;

        // 1<=m <= N
        ll tmp=m;
        ll check=1;//これがfmと一致するか判断
        while(tmp>0){
            int c=tmp%10;
            check*=c;
            tmp/=10;
        }
        if(check==fm){
            ans++;
            //cout<<m<<endl;
        }
    }

    cout<<ans<<endl;




}