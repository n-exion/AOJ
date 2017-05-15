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
#include <queue>
#include <string.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int depart[50][50];
int W, H;

struct Position
{
	Position(int x, int y): x(x), y(y) {}
	int x, y;
};
std::vector<Position> memo[50][50];

struct State
{
	State(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2), num(0) {}
	Position p1, p2;
	int num;
};

bool move(State& s, int dir)
{
	State orig = s;
	bool move = false;
	int x1, x2, y1, y2;
	if (s.num >= 99) return false;
	switch (dir)
	{	
		case 0: // up
			y1 = (s.p1.y > 0     && depart[s.p1.y-1][s.p1.x] == 0) ? s.p1.y-1 : s.p1.y;
			y2 = (s.p2.y < (H-1) && depart[s.p2.y+1][s.p2.x] == 0) ? s.p2.y+1 : s.p2.y;
			if (s.p1.y == y1 && s.p2.y == y2) return false;
			s.p1.y = y1;
			s.p2.y = y2;
		break;
		case 1: // right
			x1 = (s.p1.x < (W-1) && depart[s.p1.y][s.p1.x+1] == 0) ? s.p1.x+1 : s.p1.x;		
			x2 = (s.p2.x > 0     && depart[s.p2.y][s.p2.x-1] == 0) ? s.p2.x-1 : s.p2.x;
			if (s.p1.x == x1 && s.p2.x == x2) return false;
			s.p1.x = x1;
			s.p2.x = x2;
		break;
		case 2: // down
			y1 = (s.p1.y < (H-1) && depart[s.p1.y+1][s.p1.x] == 0) ? s.p1.y+1 : s.p1.y;
			y2 = (s.p2.y > 0     && depart[s.p2.y-1][s.p2.x] == 0) ? s.p2.y-1 : s.p2.y;		
			if (s.p1.y == y1 && s.p2.y == y2) return false;
			s.p1.y = y1;
			s.p2.y = y2;			
		break;
		case 3: // left
			x1 = (s.p1.x > 0     && depart[s.p1.y][s.p1.x-1] == 0) ? s.p1.x-1 : s.p1.x;
			x2 = (s.p2.x < (W-1) && depart[s.p2.y][s.p2.x+1] == 0) ? s.p2.x+1 : s.p2.x;		
			if (s.p1.x == x1 && s.p2.x == x2) return false;
			s.p1.x = x1;
			s.p2.x = x2;
		break;
	}
	vector<Position>& mem = memo[s.p1.y][s.p1.x];
	REP(i, SZ(mem))
	{
		if (mem[i].x == s.p2.x && mem[i].y == s.p2.y)
		{
			return false;
		}
	}
	s.num++;
	return true;
}

int main(int argc, char const *argv[])
{
	while(1)
	{
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0) break;
		int x1, y1, x2, y2;
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);
		State s(x1-1, y1-1, x2-1, y2-1);
		memset(depart, 0, 50*50);
		REP(i, 50) REP(j, 50) memo[i][j].clear();
		REP(i, H)
			REP(j, W)
			{
				int m;
				scanf("%d", &m);
				depart[i][j] = m;
			}
		queue<State> q;
		q.push(s);
		bool success = false;
		while(!q.empty() && !success)
		{
			State s = q.front();
			q.pop();
			if (s.num >= 100)
				continue;
			REP(i,4)
			{
				State next = s;
				if (move(next, i))
				{
					// printf("State:(%d, %d) (%d, %d)\n", next.p1.x, next.p1.y, next.p2.x, next.p2.y);
					if (next.p1.x == next.p2.x && next.p1.y == next.p2.y)
					{
						printf("%d\n", next.num);
						success = true;
						break;
					}
					else
					{
						memo[next.p1.y][next.p1.x].push_back(Position(next.p2.x, next.p2.y));
						q.push(next);
					}
				}
			}
		}
		if (!success)
		{
			printf("NA\n");
		}
	}
	return 0;
}
