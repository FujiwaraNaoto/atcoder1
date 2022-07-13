/*
AC
dp[i]= max(dp[j]| i<j かつ (hj<hi かつ wj<wi))
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1<<30;

/*
要素のインデックスとベクトルのインデックスが1ずれていることに注意すべし
*/
class BinaryIndexTree{
public:
int bitsize;
vector<int> bit;

   BinaryIndexTree(int bitsize_):bitsize(bitsize_+1){
     bit=vector<int>(bitsize+2,0);
   }
   ~BinaryIndexTree(){
     vector<int>().swap(bit);
   }
    
    //i番目の要素を更新　iは0から
    void update(int i,int x){
        i+=1;//ここ大事
      while(i<bitsize){
        bit[i]=max(x,bit[i]);
        i+= i&-i;
      }
    }

   //0~iまでの中で最大値
    int get(int i){
     int ans=-INF;
     i+=1;
     while(i>0){
        ans=max(ans,bit[i]);
        i -= i&-i;
     }

     return ans;

   }
};


int main(){
    int N;
    cin>>N;
    vector<P> box;
     for(int i=0;i<N;i++){
        int h,w;
        cin>>h>>w;
        box.emplace_back(h,w);
    }

    sort(box.begin(),box.end(),
    [](const P &lhs,const P& rhs){
        if(lhs.first!=rhs.first){
            return lhs.first<rhs.first;
        }else{
            return lhs.second>rhs.second;
        }
    });

    BinaryIndexTree BIT(100000);

    int ans=0;
    
    for(int i=0;i<N;i++){
        auto [h,w]=box[i];
        int num=BIT.get(w-1)+1;// k<wとなるkの中で最大値
        BIT.update(w,num);

      ans = max(ans,num);
    }

    cout<<ans<<endl;


}
