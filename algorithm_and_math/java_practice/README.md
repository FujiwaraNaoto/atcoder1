
超基本
```
import java.util.Scanner;

public class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String message = sc.next();

    }
}
```

標準入力
```
Scanner sc = new Scanner(Sytem.in);
String str1 = sc.next();//文字列として受け取る
Int num = sc.nextInt();//整数型として受け取る
```

標準出力

文字列と数字をそのまま+で連結できるという謎.
```
System.out.println(var)

int num=100;
System.out.println("Hello" + num + "!");
```


文字列が等しいか調べる
```
String str1 = "Hello";
String str2 = "Hello ;
str1.equals(str2)
```


