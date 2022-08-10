#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;

int main(){
    int N;
    cin>>N;
    string S;
    cin>>S;
    vector<int> W(N);
    vector<P> people(N);
    int tmp=0;//最初は大人でカウント
    for(int i=0;i<N;i++){
        cin>>W[i];
        people[i]=P{W[i],S[i]-'0'};
        if(S[i]=='1'){
            //大人
            tmp++;
        }
    }
    sort(people.begin(),people.end());
    
    int ans=tmp;
    for(int i=0;i<N;i++){
    //同じ体重だった場合, カウントを考えずループにする
        auto [w,c]=people[i];
        if(i+1<N && people[i].first==people[i+1].first){
                
            if(c==1){
                //大人だった場合
                //これから子供と判断するので-1
                tmp--;
            }else{
                //子供だった場合 子供と判断できるので正解数が一つ増えて+1
                tmp++;
            }
           
            continue;
        }else{

            if(c==1){
                //大人だった場合
                //これから子供と判断するので
                tmp--;
            }else{
                //子供だった場合
                tmp++;
            }

        }
        ans=max(ans,tmp);
        
    }
    cout<<ans<<endl;


}
