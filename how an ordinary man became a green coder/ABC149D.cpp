/*
AC
動的計画法
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    int N,K;
    cin>>N>>K;
    int R,S,P;
    cin>>R>>S>>P;
    string T;
    cin>>T;

    vector<vector<int>> dp(N+1,vector<int>(3,0));
    /*
    dp[i][0] の時はi回めにグー
    dp[i][1] の時はi回めにチョキ
    dp[i][2] の時はi回めにパー

    0=グー 1=チョキ 2=パー
    */

    vector<int> points={R,S,P};

    vector<int> rec;//履歴 

    for(int i=0;i<N;i++){
        int win;//高橋くんが勝つ手

        if(T[i]=='r'){//グーの場合
            win=2;//
        }else if(T[i]=='s'){//チョキの場合
            win=0;
        }else{
            //T[i]=='p' //パーの場合
            win=1;
        }

        if(i-K>=0){
           
            if(win==rec[i-K]){//禁止する手が存在する場合

                //勝つ手の出し方と K回前の手が 被ってしまう場合
                //0点をとるしかない
                int temppoint =  max({dp[i][0],dp[i][1],dp[i][2]});

                dp[i+1][win]=temppoint;
                dp[i+1][(win+1)%3]=temppoint;
                dp[i+1][(win+2)%3]=temppoint;
                //この時は歴史を好きなように変えること( (win+1)%3 or (win+2)%3 と変更が可能 )が可能なので anyの4とする
                rec.push_back(4);
            }else{  

                int temppoint =  max({dp[i][0],dp[i][1],dp[i][2]});
                dp[i+1][win] = temppoint + points[win];
                dp[i+1][(win+1)%3] = temppoint;
                dp[i+1][(win+2)%3] = temppoint;
                rec.push_back(win);

            }

        }else{//過去にタブーの手が存在しない場合 勝つ手の出し方を自由に選んで良い

            int temppoint =  max({dp[i][0],dp[i][1],dp[i][2]});

            dp[i+1][win] = temppoint + points[win];

            dp[i+1][(win+1)%3] =  temppoint;//win以外の手の1つ目
            dp[i+1][(win+2)%3] =  temppoint;//win以外の手の2つ目
            rec.push_back(win);//過去の手を記録しておく
        }

    }

    int ans = max({dp[N][0],dp[N][1],dp[N][2]});
    cout<<ans<<endl;


}