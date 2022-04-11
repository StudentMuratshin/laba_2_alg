#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	int x, y;
	string s;
	Point(int x, int y, string name) : x(x), y(y), s(name)
	{
	}
};

class dynamic {
	int n, w, max = 0, count_answer = 0;
	string name_answer;
	vector<Point> ps;
	vector<Point> res;
	vector<vector<int>> zxc;
	vector <int> column;

public:
	void Read(string fname) {
		ifstream f;
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n >> w;
		column.resize(w+1);
		int x, y;
		for (int i = 0; i < n; i++) {
			f >> x >> y;
			ps.emplace_back(x, y, "P" + std::to_string(i + 1));
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= w; j++)
				zxc.push_back(column);
		}
	}

	void Add(int idx)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= w; j++)
			{
				/*if (j >= ps[i-1].x) zxc[i][j] = std::max(zxc[i - 1][j], zxc[i - 1][j - ps[i-1].x] + ps[i-1].y);
				else zxc[i][j] = zxc[i - 1][j];*/
				zxc[i][j] = zxc[i - 1][j];
				if ( j >= ps[i - 1].x)
				{
					zxc[i][j] = std::max(zxc[i][j], zxc[i][j - ps[i - 1].x] + ps[i - 1].y);
				}
			}
		}
	}

	void Ans(int k, int s)
	{
		if (k < 0 || s < 0 || zxc[k][s] == 0) return;
		if (zxc[k - 1][s] == zxc[k][s]) { Ans(k - 1, s); }
		else {
			count_answer += ps[k - 1].y;
			name_answer += ps[k - 1].s + "+";
			Ans(k, s - ps[k - 1].x);
		}
	}

	void Print()
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= w; j++)
			{
				cout << zxc[i][j] << " ";
			}
			cout << endl;
		}
		Ans(n, w);
		cout << endl << name_answer << "   " << count_answer << "      <------ Best option" << endl;;
	}
};