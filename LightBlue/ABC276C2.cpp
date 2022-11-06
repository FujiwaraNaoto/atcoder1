#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int main(){
    int N;
    cin>>N;

    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];
       
    }
    int j=N-2;
    while(P[j]<P[j+1]){
        j--;
    }

    //抜けるとp[j]>p[j+1]となっている
    int k=N-1;
    while(P[j]<P[k]){
        k--;
    }
    //抜けるとP[j]>P[k]となる最初のkにぶつかる. p[k],p[k+1]は単調減少である性質を用いる

    swap(P[j],P[k]);

    reverse(begin(P)+(j+1),end(P));
    for(int i=0;i<N;i++){
        cout<<P[i]<<(i==N-1?'\n':' ');
    }

}