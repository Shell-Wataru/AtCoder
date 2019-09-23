#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    string S;
    ll N, K;
    cin >> N;
    cin >> K;
    cin >> S;
    if (N == 1)
    {
        if (K > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << S << endl;
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (K == 0)
            {
                cout << S[i];
            }
            else
            {
                if (i == 0)
                {
                    if (S[i] == '1'){
                        cout << 1;
                    }else{
                        cout << 1;
                        K--;
                    }
                }else{
                    if (S[i] == '0'){
                        cout << 0;
                    }else{
                        cout << 0;
                        K--;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}