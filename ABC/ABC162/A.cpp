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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    if (S[0] == '7' || S[1] == '7' || S[2] == '7'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   return 0;
}