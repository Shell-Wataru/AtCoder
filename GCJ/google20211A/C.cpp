#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

struct compass_neighbor
{
    ll x, y, value;
};

string solve()
{
    ll N,Q;
    cin >> Q >> N;
    vector<string> Exam(Q);
    vector<ll> Score(Q);
    vector<ll> possibleAnswers;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> Exam[i];
        cin >> Score[i];
    }

    string answer = "";
    ll max_score = 0;
    for(int i = 0;i < Q;i++){
        // cout << Score[i] << endl;
        ll score = max(Score[i],N- Score[i]);
        if (score > max_score){
            max_score = score;
            if (Score[i] >= N- Score[i]){
                answer = Exam[i];
            }else{
                answer = "";
                for(int j = 0;j < N;j++){
                    if (Exam[i][j] == 'T'){
                        answer += 'F';
                    }else{
                        answer += 'T';
                    }
                }
            }
        }
    }

    return answer + " " + to_string(max_score) + "/1";
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}