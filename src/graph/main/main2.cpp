#include <cstdlib>
#include <iostream>
#include "graph.hpp"
#include "pri_queue.hpp"
#include "node.hpp"
#include <prettyprint.hpp>

int main(int argc, char* argv[])
{
  graph G = graph();
  pri_queue<node> queue;
  G.create_graph(4);

  G.add_edge(0, 1, .1);
  G.add_edge(1, 2, .2);
  G.add_edge(1, 3, .3);
  G.add_edge(2, 3, .4);
  G.add_node();
  std::cout << G << std::endl;
  for(auto it = G.v().begin(); it != G.v().end(); it++) {
    queue.insert(*it);
  }
  std::cout << G << std::endl;

  return 0;
}
