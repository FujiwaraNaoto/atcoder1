
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int>A(N),B(N),C(M),D(M);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    for(int i=0;i<M;i++){
        cin>>C[i];
    }
    for(int i=0;i<M;i++){
        cin>>D[i];
    }

    vector<P> choco(N),box(M);
    for(int i=0;i<N;i++){
        choco[i]=P{A[i],B[i]};
    }
    for(int i=0;i<M;i++){
        box[i]=P{C[i],D[i]};
    }
    sort(choco.begin(),choco.end());
    reverse(choco.begin(),choco.end());
    sort(box.begin(),box.end());
    reverse(box.begin(),box.end());

    bool flag=true;
    multiset<int> mst;
    int bidx=0;
    for(int i=0;i<N;i++){
        auto [a,b]=choco[i];

        while(bidx<M && a<=box[bidx].first){
            mst.insert(box[bidx].second);
            bidx++;
        }
        auto it=mst.lower_bound(b);//b以上のものがあるかどうか
        if(it==mst.end()){
            flag=false;
            break;
        }else{
            mst.erase(it);
        }
    }

    cout<<(flag?"Yes":"No")<<endl;
    

}