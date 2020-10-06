#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

string B, P;
vector<long long> bs;
long long min_items[10];
long long BASE_NUM = 1000000007;

ll push_count(vector<vector<ll>> &numbers)
{
    if (numbers.size() == 0){
        return BASE_NUM;
    }

    ll total = numbers.size() - 1;
    for (auto n : numbers)
    {
        total += n.size();
    }
    return total;
}
int main()
{
    // 整数の入力
    cin >> B >> P;
    vector<ll> numbers;
    vector<vector<ll>> min_use_numbers(100);
    map<ll, vector<vector<ll>>> results;
    for (auto c : B)
    {
        numbers.push_back(c - '0');
        if (c != '0'){
            min_use_numbers[c - '0'].push_back(c - '0');
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (auto n : numbers)
        {
            if (i - n > 0)
            {
                if (min_use_numbers[i - n].size() > 0)
                {
                    if (min_use_numbers[i].size() == 0 || min_use_numbers[i - n].size() + 1 < min_use_numbers[i].size())
                    {
                        min_use_numbers[i] = vector<ll>(min_use_numbers[i - n]);
                        min_use_numbers[i].push_back(n);
                    }
                }
            }
        }
    }
    // for (int i = 0; i < 100; i++)
    // {
    //     for (auto n : min_use_numbers[i])
    //     {
    //         cout << n << ",";
    //     }
    //     cout << endl;
    // }

    ll total = 0;
    for (ll i = 0; i < P.size(); i++)
    {
        ll current = P[i] - '0';
        total = total * 10 + current;
        // cout << "===total:" <<total <<endl;
        for (ll j = 0; j <= 10; j++)
        {
            ll target = total - j;
            if (target >= 0)
            {
                // cout << "target" << target << endl;
                vector<vector<ll>> min_combination;
                for (ll k = 0; k < 10; k++)
                {
                    ll add_num = 10 * k + (target % 10);
                    ll base_num = (target - add_num)/10;
                    if (base_num < 0){
                        continue;
                    }
                    // cout << add_num << "," << base_num << endl;
                    vector<vector<ll>> base = results[base_num];
                    vector<ll> use_num = min_use_numbers[add_num];
                    for (ll l = 0; l < max(use_num.size(), base.size()); l++)
                    {
                        if (l >= base.size())
                        {
                            base.push_back(vector<ll>());
                        }

                        ll new_num;
                        if (l >= use_num.size())
                        {
                            new_num = 0;
                        }
                        else
                        {
                            new_num = use_num[l];
                        }
                        base[l].push_back(new_num);
                    }

                    if (push_count(base) < push_count(min_combination)){
                        // cout << "update" << endl;
                        // cout << base_num << endl;
                        min_combination = base;
                    }
                }
                // cout << "min_combination_size" << min_combination.size() << endl;
                results[target] = min_combination;
            }
        }
        // cout << total << endl;
    }

    // cout << "size" << results[total].size() << endl;
    for(int i = 0;i< results[total].size();i++){
        if (i != 0){
            cout << "+";
        }
        for(auto n:results[total][i]){
            cout << n;
        }
    }
    if (results[total].size() > 1){
        cout << "=";
    }
    cout << endl;
    return 0;
}