#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    string S,cursor,last;
    ll K = 0;
    cin >> S;
    cursor = "";
    last = "";
    for(int i = 0;i<S.size();i++){
        cursor.push_back(S[i]);
        if (last != cursor){
            K++;
            last = cursor;
            cursor = "";
        }
    }

    cout << K << endl;
    return 0;
}