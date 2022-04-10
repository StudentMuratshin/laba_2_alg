#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pointt {
public:
	int x, y;
	string s;
	Pointt(int x, int y, string name) : x(x), y(y), s(name)
	{
	}
};

class def {
	int n, w, max = 0;
	vector<Pointt> ps;
	vector<Pointt> res{ Pointt(0,0,"b") };
public:
	void Read(string fname) {
		ifstream f;
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n >> w;
		int x, y;
		for (int i = 0; i < n; i++) {
			f >> x >> y;
			if (y > max)
			{
				res[0].x = x;
				res[0].y = y;
				res[0].s = "P" + std::to_string(i + 1);
				max = y;
			}
			ps.emplace_back(x, y, "P" + std::to_string(i + 1));
		}
	}

	vector<int> v;


	void Add(int idx)
	{
		for (int i = idx; i < n; i++)
		{
			if (ps[idx].y + ps[i].y <= w && i != idx)
			{
				res.emplace_back(ps[idx].x + ps[i].x, ps[idx].y + ps[i].y, ps[idx].s + "+" + ps[i].s);
				if (ps[idx].y + ps[i].y >= max)
				{
					res[0].x = ps[idx].x + ps[i].x;
					res[0].y = ps[idx].y + ps[i].y;
					res[0].s = ps[idx].s + "+" + ps[i].s;
					max = ps[idx].y + ps[i].y;
				}
			}
		}
		if (idx == n - 1) return;
		Add(idx + 1);
	}

	void Print() {
		for (Pointt& p : ps) {
			cout << p.s << ":       " << p.x << "       " << p.y << endl;
		}
		for (int i = 1; i < res.size(); i++) {
			cout << res[i].s << ":    " << res[i].x << "       " << res[i].y << endl;
		}
		cout << endl;
		cout << res[0].s << ":       " << res[0].x << "       " << res[0].y << "      <------ Best option" << endl;
	}

};

