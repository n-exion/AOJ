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
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int main(int argc, char const *argv[])
{
	int d, a;
	int deg = 90.;
	double x = 0., y = 0.;
	while(1)
	{
		if (scanf("%d,%d", &d, &a) == EOF) break;
		if (d == 0 && a == 0) break;
		double rad = (double)deg / 180. * M_PI;
		x += d * cos(rad);
		y += d * sin(rad);
		deg -= a;
	}
	printf("%d\n%d\n", (int)x, (int)y);
	return 0;
}
