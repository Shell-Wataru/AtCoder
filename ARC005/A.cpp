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
    long long N, counter;
    counter = 0;
    string A = "TAKAHASHIKUN";
    string B = "Takahashikun";
    string C = "takahashikun";
    string temp;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> temp;
        if (temp == A || temp == B || temp == C)
        {
            counter++;
        }
    }
    cin >> temp;
    if (temp == (A + ".") || temp == (B + ".") || temp == (C + "."))
    {
        counter++;
    }

    cout << counter << endl;
    return 0;
}