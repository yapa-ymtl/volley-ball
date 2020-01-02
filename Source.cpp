#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<time.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

const int length = 80, width = 20,x=0,y=1;
bool gameover=false;

int Uscore = 0,severtype,option,hittype,Oscore = 0,opponent[2][6],Opponent, user[2][6], ballx,bonus,bally,bonusx,bonusy, px = 10, py = 10, hit1 = 0, hit2 = 0,q;
enum selectplayer { player1, player2, player3, player4, player5, player6 } player;
enum ballDirection{Up=0,Down,Right,Left}dirct;
char ask_exit;
string username,arrow;

void setup();
void draw();
void ball();
void User();
void Opponents();
void Display();
void stopFlicker();
void gotoXY(int, int);
int Menu();
//void bonusmark();


int main() {
	system("color F0");
	int input = Menu();
	
	switch (input) {
	case 0: {
		system("cls");

		gotoXY(20, 7); cout << "ENTER YOUR TEAM NAME :";
		gotoXY(20, 8); cin >> username;
		system("cls");
		for (int i = 0; i < 25; i++) {
			setup();
			//bonusmark();
			q = 0;
			while (q == 0)
			{
				draw();
				ball();
				User();
				Opponents();
				Display();
			}
			if (gameover) {
				i = 25;
			}
		}
	}
	case 1: {

	}
	case 2: {}
	case 3: {
		system("cls");
		gotoXY(20, 5);
		cout << "ARE YOU SURE\n";
		gotoXY(20, 7);
		cout << "YES(Y)\t\tNO(N)";
		gotoXY(23, 9);cin >> ask_exit;
		if (ask_exit == 'y' || ask_exit == 'Y') {
			system("cls");
			gotoXY(22, 10);
			cout << "THANK YOU!...";
			system("pause>nul");
		}
		else if (ask_exit == 'n' || ask_exit == 'N') {
			system("cls");
			main();
		}

	}
	}
	system("pause");
	return 0;
}
void draw() {
	stopFlicker();cout << endl << endl << endl << endl;
	for (int i = 0; i <= width; i++) {
		cout << "\t\t\t";
		for (int j = 0; j <=length+2; j++) {
			if (i == 0 || i == width)
				cout << "\xDB";
			else {
				int a = 0;
				if (j == 0 || j == length)
					cout << "\xDB";
				if (j == length / 2)
					cout << "\xB2";
				for (int n = 0; n < 6; n++) {
					if (opponent[x][n] == j && opponent[y][n] == i) {
						cout << n + 1; a++;
					}
					 if (user[x][n] == j && user[y][n] == i) {
						 cout << n + 1; a++;
					}
				}
				if (i == bally && j == ballx) {
					cout << "0"; a++;
				}
				if ((i == bonusy && j == bonusx)&&bonus!=1) {
					cout << "B"; a++;
				}
				if(a==0)
					cout << " ";
				
			}
		}cout << endl;
	}
	
}
void setup() {
	ballx = 79; bally = 2;
	/*for (int i = 0; i < 6; i++) {
		opponent[x][i] = 77 - 20 * (i % 2);
		opponent[y][i] = 19 - 9 * (i % 3);
		user[x][i] = 3 + 20 * (i % 2);
		user[y][i] = 19 - 9 * (i % 3);
	}*/
	user[y][(Uscore + 5) % 6] = 10; user[x][(Uscore + 5) % 6] = 10;
	user[y][(Uscore + 4) % 6] = 18; user[x][(Uscore + 4) % 6] = 2;
	user[y][(Uscore + 3) % 6] = 18; user[x][(Uscore + 3) % 6] = 20;
	user[y][(Uscore + 2) % 6] = 10; user[x][(Uscore + 2) % 6] = 32;
	user[y][(Uscore + 1) % 6] = 2; user[x][(Uscore + 1) % 6] = 20;
	user[y][Uscore % 6]= 2  ;      user[x][Uscore % 6] = 2;
	
	opponent[y][(Oscore + 5) % 6] = 10; opponent[x][(Oscore + 5) % 6] = 70;
	opponent[y][(Oscore + 4) % 6] = 18; opponent[x][(Oscore + 4) % 6] = 77;
	opponent[y][(Oscore + 3) % 6] = 18; opponent[x][(Oscore + 3) % 6] = 60;
	opponent[y][(Oscore + 2) % 6] = 10; opponent[x][(Oscore + 2) % 6] = 48;//opponent 3
	opponent[y][(Oscore + 1) % 6] = 2; opponent[x][(Oscore + 1) % 6] = 60;
	opponent[y][Oscore % 6] = 2; opponent[x][Oscore % 6] = 77;
	 
	bonus = 0;
	
}
void User(){
		if (_kbhit())
		{
			switch (_getch()) {
			case '1': player = selectplayer(0); break;
			case '2': player = selectplayer(1); break;
			case '3': player = selectplayer(2); break;
			case '4': player = selectplayer(3); break;
			case '5': player = selectplayer(4); break;
			case '6': player = selectplayer(5); break;
			case 'w': user[y][player]--; dirct = Right; break;
			case 's': user[y][player]++; break;
			case 'a': user[x][player]--; break;
			case 'd': user[x][player]++; break;
			case 'x': gameover = true; break;
			case 'e': dirct = Up; break;
			case 'q': dirct = Down; break;
					}
				}
			}	
void Opponents() {
	if (hit1 != 0) {
		for (int i = 0; i < 6; i++) {
			if (opponent[x][i] == 77 && opponent[y][i] == 2) {
				if (bally < 8 && ballx > 71 && bally>1) {
					opponent[y][i] = bally;
				}
			}
			else if (opponent[x][i] == 77 && opponent[y][i] == 18){
				if(bally < 13 && ballx > 70 && bally>=19 ){
					opponent[y][i] = bally;
				}
			}
			else if (opponent[x][i] == 70 && opponent[y][i] == 10) {
				if (bally < 13 && bally>7 && ballx>60) {
					opponent[y][i] = bally;
				}
			}
			else if (opponent[x][i] == 60 && opponent[y][i] == 18) {
				if (bally <=19 && bally>16 && ballx > 48) {
					opponent[y][i] = bally;
				}
			}
			else if (opponent[x][i] == 60 && opponent[y][i] == 2){
				if(bally>1 && bally < 5 && ballx > 48) {
						opponent[y][i] = bally;
					}
			}
			else if (opponent[x][i] == 48 && opponent[y][i] == 10) {
				if (bally >= 6 && bally <= 14 && ballx > 40) {
						opponent[y][i] = bally;
				 }
				}
			}
		}
	}
void ball()
{
	srand(time(0));

	if (ballx==79&&bally==2) {
		hit1 = 0;
		severtype = rand() % 3;

	}
	if (ballx == user[x][player] && bally == user[y][player]){
       hit1 = 1;
	}
	for (int i = 0; i < 6; i++) {
		if ((ballx == opponent[x][i] && bally == opponent[y][i])&&hit1==1) {
			hit1 = 3;
			hittype = rand() % 3;
			Opponent = i;
		}
	}
	
switch (hit1) {
	case 1: {
		
			if (dirct == Up) {
				ballx++;
				if (ballx % 4 == 0) {
					bally--;
				}
			}
			else if (dirct == Down) {
				ballx++;
				if (ballx % 4 == 0) {
					bally++;
				}
			}
			else if (dirct == Right) {
				ballx++;
			}
		
			break; }
	case 2: {
		ballx -= 5; bally++;
		break;
		}
	case 3: {
		ballx--;
		break;
	}
	case 0: {
		if(severtype == 2){
				ballx--;
				if (ballx % 4 == 0) 
					bally++;
			}
		else if(severtype==1) {
			ballx--;
				if (ballx % 5 == 0) {
				bally++;
				}
			}
		else if(severtype==0){
				ballx--; 
			}
		}
		
	}
	
}
void Display() {
	if (ballx>50 && (bally == 20 || bally == 0) || ballx == 80) {
		Uscore++;
		q++;		
	}
	else if (ballx > 40 && (bally == 20 || bally == 0)) {
		Oscore++;
		q++;
	}
	if (ballx < 30 && (bally == 20 || bally == 0) || ballx <=1 ) {
		Oscore++;
		q++;
	}
	else if (ballx < 40 && (bally == 20 || bally == 0)) {
		Uscore++;
		q++;
	}
	if (Uscore == 25) {
		gameover = true;
	}
	cout << "\t\t\t";
	cout << username << " =" << Uscore;
	if (ballx <= 79 && ballx > 40 && hit1==0) {
		cout << "\t\t"<<"Service by opponent No. " << (Oscore % 6)+1 << "player\t\t\t     ";
	}
	else if (hit1 == 1 && ballx<40 && ballx>0) {
		cout << "\t\t" << "Shot by "<<username<<"'s No. " << player+1 << " player\t\t\t     ";
	}
	else if (hit1 == 3 && ballx < 79 && ballx>40) {
		cout << "\t\t" << "Shot by opponent No. " << Opponent + 1 << " player\t\t\t     ";
	}
	else {
		cout << "\t\t\t\t\t\t\t\t     ";
	}

	cout<< Oscore << "= PC";
}
void stopFlicker() {
	HANDLE hout;
	COORD Position;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hout, Position);
}
void bonusmark() {
	bonusx = rand() % 40;
	bonusy = rand() % 50;

	if (user[x][player] == bonusx && user[y][player] == bonusy) {
		bonus = 1;
		bonusx = rand() % 40;
		bonusy = rand() % 50;
	}
}
void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
int Menu() {
	
	int menu_item = 0, run, x = 7;
	bool running = true;

	gotoXY(17, 5); cout << "SMASH VOLLEY BALL";
	gotoXY(17, 7); cout << "\xAF\xAF";

	while (running)
	{
		gotoXY(20, 7);  cout << "START";
		gotoXY(20, 8);  cout << "INSTRUCTIONS";
		gotoXY(20, 9); cout << "CREDITS";
		gotoXY(20, 10); cout << "QUIT";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 10){
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "\xAF\xAF";
			menu_item++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && x != 7){
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "\xAF\xAF";
			menu_item--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			switch (menu_item) {
			case 0: {
				gotoXY(20, 16);
				return 0;
				break;
			}
			case 1: {
				gotoXY(20, 16);
				return 1;
				break;
			}
			case 2: {
				gotoXY(20, 16);
				return 2;
				break;
			}
			case 3: {
				gotoXY(20, 16);
				return 3;
				break;
			}
			}
		}
	}
	//gotoXY(20, 21);
}

