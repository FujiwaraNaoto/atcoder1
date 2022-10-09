import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
       
        if(num==100){
            System.out.println(num);
        }else if(num<100){
            System.out.println("100より小さい");
        }else{
            System.out.println("100より大きい");
        }
    }
}