#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator>  // std::rbegin, std::rend


using namespace std;
using ll = long long;


int main()
{
    // 整数の入力
    ll n;
    cin >> n;
    if (n % 2 == 0){
        cout << n + 4 << " " << 4 << endl;
    }else{
        cout << n + 9 << " " << 9 << endl;
    }
    return 0;
}