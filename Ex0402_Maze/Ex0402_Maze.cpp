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

	// 방문했던 적이 없고 ('X'가 아니고)
	// 벽도 아닌 경우 ('1'도 아닌 경우)
	// if (...)
	//{
		// 'X' 표시

		// 옆으로 이동
	//}
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
	while (!s.IsEmpty())
	{
		Pos p = s.Top();
		s.Pop();

		cout << p << " "; // 디버깅 출력

		const char mark = maze[p.row][p.col];
		cout << mark << endl;
		
		if (mark == 'G')
		{
			cout << "Found!" << endl;
			break;
		}
		else if (mark == '0' | mark == 'S' )
		{
			 maze[p.row][p.col] == 'X';
			 s.Push({p.row+1,p.col});
			 s.Push({p.row-1,p.col});
			 s.Push({p.row,p.col+1});
			 s.Push({p.row,p.col-1});
		}
		else if (mark == '1')
		{

		}
		// TODO:
		// s.Print();
	}
}

int main()
{
	PrintMaze();
	std::cout << ""<<std::endl;
	std::cout << ""<<std::endl;
	//RecurMaze({ 1, 1 });
	StackMaze();
	std::cout << ""<<std::endl;
	std::cout << ""<<std::endl;
	PrintMaze();

	return 0;
}



// 1. 이웃 위치(Pos): 현재 위치가 (row, col)라면 그 다음에는 4방향으로 이웃하는 위치들을 탐색을 해나갈 수 있습니다. 4개의 이웃들의 위치는 (row+1, col), (row-1, col), (row, col+1), (row, col-1)가 됩니다. 이때 어느 방향을 먼저 방문해야 하는 지에 대한 순서는 중요하지 않습니다.

// 2. 재귀호출 조기 종료:  발견한 경로인지 아닌지를 반환값으로 알려줍니다.

// 3. 스택 사용: 결국은 모든 이웃들을 다 찾아본다는 전략입니다. "일단은 이쪽 이웃부터 찾아보지만 그쪽으로 가도 없다면 다시 돌아와서 못가본 방향을 찾아가겠다"는 느낌으로 스택에 "가봐야 할 이웃들을" 쌓아놓습니다.

