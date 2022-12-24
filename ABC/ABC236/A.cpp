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
    string S;
    cin >> S;
    ll a,b;
    cin >> a >> b;
    a--;b--;
    swap(S[a],S[b]);
    cout << S << endl;
    return 0;
}