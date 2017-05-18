#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

class Cake
{
public:
	Cake(int w, int d) : w(w), d(d) {}
	bool operator<(const Cake& dst) const
	{
		return this->Area() < dst.Area();
	}
	const int Area() const { return w * d; }
	Cake Cut(int p) {
		int l = w;
		bool side = true;
		while(p > l)
		{
			p -= l;
			side = !side;
			l = side ? w : d;
		}
		if (side)
		{
			int temp = (w - p) < p ? w-p : p;
			Cake c(w-temp, d);
			w = temp;
			return c;
		}
		else
		{
			int temp = (d - p) < p ? d-p : p;
			Cake c(w, d-temp);
			d = temp;
			return c;
		}
		return Cake(-1, -1);
	}
	int d, w, t;
};

int main(int argc, char const *argv[])
{
	int n,w,d;
	while(scanf("%d %d %d", &n, &w, &d) != EOF)
	{
		if (n == 0 && w == 0 && d == 0) break;
		std::list<Cake> cakes;
		cakes.push_back(Cake(w, d));
		REP(i, n)
		{
			int p, s;
			scanf("%d %d", &p, &s);
			std::list<Cake>::iterator itr = cakes.begin();
			for (int i = 0; i < (p-1) && itr != cakes.end(); itr++,i++);
			
			Cake& c1 = *itr;
			cakes.erase(itr);
			Cake c2 = c1.Cut(s);
			cakes.push_back(c1);
			cakes.push_back(c2);
		}
		cakes.sort();
		for (std::list<Cake>::iterator itr = cakes.begin(); itr != cakes.end();)
		{
			int area = itr->Area();
			itr++;
			if (itr == cakes.end())
			{
				printf("%d\n", area);
				break;
			}
			else
			{
				printf("%d ", area);
			}
		}
	}
	return 0;
}
