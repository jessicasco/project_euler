#!/usr/bin/env python
"""
Euler's totient function:
    http://en.wikipedia.org/wiki/Euler's_totient_function
"""
from PE010 import getPrimeList
def getPhi(n):
    primelist = getPrimeList(n)
    res = [i for i in range(2, n+1)]
    for i in range(len(primelist)):
        l = primelist[i]
        m = l
        while l <= n:
            res[l-2] *= (m-1)
            res[l-2] /= m
            l += m
    return res

def main():
    res = getPhi(1000000)
    maximum = 0
    for i in range(len(res)):
        if (i+2)*1.0/res[i] > maximum:
            maximum = (i+2)*1.0/res[i]
            maxn = i+2
    print maxn

if __name__ == '__main__':
    main()
