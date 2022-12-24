#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

class MatchingPatterns
{
public:
    string solve(int N, vector<int> L, vector<string> Patterns)
    {
        ll M = Patterns.size();
        ll total_length = -1;
        for (int i = 0; i < M; i++)
        {
            ll length = 0;
            for (auto c : Patterns[i])
            {
                if (c - 'a' < 0)
                {

                    length += L[c - 'A'];
                }
                else
                {
                    length++;
                }
            }
            if (total_length == -1 || total_length == length)
            {
                total_length = length;
            }
            else
            {
                return "";
            }
        }
        vector<string> real_variables(N);
        for (int i = 0; i < N; i++)
        {
            real_variables[i] = string(L[i], '*');
        }
        string answer(total_length, '*');
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < M; i++)
            {
                ll current_index = 0;
                for (auto c : Patterns[i])
                {
                    if (c - 'a' < 0)
                    {
                        for (int j = 0; j < L[c - 'A']; j++)
                        {
                            if (answer[current_index + j] == '*')
                            {
                                if (real_variables[c - 'A'][j] == '*')
                                {
                                }
                                else
                                {
                                    answer[current_index + j] = real_variables[c - 'A'][j];
                                }
                            }
                            else
                            {
                                if (real_variables[c - 'A'][j] == '*')
                                {
                                    real_variables[c - 'A'][j] = answer[current_index + j];
                                }
                                else if (answer[current_index + j] == real_variables[c - 'A'][j])
                                {
                                }
                                else
                                {
                                    return "";
                                }
                            }
                        }
                        current_index += L[c - 'A'];
                    }
                    else
                    {
                        if (answer[current_index] == '*' || answer[current_index] == c)
                        {
                            answer[current_index] = c;
                        }
                        else
                        {
                            return "";
                        }
                        current_index++;
                    }
                }
            }
        }
        // cout << total_length << endl;
        for(int i = 0;i < total_length;i++){
            if (answer[i] == '*'){
                answer[i] = 'x';
            }
        }
        return answer;
    }

};

// int main()
// {
//     MatchingPatterns m;
//     cout << m.solve(1,{2},{"AAA"}) << endl;
//     cout << m.solve(3,{2,3,2},{"ABxA","yCCB"}) << endl;
//     cout << m.solve(3,{4,5,6},{"A","B","C"}) << endl;
//     cout << m.solve(4,{1,2,3,4},{"ABCD","DxAyzB"}) << endl;
//     // cout << m.count("aaaa",13) << endl;
//     // cout << m.count("dogecoin",17) << endl;
//     // cout << m.count("decode",11) << endl;
//     return 0;
// }