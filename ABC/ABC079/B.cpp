#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,i;
    vector<long long> data;
    cin >> N;
    data.push_back(2);
    data.push_back(1);
    for (i=0;i<85;i++){
        data.push_back(data[data.size() -1] + data[data.size() -2]);
    }
    cout << data[N] << endl;

    return 0;
}