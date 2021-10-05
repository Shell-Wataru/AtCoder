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
    for(int i = 1;i < S.size();i++){
        if (S[i] == S[i-1]){
            cout << i << " " << i+ 1<< endl;
            return 0;
        }
    }

    for(int i = 2;i < S.size();i++){
        if (S[i] == S[i-2]){
            cout << i -1 << " " << i+ 1<< endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}