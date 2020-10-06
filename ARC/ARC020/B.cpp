#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    string S;
    ll diff_counts = 0;
    cin >> S;
    for(int i = 0;i < S.length()/2;i++){
        if (S[i] != S[S.length()- 1 - i]){
            diff_counts++;
        }
    }
    if (diff_counts == 0){
        if (S.length() % 2 == 0){
            cout << 25 * S.length() << endl;
        }else{
            cout << 25 * (S.length() - 1) << endl;
        }
    }else if (diff_counts == 1){
        cout << 25 * S.length() - 2 << endl;
    }else{
        cout << 25 * S.length() << endl;
    }
    return 0;
}