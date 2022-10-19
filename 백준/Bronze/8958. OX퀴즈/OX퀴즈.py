n = int(input())
flag = 0
for i in range (n):
    str = input()
    score = 0
    add = 1
    for j in range(len((str))):
        if str[j] == 'O':
            flag = 1
            if(flag == 1):
                score += (add)
                add = add + 1
            else:
            
                score += add
        else:
            flag = 0
            add = 1

    print(score)
