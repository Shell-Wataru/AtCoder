#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    if (n == 3)
    {
        cout << "2 3 25" << endl;
    }
    else if (n == 4)
    {
        cout << "2 3 6 55" << endl;
    }
    else if (n == 5)
    {
        cout << "2 3 6 8 95" << endl;
    }
    else
    {
        vector<ll> answers;
        ll total = 0;
        for (int i = 2; i <= 30000; i++)
        {
            if (answers.size() == n)
            {
                break;
            }
            if (i % 2 == 0 || i % 3 == 0)
            {
                total += i;
                answers.push_back(i);
            }
        }
        ll removed = -1;
        if (total % 6 == 0){
            for(int i = 0;i < n;i++){
                if (i!= 0){
                    cout << " ";
                }
                cout << answers[i];
            }
            cout << endl;
        }else{
            for (auto a : answers)
            {
                ll t = total - a;
                for (int i = 5; i <= 1000; i++)
                {

                    if (gcd(i, t) != 1 && (t + i) % 6 == 0 && i % 2 != 0 && i % 3 != 0)
                    {
                        bool space = false;
                        for (int j = 0;j < n;j++)
                        {
                            if (a != answers[j])
                            {
                                if (space){
                                    cout << " " ;
                                }
                                space = true;
                                cout << answers[j];
                            }
                        }
                        cout << " " << i;
                        cout << endl;
                        return 0;
                    }
                }
            }
        }

    }

    return 0;
}
