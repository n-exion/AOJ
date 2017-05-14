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
#include <string.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	REP(i, n)
	{
		char buf1[101], buf2[101];
		memset(buf1, 0, 101);
		memset(buf2, 0, 101);
		char sum[101];
		memset(sum, 0, 101);
		scanf("%s", buf1);
		scanf("%s", buf2);
		int l, l1 = 0, l2 = 0;
		for (l = 0; l < 100; l++)
		{
			if (buf1[l] == '\0' && l1 == 0)
			{
				l1 = l;
			}
			if (buf2[l] == '\0' && l2 == 0)
			{
				l2 = l;
			}
			if (l1 > 0 && l2 > 0) break;
		}
		l1--;
		l2--;
		l = (l1 > l2) ? l1 : l2;
		if (l >= 80)
		{
			printf("overflow\n");
			continue;
		}
		l++;
		bool plus = false;
		for (;l >= 0; l--)
		{
			int v1 = (l1 >= 0) ? buf1[l1] - '0': 0;
			int v2 = (l2 >= 0) ? buf2[l2] - '0': 0;
			int v = v1 + v2 + ((plus) ? 1 : 0);
			if (v > 9) 
			{
				plus = true;
				v -= 10;
			}
			else
			{
				plus = false;
			}
			sum[l] = '0' + v;
			l1--;
			l2--;
			if (l1 < 0 && l2 < 0 && !plus) break;
		}
		if (sum[0] == '\0')
		{
			printf("%s\n", &sum[1]);
		}
		else if (sum[80] != 0)
		{
			printf("overflow\n");
		}
		else
		{
			printf("%s\n", sum);
		}
	}
	return 0;
}
