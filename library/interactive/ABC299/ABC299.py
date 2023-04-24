import sys
import re

def print_msg(*s):    
    print(*s, file=sys.stderr)


def start_qa(ansstr, Q):
    """
        ansstr:正解の文字列
        Q: クエリの上限回数
    Returns:
        rc  : 0 = 正常 / それ以外 = 異常
    
    """


    N = len(ansstr)  # 文字列長さ

    # 文字列長さの出力
    print(N,flush=True)

    # クエリ回数
    count = 0

    # インタラクティブ
    while True:
        
        line = sys.stdin.readline()
       
        print_msg(str(count+1),"th query :",line)
        
        if line == '':
            break

        line = line.replace('\n', '')

        cmd, *s = re.split(' ', line)

       
        if cmd == '?':
            if(count>Q):
                print("the number of query exceed!",flush=True)
                return -1
            
            # Query.ここは問題に応じて書き換える

            if len(s) != 1:
                
                print('Query format error', file=sys.stderr)
                return -1
            
            if s[0].isdecimal():
                i = int(s[0])
                i-=1 #0indexに変換する
                if(i<0 or i>=N):
                    print("index exceeded"+str(i+1),file=sys.stderr)
                    return -1
                else:
                    
                    output=ansstr[i]
                    #print_msg(str(count+1),"output :",ouput)
                    print(output,flush=True)
                    #print(ansstr[i],flush=True)

            else:
                #数値でない場合
                print("Query format error. input=", *s,file=sys.stderr)
                return -1

            count += 1


        elif cmd == '!':
            print_msg("ans=")
            print_msg(*s)
            # Answer
          
            if len(s) != 1:
                print("Answer format error", file=sys.stderr)
                return -1

            if s[0].isdecimal():
                i = int(s[0])
                i-=1
                print_msg("result=")
                if(i<0 or i>=N):
                    print("WA",file=sys.stderr,flush=True)
                    
                elif(ansstr[i]!=ansstr[i+1]):
                    
                    print("AC",file=sys.stderr)
                   
                else:
                    print("WA",file=sys.stderr,flush=True)
                    
                return 0

            else:
                print("Query format error. input=", *s,flush=True)
                return -1
            
        
        else:
            # Unknown command
            print('Unknown command =', line, file=sys.stderr)
            return -1


if __name__ == '__main__':
    S="0010011"
    rc=start_qa(S,20)
    sys.exit(rc)