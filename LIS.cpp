#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>

using namespace std;

int LIS(const vector<int>& P){
    int sz=P.size();
    //multiset<int>tmp_list;
    vector<int> tmp_list;

    for(int i=0;i<sz;i++){
        
        //auto it=upper_bound(tmp_list.begin(),tmp_list.end(),P[i]);//これでも可
        
        auto it=lower_bound(tmp_list.begin(),tmp_list.end(),P[i]);
        if(it==tmp_list.end()){
            //tmp_list.insert(P[i]);
            tmp_list.push_back(P[i]);
        }else{
            *it=P[i];
        }

    }

    return tmp_list.size();
}


int main(){
    int N;
    cin>>N;
    vector<int> A={5,5,1,3,2,4};//
    int ans=LIS(A);//ans=3;
    cout<<ans<<endl;

}