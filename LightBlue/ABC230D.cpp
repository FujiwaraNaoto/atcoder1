/*
貪欲法.
できるだけ右端を壊すようにすると最適
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int N;
    ll D;
    cin>>N>>D;
    vector<ll> L(N),R(N);
    for(int i=0;i<N;i++) cin>>L[i]>>R[i];

    vector<P> walls(N);
    for(int i=0;i<N;i++){
        walls[i]=P(L[i],R[i]);
    }
    
    sort(walls.begin(),walls.end(),
        [](const P &lhs,const P &rhs){
            if(lhs.second!=rhs.second){
                return lhs.second<rhs.second; //右端の小さいほうを優先する
            }else{
                //左端が小さいほうから
                return lhs.first<rhs.first;
            }
    });


    int cnt=0;
    ll right=0;//パンチの届く範囲の右端
    for(int i=0;i<N;i++){
        auto [l,r]=walls[i];
        
        //rについておこなう
        if(right<l){
            //場所x=rでパンチを行う必要がある.
            right=r+D-1;//パンチの影響の最右端
            cnt++;
            
        }else{
            //right>=l
            //とっくにこの壁は壊れている
            continue;
        }
    }

    cout<<cnt<<endl;

}