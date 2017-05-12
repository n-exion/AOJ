#include <stdio.h>
#include <string.h>
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


int mem[1000000];
int ans[1000000];

int main(int argc, char const *argv[])
{
	int max_num = 1000000;
	int loop_max = sqrt(1000000);
	memset(mem, 0, 1000000);
	for (int i = 2; i < loop_max; i++)
	{
		int c = i * i;
		while(c < max_num)
		{
			mem[c] = 1;
			c+= i;
		}
	}
	int n;
	int sum = 0;
	ans[0] = ans[1] = 0;
	for (int i = 2; i < max_num; i++)
	{
		sum += mem[i] ? 0 : 1;
		ans[i] = sum;
	}
	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", ans[n]);
	}
	return 0;
}
