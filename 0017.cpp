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

#define DIST(a, b) (((a) - (b) + 26)%26)

int dht = DIST('h', 't');
int deh = DIST('e', 'h');
int dah = DIST('a', 'h');
int dta = DIST('t', 'a');
int dih = DIST('i', 'h');
int dsi = DIST('s', 'i');

int check(const char* word)
{
	if (DIST(word[1], word[0]) != dht)
		return -1;

	if (DIST(word[2], word[1]) == deh && 
		(word[3] == ' ' || word[3] == '\0' || word[3] == '.'))
	{
		return DIST(word[0], 't');
	}
	if (DIST(word[2], word[1]) == dah && 
		DIST(word[3], word[2]) == dta &&
		(word[4] == ' ' || word[4] == '\0' || word[4] == '.'))
	{
		return DIST(word[0], 't');
	}
	if (DIST(word[2], word[1]) == dih && 
		DIST(word[3], word[2]) == dsi && 
		(word[4] == ' ' || word[4] == '\0' || word[4] == '.'))
	{
		return DIST(word[0], 't');
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string s;
	while (getline(std::cin, s))
	{
		int len = s.length();
		int d = check(&s[0]);
		int i = 3;
		while (d == -1)
		{
			while(i < len && s[i] != ' ')
				i++;
			if (i == len) break;
			i++;
			d = check(&s[i]);
		}
		REP(j, len)
		{
			if (s[j] >= 'a' && s[j] <= 'z')
			{
				s[j] = (s[j] - 'a' - d + 26) % 26 + 'a';
			}
		}
		std::cout << s << std::endl;
	}
	return 0;
}
