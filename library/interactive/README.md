# Interactive

インタラクティブな問題をローカル環境で実行する方法


 atcoder ABC299D　Find By Query を例にしています.


ABC299.pyでは atcoder ABC299D　Find By Query
で対話側のプログラムが書かれています.

問題に応じてABC299.pyを適正に書き換える必要があります.


シェルファイルに権限を持たせる必要があります.(一度だけ行えばOK)
```
chmod +x ABC299.sh
```

解答のソースコードABC299.cpp　を対話で実行する際には以下のコマンドを入力.
```
./ABC299.sh ABC299.cpp ABC299.py
```

すると,ABC299.cppがコンパイルされ,与えたクエリが返ってきます
```
compiling= ABC299.cpp
using python3= quizD.py
1 th query : ? 4

2 th query : ? 5

3 th query : ? 6

4 th query : ! 5

ans=
5
result=
AC
1 th query : ? 4

2 th query : ? 5

3 th query : ? 6

4 th query : ! 5

ans=
5
result=
AC
```

`less`や`cat`コマンドで A.logでは対話型の返答
Q.logはこちらからの質問が返ります
```
cat Q.log
```
```
cat A.log
```



## 参考文献
- https://qiita.com/recuraki/items/d4f4c01f588c421c9ced