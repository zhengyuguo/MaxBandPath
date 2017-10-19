#include <cstdlib>
#include <iostream>
#include "graph.hpp"

int main(int argc, char* argv[])
{
  graph G = graph();
  G.create_graph(4);

  G.add_edge(0, 1, .1);
  G.add_edge(1, 2, .2);
  G.add_edge(1, 3, .3);
  G.add_edge(2, 3, .4);
  G.add_node();
  std::cout << G << std::endl;
  return 0;
}
