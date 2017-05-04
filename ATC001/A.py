# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np
import itertools

H, W = map(int, raw_input().split())

CITYMAP = []
ISREACHABLEMAP = np.zeros((H, W))

for i in range(H):
    CITYMAP.append(raw_input())

print CITYMAP[0][0]
for i, j in itertools.product(range(H), range(W)):
    if CITYMAP[i][j] == "s":
        startY = i
        startX = j
    if CITYMAP[i][j] == "g":
        goalY = i
        goalX = j

print len(CITYMAP)

def isReachable(x, y):
    if ISREACHABLEMAP[i][j] == 1:
        return True
    else if ISREACHABLEMAP[i][j] == 1:
        return False
    else:
        
def checkNeighbors(x, y):


