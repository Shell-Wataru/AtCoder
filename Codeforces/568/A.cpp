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
    long long A,B,C,d;
    vector<ll> data;
    cin >> A >> B >> C >> d;
    data.push_back(A);
    data.push_back(B);
    data.push_back(C);
    sort(data.begin(),data.end());
    ll total = 0;

    total += max(0LL,d -(data[1]-data[0]));
    total += max(0LL,d -(data[2]-data[1]));

    cout << total << endl;
    return 0;
}