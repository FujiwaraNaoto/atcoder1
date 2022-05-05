/*
文字列連結はコストがかかる
AC
*/
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    deque<char> deq;
    string S;
    cin>>S;
    for(int i=0;i<(int)S.size();i++){
        deq.push_back(S[i]);
    }
    bool front=true;//frontがtrueの時は 本当の前を指す 
    int Q;
    cin>>Q;
    for(int q=0;q<Q;q++){
        int t;
        cin>>t;
        if(t==1){
            front =! front;//boolの反転
        }else{//t=2;
            int f; char c;
            cin>>f>>c;
            
            if(f==1){//文字列の先頭
                if(front){
                    deq.push_front(c);
                }else{
                    deq.push_back(c);
                }

            }else{//f==2
                if(front){//後ろに入れる
                    deq.push_back(c);
                }else{
                    deq.push_front(c);
                }
            }
        }
    }

    string ans;
    if(!front){
        reverse(deq.begin(),deq.end());
    }
    
        while(!deq.empty()){
            char c = deq.front();
            deq.pop_front();
            ans+=c;
        }
   

    cout<<ans<<endl;



}