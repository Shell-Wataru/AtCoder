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
    ll y = S.back() - '0';
    string x = S.substr(0,S.size()-2);
    if (0 <= y && y <= 2){
        cout << x << "-" << endl;
    }else if (3 <= y && y <= 6){
        cout << x  << endl;
    }else{
        cout << x << "+" << endl;
    }
    return 0;
}