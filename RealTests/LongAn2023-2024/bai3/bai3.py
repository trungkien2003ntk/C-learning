n = input()
s = str(n)
ans = 0

for i in range(len(s)):
    ans += int(s[i]) * (2 ** i * 11 ** (len(s)-i-1) - 10 ** (len(s)-i-1))

print(ans)
