//AC
#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    cin>>N;
    string S;
    cin>>S;

    string str1 = S.substr(0,N);
    string str2 = S.substr(N,N);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            a--;b--;//0からに補正
            if(a<N && N<=b ){
                swap(str1[a],str2[b-N]);
            }else if(a<N && b<N){
                swap(str1[a],str1[b]);
            }else{//N<=a && N<=b
                swap(str2[a-N],str2[b-N]);
            }

        }else{
            swap(str1,str2);
        }
    }

    cout<<str1+str2<<endl;


}
