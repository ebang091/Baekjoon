changes = [25, 10, 5, 1]
T = int(input())

for _ in range(T) :
    C = int(input())
    res = []

    for i in changes :
        res.append(C // i)	# 몫이 개수
        C = C % i	# 나머지는 다시 C에 저장
        
    print(*res)	# 한 줄 출력
 