<!--
Command + K の後に V
-->
# atcoder1
 - used for library
 - how an ordinary man became a green coder
 - how to calculate time, see timer.cpp
 - how to use priority_queue, see priority_queue.cpp
 - how to count bit ,see countbit.cpp
 - how to use multiple input, see input.cpp
 
 - how to print decimal with the designated number of digits, see decimal.cpp

 - how to check random case,
 see checker.cpp (This code is convenient when you're solving adhoc questions)


 you have to compile them with options  -std=c++17 or  -std=c++11

 for example
 ```
 g++ priority_queue.cpp -o p -std=c++17
 ```

# Running sample

For running,

create a test page
```
vim sample.txt
```
add sample case (ex.ABC218G)
```
6
2 2 6 4 6 6
1 2
2 3
4 6
2 5
2 6
```
save the file 
```
:wq
```

then, compile c++ file (ex. ABC218G.cpp)
```
g++ ABC218G.cpp -o p -std=c++17
```
and
```
p < sample.txt
```




