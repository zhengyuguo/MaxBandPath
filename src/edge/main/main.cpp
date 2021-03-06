#include <cstdlib>
#include <iostream>
#include "edge.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  edge e1(1, 2);
  e1.wt(1.5);
  cout << "e1: " << e1 << endl;
  edge e2(2, 3);
  e2.wt(2.5);
  cout << "e2: " << e2 << endl;
  cout << e1.larger(e2) << endl;
  cout << e2.larger(e1) << endl;
  return 0;
}
