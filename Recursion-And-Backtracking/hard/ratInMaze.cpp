#include <bits/stdc++.h>
using namespace std;

struct Choice {
    char direction;
    int dx, dy;
};

vector<Choice> choices = {{'U', -1, 0}, {'D', 1, 0}, {'R', 0, 1}, {'L', 0, -1}};

bool isSolved(int x, int y, int n) {
    return x == n - 1 && y == n - 1;
}

bool isValid(int x, int y, int n, vector<vector<int>> &mat) {
    return x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1;
}

void solve(int x, int y, int n, string &path, vector<vector<int>> &mat, vector<string> &ans) {
    if (isSolved(x, y, n)) {
        ans.push_back(path);
        return;
    }

    for (auto &choice : choices) {
        int newX = x + choice.dx;
        int newY = y + choice.dy;

        if (isValid(newX, newY, n, mat)) {
            // Mark the current cell as visited
            mat[x][y] = 0;
            path.push_back(choice.direction);

            // Recursive call to explore further
            solve(newX, newY, n, path, mat, ans);

            // Backtrack: unmark the current cell and remove the last direction
            mat[x][y] = 1;
            path.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    string path;
    int n = mat.size();

    if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        return ans;
    }

    solve(0, 0, n, path, mat, ans);
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(mat);
    for (const string &path : result) {
        cout << path << endl;
    }

    return 0;
}
