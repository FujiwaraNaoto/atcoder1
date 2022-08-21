/*
模範解答
バケットソートの際にMo's algorithm
*/
#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD=998244353;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
typedef pair<int,int> P;



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
   
    int q;
    cin>>q;
    vector<int>l(q),r(q);
    for(int i=0;i<q;i++){
        cin>>l[i]>>r[i];
        l[i]--;r[i]--;
    }
    const int D=max(1,int(n/sqrt(q)));//0になると困るので
    
    vector<int> qis(q);
    iota(qis.begin(),qis.end(),0);//どの順番で行っていくかを考える

    sort(qis.begin(),qis.end(),
    [&](int i,int j){
        int di=r[i]/D,dj=r[j]/D;//どのブロックに自分がいるか
        if(di!=dj) return di<dj;
        return l[i]<l[j];//おなじブロックならばより左端にいる場合を探る
    });

    vector<int> ans(q);
    int nl=0,nr=-1;
    int now=0;

    vector<int> cnt(n);
    auto add = [&](int i,int x=1){
        now-=cnt[a[i]]/2;
        cnt[a[i]]+=x;
        now+=cnt[a[i]]/2;
    };

    auto del =[&](int i){ add(i,-1);};
    
    for(int qi:qis){

        while(nl<l[qi]) del(nl),nl++;
        while(nl>l[qi]) nl--,add(nl);

        while(nr<r[qi]) nr++,add(nr);
        while(nr>r[qi]) del(nr),nr--;
        ans[qi]=now;
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }



    return 0;

}