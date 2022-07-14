/*
AC

*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

set<int> prime(int n){
    set<int> st;
    vector<int> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            st.insert(i);
            for(int p=i*2;p<=n;p+=i){
                is_prime[p]=false;   
            }
        }
    }

    return st;

}


int main(){
    int N,M;
    cin>>N>>M;
    
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }


    vector<vector<int>> d(100000+1,vector<int>{});
    for(int i=2;i<=100000;i++){//MlogM
        for(int p=i;p<=100000;p+=i){
            d[p].push_back(i);
        }
    }

    //set<int> st=prime(M);

    vector<bool> is(M+1,true);

    set<int> ng;
    for(int i=0;i<N;i++){
        for(int x:d[A[i]]){//A[i]の約数たち
            ng.insert(x);
        }
    }  

    for(int x:ng){
        for(int k=x;k<=M;k+=x){
            is[k]=false;
        }
    }



    int cnt=0;
    vector<int>ans;
    for(int i=1;i<=M;i++){
        if(is[i]){
            ans.push_back(i);
            cnt++;
        }
    }

    cout<<cnt<<endl;

    for(int x:ans){
        cout<<x<<endl;
    }



}