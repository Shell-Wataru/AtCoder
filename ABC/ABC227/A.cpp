#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,K,A;
    cin >> N >> K >> A;
    K--;
    A--;
    cout << (K+A) % N + 1 << endl;
    return 0;
}