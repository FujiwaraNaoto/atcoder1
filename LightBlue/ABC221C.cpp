/*
AC
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;


ll to_ll(const vector<int> S){
    int n = S.size();
    ll ret=0;
    for(size_t i=0;i<n;i++){
        ret*=10;
        ret+=S[i];
    }

    return ret;
}


void print_vec(const vector<int> S){
    int n = S.size();

    for(int i=0;i<n;i++){
        cout<<S[i];
    }
    cout<<endl;
}

int main(){
    
    string N;
    cin>>N;
    int n = N.size();

    ll ans=0;
    for(int S=0;S<(1<<n);S++){
        
        vector<int> la,fi;
        for(int i=0;i<n;i++){
            if((S>>i)&1){
                fi.push_back(N[i]-'0');
            }else{
                la.push_back(N[i]-'0');
            }
        }
        
        sort(fi.begin(),fi.end(),
        [](const int &lhs,const int &rhs){
            return lhs>rhs;
        });

        sort(la.begin(),la.end(),
        [](const int &lhs,const int &rhs){
            return lhs>rhs;
        });


        if(fi.size()==0 || la.size()==0 || fi[0]==0 || la[0]==0) continue;
        
        //print_vec(fi);
        //print_vec(la);

        ll fi1 = to_ll(fi);
        ll la1 = to_ll(la);
        //cout<<"fi1="<<fi1<<",la1="<<la1<<",ans="<<fi1*la1<<endl;
        ans = max(ans,la1*fi1);

        vector<int>().swap(la);
        vector<int>().swap(fi);
    }
    cout<<ans<<endl;    

}