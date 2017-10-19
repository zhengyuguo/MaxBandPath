// vim: set noexpandtab tabstop=2:
#pragma once

#include <prettyprint.hpp>

class edge {
	private:
		int _id1;
		int _id2;
		double _wt;
		int _q_idx;

	public:
		int id1() const { return _id1; }
		int id2() const { return _id2; }

		double wt() const { return _wt; }
		void wt(double x) { _wt = x; }

		int q_idx() const { return _q_idx; }
		void q_idx(int x) { _q_idx = x; }

		edge(int id1, int id2): _id1(id1), _id2(id2), _wt(-1), _q_idx(-1) {}
		edge(int id1, int id2, double wt): _id1(id1), _id2(id2), _wt(wt), _q_idx(-1) {}

		bool larger(std::shared_ptr<edge> n) {
			if(_wt >= 0 && n->wt() >= 0) 
				return _wt > n->wt();
			else if(_wt < 0 && n->wt() >=0) 
				return true;
			else 
				return false;
		}

		bool larger(edge & n) {
			if(_wt >= 0 && n.wt() >= 0) 
				return _wt > n.wt();
			else if(_wt < 0 && n.wt() >=0) 
				return true;
			else 
				return false;
		}

		friend std::ostream &operator<<(std::ostream &os, const edge &obj) {
			os << "{";
			os << "edge: <" << obj.id1() <<">-<" << obj.id2() << ">; ";
			os << "wt: " << obj.wt() << "; ";
			os << "q_inx: " << obj.q_idx() << "; ";
			os << "}"; 
			return os;
		}

		friend std::ostream &operator<<(std::ostream &os, const std::shared_ptr<edge> obj) {
			os << "{";
			os << "edge: <" << obj->id1() <<">-<" << obj->id2() << ">; ";
			os << "wt: " << obj->wt() << "; ";
			os << "q_inx: " << obj->q_idx() << "; ";
			os << "}"; 
			return os;
		}
};
