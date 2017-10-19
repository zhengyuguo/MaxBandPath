// vim: set noexpandtab tabstop=2:
#pragma once

#include <vector>
#include <algorithm>
#include <prettyprint.hpp>


template <class T>
class pri_queue {
	private:
		std::vector<std::shared_ptr<T>> heap;

		void swap(int ind_x, int ind_y);

		void down_heapify(int i);

		void up_heapify(int i);

		int left(int i) { return (i << 1) + 1; };

		int right(int i) { return (i << 1) + 2; };

		int parent(int i) { return (i-1) >> 1; }

	public:
		pri_queue() {};

		bool empty() { return heap.empty(); }

		std::shared_ptr<T> pop();

		void insert(std::shared_ptr<T> element); 

		void inc_val(int i, double new_val);

		void inc_val(std::shared_ptr<T> n, double new_val);
};

template <class T>
void pri_queue<T>::swap(int ind_x, int ind_y) {
	if(ind_x < heap.size() && ind_y < heap.size()) {
		heap[ind_x]->q_idx(ind_x);
		std::swap(heap[ind_x], heap[ind_y]);
		heap[ind_y]->q_idx(ind_y);
	}
}

template <class T>
void pri_queue<T>::down_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int max = i;
	if (l < heap.size() && heap[l]->larger(heap[i]))
		max = l;
	if (r < heap.size() && heap[r]->larger(heap[max]))
		max = r;
	if (max != i) {
		swap(i,max);
		down_heapify(max);
	}
}

template <class T>
void pri_queue<T>::up_heapify(int i) {
	while(i > 0) {
		int p = parent(i);
		if ( heap[i]->larger(heap[p])) {
			swap(i, p);
			i = p;
		} else {
			break;
		}
	}
}

template <class T>
std::shared_ptr<T> pri_queue<T>::pop() {
	auto tmp = heap.front(); 
	tmp->q_idx(-1);
	heap[0] = heap.back();
	heap[0]->q_idx(0);
	heap.pop_back(); 
	down_heapify(0);
	return tmp;
}

template <class T>
void pri_queue<T>::insert(std::shared_ptr<T> element) {
	element->q_idx(heap.size());
	heap.push_back(element);
	up_heapify(heap.size()-1);
}

template <class T>
void pri_queue<T>::inc_val(int i, double new_val) {
	if(heap[i]->wt() < new_val) {
		heap[i]->wt(new_val);
		up_heapify(i);
	}
}

template <class T>
void pri_queue<T>::inc_val(std::shared_ptr<T> n, double new_val) {
	int i = n->q_idx();
	if(heap[i]->wt() < new_val) {
		heap[i]->wt(new_val);
		up_heapify(i);
	}
}

