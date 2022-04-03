#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
public:
	int x, y;
	string s;
	Point(int x, int y, string name) : x(x), y(y), s(name)
	{
	}
};

class Algo2 {
	int n, w, max = 0;
	vector<Point> ps;
	vector<Point> res{Point(0,0,"b")};
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
			ps.emplace_back(x, y, "P" + std::to_string(i+1));
		}
	}

	vector<int> v;
	

	void Add(int idx) 
	{	
		for (int i = idx; i < n; i++)
		{
			if (ps[idx].x + ps[i].x <= w && i != idx)
			{
				res.emplace_back(ps[idx].x + ps[i].x, ps[idx].y + ps[i].y, ps[idx].s + "+" + ps[i].s);
				if (ps[idx].y + ps[i].y > max) 
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
		for (Point& p : ps) {
			cout << p.s << ":       " << p.x << "       " << p.y << endl;
		}
		for (int i = 1; i < res.size(); i++) {
			cout << res[i].s << ":    " << res[i].x << "       " << res[i].y << endl;
		}
		cout << endl;
		cout << res[0].s << ":       " << res[0].x << "       " << res[0].y << "      <------ Best option" << endl;
	}

};

int main() {
	cout << "Who's   " << "Price   " << "Weight  " << endl << endl;
	Algo2 a;
	a.Read("input.txt");
	a.Add(0);
	a.Print();
	return 0;
}