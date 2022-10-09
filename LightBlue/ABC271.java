/*

javac ABC271.java
java ABC271

*/
import java.util.Scanner;
import static java.lang.System.out;

public class ABC271{
    public static void main(String[] args){
        try(Scanner sc=new Scanner(System.in)){
            int N=sc.nextInt();
            boolean[] a=new boolean[N+2];
            for(int i=0;i<N;i++) a[Math.min(N+1,sc.nextInt())] = true;
            for(int read=1;N>=0;read++){
                N-=a[read]?1:2;
                if(N<0) System.out.println(read-1);
            }
        }
        
    }
}