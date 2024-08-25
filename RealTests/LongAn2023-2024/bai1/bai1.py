from math import sqrt
import sys
sys.set_int_max_str_digits(100000000)


def isPrime(x):
    if (x == 2 or x == 3):
        return True
    elif (x < 2 or x % 2 == 0 or x % 3 == 0):
        return False
    else:
        for i in range(1, (int)((sqrt(x) + 1) / 6+1)):
            if (x % (6 * i + 1) == 0 or x % (6 * i - 1) == 0):
                return False
        return True


strDat = list()
resList = list()

k = int(input())

for i in range(1, 10):
    s = str(i)*(2*k)
    for j in range(0, 10):
        if (j != i):
            st = s[0:k] + str(j) + s[k:2*k]
            strDat.append(st)

for it in strDat:
    if isPrime(int(it)):
        resList.append(it)

print(len(resList))
for it in resList:
    print(it, end=' ')
