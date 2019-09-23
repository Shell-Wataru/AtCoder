#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main()
{
    // 整数の入力
    int N, I;
    map<int, int> unique_k;
    vector<pair<int, int>> data;
    vector<ll> Test;
    int a;
    cin >> N >> I;
    for (int i = 0; i < N; i++)
    {
        // fastscan(a);
        scanf("%d",&a);
        unique_k[a] = 1;
    }

    // for (auto &p : unique_k)
    // {
    //     data.push_back(p);
    // }

    // int use_bit = 8 * I / N;
    // cout << use_bit << endl;
    // cout << bit(unique_k.size()) << endl;
    // if (bit(unique_k.size()) <= use_bit)
    // {
    //     cout << "uora" << endl;
    //     cout << 0 << endl;
    //     return 0;
    // }
    // else
    // {

    //     int must_removes = unique_k.size() - (1 << use_bit);
    //     vector<int> lower_side(must_removes + 1), upper_side(must_removes + 1);
    //     lower_side[0] = 0;
    //     int size = data.size();
    //     for (int i = 1; i <= must_removes; i++)
    //     {
    //         lower_side[i] = data[i-1].second + lower_side[i-1];
    //     }

    //     upper_side[0] = 0;
    //     for (int i = 1; i <= must_removes; i++)
    //     {
    //         upper_side[i] = data[size - i].second + upper_side[i-1];
    //     }

    //     int min_changes = N;
    //     for (int i = 0; i <= must_removes; i++)
    //     {
    //         if (lower_side[i] + upper_side[must_removes - i] < min_changes)
    //         {
    //             min_changes = lower_side[i] + upper_side[must_removes - i];
    //         }
    //     }

    //     cout << min_changes << endl;
    // }

    return 0;
}

int bit(int k)
{
    int i = 0;
    while (k > (1 << i))
    {
        i++;
    }
    return i;

}