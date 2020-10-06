#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

bool can_make(vector<ll> &A, ll k_index)
{
    set<ll> left_candidates;
    vector<ll> lefts;
    for (int i = k_index - 1; i >= 0; i--)
    {
        if (A[i] == 0)
        {
            lefts.push_back(A[i]);
        }
        else if (lefts.size() == 0)
        {
            lefts.push_back(A[i]);
        }else if (A[i] == -1)
        {
            if (lefts.back() == 1)
            {
                lefts.pop_back();
            }
            else
            {
                lefts.push_back(A[i]);
            }
        }
        else
        {
            if (lefts.back() == -1)
            {
                lefts.pop_back();
            }
            else
            {
                lefts.push_back(A[i]);
            }
        }
        if (lefts.size() > 0)
        {
            left_candidates.insert(lefts.front());
            if (lefts.back() == 0)
            {
                break;
            }
        }
    }

    set<ll> right_candidates;
    vector<ll> rights;
    for (int i = k_index + 1; i < A.size(); i++)
    {
        // cout << A[i] << endl;
        if (A[i] == 0)
        {
            rights.push_back(A[i]);
        }
        else if (rights.size() == 0)
        {
            rights.push_back(A[i]);
        }else if (A[i] == -1)
        {
            if (rights.back() == 1)
            {
                rights.pop_back();
            }
            else
            {
                rights.push_back(A[i]);
            }
        }
        else
        {
            if (rights.back() == -1)
            {
                rights.pop_back();
            }
            else
            {
                rights.push_back(A[i]);
            }
        }
        for(auto r:rights){
            cout << r << ",";
        }
        cout << endl;
        if (rights.size() > 0)
        {
            right_candidates.insert(rights.front());
            if (rights.back() == 0)
            {
                break;
            }
        }
    }
    // cout << rights.size() << endl;
    for(auto r:rights){
        cout << r << ",";
    }
    cout << endl;
    // cout << lefts.size() << endl;
    if (left_candidates.find(0) != left_candidates.end() ||
        left_candidates.find(1) != left_candidates.end() ||
        (lefts.size() == 2 && lefts.back() == 0) ||
        right_candidates.find(0) != right_candidates.end() ||
        right_candidates.find(1) != right_candidates.end() ||
        (rights.size() == 2 && rights.back() == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a < k)
        {
            A[i] = -1;
        }
        else if (a > k)
        {
            A[i] = 1;
        }
        else
        {
            A[i] = 0;
        }
    }
    bool can = false;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            can = can || can_make(A, i);
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (A[i] == 0 && A[i - 2] == 0)
        {
            can = true;
        }
    }

    for (int i = 3; i < n; i++)
    {
        if (A[i] == 0 && A[i - 1] == 1 && A[i - 2] == 1 && A[i - 3] == 0)
        {
            can = true;
        }
    }
    if (n == 1 && A[0] == 0)
    {
        cout << "yes" << endl;
    }
    else if (can)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
