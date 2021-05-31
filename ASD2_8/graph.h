#pragma once
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
	std::unordered_map<int, std::unordered_map<int, bool >> table;
public:
	void addVer(int ver);
	void remVer(int ver);
	void addEdge(int verL, int verR);
	void remEdge(int verL, int verR);
	std::vector<int> detourInDepth(int ed) const;
	int distBetween(int verL, int verR) const;
private:
	void _detourInDepth(int e, std::vector<int>& edges, std::unordered_set<int>& usedEdges) const;
};