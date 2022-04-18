#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Pointt {
public:
	int x, y, k;
	string s;
	Pointt(int x, int y, string name, int k) : x(x), y(y), s(name), k(k)
	{
	}
};


class def {
	int n, w, max = 0;
	int Count = 0;
	vector<Pointt> ps;
	vector<Pointt> res;
	vector<Pointt> Max_par{ Pointt(0,0,"b",0) };
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
			ps.emplace_back(x, y, "P" + std::to_string(i + 1), 0);
		}
	}


	void Add(int Wes, int Pri, string Name)
	{
		for (int i = 0; i < n; i++)
		{
			Wes += ps[i].x;
			if (Wes > w) { Wes -= ps[i].x; continue; }
			Count += i;
			Pri += ps[i].y;
			int size = Name.size();
			Name += ps[i].s + "+";
			if (Wes <= w)
			{
				if (Check(Wes, Pri, Name, Count))
				res.emplace_back(Wes, Pri, Name, Count);
				Add(Wes, Pri, Name);
				Wes -= ps[i].x;
				Pri -= ps[i].y;
				Count -= i;
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

	bool Check(int Wes, int Pri, string Name, int Count)
	{
		for (int i = 0; i < res.size(); i++)
		{
			if ((res[i].s).size() == Name.size() && res[i].k == Count && res[i].x == Wes && res[i].y == Pri)
				return false;
		}
		return true;
	}

	void Print() 
	{
		Sort_max();
		/*for (Pointt& p : ps) {
			cout << p.s << ":       " << p.x << "       " << p.y << endl << endl;
		}*/
		for (Pointt& p : ps) {
			cout << p.s << ":" << setw(16) << p.x << "" << setw(10) << p.y << endl << endl;
		}
		/*for (int i = 0; i < res.size(); i++) {
			cout << res[i].s << ":    " << res[i].x << "       " << res[i].y << "          " << res[i].k << endl;
		}*/
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].s << ":" << setw(18 - (res[i].s).size()) << res[i].x << "" << setw(10) << res[i].y <<  endl;
		}
		cout << endl; 
		cout << Max_par[0].s << ":       " << Max_par[0].x << "       " << Max_par[0].y << "      <------ Best option" << endl;
	}

};