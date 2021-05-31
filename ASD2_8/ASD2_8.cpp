#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"
#include "profile.h"

using namespace std;

Graph getGraphFromFile(const string& file) {
    Graph res;
    ifstream fin(file);
    string line;
    getline(fin, line);
    istringstream ss(line);
    int cur = 0;
    while (!ss.eof()) {
        int x;
        ss >> x;
        res.addVer(cur++);
        if (x == 1)
            res.addEdge(0, cur - 1);
    }
    return res;
}

int main()
{
    Graph g = getGraphFromFile("graph.txt");
    for (int i = 0; i < 5; i++) {
        clog << "Graph with " << 19 + i * 100 << " nodes\n";
        
        {
            LOG_DURATION("Detour in depth");
            volatile auto tem = g.detourInDepth(0);
        }

        {
            int rVer = 19 + 100 * i;
            LOG_DURATION("Get distance between 0 and " + to_string(rVer));
            volatile int dist = g.distBetween(0, rVer);
        }

        {
            LOG_DURATION("Add vertexes");
            for (int j = 0; j < 100; j++)
                g.addVer(19 + i * 100 + j);
        }

        {
            LOG_DURATION("Add edges");
            for (int j = 0; j < 200; j++)
                g.addEdge(19 + i * 100 + rand() % 100, 19 + i * 100 + rand() % 100);
        }
        clog << "\n";
    }
    return 0;
}