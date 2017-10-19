// vim: set noexpandtab tabstop=2:
#pragma once
#include <prettyprint.hpp>

class node {
	private:
		int _id;
		double _wt;
		int _q_idx;

	public:
		int id() const { return _id; }

		double wt() const { return _wt; }
		void wt(double x) { _wt = x; }

		int q_idx() const { return _q_idx; }
		void q_idx(int x) { _q_idx = x; }
		
		void clear() { _wt = -1; _q_idx = -1; }

		node(int id): _id(id) , _wt(-1), _q_idx(-1) {}
		node(int id, double wt): _id(id) , _wt(wt), _q_idx(-1) {}

		bool larger(std::shared_ptr<node> n) {
			if(_wt >= 0 && n->wt() >= 0) 
				return _wt > n->wt();
			else if(_wt < 0 && n->wt() >=0) 
				return true;
			else 
				return false;
		}

		bool larger(node & n) {
			if(_wt >= 0 && n.wt() >= 0) 
				return _wt > n.wt();
			else if(_wt < 0 && n.wt() >=0) 
				return true;
			else 
				return false;
		}

		friend std::ostream &operator<<(std::ostream &os, const node &obj) {
			os << "{";
			os << "id: " << obj.id() << "; ";
			os << "wt: " << obj.wt() << "; ";
			os << "q_inx: " << obj.q_idx() << "; ";
			os << "}"; 
			return os;
		}

		friend std::ostream &operator<<(std::ostream &os, const std::shared_ptr<node> obj) {
			os << "{";
			os << "id: " << obj->id() << "; ";
			os << "wt: " << obj->wt() << "; ";
			os << "q_inx: " << obj->q_idx() << "; ";
			os << "}"; 
			return os;
		}
};
