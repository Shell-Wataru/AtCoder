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
    long long Y;
    cin >> Y;
    if (Y % 400 == 0){
        cout << "YES" << endl;
    }else if (Y % 100 == 0){
        cout << "NO" << endl;
    }else if( Y % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}