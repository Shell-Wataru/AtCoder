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
    long long N;
    cin >> N;
    if (N % 4 == 0){
        cout << "1 A" << endl;
    }else if (N % 4 == 1){
        cout << "0 A" << endl;
    }else if (N % 4 == 2){
        cout << "1 B" << endl;
    }else if (N % 4 == 3){
        cout << "2 A" << endl;
    }
    return 0;
}