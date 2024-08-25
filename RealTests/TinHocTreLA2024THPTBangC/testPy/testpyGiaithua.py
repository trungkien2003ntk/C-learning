import sys
n = int(input())
sys.set_int_max_str_digits(100000000)


def giaithua(x):
    if (x == 0 or x == 1):
        return 1
    else:
        res = 1
        for i in range(2, x+1):
            res = res * i
        return res


print(giaithua(n))
