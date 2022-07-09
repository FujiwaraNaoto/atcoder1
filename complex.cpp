/*
複素数型
まあc++にはデフォルトで複素数ライブラリあるけどね
*/
#include<vector>
#include<sstream>//for ostream and istream
#include<iostream>
#include<iomanip>//setprecision を使用
#include<cmath>
#include<cassert>

class Complex{
    double re;//実部
    double im;//虚部

public:
    //const double EPS=1e-10;
    //コンストラクタ
    //引数がなければ 0+0j
    Complex(double re_=0,double im_=0):re(re_),im(im_){};

    ~Complex(){
        //do nothing
    }


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
    Complex& operator*=(const Complex& arg){
        Complex tmp=*this;
        re = tmp.re*arg.re - tmp.im*arg.im;
        im = tmp.re*arg.im + tmp.im*arg.re;

        return *this;
    }
    
    Complex& operator/=(const Complex& arg){
        Complex tmp=*this;
        assert( fabs(arg.re*arg.re + arg.im*arg.im)>1e-10 );
        
        re=(tmp.re*arg.re+tmp.im*arg.im)/(arg.re*arg.re + arg.im*arg.im);
        im = (tmp.im*arg.re - arg.im*tmp.re)/(arg.re*arg.re + arg.im*arg.im);

        return *this;
    }
   


    /* クラス中で定義されている非メンバ関数*/
    /* クラス定義の中で定義されたfriendは自動的にinline
    friend inline Complex operator+(const Complex& arg1, const Complex& arg2)
    に書かなくてよい
    */
    friend Complex operator+(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re+ arg2.re ,arg1.im+ arg2.im);
    }

    friend Complex operator-(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re- arg2.re ,arg1.im-arg2.im);
    }

    friend Complex operator*(const Complex& arg1, const Complex& arg2){
        return Complex(arg1.re*arg2.re - arg1.im*arg2.im ,arg1.re*arg2.im + arg1.im*arg2.re);
    }

    //arg1をarg2でわる
    friend Complex operator/(const Complex& arg1,const Complex& arg2){

        assert(fabs(arg2.re*arg2.re + arg2.im*arg2.im)>1e-10);
        return Complex((arg1.re*arg2.re + arg1.im*arg2.im)/(arg2.re*arg2.re + arg2.im*arg2.im),(arg2.re*arg1.im - arg2.im*arg1.re)/(arg2.re*arg2.re + arg2.im*arg2.im));

    }
   

    //等しいかどうか
    friend bool operator==(const Complex& arg1, const Complex& arg2){
        return (arg1.re==arg2.re) && (arg1.im==arg2.im);
    }

    //等しくないかどうか
    friend bool operator!=(const Complex& arg1, const Complex& arg2){
        return !(arg1==arg2);
    }


    


};

inline std::ostream& operator<<(std::ostream& s,const Complex& arg){
      
    return s<<std::fixed<<std::setprecision(10)<<arg.real()<<"+j"<<std::fixed<<std::setprecision(10)<<arg.imaginary();
   
    //return s<<arg.real()<<"+"<<arg.imaginary()<<"j";
    
}
/*
cin は考えない
inline std::istream& operator>>(std::istream& s,Complex& x){

}
*/


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

    Complex c4(5,6),c5(7,8),c6(20,24),c9(3,4);
    Complex c0(0,0);
    cout<<"c6/c4="<<c6/c4<<endl;
    cout<<"c6/4="<<c6/4<<endl;
    cout<<"2/c9="<<2/c9<<endl;
    cout<<"2*c9="<<2*c9<<endl;
    c9*=2;
    cout<<"c9="<<c9<<endl;
    cout<<"c4*c5="<<c4*c5<<endl;
    Complex c7=c4*c5;
    cout<<"c7/c5="<<c7/c5<<endl;//c4に戻るはず
    c7/=10;
    cout<<"c7="<<c7<<endl;
    c7*=10;
    cout<<"c7="<<c7<<endl;
    c7/=c4;
    cout<<"c7="<<c7<<endl;//c5になるはず
    cout<<"c4*c5/c5="<<c4*c5/c5<<endl;


    Complex c02;//0+0jになるはず
    cout<<"c02="<<c02<<endl;


    cout<<"c4/c0="<<c4/c0<<endl;//errorとなるはず

    

}