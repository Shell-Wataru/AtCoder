# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np
import itertools

def gcd(x, y):
    if x == y:
        return x
    elif x > y:
        return gcd(x-y, y)
    else:
        return gcd(y-x, x)

A, B, C = map(int, raw_input().split())
if (C % gcd(A, B)) == 0:
    print "YES"
else:
    print "NO"