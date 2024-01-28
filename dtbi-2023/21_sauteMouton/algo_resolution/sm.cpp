
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool IsValidMove(const string& current, const string& next) {
    int diff_count = 0, last_diff = -1;
    for (int i = 0; i < current.size(); ++i) {
        if (current[i] != next[i]) {
            diff_count++;
            if (last_diff == -1) last_diff = i;
            else if (abs(i - last_diff) > 2) return false;
        }
    }
    return diff_count == 2;
}

vector<string> GetNextStates(const string& state) {
    vector<string> next_states;
    int empty_index = state.find('V');

    for (int i : {-1, 1, -2, 2}) {
        if (empty_index + i >= 0 && empty_index + i < state.size()) {
            string next_state = state;
            swap(next_state[empty_index], next_state[empty_index + i]);
            if (IsValidMove(state, next_state)) {
                next_states.push_back(next_state);
            }
        }
    }

    return next_states;
}

vector<string> SolveSheepPuzzle() {
    string initial_state = "BBBVNNN";
    string target_state = "NNNVBBB";
    queue<pair<string, vector<string>>> q;
    set<string> visited;

    q.push({initial_state, {initial_state}});
    visited.insert(initial_state);

    while (!q.empty()) {
        auto [current_state, path] = q.front();
        q.pop();

        if (current_state == target_state) {
            return path;
        }

        for (const auto& next_state : GetNextStates(current_state)) {
            if (!visited.count(next_state)) {
                visited.insert(next_state);
                vector<string> new_path = path;
                new_path.push_back(next_state);
                q.push({next_state, new_path});
            }
        }
    }

    return {};
}

int main() {
    vector<string> solution = SolveSheepPuzzle();
    for (const string& state : solution) {
        cout << state << endl;
    }
    return 0;
}
