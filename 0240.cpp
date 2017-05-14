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
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int main(int argc, char const *argv[])
{
	while(true)
	{
		int n, y;
		scanf("%d", &n);
		if (n == 0) break;
		scanf("%d", &y);
		int b, r, t;
		int number = 0;
		float maxVal = 0.0;
		REP(i, n)
		{
			scanf("%d %d %d", &b, &r, &t);
			float val = 1.0;
			if (t == 1)
			{
				val = 1.0 + ((float)r / 100. * (float)y);
			}
			else
			{
				float a = 1.0 + ((float)r / 100.);
				REP(j, y)
				{
					val *= a;
				}
			}
			if (val > maxVal)
			{
				number = b;
				maxVal = val;
				// printf("num:%d, val:%f\n", number, val);
			}
		}
		printf("%d\n", number);
	}
	return 0;
}
