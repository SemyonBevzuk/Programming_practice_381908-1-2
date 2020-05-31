#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

enum eDirection {DEFAULT, STOP, LEFT, RIGHT, UP, DOWN};

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

struct Snake
{
    int x,y,bodyX[400], bodyY[400], body, dir;
};

class Input
{
public:
    int dirInput()
    { 
        if (_kbhit()) {
            switch (_getch())
            { 
            case 75:
                return LEFT;
            case 72:
                return UP;
            case 80:
                return DOWN;
            case 77:
                return RIGHT;
            case 'q':
                return STOP;
            default:
                return DEFAULT;
            }
        }
    }
};

class Console
{
public:
    void SetColor(int text, int background)
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    void Draw(size_t width, size_t height, Snake snake, int fruitX, int fruitY, int score)
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
                
                if (i == snake.y && j == snake.x) {
                     SetColor(Red,Black);
                    cout << "O";
                }
                
                
                else if (i == fruitY && j == fruitX) 
                    cout << "Q";
            
                else 
                {
                    
                    bool print = false;
                    for (int k = 0; k < snake.body; k++) 
                    {
                        if (snake.bodyX[k] == j && snake.bodyY[k] == i) 
                        {   
                            SetColor(Green,Black);
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
};

class Game
{
private:
    size_t width, height;
    bool end = false, off = false;
    int fruitX, fruitY;
    int score;
    Snake snake;
public:
    Game(size_t _width, size_t _height)
    {
        width = _width;
        height = _height;
    }
    void init_Game()
    { 
        system("cls");
        cout << "\n!!!!!!!!!!!!!!!ÇÌÅÉÊÀ!!!!!!!!!!!!!!!!!!!!"
            << "\n%%%%%%%%%%%%nÑîáåðèòå 9 Q %%%%%%%%%%%%%%%%%"
            << "\n\n             Íàæìèòå 'g' ÷òîáû Íà÷àòü!"
            << "\n\n             Íàæìèòå 'q' äëÿ âûõîäà"
            << "\n\n             Âàø ñ÷åò: " << score << endl;
    }
    pair<int, int> fruit_init()
    {
        int x,y;
        x = rand() % width;
        y = rand() % height;
        return pair<int,int> (x,y);
    }
    void Setup() 
    {
        end = false;
        off = false;
        snake.x = width / 2;
        snake.y = height / 2;
        pair<int, int> fruitXY;
        fruitXY = fruit_init();
        fruitX = fruitXY.first;
        fruitY = fruitXY.second;
        score = 0;
        snake.body = 0;
        if (score < 1) 
        {
            snake.body=5;snake.dir = LEFT; 
        }
    }
    void Logic()
    {
        int prevX = snake.bodyX[0];
        int prevY = snake.bodyY[0];
        int prev2X, prev2Y;
        snake.bodyX[0] = snake.x;
        snake.bodyY[0] = snake.y;

        for (int i = 1; i < snake.body; i++) {
            prev2X = snake.bodyX[i];
            prev2Y = snake.bodyY[i];
            snake.bodyX[i] = prevX;
            snake.bodyY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;

        }

        switch (snake.dir)
        {
        case LEFT:
            snake.x--;
            break;
        case RIGHT:
            snake.x++;
            break;
        case UP:
            snake.y--;
            break;
        case DOWN:
            snake.y++;
            break;
        }
        if (snake.x > width || snake.body < 0 || snake.y > height || snake.y < 0) {
            off = true;
            init_Game();
        }

        for (int i = 0; i < snake.body; i++) {
            if (snake.bodyX[i] == snake.x && snake.bodyY[i] == snake.y)
                off = true;
        }

        if (snake.x == fruitX && snake.y == fruitY) {
            score++;
            snake.body++;
            fruit_init();
        }
        if (score>8) {
            system("cls"); 
            cout << "ÏÎÁÅÄÀ";
            off = true;
        }
        
    }
    void run()
    {
        Input input;
        Console console;

        console.SetColor(Green,Black);
        do {
            init_Game();
            string btn;
            cin >> btn;
            if (btn == "g")
            {
                Setup();
                while (!off)
                {
                    console.Draw(width, height, snake, fruitX, fruitY, score);
                    snake.dir = input.dirInput();
                    Logic();
                    //Sleep(100);
                }
            }
            else if (btn == "q")
                off = true;
        } while (off == false);
    }
};