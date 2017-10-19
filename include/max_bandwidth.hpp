// vim: set noexpandtab tabstop=2:
#pragma once

#include <vector>
#include "node.hpp"
#include "graph.hpp"

std::vector<int> dijkstra(
		graph & G
		, int source
		, int dest
		);

std::vector<int> dijkstra_noheap(
		graph & G
		, int source
		, int dest
		);

std::vector<int> kruskal(
		graph & G
		, int source
		, int dest
		);
