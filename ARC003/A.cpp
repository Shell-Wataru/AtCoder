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
    long long N,i,total;
    string S;
    cin >> N;
    cin >> S;
    total = 0;

    for (i= 0;i<N;i++){
        if (S[i] != 'F'){
            total += 'F' - S[i] - 1;
        }
    }
    cout << fixed << setprecision(14) << total*1.0/N << endl;
    return 0;
}