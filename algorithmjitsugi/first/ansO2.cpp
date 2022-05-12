/*
AC

for(int k=0;k<6;k++){
    temp+=dp[A[q][k]]/6;
}
からさらに計算量を工夫したものが模範解答

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> A(N,vector<int>(6,0));
    
    set<int> dice;
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){
            cin>>A[i][j];
            dice.insert(A[i][j]);
        }
    }

    map<int,int> mp;
    for(int x:dice){
        mp[x]=mp.size()+1;
    }

    //座圧
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){     
            A[i][j] = mp[A[i][j]];
        }
    }
    
    int maxA=dice.size();//目の種類数

    vector<vector<int>> que(maxA+1,vector<int>{});
    
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){    
            //目 A[i][j]を持っているサイコロi 
            que[A[i][j]].push_back(i);
        }
    }

    /*
    //座圧がうまく行われているかの確認
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){     
            cout<<"A["<<i<<"]["<<j<<"]="<<A[i][j];
        }
        cout<<endl;
    }

    cout<<"maxA="<<maxA<<endl;
    */

    double ma=0;
    
    vector<double> dp(maxA+1,0);
    
    dp[maxA]=1;
    for(int i = maxA-1;i>=0;i--){//maxAから?
        
        for(int q:que[i+1]){//目i+1を持っているサイコロq(q番目のサイコロ)について考える
            
            double temp=0;
            // i+1のループの際に dpの部分が更新されているのでそこのみ再計算している
            for(int k=0;k<6;k++){
                temp+=dp[A[q][k]]/6;
            }
            ma = max(ma,temp);
        }

        dp[i]=ma+1;



    }

    printf("%.10f\n",dp[0]);




}
