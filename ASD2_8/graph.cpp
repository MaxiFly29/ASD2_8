#include <queue>
#include "graph.h"

using namespace std;

void Graph::addVer(int ver) {
	table[ver];
	auto it = table.find(ver);
	for (auto& t : table) {
		t.second[ver];
		it->second[t.first];
	}
}

void Graph::remVer(int ver) {
	table.erase(ver);
	for (auto& t : table)
		t.second.erase(ver);
}

void Graph::addEdge(int verL, int verR) {
	table.at(verL).at(verR) = 1;
}

void Graph::remEdge(int verL, int verR) {
	table.at(verL).at(verR) = 0;
}

std::vector<int> Graph::detourInDepth(int ver) const {
	vector<int> res;
	unordered_set<int> usedEdges;
	_detourInDepth(ver, res, usedEdges);
	return res;
}

void Graph::_detourInDepth(int ver, std::vector<int>& vertexes, std::unordered_set<int>& usedVertexes) const {
	usedVertexes.insert(ver);
	vertexes.push_back(ver);
	const auto& nxtEdges = table.at(ver);
	for (auto e : nxtEdges) {
		if (e.second && usedVertexes.find(e.first) == end(usedVertexes))
			_detourInDepth(e.first, vertexes, usedVertexes);
	}
}

int Graph::distBetween(int verL, int verR) const {
	unordered_map<int, int> distances;
	distances[verL] = 0;
	queue<int> q;
	q.push(verL);
	while (!q.empty()) {
		int curVer = q.front();
		q.pop();
		for (const auto& x : table.at(curVer)) {
			if (x.second && distances.count(x.first) == 0) {
				distances[x.first] = distances[curVer] + 1;
			}
		}
	}
	return distances.count(verR) ? distances[verR] : -1;
}