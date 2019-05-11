#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
    // 整数の入力
    char broken;
    string s;
    long long c = 0;
    cin >> broken;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != broken){
            cout << s[i];
        }
    }
    cout << endl;
   return 0;
}