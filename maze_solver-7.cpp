#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

const int DR[] = {-1, 1, 0, 0};
const int DC[] = {0, 0, -1, 1};

void printMaze(const vector<string>& maze, const vector<pair<int,int>>& path, char pathChar) {
    vector<string> display = maze;
    for (auto& [r, c] : path)
        if (display[r][c] != 'S' && display[r][c] != 'E')
            display[r][c] = pathChar;
    for (auto& row : display)
        cout << "  " << row << "\n";
}

vector<pair<int,int>> reconstructPath(vector<vector<pair<int,int>>>& parent, int er, int ec) {
    vector<pair<int,int>> path;
    int r = er, c = ec;
    while (r != -1 && c != -1) {
        path.push_back({r, c});
        auto [pr, pc] = parent[r][c];
        r = pr; c = pc;
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int,int>> bfs(const vector<string>& maze, pair<int,int> start, pair<int,int> end_) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1, -1}));
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == end_.first && c == end_.second)
            return reconstructPath(parent, r, c);
        for (int d = 0; d < 4; d++) {
            int nr = r + DR[d], nc = c + DC[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                !visited[nr][nc] && maze[nr][nc] != '#') {
                visited[nr][nc] = true;
                parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
    return {};
}

vector<pair<int,int>> dfs(const vector<string>& maze, pair<int,int> start, pair<int,int> end_) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1, -1}));
    stack<pair<int,int>> s;
    s.push(start);
    visited[start.first][start.second] = true;
    while (!s.empty()) {
        auto [r, c] = s.top(); s.pop();
        if (r == end_.first && c == end_.second)
            return reconstructPath(parent, r, c);
        for (int d = 0; d < 4; d++) {
            int nr = r + DR[d], nc = c + DC[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                !visited[nr][nc] && maze[nr][nc] != '#') {
                visited[nr][nc] = true;
                parent[nr][nc] = {r, c};
                s.push({nr, nc});
            }
        }
    }
    return {};
}

int main() {
    // Read maze from stdin (piped from frontend or terminal)
    // First line: rows cols
    // Next `rows` lines: maze rows (# = wall, space = open, S = start, E = end)
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();

    vector<string> maze(rows);
    for (int r = 0; r < rows; r++)
        getline(cin, maze[r]);

    // Pad short rows
    for (auto& row : maze)
        while ((int)row.size() < cols) row += '#';

    pair<int,int> start = {-1,-1}, end_ = {-1,-1};
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) {
            if (maze[r][c] == 'S') start = {r, c};
            if (maze[r][c] == 'E') end_  = {r, c};
        }

    if (start.first == -1 || end_.first == -1) {
        cerr << "ERROR: Maze must contain S and E\n";
        return 1;
    }

    cout << "\n========================================\n";
    cout << "         C++ MAZE SOLVER\n";
    cout << "========================================\n\n";
    cout << "Original Maze:\n";
    printMaze(maze, {}, ' ');
    cout << "\nStart: (" << start.first << "," << start.second << ")  "
         << "End: (" << end_.first << "," << end_.second << ")\n";

    // BFS
    cout << "\n----------------------------------------\n";
    cout << "  BFS (Breadth-First Search) - Shortest Path\n";
    cout << "----------------------------------------\n";
    auto bfsPath = bfs(maze, start, end_);
    if (bfsPath.empty()) {
        cout << "  No path found!\n";
    } else {
        cout << "  Path length: " << bfsPath.size() - 1 << " steps\n\n";
        printMaze(maze, bfsPath, '.');
        cout << "\n  Path coordinates:\n  ";
        for (int i = 0; i < (int)bfsPath.size(); i++) {
            cout << "(" << bfsPath[i].first << "," << bfsPath[i].second << ")";
            if (i < (int)bfsPath.size() - 1) cout << " -> ";
            if ((i+1) % 6 == 0) cout << "\n  ";
        }
        cout << "\n";
    }

    // DFS
    cout << "\n----------------------------------------\n";
    cout << "  DFS (Depth-First Search)\n";
    cout << "----------------------------------------\n";
    auto dfsPath = dfs(maze, start, end_);
    if (dfsPath.empty()) {
        cout << "  No path found!\n";
    } else {
        cout << "  Path length: " << dfsPath.size() - 1 << " steps\n\n";
        printMaze(maze, dfsPath, '*');
        cout << "\n  Path coordinates:\n  ";
        for (int i = 0; i < (int)dfsPath.size(); i++) {
            cout << "(" << dfsPath[i].first << "," << dfsPath[i].second << ")";
            if (i < (int)dfsPath.size() - 1) cout << " -> ";
            if ((i+1) % 6 == 0) cout << "\n  ";
        }
        cout << "\n";
    }

    cout << "\n========================================\n";
    cout << "  SUMMARY\n";
    cout << "========================================\n";
    if (!bfsPath.empty() && !dfsPath.empty()) {
        cout << "  BFS steps: " << bfsPath.size() - 1 << "  (always optimal)\n";
        cout << "  DFS steps: " << dfsPath.size() - 1 << "  (may not be optimal)\n";
        if (bfsPath.size() <= dfsPath.size())
            cout << "  BFS found the shorter/equal path!\n";
        else
            cout << "  DFS found a shorter path this time.\n";
    }
    cout << "========================================\n\n";
    cout << "Legend: '#'=wall | '.'=BFS path | '*'=DFS path\n\n";

    return 0;
}
