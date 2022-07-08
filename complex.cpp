/*
複素数型
まあc++にはデフォルトで複素数ライブラリあるけどね
*/
#include<vector>
#include<sstream>//for ostream and istream
#include<iostream>
#include<iomanip>//setprecision を使用
#include<cmath>

class Complex{
    double re;//実部
    double im;//虚部

public:
    //const double EPS=1e-10;
    //コンストラクタ
    //引数がなければ 0+0j
    Complex(double re_=0,double im_=0):re(re_),im(im_){};



    double real()const{
        //getter　必ずconstをつけるべし 
        return re;
    }

    double imaginary()const{//getter
        //getter　必ずconstをつけるべし 
        return im;
    }   

    double radius()const{
        return std::sqrt(re*re+im*im);
    }
    /*
    double radius()const{
        if(fabs(im-0)<1e-10 && fabs(re-0)<1e-10){
            return 0;//仮
        }

        if(fabs(im-0)<1e-10){
            if(re>0){ return std::M_PI/2};
            else{
                return (-1)std::M_PI/2;
            }
        }


        return std::sqrt(re*re+im*im);
    }
    */

    Complex& operator+=(const Complex& arg){
        re += arg.re;
        im += arg.im;
        return *this;
    }

    Complex& operator-=(const Complex& arg){
        re -= arg.re;
        im -= arg.im;
        return *this;
    }

    
   


    /* クラス中で定義されている非メンバ関数*/
    friend inline Complex operator+(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re+ arg2.re ,arg1.im+ arg2.im);
    }

    friend inline Complex operator-(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re- arg2.re ,arg1.im-arg2.im);
    }

    friend inline Complex operator*(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re+ arg2.re ,arg1.im+ arg2.im);
    }

    //等しいかどうか
    friend inline bool operator==(const Complex& arg1, const Complex& arg2){
        return (arg1.re==arg2.re) && (arg1.im==arg2.im);
    }

    //等しくないかどうか
    friend inline bool operator!=(const Complex& arg1, const Complex& arg2){
        return !(arg1==arg2);
    }



};

inline std::ostream& operator<<(std::ostream& s,const Complex& arg){
      
    //return s<<std::fixed<<std::setprecision(10)<<arg.real()<<"+j"<<std::fixed<<std::setprecision(10)<<arg.imaginary();
   
    return s<<arg.real()<<"+"<<arg.imaginary()<<"j";
    
}

inline std::istream& operator>>(std::istream& s,Complex& x){
    //ここ,どうする?
    double re_,im_;
    s>>re_>>im_;
    x=Complex(re_,im_);
    return s;
}



int main(){
    using namespace std;

    double x1=3.0,y1=5.0;
    double x2=4.0,y2=6.0;

    Complex c1(x1,y1),c2(x2,y2);

    cout<<c1+c2<<endl;
    cout<<c1-c2<<endl;
    cout<<c1+4<<endl;
    cout<<4+c1<<endl;
    cout<<c1-4<<endl;

    c1-=c2;//c1=c1-c2
    cout<<c1<<endl;

    Complex c1_1(x2,y2);

    cout<<(c1_1==c2?"true":"false")<<endl;
    cout<<(c2==c1?"true":"false")<<endl;
    

    Complex c3=c1;//コピーコンストラクタはデフォルトで提供される見たい.
    cout<<c3<<endl;

}