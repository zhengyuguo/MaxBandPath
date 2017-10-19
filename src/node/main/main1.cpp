#include <cstdlib>
#include <iostream>
#include "node.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  auto n1 = std::make_shared<node>(1);
  n1->wt(1.5);
  cout << "n1: " << *n1 << endl;
  auto n2 = std::make_shared<node>(2);
  n2->wt(2.5);
  cout << "n2: " << *n2 << endl;
  cout << n1->larger(n2) << endl;
  cout << n2->larger(n1) << endl;
  return 0;
}
