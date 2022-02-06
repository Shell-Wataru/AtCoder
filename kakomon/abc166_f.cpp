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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    vector<ll> counts(3);
    cin >> N >> counts[0] >> counts[1] >> counts[2];
    vector<string> queries(N);
    bool can_make = true;
    for(int i = 0;i < N;i++){
        cin >> queries[i];
    }
    vector<char> answers;
    for(int i = 0;i < N;i++){
        // cout << counts[0] << " " << counts[1] << " " << counts[2] << endl;
        if (counts[queries[i][0]-'A'] == 0 && counts[queries[i][1]-'A'] == 0){
            cout << "No" << endl;
            return 0;
        }else if (counts[queries[i][0]-'A'] > counts[queries[i][1]-'A']){
            answers.push_back(queries[i][1]);
            counts[queries[i][0]-'A']--;
            counts[queries[i][1]-'A']++;
        }else if (counts[queries[i][0]-'A'] < counts[queries[i][1]-'A']){
            answers.push_back(queries[i][0]);
            counts[queries[i][0]-'A']++;
            counts[queries[i][1]-'A']--;
        }else{
            if (i == N-1 || queries[i] == queries[i+1]){
                answers.push_back(queries[i][1]);
                counts[queries[i][0]-'A']--;
                counts[queries[i][1]-'A']++;
            }else{
                if (queries[i] == "AB" && queries[i+1] == "AC"){
                    answers.push_back('A');
                    counts['A'-'A']++;
                    counts['B'-'A']--;
                }else if (queries[i] == "AB" && queries[i+1] == "BC"){
                    answers.push_back('B');
                    counts['B'-'A']++;
                    counts['A'-'A']--;
                }else if (queries[i] == "AC" && queries[i+1] == "AB"){
                    answers.push_back('A');
                    counts['A'-'A']++;
                    counts['C'-'A']--;
                }else if (queries[i] == "AC" && queries[i+1] == "BC"){
                    answers.push_back('C');
                    counts['C'-'A']++;
                    counts['A'-'A']--;
                }else if (queries[i] == "BC" && queries[i+1] == "AB"){
                    answers.push_back('B');
                    counts['B'-'A']++;
                    counts['C'-'A']--;
                }else if (queries[i] == "BC" && queries[i+1] == "AC"){
                    answers.push_back('C');
                    counts['C'-'A']++;
                    counts['B'-'A']--;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for(auto c:answers){
        cout << c << "\n";
    }
    cout << flush;
    return 0;
}