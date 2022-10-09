import java.util.Scanner;
//string.equal()
public class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String message = sc.next();

        if(message.equals("Hello")){
            System.out.println("こんにちは");
        }else{
            System.out.println("さようなら");
        }


    }
}