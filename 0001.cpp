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
	int h;
	int max[3] = {0, 0, 0};
	while(scanf("%d", &h) != EOF)
	{
		if (max[0] < h)
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = h;
		}
		else if (max[1] < h)
		{
			max[2] = max[1];
			max[1] = h;
		}
		else if (max[2] < h)
		{
			max[2] = h;
		}
	}
	printf("%d\n%d\n%d\n", max[0], max[1], max[2]);
	return 0;
}
