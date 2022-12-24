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
    set<ll> ss = {
        0,1,2,3,4,5,6,7,8,9
    };
    string S;
    cin >> S;
    for(auto c:S){
        ss.erase(c - '0');
    }
    cout << *ss.begin() << endl;
    return 0;
}