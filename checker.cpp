/*
ランダムチェッカー. ARCで役に立つ
atcoderはGCC9.2.1
https://qiita.com/e869120/items/8be6521e72025d7b2a13#5-%E3%82%B9%E3%83%86%E3%83%83%E3%83%97-c%E6%9C%80%E7%B5%82%E6%89%8B%E6%AE%B5%E3%83%A9%E3%83%B3%E3%83%80%E3%83%A0%E3%83%81%E3%82%A7%E3%83%83%E3%82%AB%E3%83%BC%E3%81%AE%E3%81%99%E3%81%99%E3%82%81

*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<numeric>
#include<queue>
using namespace std;
typedef long long ll;
const int INF=1<<30;
typedef pair<int,int> P;
typedef pair<int,P> PP;
const ll MOD=1e9+7;
const int NUMTESTCASE=1000;

void random_generate(int n,vector<int>&testcase){
    //rand()は[0,32767]の整数しか返さない. rand()%1000000000+1で書いても意味がない
    //ランダムで生成する
    for(int i=0;i<n;i++){
        testcase[i]=rand()%10+1;
    }
}

//引数は問題に応じて適切に変更するべし
int solve(int N,vector<int>A){
    //ここに自分のプログラムを書いて正しい答えを出す
}

int solve_Jury(int N,vector<int>A){
    //ここに,実行が遅いが,確実に正しいプログラムを書く
}



int main(){

    for(int t=0;t<NUMTESTCASE;t++){
        int n=8;//入力データサイズ.適当に決める
        vector<int> testcase(n);
        random_generate(n,testcase);

        int J1=solve(n,testcase);
        int J2=solve_Jury(n,testcase);
        if(J1!=J2){
            cout<<"Wrong Answer on Test #"<<t<<endl;
            cout<<"Jury="<<J2<<",Output="<<J1<<endl;

            cout<<"number="<<n<<endl;
            for(int i=0;i<n;i++){
                cout<<"i="<<testcase[i]<<(i==n-1?'\n':' ');
            }
            return 0;
        }
    }

    cout<<"end"<<endl;
    return 0;
}