#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long  N,M;
    double meanTime,p;
    p = 1-1.0/(1<<M);
    meanTime = p/(1-p);
    cin >> N >> M;
    cout << ((N - M) * 100 + 1900 * M) * (1<<M) << endl;

    return 0;
}