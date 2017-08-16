#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    long long total,i;
    total = 0;

    for (i=0;i< S.length();i++){
        if (S[i] == 'U'){
            total += S.length() - 1 - i + 2 * (i);
        } else{
            total +=  2 *(S.length ()- 1 - i) + i;
        }
    }
    cout << total << endl;
    return 0;
}