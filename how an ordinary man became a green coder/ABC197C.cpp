/*
AC
ちょっと実装が面倒
*/
#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    int ans=INF;
    //仕切りを入れるか入れないかで N-1 こ
    for(int S=0;S<(1<<(N-1));S++){

        int tempxor=0;
        int tempor=A[0];//区間内部でのor 最初のみA[0]

        for(int i=0;i<(N-1);i++){
            if((S>>i)&1){
                //仕切り
                tempxor ^= tempor;
                tempor=0;//0にリセットする
                tempor |= A[i+1];
            }else{//(S>>i)&1==0
                tempor |= A[i+1]; 
            }

        }
        tempxor^=tempor;

        ans = min(ans,tempxor);

    }
    cout<<ans<<endl;

}