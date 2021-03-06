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
	long a, b;
	while(scanf("%ld %ld", &a, &b) != EOF)
	{
		long x,y;
		if (a > b)
		{
			x = a;
			y = b;
		}
		else
		{
			x = b;
			y = a;
		}
		while(x != y)
		{
			long tmp = x - y;
			x = tmp > y ? tmp : y;
			y = tmp > y ? y : tmp;
		}
		long l = a/x * b;
		printf("%ld %ld\n", x, l);
	}
	return 0;
}
