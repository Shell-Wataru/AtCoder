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
    ll N,a,positives,negatives,current_posi,current_nega;
    cin >> N;
    cin >> a;
    current_posi = 0;
    current_nega = 0;
    if (a > 0){
        current_posi++;
    }else
    {
        current_nega++;
    }
    positives = current_posi;
    negatives = current_nega;


    for (int i = 0; i < N-1; i++)
    {
        cin >> a;
        if (a > 0){
            current_posi = current_posi + 1;
            current_nega = current_nega;
        }else
        {
            ll tmp_posi = current_posi;
            current_posi = current_nega;
            current_nega = tmp_posi + 1;
        }

        // cout << "p:" <<current_posi << endl;
        // cout << "n:" <<current_nega << endl;

        positives += current_posi;
        negatives += current_nega;
    }

    cout << negatives << " " << positives << endl;
    return 0;
}