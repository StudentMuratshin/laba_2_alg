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
	int n, w, max = 0;
	vector<Point> ps;
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
				if (ps[i - 1].x <= j)
				{
					zxc[i][j] = std::max(zxc[i][j], zxc[i][j - ps[i-1].x] + ps[i - 1].y);
				}
			}
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
	}
};