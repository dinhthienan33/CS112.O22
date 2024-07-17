#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Building {
    int l, r, h;
};

vector<pair<int, int>> getPoints(const vector<Building>& buildings) 
{
    int max_x = 0;
    for (const auto& b : buildings) 
        max_x = max(max_x, b.r);

    vector<int> heights(max_x + 1, 0);
    for (const auto& b : buildings) 
    {
        for (int i = b.l; i < b.r; i++)
            heights[i] = max(heights[i], b.h);
    }

    vector<pair<int, int>> points;
    int current_height = 0;
    for (int i = 0; i <= max_x; i++) 
    {
        if (heights[i] != current_height) 
        {
            points.emplace_back(i, heights[i]);
            current_height = heights[i];
        }
    }

    return points;
}

int main() 
{
    int n;
    cin >> n;
    
    vector<Building> buildings(n);
    for (int i = 0; i < n; i++)
        cin >> buildings[i].l >> buildings[i].r >> buildings[i].h;

    vector<pair<int, int>> results = getPoints(buildings);
    
    for (const auto& p : results)
        cout << p.first << " " << p.second << "\n";
    return 0;
}