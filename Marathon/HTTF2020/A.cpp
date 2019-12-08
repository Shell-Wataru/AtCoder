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
ll BASE_NUM = 1000000007;

struct robot
{
    ll y, x;
    char direction;
    bool cleared;
};

ll c_score(vector<vector<ll>> &RobotMoves)
{
    ll value = 0;
    for (auto v : RobotMoves)
    {
        for (auto c : v)
        {
            if (c > 0)
            {
                value++;
            }
        }
    }
    return value;
}

set<tuple<ll, ll, char>> move_robot(ll N, robot &r, vector<vector<char>> &CurrentSituation)
{
    char current_direction = r.direction;
    ll current_x = r.x;
    ll current_y = r.y;
    set<tuple<ll, ll, char>> s;
    while (CurrentSituation[current_y][current_x] != 'G' && CurrentSituation[current_y][current_x] != 'B')
    {
        if (CurrentSituation[current_y][current_x] != '-')
        {
            current_direction = CurrentSituation[current_y][current_x];
        }
        tuple<ll, ll, char> current_r{current_x, current_y, current_direction};
        if (s.find(current_r) != s.end())
        {
            break;
        }
        s.insert(current_r);
        if (current_direction == 'D')
        {
            current_y = (current_y + 1) % N;
        }

        if (current_direction == 'U')
        {
            current_y = (current_y + N - 1) % N;
        }

        if (current_direction == 'R')
        {
            current_x = (current_x + 1) % N;
        }

        if (current_direction == 'L')
        {
            current_x = (current_x + N - 1) % N;
        }
    }

    if (CurrentSituation[current_y][current_x] == 'G')
    {
        tuple<ll, ll, char> current_r{current_x, current_y, current_direction};
        s.insert(current_r);
        r.cleared = true;
    }
    return s;
}
tuple<ll, ll, char> candidates_next(ll N,ll x,ll y,char direction){
    if (direction == 'U'){
        return {x,(y+1LL) % N,direction};
    }else if (direction == 'D'){
        return {x,(y+N-1LL) % N,direction};
    }else if(direction == 'L'){
        return {(x+1LL) % N,y,direction};
    }else{
        return {(x+N-1LL) % N,y,direction};
    }
}
void SubSetDirectionCandidates(ll N, vector<vector<char>> &CurrentSituation, set<tuple<ll, ll, char>> &new_candidates,set<tuple<ll, ll, char>> &checked, tuple<ll, ll, char> new_candidate)
{
    if (checked.find(new_candidate) != checked.end()){
        return;
    }
    ll x = get<0>(new_candidate);
    ll y = get<1>(new_candidate);
    char direction = get<2>(new_candidate);
    // cout << x  << ","<< y << "," << direction << endl;

    char current = CurrentSituation[y][x];
    if (current == 'B' || current == 'G'){
        return;
    }

    checked.insert(new_candidate);
    if (current == '-'){
        new_candidates.insert(new_candidate);
        SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, candidates_next(N,x,y,direction));
    }else{
        SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, candidates_next(N,x,y,'U'));
        SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, candidates_next(N,x,y,'D'));
        SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, candidates_next(N,x,y,'R'));
        SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, candidates_next(N,x,y,'L'));
    }
    return;
}

void SetDirectionCandidates(ll N, vector<vector<char>> &CurrentSituation, set<tuple<ll, ll, char>> &new_candidates, ll x, ll y)
{
    set<tuple<ll, ll, char>> checked;
    SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, {(x + 1LL) % N, y, 'R'});
    SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, {(x + N - 1LL) % N, y, 'L'});
    SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, {x, (y + 1LL) % N, 'U'});
    SubSetDirectionCandidates(N, CurrentSituation, new_candidates,checked, {x, (y + N -1LL) % N, 'D'});
}


void showCurrentSituation(vector<vector<char>> &CurrentSituation)
{
    for (auto v : CurrentSituation)
    {
        for (auto c : v)
        {
            cout << c;
        }
        cout << endl;
    }
}

void showRobotMoves(vector<vector<ll>> &RobotMoves)
{
    for (auto v : RobotMoves)
    {
        for (auto c : v)
        {
            cout << c;
        }
        cout << endl;
    }
}

ll score(ll N, ll gx, ll gy, vector<vector<char>> &CurrentSituation, vector<robot> &Robots, ll directions)
{
    // cout << "a" << endl;
    vector<vector<ll>> RobotMoves(N, vector<ll>(N, 0));
    for (auto r : Robots)
    {
        set<tuple<ll, ll, char>> orbit = move_robot(N, r, CurrentSituation);
        set<pair<ll, ll>> positions;
        for (auto r : orbit)
        {
            positions.insert(make_pair(get<0>(r), get<1>(r)));
        }
        for (auto p : positions)
        {
            RobotMoves[p.second][p.first]++;
        }
    }
    // cout << "b" << endl;

    // showCurrentSituation(CurrentSituation);
    // showRobotMoves(RobotMoves);
    set<tuple<ll, ll, char>> new_candidates;
    SetDirectionCandidates(N,CurrentSituation,new_candidates,gx,gy);
    // cout << "c" << endl;

    // ll current_score = 1000 * RobotMoves[gy][gx] - 10 * directions + c_score(RobotMoves) +  new_candidates.size();
    ll current_score = 1000 * RobotMoves[gy][gx] - 10 * directions + c_score(RobotMoves) +  new_candidates.size();
    return current_score;
}

ll find_best(ll N, ll gx, ll gy, vector<vector<char>> &CurrentSituation, vector<robot> &Robots,set<tuple<ll, ll, char>> &directions){
    ll max_score = score(N, gx, gy, CurrentSituation, Robots, directions.size());
    set<tuple<ll, ll, char>> new_candidates;
    SetDirectionCandidates(N,CurrentSituation,new_candidates,gx,gy);
    tuple<ll, ll, char> max_candidate;
    bool changed=false;
    cout << new_candidates.size() << endl;
    for(auto new_candidate: new_candidates){
        ll x = get<0>(new_candidate);
        ll y = get<1>(new_candidate);
        char direction = get<2>(new_candidate);
        // cout << x << " "<< y << " "<< direction<< endl;

        CurrentSituation[y][x] = direction;
        ll new_score = score(N, gx, gy, CurrentSituation, Robots, directions.size()+1);
        if (new_score > max_score){
            max_score = new_score;
            max_candidate = new_candidate;
            changed = true;
        }
        CurrentSituation[y][x] = '-';
    }

    if (changed){
        cout << "changed" << max_score << " d" << directions.size() << endl;
        ll x = get<0>(max_candidate);
        ll y = get<1>(max_candidate);
        char direction = get<2>(max_candidate);
        CurrentSituation[y][x] = direction;
        directions.insert(max_candidate);
        if (directions.size() == 80 ){
            showCurrentSituation(CurrentSituation);
            return max_score;
        }else{
            return find_best(N,gx,gy,CurrentSituation,Robots,directions);
        }
    }else{
        return max_score;
    }
}

int main()
{
    ll N, M, B;
    ll gy, gx;
    cin >> N >> M >> B;
    cin >> gy >> gx;
    vector<vector<char>> CurrentSituation(N, vector<char>(N, '-'));
    vector<robot> Robots;

    for (int i = 0; i < M; i++)
    {
        robot r;
        cin >> r.y >> r.x >> r.direction;
        r.cleared = false;
        Robots.push_back(r);
        // CurrentSituation[r.y][r.x] = r.direction;
    }

    for (int i = 0; i < B; i++)
    {
        ll x, y;
        cin >> y >> x;
        CurrentSituation[y][x] = 'B';
    }
    CurrentSituation[gy][gx] = 'G';

    set<tuple<ll, ll, char>> directions;
    find_best(N,gx,gy,CurrentSituation,Robots,directions);
    return 0;
}
