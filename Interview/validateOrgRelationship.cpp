#include <bits/stdc++.h>
using namespace std;

// DFS as a standalone function
void dfs(const string &node, unordered_map<string, vector<string>> &graph, unordered_set<string> &visited) {
    if (visited.count(node)) return;
    visited.insert(node);
    for (auto &child : graph[node]) {
        dfs(child, graph, visited);
    }
}

bool validateOrgRelationship(vector<vector<string>> &list) {
    unordered_set<string> managers, reportees;

    // 1. Check self-manager
    for (auto &rel : list) {
        string manager = rel[0];
        string reportee = rel[1];
        if (manager == reportee) return false;
        managers.insert(manager);
        reportees.insert(reportee);
    }

    // 2. Find ultimate leader (manager but not reportee)
    vector<string> leaders;
    for (auto &m : managers) {
        if (reportees.find(m) == reportees.end()) {
            leaders.push_back(m);
        }
    }
    if (leaders.size() != 1) return false;
    string leader = leaders[0];

    // 3. Build graph
    unordered_map<string, vector<string>> graph;
    for (auto &rel : list) {
        graph[rel[0]].push_back(rel[1]);
    }

    // All members
    unordered_set<string> allMembers;
    for (auto &m : managers) allMembers.insert(m);
    for (auto &r : reportees) allMembers.insert(r);

    // DFS to check connectivity
    unordered_set<string> visited;
    dfs(leader, graph, visited);

    return visited.size() == allMembers.size();
}

int main() {
    vector<vector<string>> list1 = {
        {"Alice", "Bob"},
        {"Alice", "Charlie"},
        {"Bob", "David"},
        {"Bob", "Eve"}
    };

    vector<vector<string>> list2 = {
        {"Alice", "Bob"},
        {"Alice", "Charlie"},
        {"Bob", "David"},
        {"Bob", "Eve"},
        {"Nirav", "Daya"}
    };

    cout << (validateOrgRelationship(list1) ? "true" : "false") << endl; // true
    cout << (validateOrgRelationship(list2) ? "true" : "false") << endl; // false

    return 0;
}
