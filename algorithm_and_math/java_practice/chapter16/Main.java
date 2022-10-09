import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(n);
        for(int i=0;i<n;i++){
            int X = sc.nextInt();
            if(X==0){
                System.out.println(X+"は0");
            }else if(X>0){
                System.out.println(X+"はプラス");
            }else{
                //X<0
                System.out.println(X+"はマイナス");
            }
        }    
    }
}
