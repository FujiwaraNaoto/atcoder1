#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    //周期の長さlen
    //Nの約数を考える
    for(int len=1;len<=N;len++){
        if(N%len==0){//Nがlenの倍数になる時

            // a~zまで cnt[i][c] =Sの (i%len)番目の文字がcが使われている回数 
            vector<vector<int>> cnt(len,vector<int>(26));
           
            for(int k=0;k<N;k++){
                cnt[k%len][S[k]-'a']++;
            }
            int ans=0; 
            for(int k=0;k<len;k++){
                int max_cnt=0;
                
                for(int c='a'-'a';c<='z'-'a';c++){
                    max_cnt=max(max_cnt,cnt[k][c]);
                }
                //出現頻度が多い文字に合わせるべし max_cntを取るときの文字cについて は 更新しなくてよいから

                ans+=(N/len - max_cnt);
            }
            //cout<<"len="<<len<<"ans="<<ans<<endl;

           

            if(ans<=K){
                cout<<len<<endl;
                return 0;
            }

        }

    }
/*
     for(int k=0;k<N;k++){
                for(int c='a'-'a';c<='z'-'a';c++){
                cout<<"cnt["<<k<<"]["<<c<<"]="<<cnt[k%len][S[k]-'a'];
                }
                cout<<endl;
            }
        
*/

}