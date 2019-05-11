#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,i,j,k,minValue,total;
    set<long long>data;
    string s;
    cin >> N;
    total = 0;
    minValue = 0;
    for (i= 0;i< N ;i++){
        cin >> k;
        total += k;
        minValue += abs(k);
        vector<long long> tempValues;
        tempValues.push_back(k);
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (!(i == N-1 && *it != total)) tempValues.push_back(*it + k);
        }

        for (j = 0;j < tempValues.size();j++){
            data.insert(tempValues[j]);
        }
    }
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (minValue > abs(total - 2 * (*it))) minValue = abs(total - 2 * (*it));
    }
    cout << minValue << endl;
    return 0;
}