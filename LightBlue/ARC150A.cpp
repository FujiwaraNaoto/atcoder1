/*
AC 累積和で解く
*/
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

bool f(string S,int k,int n){
    vector<int> cnt_zero(n+1,0),cnt_one(n+1,0);


    for(int i=0;i<n;i++){
        cnt_zero[i+1]= cnt_zero[i] + (S[i]=='0'?1:0);
        cnt_one[i+1] = cnt_one[i]  + (S[i]=='1'?1:0);
    }

    int ans=0;
    for(int i=1;i+k-1<=n;i++){
        
        
        //[i,i+k-1]に0がない
        if(cnt_zero[i+k-1]-cnt_zero[i-1]!=0)continue;
        
        //[1,i-1] [i+k,n]に1がない
        if(cnt_one[i-1]-cnt_one[1-1]!=0 || cnt_one[n]-cnt_one[i+k-1]!=0)continue;

        ans++;

    }

    return ans==1;

}

int main(){
    int T;
    cin>>T;
    int N,K;
    string S;
    for(int i=0;i<T;i++){
        cin>>N>>K;
        cin>>S;
        if(f(S,K,N)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }


    }


}
/*

AC
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

bool f(string S,int k,int n){

    int ans=0;
    int cnt_one=0;
    for(int i=0;i<n;i++){
        if(S[i]=='1')cnt_one++;
    }
    int cnt_M=0,cnt_zero=0;
    for(int i=0;i<k;i++){
        if(S[i]=='1'){
            cnt_M++;
        }else if(S[i]=='0'){
            cnt_zero++;
        }
    }

    if(cnt_zero==0 && cnt_M == cnt_one)ans++;

    for(int i=1;i+k-1<n;i++){//[i,i+k-1]
        if(S[i-1]=='0'){
            cnt_zero--;
        }
        else if(S[i-1]=='1'){
            cnt_M--;
        }

        if(S[i+k-1]=='0'){
            cnt_zero++;
        }
        else if(S[i+k-1]=='1'){
            cnt_M++;
        }

        if(cnt_zero==0 && cnt_M == cnt_one)ans++;


    }

    return ans==1;


}



int main(){
    int T;
    cin>>T;
    int N,K;
    string S;
    for(int i=0;i<T;i++){
        cin>>N>>K;
        cin>>S;
        if(f(S,K,N)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }


    }


}

*/