// vim: set noexpandtab tabstop=2:
#pragma once

#include <vector>
#include <iostream>
#include "node.hpp"
#include "edge.hpp"
#include <prettyprint.hpp>

class adj_list_node {
	public:
		int dest;
		double weight;
		adj_list_node(int d, double w) : dest(d), weight(w) {}

		friend std::ostream &operator<<(std::ostream &os, const adj_list_node &obj);
};

class graph {
	private:
		int _size;
		std::vector<std::shared_ptr<node>> _vertex;
		std::vector<std::shared_ptr<edge>> _edge;
		std::vector<int> _degree;
		std::vector<std::vector<adj_list_node>> _adj_list;

	public:
		graph(): _size(0) {}

		int size() { return _size; }

		std::vector<std::shared_ptr<node>> & v() {return _vertex; }
		std::shared_ptr<node>& operator[](int idx) { return _vertex[idx]; }

		std::vector<std::shared_ptr<edge>> & e() {return _edge; }

		int deg(int i) { return _degree[i]; }
		const std::vector<int> & deg() const { return _degree; }

		const std::vector<std::vector<adj_list_node>> & adj_list() const { return _adj_list; }
		std::vector<adj_list_node> & neighbors(int i) { return _adj_list[i]; }

		void add_edge(int i, int j, double weight); 
		void add_edge(edge e); 

		int add_node(); 

		void clear() {
			for(auto it = _vertex.begin(); it != _vertex.end(); it++)
				(*it)->clear();
		}

		void create_graph(int n);

		void create_k_regular(int size, int k, int seed);

		friend std::ostream &operator<<(std::ostream &os, graph &obj);

};
