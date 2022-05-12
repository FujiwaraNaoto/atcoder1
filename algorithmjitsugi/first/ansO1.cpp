/*
O(N^2)の解答
方針はあっている
TLE
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
    
    set<int> st_A;
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){
            cin>>A[i][j];
            st_A.insert(A[i][j]);
        }
    }

    map<int,int> mp;

    int cnt_id=1;//ここポイント 0からにしない
    for(int x:st_A){
        mp[x]=cnt_id++;
    }

    //座圧
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){     
            A[i][j] = mp[A[i][j]];
        }
    }
    
    int maxA=st_A.size();//目の種類数

    vector<vector<int>> dice(maxA+1,vector<int>{});
    
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){    
            //目 A[i][j]を持っているサイコロi 
            dice[A[i][j]].push_back(i);
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
    vector<double> total(N,0);
    vector<double> dp(maxA,0);//test case1の場合は　dp[0]~dp[11]
    for(int i = maxA;i>=0;i--){//maxAから?
        
        double tempmax=0;
        //iよりも大きな目が出ているサイコロについて
       
        for(int j=0;j<N;j++){
            bool flag=false;//サイコロjは iよりも大きな目を持っていないと仮定

            double temp=0;
            for(int k=0;k<6;k++){
                if(A[j][k]>i) flag=true;

                temp +=dp[A[j][k]]/6;
            }

            if(flag){
                tempmax = max(temp,tempmax);
            }
        }



        dp[i]=tempmax+1;

    }

    printf("%.10f\n",dp[0]);




}
