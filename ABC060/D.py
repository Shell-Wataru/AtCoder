# coding: utf-8
# 整数の入力
#a = int(raw_input())
# スペース区切りの整数の入力
import numpy as np

N, MaxTotalWeight = map(int, raw_input().split())

def getWeightValuePair(W,Values,WeightValuePair):
    totalValue = 0
    WeightKeys = WeightValuePair.keys()
    WeightValuePairCopy = WeightValuePair.copy()
    for i in xrange(len(Values)):
        totalValue += Values[i]
        for totalWeight in WeightKeys:
            if (totalWeight + W * (i+1)) <= MaxTotalWeight:
                if (totalWeight + W * (i+1)) not in WeightValuePair:
                    WeightValuePair[totalWeight + W * (i+1)] = WeightValuePairCopy[totalWeight] +  totalValue
                elif WeightValuePairCopy[totalWeight] +  totalValue > WeightValuePairCopy[totalWeight + W * (i+1)]:
                    WeightValuePair[totalWeight + W * (i+1)] = WeightValuePairCopy[totalWeight] +  totalValue
    return WeightValuePair

Weights = []
WeightsValues = []

for i in xrange(N):
    tempData = map(int, raw_input().split())
    if i == 0:
        Weights.append(tempData[0])
        Weights.append(tempData[0]+1)
        Weights.append(tempData[0]+2)
        Weights.append(tempData[0]+3)
        WeightsValues.append([tempData[1]])
        WeightsValues.append([])
        WeightsValues.append([])
        WeightsValues.append([])
    else:
        WeightsValues[tempData[0] - Weights[0]].append(tempData[1])

for data in WeightsValues:
    data.sort(reverse=True)

returnWeightValuePair = {0:0}
for i in range(4):
    returnWeightValuePair = getWeightValuePair(Weights[i],WeightsValues[i],returnWeightValuePair)

print max(returnWeightValuePair.values())