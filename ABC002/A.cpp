#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    ll X,Y;
    cin >> X >> Y;
    if (X < Y){
        cout << Y << endl;
    }else{
        cout << X << endl;
    }

    return 0;
}