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

vector<string> SolveSheepPuzzle(int& totalStates, int& noMoveStates) {
    string initial_state = "BBBVNNN";
    string target_state = "NNNVBBB";
    queue<pair<string, vector<string>>> q;
    set<string> visited;

    q.push({initial_state, {initial_state}});
    visited.insert(initial_state);

    totalStates = 0;
    noMoveStates = 0;

    while (!q.empty()) {
        auto [current_state, path] = q.front();
        q.pop();

        if (current_state == target_state) {
            return path;
        }

        vector<string> next_states = GetNextStates(current_state);
        if (next_states.empty()) {
            cout << "No moves possible from state: " << current_state << endl;
            noMoveStates++;
        }

        for (const auto& next_state : next_states) {
            if (!visited.count(next_state)) {
                cout << "Move from " << current_state << " to " << next_state;
                if (GetNextStates(next_state).empty()) {
                    cout << " (leads to an impasse)";
                }
                cout << endl;

                visited.insert(next_state);
                vector<string> new_path = path;
                new_path.push_back(next_state);
                q.push({next_state, new_path});
                totalStates++;
            }
        }
    }

    return {};
}

int main() {
    int totalStates, noMoveStates;
    vector<string> solution = SolveSheepPuzzle(totalStates, noMoveStates);

    cout << "Solution Path:" << endl;
    for (const string& state : solution) {
        cout << state << endl;
    }

    cout << "Total states visited: " << totalStates << endl;
    cout << "Number of no-move states: " << noMoveStates << endl;

    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
    return 0;
}
