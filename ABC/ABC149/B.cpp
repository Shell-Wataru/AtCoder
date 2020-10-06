#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll A,B,K;
    cin >> A >> B >> K;
    ll remainA = max(0LL,A-K);
    K = max(0LL,K - A);
    ll remainB = max(0LL,B-K);

    cout << remainA << " " << remainB << endl;
    return 0;
}