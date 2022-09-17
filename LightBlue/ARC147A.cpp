/*
AC 
multisetを思いつくことが難しいかな
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    multiset<int> mst;
    for(int i=0;i<N;i++){
        cin>>A[i];
        mst.insert(-A[i]);
    }
    ll ans=0;
    while(mst.size()>1){
        auto itb=mst.begin();//最小のもの=－がつくので,実際は最大値 
        auto itl=mst.rbegin();//最大のもの=－がつくので,実際は最小値
        int ai=-(*itb);//最大値
        int aj=-(*itl);//最小値
        //mst.erase(itl);//のける reverseは無理みたい
        mst.erase(itb);
        if(ai%aj!=0){
            mst.insert(-(ai%aj));
        }
        ans++;
    }
    
    cout<<ans<<endl;

}