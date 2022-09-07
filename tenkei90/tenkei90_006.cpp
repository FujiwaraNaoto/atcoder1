#include<iostream>
#include<map>
#include<numeric>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1e9+7;
const int INF=1<<30;

int main(){
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    // 0~N
    vector<vector<int>> ord(N+1,vector<int>(26,INF));
    //cout<<"tmp"<<endl;
    //ord[i][c-'a']=Sのi文字目までを見ている.文字cが次にSのどこに出てくるか
    for(int i=N-1;i>=0;i--){
        for(char c='a';c<='z';c++){
            if(S[i]==c){
                ord[i][c-'a']=i;
            }else{
                ord[i][c-'a']=ord[i+1][c-'a'];
            }
        }
    }
    //cout<<"tmp2"<<endl;


    int pos=0;//最初は先頭から
    string ans;
    for(int k=K;k>0;k--){
        //cout<<"k="<<k<<endl;

        for(char c='a';c<='z';c++){
            int tmppos=ord[pos][c-'a'];//この部分をとったとする
            
            int len=N-tmppos;//tmpposの文字を含めた長さ. [tmppos,N) で長さになる.
            //tmpposの位置にある文字を仕様することにする
            // tmpposまで移動した際に,kを稼げるかどうか
            //cout<<"c="<<c<<endl;
            //cout<<"tmppos="<<tmppos<<",len="<<len<<endl;
            
            if(len>=k){
                pos=tmppos+1;//tmpposで選んでしまったので,次へ行く
                ans=ans+c;
                //cout<<"c="<<c<<",pos="<<pos<<endl;
                break;
            }
        }
    }

    cout<<ans<<endl;




}