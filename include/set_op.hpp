// vim: set noexpandtab tabstop=2:
#pragma once

class set_element {
	public:
		int element;
		set_element * p;
		int rank;
		set_element(int x): element(x), p(NULL), rank(0) {};
		void rank_inc() { ++ rank; }

		set_element * find_set() {
			if(p != NULL) {
				p = p->find_set();
				return p;
			}
			else
				return this;
		}
};


void union_sets(set_element * x, set_element * y) {
	if(x->rank > y->rank)
		y->p = x;
	else {
		x->p = y;
		if(x->rank == y->rank)
			y->rank_inc();
	}
}
