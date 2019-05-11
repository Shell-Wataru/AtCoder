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
    long long  A,B,C,S;
    cin >> A >> B >> C >> S;
    if (A + B + C <= S && S <= A + B + C + 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}