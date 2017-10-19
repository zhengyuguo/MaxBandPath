#include <cstdlib>
#include <iostream>
#include <prettyprint.hpp>
#include "graph.hpp"
#include "max_bandwidth.hpp"
#include <ctime>


int main(int argc, char* argv[])
{
  for( int i = 0; i < 5; i++) {
  int seed = time(NULL) + i;
  srand (seed);
  int n1 = rand() % 5000;
  int n2 = rand() % 5000;
  std::cout << "n1:	" << i << "	" << n1 << std::endl;
  std::cout << "n2:	" << i << "	" << n2 << std::endl;

  graph G1 = graph();
  G1.create_k_regular(5000, 6, time(NULL));
  //std::cout <<  G1 << std::endl;

  auto t = clock();
  auto b = dijkstra_noheap(G1, n1, n2);
  t = clock() - t;
  std::cout << "noheap:	" << i << "	" << t << std::endl; 

  G1.clear();
  //std::cout <<  G1 << std::endl;

  t = clock();
  auto a = dijkstra(G1, n1, n2);
  t = clock() - t;
  std::cout << "heap:	" << i << "	" << t << std::endl; 

  G1.clear();

  t = clock();
  kruskal(G1, n1, n2);
  t = clock() - t;
  std::cout << "kruskal:	" << i << "	" << t << std::endl; 
  //std::cout << a << std::endl;
  }
  return 0;
}
