#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
int main()
{
    // 整数の入力
    long long A,B;
    cin >> A;
    cin >> B;
    cout << A - (A % B) << endl;
    return 0;
}