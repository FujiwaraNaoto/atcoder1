/*
この実装うまい
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;

int main(){
    int N;
    cin>>N;
    vector<bool> st(N+2,false);//0~N+1
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        st[min(N+1,a)]=true;
    }

    //N巻の本がある. 
    //1巻目から順番に見ていく
    for(int read=1;N>=0;read++){
        N -= (set[read]?1:2);
        if(N<0){
            cout<<read-1<<endl;
            return 0;
        }
    }

}