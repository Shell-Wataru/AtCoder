#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
int Solve(string S,string shortCut1,string shortCut2){
    ll commandCount,commandCountBefore,countTemp,i;
    commandCount = 1;
    commandCountBefore = 0;
    for (i = 1;i< S.length();i++){
        if (S.substr(i-1,2) == shortCut1 || S.substr(i-1,2) == shortCut2) {
            countTemp = commandCount;
            commandCount = commandCountBefore + 1;
            commandCountBefore = countTemp;
        }else{
            commandCountBefore = commandCount;
            commandCount++;
        }
    }
    return commandCount;
}

int main()
{
    // 整数の入力
    ll N,i,j,minActionCount;
    string S;
    cin >> N;
    cin >> S;
    minActionCount = N;
    string commands[16] = {"AA","AB","AX","AY",
                           "BA","BB","BX","BY",
                           "XA","XB","XX","XY",
                           "YA","YB","YX","YY",};
    for (i = 0;i<16;i++){
        for(j = 0;j<16;j++){
            ll temp =  Solve(S,commands[i],commands[j]);
            if (temp < minActionCount){
                minActionCount = temp;
            }
        }
    }

    cout << minActionCount << endl;
    return 0;
}