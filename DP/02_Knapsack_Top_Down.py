val = [6,10,12]
wt = [1,2,3]
n = 3
W = 5
t = [[0 for x in range(W+1)] for x in range(n+1)]
for i in range(n+1):
    for j in range(W+1):
        if i==0 or j==0:
            t[i][j] = 0
        elif wt[i-1]<= j:
            t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j])
        else:
            t[i][j] = t[i-1][j]
print(t)