/*
shrink_to_fit　は　capacityで,今使用していないメモリを解法. 
vector<int>().swap(v);はメモリの完全解法
*/
#include<vector>
#include<iostream>
using namespace std;


int main(){
    
    vector<int> v={1,2,3};
    cout<<v.capacity()<<endl;//3
    v.erase(v.begin());//先頭要素を削除
    cout<<v.capacity()<<endl;//3

    v.shrink_to_fit();
    cout<<v.capacity()<<endl;//2

    vector<int>().swap(v);
    cout<<v.capacity()<<endl;//0

} 