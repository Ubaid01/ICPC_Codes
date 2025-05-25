#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<string>

using namespace std;

// Function to parse input grid
vector<vector<int>> parseGrid(const string& gridString, int rows, int cols,int start) {
    vector<vector<int>> grid(rows, vector<int>(cols));
    size_t pos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pos = gridString.find(',', start);
            grid[i][j] = stoi(gridString.substr(start, pos - start));
            start = pos + 1;
        }
    }
    return grid;
}

// Calculate prefix sum of the grid for efficient rectangle sum calculation
vector<vector<int>> calculatePrefixSum(const vector<vector<int>>& grid, int rows, int cols) {
    vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            prefix[i][j] = grid[i - 1][j - 1] 
                + prefix[i - 1][j] 
                + prefix[i][j - 1] 
                - prefix[i - 1][j - 1];
        }
    }
    return prefix;
}

// Function to calculate the sum of a sub-rectangle
int sumOfSubRectangle(const vector<vector<int>>& prefix, int x1, int y1, int x2, int y2) {
    return prefix[x2 + 1][y2 + 1] 
        - prefix[x2 + 1][y1] 
        - prefix[x1][y2 + 1] 
        + prefix[x1][y1];
}

// BFS to find the shortest path
int bfs(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end, int rows, int cols) {
    vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    if( grid[start.first][start.second] == INT_MIN) return -1;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int steps;
    while (!q.empty()) {
        auto [x, y] = q.front();
        steps=visited[x][y];
        q.pop();
        if (x == end.first && y == end.second)
            return steps;
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && visited[nx][ny]>steps+1 && grid[nx][ny] != INT_MIN) {
                visited[nx][ny] = steps+1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

void solveProblem() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        // Parse test case inputs
        size_t pos = 0, start = 0,rows,cols;
        pair<int, int> endPos,startPos;
        vector<int> params;
        pos = line.find(',', start);
        rows=stoi(line.substr(start, pos - start));
        start = pos + 1;
        pos = line.find(',', start);
        cols=stoi(line.substr(start, pos - start));
        start = pos + 2;
        pos = line.find(',', start);
        startPos.first=stoi(line.substr(start, pos - start))-1;
        start = pos + 1;
        pos = line.find(')', start);
        startPos.second=stoi(line.substr(start, pos - start))-1;
        start = pos + 3;
        pos = line.find(',', start);
        endPos.first=stoi(line.substr(start, pos - start))-1;
        start = pos + 1;
        pos = line.find(')', start);
        endPos.second=stoi(line.substr(start, pos - start))-1;
        start = pos + 2;

        // Parse grid and calculate prefix sums
        vector<vector<int>> grid = parseGrid(line, rows, cols,start);
        vector<vector<int>> prefix = calculatePrefixSum(grid, rows, cols);

        // Determine the optimal barricade placement
        int maxSum = INT_MIN;
        pair<int, int> blockStart = {0, 0}, blockEnd = {0, 0};

        for (int x1 = 0; x1 < rows; x1++) {
            for (int y1 = 0; y1 < cols; y1++) {
                for (int x2 = x1; x2 < rows; x2++) {
                    for (int y2 = y1; y2 < cols; y2++) {
                        int currentSum = sumOfSubRectangle(prefix, x1, y1, x2, y2);
                        if (currentSum > maxSum) {
                            maxSum = currentSum;
                            blockStart = {x1, y1};
                            blockEnd = {x2, y2};
                        }
                    }
                }
            }
        }
        // Apply the barricade
        for (int i = blockStart.first; i <= blockEnd.first; i++) {
            for (int j = blockStart.second; j <= blockEnd.second; j++) {
                grid[i][j] = INT_MIN;
            }
        }
        // Perform BFS to find the shortest path
        int pathLength = bfs(grid, startPos, endPos, rows, cols);
        int possible = pathLength != -1 ? 1 : 0;

        // Output the results
        cout << possible << ",(" << blockStart.first + 1 << "," << blockStart.second + 1 << "),("
             << blockEnd.first + 1 << "," << blockEnd.second + 1 << ")," << pathLength << endl;
    }
}

int main() {
    solveProblem();
    return 0;
}
