#include <cstdlib>
#include <iostream>
#include "graph.hpp"
#include <prettyprint.hpp>

int main(int argc, char* argv[])
{
  graph G = graph();
  G.create_k_regular(5, 2);

  std::cout << G.deg() << std::endl;
  //std::cout << G.e() << std::endl;
  std::cout << G << std::endl;
  //std::cout << G.size() << std::endl;
  return 0;
}
