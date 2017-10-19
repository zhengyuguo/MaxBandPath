#include <cstdlib>
#include <iostream>
#include <prettyprint.hpp>
#include "pri_queue.hpp"
#include "node.hpp"

int main(int argc, char* argv[])
{
  pri_queue<node> q;
  for( int i = 1; i < argc; i++) {
    auto n = std::make_shared<node>(i,atof(argv[i]));
    q.insert(n);
  }
  while(q.empty() == false) {
    std::cout << "pop out:" << q.pop()->wt() << std::endl;
  }
  return 0;
}
