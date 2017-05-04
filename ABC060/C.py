# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np
import itertools

N, T = map(int, raw_input().split())
Timings = map(int, raw_input().split())

TotalTime = 0
beforeTime = 0
for i in range(N):
    if (Timings[i] - beforeTime) > T or i == 0:
        TotalTime += T
    else:
        TotalTime += Timings[i] - beforeTime
    beforeTime = Timings[i]

print TotalTime