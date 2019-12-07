

/*
	  A   B   C   D   E   F   G   H
1   *********************************
2   * 1 | 2 | 3 | 4 | 5 | 3 | 2 | 1 * 1
3   *********************************
4   * 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 * 2
5   *********************************
6   *   |   |   |   |   |   |   |   * 3
7   *********************************
8   *   |   |   |   |   |   |   |   * 4
9   *********************************
10  *   |   |   |   |   |   |   |   * 5
11  *********************************
12  *  |   |   |   |   |   |   |   * 6
13  *********************************
14  * P| 0 | 0 | 0 | 0 | 0 | 0 | 0 * 7
15  *********************************
16  * 1 | 2 | 3 | 4 | 5 | 3 | 2 | 1 * 8
17  *********************************
	  1234567
*/

//preproccessor


#include <iostream>
#include <map>
#include <string>
#include <vector>
//defined variables

//chess board height and width
#define height 17
#define width 33

//game logic
bool gameOver = false;

//pieces coordinates

//Player 1 Coordinates

int  T = 2;int  H = 6;int  B = 10; int  Q = 14; int  K = 18; int  B1 = 22; int  H1 = 26; int T1 = 30;
int P1 = 2; int P2 = 6; int P3 = 10; int P4 = 14; int P5 = 18; int P6 = 22; int P7 = 26; int P8 = 30;

//Computer / Player 2 Coordinates

int one = 2; int two = 6; int three = 10; int four = 14; int five = 18; int three1 = 22; int two1 = 26; int one1 = 30;
int z1 = 2; int z2 = 6; int z3 = 10; int z4 = 14; int z5 = 18; int z6 = 22; int z7 = 26; int z8 = 30;
//y start coordinates
int yone = 1; int ytwo = 1; int ythree = 1; int yfour = 1; int yfive = 1; int ythree1 = 1; int ytwo1 = 1; int yone1 = 1;
int yz1 = 3; int yz2 = 3; int yz3 = 3; int yz4 = 3; int yz5 = 3; int yz6 = 3; int yz7 = 3; int yz8 = 3;
int yP1 = 13; int yP2 = 13; int yP3 = 13; int yP4 = 13; int yP5 = 13; int yP6 = 13; int yP7 = 13; int yP8 = 13;
int yT = 15; int yH = 15; int yB = 15; int yQ = 15; int yK = 15; int yB1 = 15; int yH1 = 15; int yT1 = 15;


//chess board
char map[width][height];

char piece[4] = { 'T', 'H', 'Q', 'K' };

//decleared functions
void init_map();
void print_map();
void chess_pieces();
void moves();


/*
||||||||||||||||||||||||
||                    ||
||       Maping       ||
||                    ||
||||||||||||||||||||||||
*/

std::map <int, char> y{
  {1, '1'},
  {3, '2'},
  {5, '3'},
  {7, '4'},
  {9, '5'},
  {11, '6'},
  {13, '7'},
  {15, '8'},
};
std::map <int, char> x{
  {2, 'A'},
  {6, 'B'},
  {10, 'C'},
  {14, 'D'},
  {18, 'E'},
  {22, 'F'},
  {26, 'G'},
  {30, 'H'},
};
std::map <char, int> xr{
	{'A', 2},
	{'B', 6},
	{'C', 10},
	{'D', 14},
	{'E', 18},
	{'F', 22},
	{'G', 26},
	{'H', 30},
};
std::map <int, int> yr{
  {'1', 1},
  {'2', 3},
  {'3', 5},
  {'4', 7},
  {'5', 9},
  {'6', 11},
  {'7', 13},
  {'8', 15},
};


/*
||||||||||||||||||||||||
||                    ||
||      CLASSES       ||
||                    ||
||||||||||||||||||||||||
*/



//main function
int main()
{

	while (!gameOver) {

		init_map();
		chess_pieces();
		print_map();
		moves();
	}

	return 0;

}













/*
||||||||||||||||||||||||
||                    ||
||      FUNCTIONS     ||
||                    ||
||||||||||||||||||||||||
*/
//initilize map
void init_map()
{
	//nested loop to initilize the grid patter
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == width - 1 || i == height - 1 || j == 0 || i == 0 || i % 2 == 0)
			{
				map[j][i] = '*';
			}
			else if (j % 4 == 0)
			{
				map[j][i] = '|';
			}
			else
			{
				map[j][i] = ' ';
			}
		}
	}
}


//print map functions
void print_map()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << map[j][i];

		}std::cout << std::endl;

	}
}
//set chess pieces
void chess_pieces()
{
	//tower
	map[T][yT] = 'T';
  map[H][yH] = 'H';
  map[B][yB] = 'B';
  map[Q][yQ] = 'Q';
  map[P1][yP1] = '+';
  map[P2][yP2] = '!';
  map[P3][yP3] = '@';
  map[P4][yP4] = '#';
  map[P5][yP5] = '$';
  map[P6][yP6] = '%';
  map[P7][yP7] = '^';
  map[P8][yP8] = '&';


}

//movement of chess pieces
void moves()
{
  char l;
  std::cout << "What piece do you want to move: " << std::endl;
  std::cin >> l;

//tower moves
  if(l == 'T')
  {
	std::cout << "These are all the possible moves you can do" << std::endl;
	for (int i = 1; i < 10; i++)
	{

		if (map[T][yT - 2 * i] == ' ')
		{
			std::cout << x.at(T) << " " << y.at(yT - 2 * i) << std::endl;
		}
		else if (map[T][yT - 2 * i] == 'X')
		{
			std::cout << "You Can Eat: " << x.at(T) << " " << y.at(yT - 2 * i) << std::endl;

			break;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (map[T + 4 * i][yT] == ' ')
		{
			std::cout << x.at(T + 4 * i) << ' ' << y.at(yT) << std::endl;
		}
		else if (map[T + 4 * i][yT] == 'X') {
			std::cout << "You Can Eat: " << x.at(T + 4 * i) << ' ' << y.at(yT) << std::endl;
			break;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (map[T][yT + 2 * i] == ' ')
		{

			std::cout << x.at(T) << " " << y.at(yT + 2 * i) << std::endl;
		}
		else if (map[T][yT + 2 * i] == 'X') {
			std::cout << "You Can Eat: " << x.at(T + 4 * i) << ' ' << y.at(yT) << std::endl;
			break;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (map[T][yT + 2 * i] == ' ')
		{
			std::cout << x.at(T) << " " << y.at(yT + 2 * i) << std::endl;
		}
		else if (map[T][yT + 2 * i] == 'X') {
			std::cout << "You Can Eat: " << x.at(T + 4 * i) << ' ' << y.at(yT) << std::endl;
			break;
		}
	}
	 std::string move;
	  std::cout << "Where do you want to move your tower: ";
	   std::cin >> move;
	    T = xr.at(move[0]);
	     yT = yr.at(move[1]);
	     map[T][yT] = 'T';
}
//horse moves

else if(l  == 'H')
{
  std::cout << "Possible movevs: " << std::endl;
  for(int i = 0; i < 2; i++)
  {
    //H - 4*i - 4 yH - 4/(i+1)
    if(map[H - 4*i - 4][yH - 4/(i+1)]  == ' ')
    {
      std::cout << x.at(H - 4*i - 4) << " " << y.at(yH - 4 / (i + 1)) << std::endl;
    }
  }
  for(int i = 0; i < 2; i++)
  {
    //initial is y
    //H + 4 *i + 4 yB + 4 / (i + 1)
    if(map[H + 4*i + 4][yH + 4/(i + 1)] == ' ')
    {

      std::cout << x.at(H + 4*i + 4) << " " << y.at(yH + 4 / (i + 1)) << std::endl;
    }
  }
    for(int i = 0; i < 2; i++)
    {
      //initial is y
      ///H + 4*i + 4   yB - 4 /(i+1)
      if(map[H + 4*i + 4][yH - 4 /(i+1)] == ' ')
      {
        std::cout << x.at(H + 4*i + 4) << " " << y.at(yH - 4 / (i + 1)) << std::endl;
      }

  }
  for(int i = 0; i < 2; i++)
  {
    //initial is y
    //H - 4*i - 4 yH + 4 / ( i + 1)

    if(map[H-4*i - 4][yH + 4 / (i+1)] == ' ')
    {
      std::cout << x.at(H - 4*i - 4) << " " << y.at(yH + 4 / (i + 1)) << std::endl;
    }
  }

 std::string move;
 std::cout << "Where do you want to move your Horse: ";
 std::cin >> move;
 H = xr.at(move[0]);
 yH = yr.at(move[1]);
 map[H][yH] = 'H';

}
//bishop moves
else if(l == 'B')
{
    std::cout << "Possible movevs: " << std::endl;

    for(int i = 0; i < 8; i++)
    {
      if(map[B - 4 * i][yB + 2 * i] == ' ')
      {
        std::cout << x.at(B - 4*i) << " " << y.at(yB + 2*i) << std::endl;
      }
      else if(map[B - 4*i][yB + 2*i] == 'X')
      {
        std::cout <<"You can Eat: " << x.at(B - 4*i) << " " << y.at(yB + 2*i) << std::endl;
        break;
      }
    }

  for(int i = 0; i < 8; i++)
  {
    if(map[B + 4 * i][yB + 2 * i] == ' ')
    {
      std::cout << x.at(B + 4*i) << " " << y.at(yB + 2*i) << std::endl;
    }
    else if(map[B + 4*i][yB + 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(B + 4*i) << " " << y.at(yB + 2*i) << std::endl;
      break;
    }
  }

  for(int i = 0; i < 8; i++)
  {
    if(map[B + 4 * i][yB - 2 * i] == ' ')
    {
      std::cout << x.at(B + 4*i) << " " << y.at(yB - 2*i) << std::endl;
    }
    else if(map[B + 4*i][yB - 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(B + 4*i) << " " << y.at(yB - 2*i) << std::endl;
      break;
    }
  }

  for(int i = 0; i < 8; i++)
  {
    if(map[B - 4 * i][yB - 2 * i] == ' ')
    {
      std::cout << x.at(B - 4*i) << " " << y.at(yB - 2*i) << std::endl;
    }
    else if(map[B - 4*i][yB - 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(B - 4*i) << " " << y.at(yB - 2*i) << std::endl;
      break;
    }
  }


  std::string move;
  std::cout << "Where do you want to move your Bishop: ";
  std::cin >> move;
  B = xr.at(move[0]);
  yB = yr.at(move[1]);
  map[B][yB] = 'B';
}
  if(l == 'Q')
  {
    std::cout << "Possible movevs: " << std::endl;
    for (int i = 1; i < 10; i++)
  	{

  		if (map[Q][yQ - 2 * i] == ' ')
  		{
  			std::cout << x.at(Q) << " " << y.at(yQ - 2 * i) << std::endl;
  		}
  		else if (map[Q][yQ - 2 * i] == 'X')
  		{
  			std::cout << "You Can Eat: " << x.at(Q) << " " << y.at(yQ - 2 * i) << std::endl;

  			break;
  		}
  	}
  	for (int i = 1; i < 10; i++)
  	{
  		if (map[Q + 4 * i][yQ] == ' ')
  		{
  			std::cout << x.at(Q + 4 * i) << ' ' << y.at(yQ) << std::endl;
  		}
  		else if (map[Q + 4 * i][yQ] == 'X') {
  			std::cout << "You Can Eat: " << x.at(Q + 4 * i) << ' ' << y.at(yQ) << std::endl;
  			break;
  		}
  	}
  	for (int i = 1; i < 10; i++)
  	{
  		if (map[Q][yQ + 2 * i] == ' ')
  		{
  			std::cout << x.at(Q) << " " << y.at(yQ + 2 * i) << std::endl;
  		}
  		else if (map[Q][yQ + 2 * i] == 'X') {
  			std::cout << "You Can Eat: " << x.at(Q + 4 * i) << ' ' << y.at(yQ) << std::endl;
  			break;
  		}
  	}
  	for (int i = 1; i < 10; i++)
  	{
  		if(map[Q][yQ + 2 * i] == ' ')
  		{
  			std::cout << x.at(Q) << " " << y.at(yQ + 2 * i) << std::endl;
  		}
  		else if (map[Q][yQ + 2 * i] == 'X') {
  			std::cout << "You Can Eat: " << x.at(Q + 4 * i) << ' ' << y.at(yQ) << std::endl;
  			break;
  		}
  	}
    for(int i = 0; i < 8; i++)
    {
      if(map[Q - 4 * i][yQ + 2 * i] == ' ')
      {
        std::cout << x.at(Q - 4*i) << " " << y.at(yQ + 2*i) << std::endl;
      }
      else if(map[Q - 4*i][yQ + 2*i] == 'X')
      {
        std::cout <<"You can Eat: " << x.at(Q - 4*i) << " " << y.at(yQ + 2*i) << std::endl;
        break;
      }
    }

  for(int i = 0; i < 8; i++)
  {
    if(map[Q + 4 * i][yQ + 2 * i] == ' ')
    {
      std::cout << x.at(Q + 4*i) << " " << y.at(yQ + 2*i) << std::endl;
    }
    else if(map[Q + 4*i][yQ + 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(Q + 4*i) << " " << y.at(yQ + 2*i) << std::endl;
      break;
    }
  }

  for(int i = 0; i < 8; i++)
  {
    if(map[Q + 4 * i][yQ - 2 * i] == ' ')
    {
      std::cout << x.at(Q + 4*i) << " " << y.at(yQ - 2*i) << std::endl;
    }
    else if(map[Q + 4*i][yQ - 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(Q + 4*i) << " " << y.at(yQ - 2*i) << std::endl;
      break;
    }
  }

  for(int i = 0; i < 8; i++)
  {
    if(map[Q - 4 * i][yQ - 2 * i] == ' ')
    {
      std::cout << x.at(Q - 4*i) << " " << y.at(yQ - 2*i) << std::endl;
    }
    else if(map[Q - 4*i][yQ - 2*i] == 'X')
    {
      std::cout <<"You can Eat: " << x.at(Q - 4*i) << " " << y.at(yQ - 2*i) << std::endl;
      break;
    }
  }
  std::string move;
  std::cout << "Where do you want to move your Queen: ";
  std::cin >> move;
  Q = xr.at(move[0]);
  yQ = yr.at(move[1]);
  map[Q][yQ] = 'Q';



    //enter

  }
  if(l == '+')
  {
    if(P1 == 2 && yP1 == 13)
    {
      if(map[P1][yP1 - 4] == ' ')
      {
        std::cout << x.at(P1) << " " << y.at(yP1 - 4) << std::endl;
      }
      if(map[P1][yP1 - 2] == ' ')
      {
        std::cout << x.at(P1) << " " << y.at(yP1 - 2) << std::endl;
      }

    }
    else
    {
      if(map[P1][yP1 - 2] == ' ')
      {
        std::cout << x.at(P1) << " " << y.at(yP1 - 2) << std::endl;
      }
      else if(map[P1 - 4][yP1 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P1- 4) << " " << y.at(yP1 - 2) << std::endl;
      }
      else if(map[P1 + 4][yP1 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P1 + 4) << " " << y.at(yP1 - 2) << std::endl;
      }

    }

    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P1 = xr.at(move[0]);
    yP1 = yr.at(move[1]);
    map[P1][yP1] = '+';
  }
  if(l == '!')
  {
    if(P2 == 6 && yP2 == 13)
    {
      if(map[P2][yP2 - 4] == ' ')
      {
        std::cout << x.at(P2) << " " << y.at(yP2 - 4) << std::endl;
      }
      if(map[P2][yP2 - 2] == ' ')
      {
        std::cout << x.at(P2) << " " << y.at(yP2 - 2) << std::endl;
      }

    }
    else
    {
      if(map[P2][yP2 - 2] == ' ')
      {
        std::cout << x.at(P2) << " " << y.at(yP2 - 2) << std::endl;
      }
      else if(map[P2 - 4][yP2 + 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P2 - 4) << " " << y.at(yP2 + 2) << std::endl;
      }
      else if(map[P2 + 4][yP2 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P2 + 4) << " " << y.at(yP2 - 2) << std::endl;
      }

    }

    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P2 = xr.at(move[0]);
    yP2 = yr.at(move[1]);
    map[P2][yP2] = '!';
  }

  if(l == '@')
  {
    if(P3 == 10 && yP3 == 13)
    {
      if(map[P3][yP3 - 4] == ' ')
      {
        std::cout << x.at(P3) << " " << y.at(yP3 - 4) << std::endl;
      }
      if(map[P3][yP3 - 2] == ' ')
      {
        std::cout << x.at(P3) << " " << y.at(yP3 - 2) << std::endl;
      }
    }
    else
    {
      if(map[P3][yP3 - 2] == ' ')
      {
        std::cout << x.at(P3) << " " << y.at(yP3 - 2) << std::endl;
      }
      else if(map[P3 - 4][yP3 - 2] == 'X')
       {
         std::cout << "You Can Eat: " << std::endl;
         std::cout << x.at(P3- 4) << " " << y.at(yP3 - 2) << std::endl;
       }
       else if(map[P3 + 4][yP3 - 2] == 'X')
       {
         std::cout << "You Can Eat: " << std::endl;
         std::cout << x.at(P3 + 4) << " " << y.at(yP3 - 2) << std::endl;
       }

    }


    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P3 = xr.at(move[0]);
    yP3 = yr.at(move[1]);
    map[P3][yP3] = '@';
  }
  if(l == '#')
  {
    if(P4 == 14 && yP4 == 13)
    {
      if(map[P4][yP4 - 4] == ' ')
      {
        std::cout << x.at(P4) << " " << y.at(yP4 - 4) << std::endl;
      }
      if(map[P4][yP4 - 2] == ' ')
      {
        std::cout << x.at(P4) << " " << y.at(yP4 - 2) << std::endl;
      }

    }
    else{
      if(map[P4][yP4 - 2] == ' ')
      {
        std::cout << x.at(P4) << " " << y.at(yP4 - 2) << std::endl;
      }
      else if(map[P4 - 4][yP4 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P4 - 4) << " " << y.at(yP4 - 2) << std::endl;
      }
      else if(map[P4 + 4][yP4 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P4 + 4) << " " << y.at(yP4 - 2) << std::endl;
      }
    }
    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P4 = xr.at(move[0]);
    yP4 = yr.at(move[1]);
    map[P4][yP4] = '#';
  }
  if(l == '$')
  {
    if(P5 == 18 && yP5 == 13)
    {
      if(map[P5][yP5 - 4] == ' ')
      {
        std::cout << x.at(P5) << " " << y.at(yP5 - 4) << std::endl;
      }
      if(map[P5][yP5 - 2] == ' ')
      {
        std::cout << x.at(P5) << " " << y.at(yP5 - 2) << std::endl;
      }
    }
    else
    {
      if(map[P5][yP5 - 2] == ' ')
      {
        std::cout << x.at(P5) << " " << y.at(yP5 - 2) << std::endl;
      }
      else if(map[P5 - 4][yP5 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P5- 4) << " " << y.at(yP5 - 2) << std::endl;
      }
      else if(map[P5 + 4][yP5 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P5 + 4) << " " << y.at(yP5 - 2) << std::endl;
      }
    }
    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P5 = xr.at(move[0]);
    yP5 = yr.at(move[1]);
    map[P5][yP5] = '$';
  }
  if(l == '%')
  {
    if(P1 == 22 && yP1 == 13)
    {
      if(map[P6][yP6 - 4] == ' ')
      {
        std::cout << x.at(P6) << " " << y.at(yP6 - 4) << std::endl;
      }
      if(map[P6][yP6 - 2] == ' ')
      {
        std::cout << x.at(P6) << " " << y.at(yP6 - 2) << std::endl;
      }
      else
      {
        if(map[P6][yP6 - 2] == ' ')
        {
          std::cout << x.at(P6) << " " << y.at(yP6 - 2) << std::endl;
        }
        else if(map[P6 - 4][yP6 - 2] == 'X')
        {
          std::cout << "You Can Eat: " << std::endl;
          std::cout << x.at(P6- 4) << " " << y.at(yP6 - 2) << std::endl;
        }
        else if(map[P6 + 4][yP6 - 2] == 'X')
        {
          std::cout << "You Can Eat: " << std::endl;
          std::cout << x.at(P6 + 4) << " " << y.at(yP6 - 2) << std::endl;
        }

      }
    }
    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P6 = xr.at(move[0]);
    yP6 = yr.at(move[1]);
    map[P6][yP6] = '%';
  }
  if(l == '^')
  {
    if(P7 == 26 && yP7 == 13)
    {
      if(map[P7][yP7 - 4] == ' ')
      {
        std::cout << x.at(P7) << " " << y.at(P7 - 4) << std::endl;
      }
      if(map[P7][yP7 - 2] == ' ')
      {
        std::cout << x.at(P7) << " " << y.at(P7 - 2) << std::endl;
      }
    }
    else
    {
      if(map[P7][yP7 - 2] == ' ')
      {
        std::cout << x.at(P7) << " " << y.at(P7 - 2) << std::endl;
      }
      if(map[P7 - 4][yP7 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P7- 4) << " " << y.at(yP7 - 2) << std::endl;
      }
      else if(map[P7 + 4][yP7 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P1 + 4) << " " << y.at(yP1 - 2) << std::endl;
      }

    }
    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P7 = xr.at(move[0]);
    P7 = yr.at(move[1]);
    map[P7][yP7] = '^';
  }
  if(l == '&')
  {
    if(P8 == 27 && yP8 == 13)
    {
      if(map[P8][yP8 - 4] == ' ')
      {
        std::cout << x.at(P8) << " " << y.at(yP8 - 4) << std::endl;
      }
      if(map[P8][yP8 - 2] == ' ')
      {
        std::cout << x.at(P8) << " " << y.at(yP8 - 2) << std::endl;
      }
    }
    else
    {
      if(map[P8][yP8 - 2] == ' ')
      {
        std::cout << x.at(P8) << " " << y.at(yP8 - 2) << std::endl;
      }

      else if(map[P8 - 4][yP8 - 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P8 - 4) << " " << y.at(yP8 - 2) << std::endl;
      }
      else if(map[P8 + 4][yP8 + 2] == 'X')
      {
        std::cout << "You Can Eat: " << std::endl;
        std::cout << x.at(P8 + 4) << " " << y.at(yP8 - 2) << std::endl;
      }
    }
    std::string move;
    std::cout << "Where do you want to move your Pawn: ";
    std::cin >> move;
    P8 = xr.at(move[0]);
    yP8 = yr.at(move[1]);
    map[P8][yP8] = '&';
  }




}
