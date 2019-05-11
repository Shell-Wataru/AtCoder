#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

int A[300][300] = {0};
set<int> removedSet;

int main()
{
    // 整数の入力
    string S;
    long long w,i;
    cin >> S;
    cin >> w;
    i = 0;
    while (i < S.length()){
        cout << S[i];
        i += w;
    }
    cout << endl;
    return 0;
}