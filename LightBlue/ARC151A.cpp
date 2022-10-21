/*
AC
辞書順部分が難しい
差分がどこに出るかを考える
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    string S,T;
    cin>>S;
    cin>>T;
    vector<int> sum(N,0);
    for(int i=0;i<N;i++){
        sum[i]=(S[i]!=T[i]?1:0);
    }

    for(int i=1;i<N;i++){
        sum[i]=sum[i-1]+sum[i];
    }
    if(sum[N-1]%2!=0){
        //最後が偶数ならいける
        cout<<-1<<endl;

    }else{
        string U(N,'1');
        int t = sum[N-1]/2;//S側とT側で半分半分
        
        int cntS=t;
        int cntT=t;
        for(int i=0;i<N;i++){
            if(S[i]==T[i]){
                U[i]='0';//自動的に0
            }else{
                if(S[i]=='0' && T[i]=='1'){
                    if(cntT>0){
                        U[i]='0';//S側を採用する. 
                        cntT--;
                    }
                }else{
                    //S[i]=='1' && T[i]=='0'
                    if(cntS>0){
                        U[i]='0';//T側を採用する
                        cntS--;
                    }

                }

                

            }
        }

        cout<<U<<endl;
        
    }


}