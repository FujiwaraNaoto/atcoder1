/*
istringstream で文字から数値

to_stringで数値をstring型
stoi でstringから数値

クリア

*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int main(){
    int N,K;
    cin>>N>>K;

    for(int i=0;i<K;i++){
        string  tempstr = to_string(N);
        sort(tempstr.begin(),tempstr.end());//数字の小さい順に並ぶので
        
        int g2 = stoi(tempstr);
        reverse(tempstr.begin(),tempstr.end());
        int g1 = stoi(tempstr);//大きい順

        N = g1 - g2; 
    }

    cout<<N<<endl;

}