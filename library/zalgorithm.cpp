/*
ABC141E, ABC284F
*/
#include<iostream>
#include<map>
#include<numeric>
#include<vector>
#include<cmath>
#include<algorithm>
typedef long long ll;


std::vector<int> z_algorithm(const std::string& S){
    std::vector<int> Z(S.size(),0);
    Z[0]=S.size();

    int i=1,j=0;//最初は0文字の一致
    while(i<S.size()){
        while(i+j<S.size() && S[j]==S[i+j]){
            j++;
        }
        Z[i]=j;

        if(j==0){
            i++;    
            continue;
        }

        int k=1;
        while(k<j && k+Z[k]<j){
        //while(i+k<S.size() && k+Z[k]<j){
            Z[i+k]=Z[k];
            k++;   
        }
        i+=k;
        j-=k;
        /*
        i+k文字目からカウントするわけだが,
        先頭からj-k文字目まであっているところからスタートする
        */
    }

    return Z;
}

int main(){
    std::string S;

}