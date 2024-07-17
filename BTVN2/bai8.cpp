#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <queue>
using namespace std;

struct Compare {
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
		if (p1.first != p2.first) {
			return p1.first > p2.first;
		}
		return p1.second < p2.second;
	}
};

void printPath(vector<int>& track, vector<string>& map_2) {
	for(auto it = track.begin(); it != track.end(); it++){
		cout << map_2[*it] << " ";
	}
	cout << endl;
}

void dijkstra(int start, int end, int v, vector<vector<int>>& grid, vector<string>& map_2){
	vector<pair<int, int>> dist(v, make_pair(100000, v));
	dist[start] = make_pair(0, start);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> open_list;
	open_list.push({0, start});
	int opened_node = 0;

	while(!open_list.empty()){
		pair<int, int> min_node = open_list.top();
		open_list.pop();
		int u = min_node.second;
		if(min_node.first > dist[u].first)
			continue;
		if(u == end){
			vector<int> track = {end};
			while(track.front() != start){
				track.insert(track.begin(), dist[track.front()].second);
			}
			printPath(track, map_2);
			cout << ++opened_node << " " << min_node.first << endl;
			return;
		}
		opened_node++;
		for(int j = 0; j < v; j++){
			int distance = dist[u].first + grid[u][j];
			if(grid[u][j] && dist[j].first > distance){
				dist[j] = make_pair(distance, u);
				open_list.push({dist[j].first, j});
			}
		}
	}
	cout << "-unreachable-" << endl;
	cout << opened_node << " " << 0 << endl;
}

int main(){
	int v, n;
	cin >> v >> n;
	map<string, int> map_1;
	vector<string> map_2(v, "");
	string u, s;
	for(int i = 0; i < v; i++){
		cin >> u;
		map_1[u] = i;
		map_2[i] = u;
	}
	vector<vector<int>> grid(v, vector<int>(v, 0));
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			cin >> grid[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		cin >> s >> u;
		dijkstra(map_1[s], map_1[u], v, grid, map_2);
	}
	return 0;
}