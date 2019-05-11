# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np
import itertools

A, B, C = raw_input().split()
if (A[len(A) - 1] == B[0] and B[len(B)-1] == C[0]):
    print "YES"
else:
    print "NO"
