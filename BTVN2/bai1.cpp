#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<string, string>> pairs;
    while (n--)
    {
        string x, y;
        cin >> x >> y;
        pairs.push_back(make_pair(x, y));
    }

    bool check = true;
    for (const auto &pair : pairs)
    {
        bool found = false;
        for (const auto &p : pairs)
        {
            if (p.first == pair.second && p.second == pair.first)
            {
                found = true;
                break;
            }
        }
        if (found==false)
        {
            check = false;
            break;
        }
    }

    if (check == true)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
}