
#include<cassert>
#include<iostream>

void f(int x){
    //parameter must be possitive
    assert(x>=0);

    std::cout<<x<<std::endl;
}

int main(){

    f(3);
    f(-1);//Assertion failed: x>=0, file assert.cpp, line 7

}