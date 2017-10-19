// vim: set noexpandtab tabstop=2:

#include <algorithm> 
#include <cstdlib>
#include "graph.hpp"
#include <prettyprint.hpp>

void graph::add_edge(int i, int j, double weight) { 
	std::vector<adj_list_node> & tmp = _adj_list[i];
	for( auto it = tmp.begin(); it != tmp.end(); ++ it) {
		if (it->dest == j)
			return;
	}
	_adj_list[i].push_back(adj_list_node(j, weight));
	_adj_list[j].push_back(adj_list_node(i, weight));
	_edge.push_back(std::make_shared<edge>(i, j, weight));
	_degree[i]++;
	_degree[j]++;
}

int graph::add_node() { 
	int id = _size; 
	_vertex.push_back(std::make_shared<node>(id)); 
	_degree.push_back(0);
	_adj_list.push_back(std::vector<adj_list_node>());
	++ _size;
	return id; 
}

void graph::create_graph(int n) {
	for(int i = 0; i<n; ++i)
		add_node();
}

void graph::create_k_regular(int size, int k, int seed) {
	srand(seed);
	create_graph(size);
	auto tmp = _vertex;
	std::random_shuffle ( tmp.begin(), tmp.end() );
	for(int i = 0; i < size; i++)
	{
		for(int j = 1; j < k/2+1; j++)
			add_edge(tmp[i]->id(), tmp[(i+j)%size]->id(), rand()%100000);
	}
}

std::ostream &operator<<(
		std::ostream &os
		, graph &obj
		) {
	os << "node: " << obj.v() << std::endl;
	os << "degree: " << obj.deg() << std::endl;
	os << "edge: " << obj.e() << std::endl;
	os << "adj_list: " << obj.adj_list() << std::endl;
	return os;
}

std::ostream &operator<<(
		std::ostream &os
		, const adj_list_node &obj
		) {
	os << "{ ";
	os << "dest: " << obj.dest << "; ";
	os << "weight: " << obj.weight << "; ";
	os << "}";
	return os;
}
