/*
aが単調増加のときに,

lower_bound(a.begin(),a.end(),k)は k<=ai となる最小のaiのポインタを返す.
upper_bound(a.begin(),a.end(),k)は k<ai となる最小のaiのポインタを返す.


auto it = lower_bound(a.begin(),a.end(),k)で 
itにはxの値か,xより大きいの最小の数を指すイテレータが入る.

it--で　xの値より小さい,最大の数を指すイテレータが入る


auto it = upper_bound(a.begin(),a.end(),k)で 
it!=a.end()ならば *itにはxより大きい最小の数が入る.



*/
#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    std::vector<int> a={5,5,2,3,4,10};
    std::sort(a.begin(),a.end());// 2,3,4,5,5,10
    int k=5;
    auto it1=lower_bound(a.begin(),a.end(),k);
    auto it2=upper_bound(a.begin(),a.end(),k);
    int num = it2-it1;//kの数
    std::cout<<"*it1="<<*it1<<std::endl;//5
    std::cout<<"*it2="<<*it2<<std::endl;//10
    std::cout<<"it1-a.begin()="<<it1-a.begin()<<std::endl;//3
    std::cout<<"it2-a.begin()="<<it2-a.begin()<<std::endl;//5
    std::cout<<"num="<<num<<std::endl;//2

    auto it3=upper_bound(a.begin(),a.end(),100);//100よりも大きい要素が存在しない場合
    
    std::cout<<*it3<<std::endl;
    std::cout<<it3 - a.begin()<<std::endl;//後ろの要素を指す. A.end()

    auto it4=upper_bound(a.begin(),a.end(),0);//0よりも大きい要素
    
    std::cout<<*it4<<std::endl;//a.begin()を返す
    std::cout<<it4 - a.begin()<<std::endl;//0番目の要素 



}