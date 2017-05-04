# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np
import math

class SegmentTree():
    INFINITY = 1000000001
    N = 0
    Data = np.ones(0)
    def __init__(self, _N):
        self.N = 2**math.ceil(math.log(_N, 2) + 1) -1
        self.Data = np.ones(self.N)*self.INFINITY

    def update(self, i, x):
        index = i + self.N/2
        self.Data[index] = x
        while index > 0:
            index= int((index-1)/2)
            self.Data[index] = min(self.Data[2*index + 1],self.Data[2*index+2])
    
    def query(self, a, b, k = 0, l = 0, r = None):
        if r is None:
            r = int(self.N+1)/2
        if (r <=a or b <= l):
            return self.INFINITY
        if (a <= l and r <= b):
            return self.Data[k]
        else:
            vl = self.query(a,b,k*2+1,l,int((l+r)/2))
            vr = self.query(a,b,k*2+2,int((l+r)/2),r)
            return min([vl,vr])
    
    def add(self,x):
        self.Data += x 

    def get(self,i):
        return self.Data[i + int(self.N/2)]
    
    def getData(self):
        return self.Data[int(self.N/2):]

N, Q, A, B =map(int, input().split())
X = list(map(int, input().split()))

DP_minusj = SegmentTree(N+1)
DP_plusj = SegmentTree(N+1)

DP_minusj.update(A,0 - A)
DP_plusj.update(A,0 + A)

beforeX = B

for i in range(Q):
    min_minus = DP_minusj.query(1, X[i]+1) + X[i]
    min_plus = DP_plusj.query(X[i]+1, N+1) - X[i]
    DP_minusj.add(abs(X[i] - beforeX))
    DP_plusj.add(abs(X[i] - beforeX))
    newDP_Xij =  min(min_minus, min_plus)
    DP_minusj.update(beforeX,newDP_Xij - beforeX)
    DP_plusj.update(beforeX,newDP_Xij + beforeX)
    beforeX = X[i] 
print(int(min(DP_minusj.getData()[:N+1] + np.arange(N+1))))