import java.util.Scanner;
import java.util.ArrayList;


public class Main {
   
   void solve(){

       
       
       try(Scanner sc = new Scanner(System.in)){
           int A=sc.nextInt();
           int B=sc.nextInt();
           int ans=1;
           for(int g=1;g<=B;g++){
               int a=(A+g-1)/g*g;
               int b=B/g*g;
               if(a<b)ans=g;
           }

           System.out.println(ans);
       }
      
       
   }

   public static void main(String[] args){
       new Main().solve();
   }

}


