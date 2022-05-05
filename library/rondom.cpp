/*
https://qiita.com/e869120/items/8be6521e72025d7b2a13#5-ステップ-c最終手段ランダムチェッカーのすすめ
*/

#include<iostream>
#include<vector>
using namespace std;

void random_generate(int N,vector<int> &A,vector<int> &B){
    for(int i=0;i<N;i++) A[i]=rand()%10+1;
    for(int i=0;i<N;i++) B[i]=rand()%10+1;
}

int solve(int N,vector<int> A,vector<int> B){
    //write your code here
}

int solve_Jury(int N,vector<int>A,vector<int> B){
    //ここに遅いが正しいプログラム
}

int main(){
    for(int t=1;t<=1000;t++){
        int N=8;
        vector<int> A(N),B(N);
        random_generate(N,A,B);
        int J1 = solve(N,A,B);
        int J2 = solve_Jury(N,A,B);
        if(J1!=J2){
            cout<<"Wrong Answer on Test#"<<t<<endl;
            cout<<"Jury="<<J2<<",Output="<<J1<<endl;
            return 0;
        }

    }
    cout<<"Yay!"<<endl;
}
