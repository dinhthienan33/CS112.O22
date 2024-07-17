#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
int m, n;
float calculateManhattanDistance(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
vector<pair<int, int>> get_legal_actions(vector<vector<int>> &grid, pair<int, int> &pos)
{
    vector<pair<int, int>> legal_actions;
    pair<int, int> actions[8] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

    for (auto &action : actions)
    {
        int newX = pos.first + action.first;
        int newY = pos.second + action.second;

        if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY]==1)
            continue;

        legal_actions.push_back(action);
    }

    return legal_actions;
}
int AStar(vector<vector<int>> &grid, pair<int, int> &startPos, pair<int, int> &endPos)
{
    using Node = pair<int, pair<int, int>>;
    using QueueNode = pair<float, Node>;

    priority_queue<QueueNode, vector<QueueNode>, greater<QueueNode>> frontier;
    frontier.push({ calculateManhattanDistance(startPos, endPos), {0, startPos} });

    set<pair<int, int>> closedSet;

    while (!frontier.empty())
    {
        Node currentNode = frontier.top().second;
        frontier.pop();

        if (currentNode.second == endPos)
            return currentNode.first;

        if (closedSet.find(currentNode.second) != closedSet.end())
            continue;

        closedSet.insert(currentNode.second);

        vector<pair<int, int>> legal_actions = get_legal_actions(grid, currentNode.second);

        for (auto &action : legal_actions)
        {
            pair<int, int> newPos(currentNode.second.first + action.first, currentNode.second.second + action.second);
            Node best = { currentNode.first + 1, newPos };
            float priority = 2 * best.first + calculateManhattanDistance(newPos, endPos);
            frontier.push({ priority, best });
        }
    }

    return -1;
}
int main()
{
    pair<int, int> startPos, endPos;
    cin >> m >> n;
    cin >> startPos.first >> startPos.second;
    cin >> endPos.first >> endPos.second;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = m - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << AStar(grid, startPos, endPos) << endl;

    return 0;
}