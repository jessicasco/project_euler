#!/usr/bin/env python
import copy
Result = 0
def solve(S):
    global Result
    def options(i,j):
        r = list(S[i])
        r.extend(S[k][j] for k in range(9))
        r.extend(S[i/3*3+k][j/3*3+m]
                  for k in range(3) for m in range(3))
        s = set(r)
        return [z for z in range(1,10) if z not in list(s)]
    mnp = 99
    mp = None
    for i in range(9):
        for j in range(9):
            if S[i][j] == 0:
                p = options(i,j)
                if len(p) < mnp:
                    mnp = len(p)
                    mp = i, j, p
    if mp == None:
        Result += 100*S[0][0]+10*S[0][1]+S[0][2]
        return
    T = copy.deepcopy(S)
    i, j, p = mp
    W = []
    for c in p:
        T[i][j] = c
        W.append(solve(T))
    for c in W:
        return c

def main():
    f = open("PE096.txt")
    for grid in range(50):
        if f.readline()[0:4] != 'Grid':
            raise 'Error while reading.'
        M = []
        for j in range(9):
            M.append([int(c) for c in f.readline().strip()])
        solve(M)
    print Result

if __name__ == '__main__':
     main()
