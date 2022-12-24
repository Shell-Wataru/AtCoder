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
    reverse(S.begin(),S.end());
    if (S.substr(0,2) == "re"){
        cout << "er" << endl;
    }else{
        cout << "ist" << endl;
    }
    return 0;
}