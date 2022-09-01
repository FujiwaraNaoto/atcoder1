/*
multiset やset のlower_boundには注意

lower_bound(st.begin(),st.end(),x)という書き方ではO(N)かかる

lower_boundが提供されており, st.lower_bound(x) これはO(logN)

ABC245Eを載せたので参考にすべき


*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;

int main(){
    int N,M;
    cin>>N>>M;
    vector<P> box(M);
    vector<P> choco(N);
    
    for(int i=0;i<N;i++){
        cin>>choco[i].first;
    }
    for(int i=0;i<N;i++){
        cin>>choco[i].second;
    }

    for(int i=0;i<M;i++){
        cin>>box[i].first;
    }
    for(int i=0;i<M;i++){
        cin>>box[i].second;
    }
    

    sort(box.begin(),box.end());
    sort(choco.begin(),choco.end());

    reverse(box.begin(),box.end());
    reverse(choco.begin(),choco.end());

    multiset<int> bx;

    bool flag=true;

    //i番目のチョコレートについて
    int cntbx=0;
    for(int i=0;i<N;i++){
        
        auto [a,b]=choco[i];
        while(cntbx<M && a<=box[cntbx].first){
            bx.insert(box[cntbx].second);
            cntbx++;
        }

        auto it = bx.lower_bound(b);//O(logN)
        //auto it = lower_bound(bx.begin(),bx.end(),b);//O(N)

        if(it==bx.end()){//b以上のものが見つからない場合.
            flag=false;
            break;
        }
        
        //it以上で最小のもの.
        bx.erase(it);
    }

    cout<<(flag?"Yes":"No")<<endl;



}