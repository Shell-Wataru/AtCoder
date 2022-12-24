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
    vector<string> days = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
    };
    for(int i = 0; i < days.size();i++){
        if (S == days[i]){
            cout << 5 - i << endl;
            return 0;
        }
    }

    return 0;
}