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

	int a, b;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		int sum = a+b;	
		int digit = 0;
		while(sum)
		{
			digit++;
			sum /= 10;
		} 
		printf("%d\n", digit);
	}
	return 0;
}
