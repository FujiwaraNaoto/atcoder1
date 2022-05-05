/*
AC
周期性を考える
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll K;
    cin>>N>>K;
    vector<int> A(N+1);    
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    vector<int> order;
    set<int> st1,st2;
    int now=1;//スタートの街
    while(st1.find(now)==st1.end()){
        st1.insert(now);
        order.push_back(now);
        now=A[now];//次の街
    }
    int offsetcity=now;
    ll cycle=0;
    //1から1にもどるサイクルではない場合
    //1から街を経由して街xへ行き,そのxでサイクルを形成する場合
    if(now!=1){
        while(st2.find(now)==st2.end()){
        st2.insert(now);
        now=A[now];//次の街
        }
        cycle = (ll)st2.size();//街の数を考えた時に cycle<=Nが必ず成立

    }else{
        //街1から街1までが1サイクル
        cycle = st1.size();
    }

    ll offset = st1.size() - st2.size();//周期に入るまでにかかるターン数
    


    ll ans=1;
    if(K<offset){
        ans = order[K];//

    }else{
        K = K-offset;
        K%=cycle;
        ans = offsetcity;//最初のスタート
        for(int i=0;i<K;i++){
            //愚直シミュレーション
            // K<200000 なのですぐに終わる 
            ans=A[ans];
        }
    }

    cout<<ans<<endl;


    

}