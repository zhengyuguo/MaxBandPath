#include <iostream>
#include <algorithm>
#include <prettyprint.hpp>
#include "pri_queue.hpp"
#include "node.hpp"
#include "max_bandwidth.hpp"
#include "set_op.hpp"

std::vector<int> dijkstra(graph & G, int source, int dest) {
  pri_queue<node> queue;
  std::vector<int> dad(G.size(), -1);
  std::vector<int> status(G.size(), -1); // intree = 0; unseen = -1; fringe = 1;

  for(auto it = G.v().begin(); it != G.v().end(); it++) 
    (*it)->wt(-1);

  G[source]->wt(0);
  status[source] = 0;

  for( auto it = G.neighbors(source).begin(); it != G.neighbors(source).end(); ++it) {
    int neighbor_idx = it->dest;
    G[neighbor_idx]->wt(it->weight);
    queue.insert(G[neighbor_idx]);
    dad[neighbor_idx] = source;
    status[neighbor_idx] = 1;
  }

  while(! queue.empty()) {
    auto u = queue.pop();
    //std::cout << u << std::endl;

    int u_idx = u->id();
    status[u_idx] = 0;
    for( auto it = G.neighbors(u_idx).begin(); it != G.neighbors(u_idx).end(); ++it) {
      int v_idx = it->dest;
      if(status[v_idx] == -1) {
        status[v_idx] = 1;
        G[v_idx]->wt(std::min(u->wt(), it->weight));
        queue.insert(G[v_idx]);
        dad[v_idx] = u_idx;
      } else if (status[v_idx] == 1 && (G[v_idx]->wt() < std::min(G[u_idx]->wt(), it->weight))) {
        dad[v_idx] = u_idx;
        queue.inc_val(G[v_idx], std::min(G[u_idx]->wt(),  it->weight));
      }
    }
  }
  return dad;
}

std::vector<int> dijkstra_noheap(graph & G, int source, int dest) {
  std::vector<std::shared_ptr<node>> fringe;
  std::vector<int> dad(G.size(), -1);
  std::vector<int> status(G.size(), -1); // intree = 0; unseen = -1; fringe = 1;

  for(auto it = G.v().begin(); it != G.v().end(); it++) 
    (*it)->wt(-1);

  G[source]->wt(0);
  status[source] = 0;

  for( auto it = G.neighbors(source).begin(); it != G.neighbors(source).end(); ++it) {
    int neighbor_idx = it->dest;
    G[neighbor_idx]->wt(it->weight);
    fringe.push_back(G[neighbor_idx]);
    dad[neighbor_idx] = source;
    status[neighbor_idx] = 1;
  }

  while(fringe.size() != 0) {
    int max_idx = 0;
    for ( int i = 1; i< fringe.size(); i++) {
      if(fringe[i]->wt() > fringe[max_idx]->wt())
        max_idx = i;
    }

    auto u = fringe[max_idx];
    fringe.erase(fringe.begin()+max_idx);
    //std::cout << u << std::endl;

    int u_idx = u->id();
    status[u_idx] = 0;
    for( auto it = G.neighbors(u_idx).begin(); it != G.neighbors(u_idx).end(); ++it) {
      int v_idx = it->dest;
      if(status[v_idx] == -1) {
        status[v_idx] = 1;
        G[v_idx]->wt(std::min(u->wt(), it->weight));
        fringe.push_back(G[v_idx]);
        dad[v_idx] = u_idx;
      } else if (status[v_idx] == 1 && (G[v_idx]->wt() < std::min(G[u_idx]->wt(), it->weight))) {
        dad[v_idx] = u_idx;
        G[v_idx]->wt(std::min(G[u_idx]->wt(),  it->weight));
      }
    }
  }
  return dad;
}

std::vector<int> kruskal(graph & G , int source , int dest) {
  pri_queue<edge> q;
  for(auto it = G.e().begin(); it != G.e().end(); it++) 
    q.insert(*it);

  std::vector<std::shared_ptr<edge>> T;
  std::vector<set_element> S;

  for( auto it = G.v().begin(); it != G.v().end(); it++) {
    S.push_back(set_element((*it)->id()));
  }

  while(!q.empty()) {
    auto e = q.pop();
    auto s1 = S[e->id1()].find_set();
    auto s2 = S[e->id2()].find_set();
    //std::cout << s1->find_set()->element << std::endl;
    //std::cout << s2->find_set()->element << std::endl;
    if (s1 != s2) {
      T.push_back(e);
      union_sets(s1, s2);
    }
    //std::cout << s1->find_set()->element << std::endl;
    //std::cout << s2->find_set()->element << std::endl;
  }
  return std::vector<int>();
}
