#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxint = 1e+7;

set<int> init(){
    vector<bool> isprime(maxint+1,true);

    isprime[0]=isprime[1]=false;

    set<int> st;

    for(int i=2;i<=maxint;i++){
        if(isprime[i]){
            st.insert(i);
            for(int p=2*i;p<=maxint;p+=i){
                isprime[p]=false;
            }
        }
    }

    return st;

}

int main(){
    int X;
    cin>>X;

    set<int> st = init();

    auto it = st.lower_bound(X);
    cout<<*it<<endl;

    return 0;
}