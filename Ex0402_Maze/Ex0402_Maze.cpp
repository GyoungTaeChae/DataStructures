#include <iostream>

#include "../shared/Stack.h"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;
//1 은 못가는곳 
//0은 갈수잇는곳
//S->G까지 가는 경로 하나를 찾으면됨
//방문한곳은 X로표시 

char maze[kNumRows][kNumCols] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze()
{
	for (int j = 0; j < kNumRows; j++)
	{
		for (int i = 0; i < kNumCols; i++)
			cout << maze[j][i] << " ";
		cout << endl;
	}
}

struct Pos
{
	int row;
	int col;

	// 디버깅을 위한 편의 기능
	friend ostream& operator<<(ostream& os, const Pos& pos)
	{
		cout << "(" << pos.row << ", " << pos.col << ")" << flush;
		return os;
	}
};

void RecurMaze(Pos p)
{
	const char mark = maze[p.row][p.col];

	if (mark == 'G')
	{
		cout << "Found!" << endl;
		return;
	}

	if (mark != 'X' && mark != '1')
	{
		maze[p.row][p.col] = 'X';
		RecurMaze({p.row+1,p.col});
		RecurMaze({p.row-1,p.col});
		RecurMaze({p.row,p.col+1});
		RecurMaze({p.row,p.col-1});
	}
}

//조기 종료가 가능한 버전
//int RecurMaze(Pos p)
//{
//	// TODO:
//}

void StackMaze()
{
	Stack<Pos> s;
	Pos start = { 1, 1 }; // i = 1, j = 1  시작 지점
	s.Push(start); // s.Push({1, 1});
	// s.Print(); // 디버깅에 사용 가능
	// std::cout << s.Size();
	while (!s.IsEmpty())
	{
		Pos p = s.Top();
		s.Pop();

		cout << p << " "; // 디버깅 출력

		const char mark = maze[p.row][p.col];
		
		if (mark == 'G')
		{
			cout << "Found!" << endl;
			break;
		}
		else if (mark == '0')
		{
			 maze[p.row][p.col] = 'X';
			 s.Push({p.row+1,p.col});
			 s.Push({p.row-1,p.col});
			 s.Push({p.row,p.col+1});
			 s.Push({p.row,p.col-1});
		}
		else if (mark == 'S' )
		{
			 s.Push({p.row+1,p.col});
			 s.Push({p.row-1,p.col});
			 s.Push({p.row,p.col+1});
			 s.Push({p.row,p.col-1});
		}
	}
}

int main()
{
	PrintMaze();
	std::cout << ""<<std::endl;
	std::cout << ""<<std::endl;
	RecurMaze({ 1, 1 });
	// StackMaze();
	std::cout << ""<<std::endl;
	std::cout << ""<<std::endl;
	PrintMaze();

	return 0;
}


