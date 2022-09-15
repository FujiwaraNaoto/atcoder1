/*
1009 =>999がコーナーケース

AC
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int INF=1<<30;

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        string N;
        cin>>N;
        int len=N.size();
        vector<int> sz;
        sz.push_back(1);//長さが1
        for(int k=2;k*k<=len;k++){
            if(len%k==0){
                sz.push_back(k);
                if(k!=len/k) sz.push_back(len/k);
            }
        }

        string ans_tmp;
        for(int l=0;l<len-1;l++){
            ans_tmp=ans_tmp+"9";
        }
        ll ans=stoll(ans_tmp);

        for(int l:sz){
            string tmp;
            for(int t=0;t<len/l;t++){
                tmp=tmp+N.substr(0,l);
            }

            if(stoll(tmp)<=stoll(N)){
                ans=max(ans,stoll(tmp));
            }

            string tmp2;
            for(int t=0;t<len/l;t++){
                tmp2=tmp2+to_string(stoll(N.substr(0,l))-1);
            }
            
            if(stoll(tmp2)<=stoll(N)){
                ans=max(ans,stoll(tmp2));
            }



        }

        cout<<ans<<endl;
    }
}