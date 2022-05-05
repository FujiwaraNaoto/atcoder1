#include<iostream>
#include<vector>
using namespace std;

int main(){
    int K;
    cin>>K;

    //mod Kで考える
    int cnt=0;
    int temp=0;
    vector<bool> remain(K,false);//一度　あまりになった場合
    bool flag=true;
    while(true){
        //*10は位上げのぶん
        temp = (temp*10+7)%K;//あまり
        cnt++;
        if(temp==0){
            //うまく割り切れた場合
            break;
        }

        if(remain[temp]){//循環する場合
            flag=false;
            break;
        }else{//ramain[temp]=falseの場合
            remain[temp]=true;
        }
    }

    cout<<(flag ? cnt:-1)<<endl;
}