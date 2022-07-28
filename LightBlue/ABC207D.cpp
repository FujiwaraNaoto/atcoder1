#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<double> a(N),b(N),c(N),d(N);
    int sumA=0,sumB=0;
    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i];
        sumA+=a[i];
        sumB+=b[i];
    }
    int gA=sumA;
    int gB=sumB;
    for(int i=0;i<N;i++){
        a[i]=N*a[i]- gA;
        b[i]=N*b[i]- gB;
    }//原点にそろえることにする

    int sumC=0,sumD=0;
    for(int i=0;i<N;i++){
        cin>>c[i]>>d[i];
        sumC+=c[i];
        sumD+=d[i];
    }
    int gC=sumC;
    int gD=sumD;
    for(int i=0;i<N;i++){
        c[i]=c[i]*N-gC;
        d[i]=d[i]*N-gD;
    }//原点に重心をそろえることにする
    
    for(int i=0;i<N;i++){  

        //a[0]==0 && b[0]==0　のときを回避する必要ある
        // これはのちのatan2で困る
         if(a[i]!=0 || b[i]!=0 ){
            swap(a[0],a[i]);
            swap(b[0],b[i]);
        }

    }

    //重心を原点にして,座標をn倍に拡大したあとで考える

    
    bool ans=false;
    for(int i=0;i<N;i++){
        //atan2(y,x)= y/xとなるθ [-pi,pi]
        //(a[0],b[0])をtheta回転させると (c[i],d[i])に一致すると仮定する
        double theta= atan2(d[i],c[i]) - atan2(b[0],a[0]);

        
        double tmpC,tmpD;
        int cnt=0;
        bool flag=true;
        for(int k=0;k<N;k++){
            
            tmpC=a[k]*cos(theta)-b[k]*sin(theta);
            tmpD=a[k]*sin(theta)+b[k]*cos(theta);
            bool flag2=false;
            for(int j=0;j<N;j++){
                //一つでも一致するものがあればよい
                //必ず全部の(c,d)が回転を通して座標が変化する
                //システム上同じjに対して(k1,j), (k2,j)となることなるk1,k2は存在しない
                if( fabs(tmpC-c[j])<=1e-5 && fabs(tmpD-d[j])<=1e-5 ) flag2=true;
            }

            flag &=flag2;//少なくとも一つflag2がfalseとなると, flagはfalseとなる

        }

        ans|=flag;

    }

    cout<<(ans?"Yes":"No")<<endl;



}