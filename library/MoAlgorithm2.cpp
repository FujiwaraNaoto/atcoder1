// Moのアルゴリズム [l,r)バージョン
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<numeric>
#include<queue>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
const ll MOD=998244353;

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> c(N);
    for(int i=0;i<N;i++){
        cin>>c[i];
    }

    vector<P> ranges;

    vector<int> l(Q),r(Q);
    for(int i=0;i<Q;i++){
        cin>>l[i]>>r[i];
        l[i]--;//[l[i],r[i])なので.0インデックスにする
        ranges.emplace_back(l[i],r[i]);
    }

    vector<int> order(Q);
    iota(order.begin(),order.end(),0);

    const int D=max((int)sqrt(2*N),1);

    sort(order.begin(),order.end(),
    [&](const int i,const int j){
        int ri=r[i]/D;
        int rj=r[j]/D;
        if(ri!=rj){
            return ri<rj;
        }else{
            return l[i]<l[j];
        }
    });



   
    int anscnt=0;

    auto add=[&](int id){
        //idが加わった分の処理を書く
    };

    auto del=[&](int id){
        //idが除かれた分の処理を書く

    };


    vector<int> ans(Q);

    int left=0,right=0;

    //[left,right)

    //[nl,nr)が目標
    for(int q=0;q<Q;q++){
        int nl=l[order[q]];//目標
        int nr=r[order[q]];
        
        while(nl<left){
            //今見ている先のleft(つまりleft-1)を含ませる
            left--;
            add(left);
            
        }

        while(nr<right){
            //今見ているright(実際は[left,right)なのでright-1)を消す
            right--;
            del(right);
            
        }

        while(left<nl){
            del(left);//今見ているleftを消す
            left++;
        }

        while(right<nr){
            add(right);//今見ているrightを含ませる
            right++;//[left,right)になるようにする            
        }

        ans[order[q]]=anscnt;

        


    }

    for(int q=0;q<Q;q++){
        cout<<ans[q]<<endl;
    }
}