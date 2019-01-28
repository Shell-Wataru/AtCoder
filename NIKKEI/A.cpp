#include<iostream>
#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long  N,A,B;
    cin >> N >> A >> B;
    cout << min(A,B) << " " << max(A + B - N, 0LL) << endl;
    return 0;
}