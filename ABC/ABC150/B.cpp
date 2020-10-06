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
    ll N;
    string S;
    cin >> N>> S;
    ll count = 0;
    for(int i = 2;i< N;i++){
        if (S[i-2] == 'A' && S[i-1] == 'B' && S[i] == 'C'){
            count++;
        }
    }

    cout << count << endl;
    return 0;
}