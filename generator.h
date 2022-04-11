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
	int k = 0;
	vector<Pointt> ps;
	vector<Pointt> res;
	vector<Pointt> Max_par{ Pointt(0,0,"b") };
public:
	void Read(string fname) {
		ifstream f;
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n >> w;
		int x, y;
		for (int i = 0; i < n; i++) {
			f >> x >> y;
			if (y > max && x <= w)
			{
				Max_par[0].x = x;
				Max_par[0].y = y;
				Max_par[0].s = "P" + std::to_string(i + 1);
				max = y;
			}
			ps.emplace_back(x, y, "P" + std::to_string(i + 1));
		}
	}


	void Add(int Wes, int Pri, string Name)
	{
		for (int i = 0; i < n; i++)
		{
			Wes += ps[i].x;
			if (Wes > w) { Wes -= ps[i].x; continue; }
			Pri += ps[i].y;
			int size = Name.size();
			Name += ps[i].s + "+";
			if (Wes <= w)
			{
				res.emplace_back(Wes, Pri, Name);
				Add(Wes, Pri, Name);
				Wes -= ps[i].x;
				Pri -= ps[i].y;
				Name.erase(size);
			}
		}
	}

	void Sort_max()
	{
		for (Pointt p : res)
		{
			if (p.y >= max)
			{
				Max_par[0].x = p.x;
				Max_par[0].y = p.y;
				Max_par[0].s = p.s;
				max = p.y;
			}
		}
	}

	void Sort_row()
	{
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = i + 1; j < res.size(); j++)
			{
				if ((res[i].s).size() == (res[j].s).size() && )
			}
		}
	}

	void Print() 
	{
		for (Pointt& p : ps) {
			cout << p.s << ":       " << p.x << "       " << p.y << endl << endl;
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].s << ":    " << res[i].x << "       " << res[i].y << endl;
		}
		cout << endl; 
		Sort_max();
		cout << Max_par[0].s << ":       " << Max_par[0].x << "       " << Max_par[0].y << "      <------ Best option" << endl;
	}

};