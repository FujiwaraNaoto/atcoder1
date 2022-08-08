#include<iostream>
#include<vector>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<bool> is_said(2*N+2,false);
    int aoki;
    while(true){
        for(int i=1;i<=2*N+1;i++){
            if(!is_said[i]){
                is_said[i]=true;
                cout<<i<<endl;
                std::flush(std::cout);
                break;
            }
        }
        cin>>aoki;
        is_said[aoki]=true;
        if(aoki==0)return 0;

    }

}