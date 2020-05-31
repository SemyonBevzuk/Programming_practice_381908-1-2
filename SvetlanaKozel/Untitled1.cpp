#include <iostream>
#include <conio.h>
#include <string>
#include<windows.h>

using namespace std;
//заводим переменные
bool end;
bool off;
int width;
int height;
int x, y;
int fruitX, fruitY; 
int score;
int bodyX[400], bodyY[400], body;
//цвета
enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
       DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};
//также цвета
void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
 
void SetColor(int text, ConsoleColor background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
// управление
enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};

eDirection dir;
// меню
void init_Game()
{ 
	system("cls");
	cout << "\n!!!!!!!!!!!!!!!ЗМЕЙКА!!!!!!!!!!!!!!!!!!!!"
		<< "\n%%%%%%%%%%%%nСоберите 9 Q %%%%%%%%%%%%%%%%%"
	     << "\n\n             Нажмите 'g' чтобы Начать!"
	     << "\n\n             Нажмите 'q' для выхода"
	     << "\n\n             Ваш счет: " << score << endl;
	    
}


void fruit_init(){
	fruitX = rand() % width;
	fruitY = rand() % height;
}
void Setup() 
{
	end = false;
	off = false;
	x = width / 2;
	y = height / 2;
	fruit_init();
	score = 0;
	body = 0;
	if (score < 1) {
			body=5;dir = LEFT; }
}
// рисуем карту,голову,еду,тело и пустое место
void Draw()
{
	system("cls");                         

	for (int i = 0; i < width + 2; i++) 
	{
		cout << "#";
	}
	cout << endl;
	
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (j == 0) 
				cout << "#";
			
			if (i == y && j == x) {
				SetColor(Red,Black);
				cout << "O";
			}
			
			
			else if (i == fruitY && j == fruitX) 
				cout << "Q";
		
			else 
			{
				
				bool print = false;
				for (int k = 0; k < body; k++) 
				{
					if (bodyX[k] == j && bodyY[k] == i) 
					{   SetColor(Green,Black);
						cout << "o";
						print = true;
					}
							
				}
				
				if(!print)
					cout << " ";
			}
			
			if (j == width - 1) 
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
	
}
// управление, ждет нажатие клавиши и при нажатии стрелок выполняет dir=*
void Input()
{ 
	if (_kbhit()) {
		switch (_getch())
		{ 
		case 75:
			dir = LEFT;
			break;
			
		case 72:
			dir = UP;
			
			break;
		case 80:
			dir = DOWN;
			
			break;
		case 77:
			dir = RIGHT;
		
			break;
		case 'q':
			off = true;
			break;
		}
	}
}
// логика игры
void Logic()
{
	int prevX = bodyX[0];
	int prevY = bodyY[0];
	int prev2X, prev2Y;
	bodyX[0] = x;
	bodyY[0] = y;

	for (int i = 1; i < body; i++) {
		prev2X = bodyX[i];
		prev2Y = bodyY[i];
		bodyX[i] = prevX;
		bodyY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x > width || x < 0 || y > height || y < 0) {
		off= true;
		init_Game();
	}

	for (int i = 0; i < body; i++) {
		if (bodyX[i] == x && bodyY[i] == y)
			off = true;
	}

	if (x == fruitX && y == fruitY) {
		score++;
		body++;
		fruit_init();
	}
	if (score>8) {
		system("cls"); 
		cout << "ПОБЕДА";
		off = true;
	}
	
}

int main()
{  
// русс
setlocale(LC_ALL, "Russian");
//цвет
SetColor(Green,Black);
// ввод m/n
cout << "Введите n\n";
  cin >> width;

   cout << "Введите m\n";
  cin >> height;
  height = height;
	do {
		init_Game();
		string btn;
		cin >> btn;
		// если нажали g, запускаем
		if (btn == "g")
		{
			Setup();
			while (!off)
			{
				Draw();
				Input();
				Logic();
				Sleep(100);
			}
		}
	// если q - выход
		else if (btn == "q")
			off = true;
	} while (off == false);

    return 0;
}

