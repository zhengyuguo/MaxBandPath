#include <cstdlib>
#include <iostream>
#include "pri_queue.hpp"
#include "node.hpp"

int main(int argc, char* argv[])
{
  pri_queue<node> q;
  for( int i = 1; i < argc; ++i) {
    auto n = std::make_shared<node>(i,atof(argv[i]));
    q.insert(n);
  }
  q.inc_val(6,10);
  q.inc_val(5,12);
  while(q.empty() == false) {
    auto tmp = q.pop();
    std::cout << "pop out:" << tmp->wt() << "; " << tmp->id() << "; " << tmp->q_idx() << std::endl;
  }
  return 0;
}
