#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<numeric>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
//typedef pair<int,int> P;
//typedef pair<int,P> PP;

const ll MOD = 998244353;

const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};

int main(){
    int N;
    cin>>N;
    
    int lb=1;
    int ub=N;


    while(ub-lb>1){
        int mid=(ub+lb)/2;

        cout<<'?'<<' '<<mid<<endl;
        flush(cout);
        int t;
        cin>>t;

        if(t==0){
            lb=mid;
        }else{
            //t==1
            ub=mid;
        }

    }

    cout<<"! "<<lb<<endl;
   
}