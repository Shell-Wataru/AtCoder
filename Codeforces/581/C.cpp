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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    // 整数の入力
    ll n, k;
    cin >> n;
    vector<vector<ll>> G;
    vector<int> P;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<ll> row;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
            {
                row.push_back(100000000);
            }
            else
            {
                row.push_back(1);
            }
        }
        G.push_back(row);
    }

    warshall_floyd(n, G);

    for(int i = 0;i<n;i++){
        G[i][i] = 0;
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int p;
        scanf("%d",&p);
        P.push_back(p - 1);
    }

    vector<ll> ans;
    ll current = P[0];
    ll distance = 0;
    ans.push_back(current);
    for (int i = 1; i < k - 1; i++)
    {
        distance++;
        if (G[current][P[i + 1]] < distance + 1)
        {
            current = P[i];
            ans.push_back(current);
            distance = 0;
        }
    }

    ans.push_back(P[k - 1]);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
        {
            cout << ans[i] + 1;
        }
        else
        {
            cout << " " << ans[i] + 1;
        }
    }
    cout << endl;
    return 0;
}
