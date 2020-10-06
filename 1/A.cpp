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
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <cctype>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S, T;
    cin >> S >> T;
    string upperS = S;
    string upperT = T;
    transform(upperS.begin(), upperS.end(), upperS.begin(), [](unsigned char c){ return tolower(c);});
    transform(upperT.begin(), upperT.end(), upperT.begin(), [](unsigned char c){ return tolower(c);});
    if (S == T)
    {
        cout << "same" << endl;
    }
    else if (upperS == upperT)
    {
        cout << "case-insensitive" << endl;
    }
    else
    {
        cout << "different" << endl;
    }
    return 0;
}