#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>


using namespace std;


/* Init X and Y plus the Variables which hold
 previous X and Y. */
int x, y, way, botX = 10, botY = 10, botA, botF;
/* Make a CHAR variable to get Key Input */
char a, pr;
/* Map */
int map[20][20];
/* bool for only one step */
bool step = 0;
bool who = 0;
int life = 3;

void printMap();

void cleanMap();

void printFire();

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;

void clearScreen(int characterLength) {
	for (int i = 0; i < characterLength; i++) {
		cout << "\b";
	}
}

void changeColour(int colour) {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

void showLoadingScreen() {
	int i;
	string closed = "- - -", open = "* * *";
	int colour[] = { RED, GREEN, BLUE };

	cout << closed;

	for (i = 0; i < 3; i++) {
		Sleep(1000);

		clearScreen(5);
		changeColour(colour[i]);

		cout << open;

		Sleep(1000);

		clearScreen(5);
		changeColour(WHITE);

		cout << closed;
	}

	clearScreen(5);
	changeColour(WHITE);
}


void showBlinkingLights() {
	changeColour(RED);
	cout << "CONSOLE ";
	Sleep(1000);

	changeColour(GREEN);
	cout << "TANKS ";
	Sleep(1000);

	changeColour(BLUE);
	cout << " C++";
	Sleep(1000);

	changeColour(WHITE);
}

/* Main Function */
int main() {

	cout << "\n\n\n";
	cout << "      ";

	showLoadingScreen();
	showBlinkingLights();

	cout << "\n\n\n";
	/* Give a value to all integer variables we declared */
	x = 6;
	y = 6;
	way = 177;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
	map[x][y] = 8;
	map[botX][botY] = 18;
	printMap();


	/* start an Infinite Loop */
	while (1 == 1) {


		/* Bot brain */

		/* Bot fire */
		botF = rand() % 2;

		/* Bot way */
		way = rand() % 4;

		/* right way */
		//cout << way;
		//_getch();
		if (step == 1) {
			if (way == 0) {

				if (botY < 19) {
					cleanMap();
					system("CLS");
					map[botX][botY] = 0;
					botY = botY + 1;
					map[botX][botY] = 16;
					printMap();
				}
				if (botF == 1) {
					for (int i = 19; i > botY; i--)
						if (map[botX][botY + (20 - i)] < 2) {
							map[botX][botY + (20 - i)] = 66;
							printMap();
						}
						else {
							system("CLS");
							who = 0;
							printFire();
							break;

						}

				}
			}

			/* up way */


			if (way == 1) {
				if (botX > 0) {
					cleanMap();
					system("CLS");
					map[botX][botY] = 0;
					botX = botX - 1;
					map[botX][botY] = 12;
					printMap();
				}
				if (botF == 1) {
					for (int i = botX - 1; i > -1; i--) {
						if (map[botX - (botX - i)][botY] < 2) {
							map[botX - (botX - i)][botY] = 68;
							printMap();
						}
						else {
							system("CLS");
							who = 0;
							printFire();
							break;

						}
					}
				}
			}

			/* left way */

			if (way == 2) {
				if (botY > 0) {
					cleanMap();
					system("CLS");
					map[botX][botY] = 0;
					botY = botY - 1;
					map[botX][botY] = 14;
					printMap();
				}
				if (botF == 1) {
					for (int i = botY - 1; i > -1; i--) {
						if (map[botX][botY - (botY - i)] < 2) {
							map[botX][botY - (botY - i)] = 66;
							printMap();
						}
						else {
							system("CLS");
							who = 0;
							printFire();
							break;

						}
					}
				}
			}

			/* Down way */

			if (way == 3) {
				if (botY < 19) {
					cleanMap();
					system("CLS");
					map[botX][botY] = 0;
					botX = botX + 1;
					map[botX][botY] = 18;
					printMap();
				}
				for (int i = 1; i + botX < 20; i++) {
					if (map[botX + i][botY] < 2) {
						map[botX + i][botY] = 68;
						printMap();
					}
					else {
						system("CLS");
						who = 0;
						printFire();
						break;

					}

				}

			}
			step = 0;
		}





		/* Arrow check or fire check */
		a = _getch();

		/* If Down Arrow is Pressed, Y is increased */
		if (a == 's') {
			if (x < 19) {
				cleanMap();
				system("CLS");
				map[x][y] = 0;
				x = x + 1;
				map[x][y] = 2;
				printMap();
				step = 1;
			}
		}

		/* If Up Arrow is Pressed, Y is decreased */
		if (a == 'w') {
			if (x > 0) {
				cleanMap();
				system("CLS");
				map[x][y] = 0;
				x = x - 1;
				map[x][y] = 8;
				printMap();
				step = 1;
			}
		}

		/* If Right Arrow is Pressed, X is increased */
		if (a == 'd') {
			if (y < 19) {
				cleanMap();
				system("CLS");
				map[x][y] = 0;
				y = y + 1;
				map[x][y] = 6;
				printMap();
				step = 1;
			}
		}

		/* If Left Arrow is Pressed, X is decreased */
		if (a == 'a') {
			if (y > 0) {
				cleanMap();
				system("CLS");
				map[x][y] = 0;
				y = y - 1;
				map[x][y] = 4;
				printMap();
				step = 1;
			}
		}


		//exit
		if (a == 'q') return 0;



		/* Fire */

		if (a == 'f') {

			cleanMap();

			if (map[x][y] == 2)/* down */ {
				for (int i = 1; i + x < 20; i++) {
					if (map[x + i][y] < 10) {
						map[x + i][y] = 68;
						printMap();
					}
					else {
						who = 1;
						printFire();
						break;
					}

				}
				cleanMap();
			}
			/* up */
			if (map[x][y] == 8) {
				for (int i = x - 1; i > -1; i--) {
					if (map[x - (x - i)][y] < 10) {
						map[x - (x - i)][y] = 68;
						printMap();
					}
					else {
						who = 1;
						printFire();
						break;
					}
				}
				cleanMap();
			}
			if (map[x][y] == 6)/* r */ {
				for (int i = 19; i > y; i--) {
					if (map[x][y + (20 - i)] < 10) {
						map[x][y + (20 - i)] = 66;
						printMap();
					}
					else {
						who = 1;
						printFire();
						break;
					}
				}
				cleanMap();
			}
			if (map[x][y] == 4) /* l */ {
				for (int i = y - 1; i > -1; i--) {
					if (map[x][y - (y - i)] < 10) {
						map[x][y - (y - i)] = 66;
						printMap();
					}
					else {
						who = 1;
						printFire();
						break;
					}
				}
				cleanMap();
			}
		}

	}
}

void cleanMap() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == 68)map[i][j] = 0;
			if (map[i][j] == 66)map[i][j] = 0;
		}
	}
}

void printFire() {
	system("CLS");
	if (life == 1) {
		cout << "Wow WOW wow WWOOWW";
		if (who) {
			cout << "Lucky you!";
			cout << endl << "If you want to play just press any /a-s-w-d/-key" << endl << "If you want exit press /q/";
		}
		else {
			cout << "Be careful!" << endl;
			life--;
			cout << "You have no more life ";
			cout << "press 'q'";
		}
	}
	if (life == 2) {
		if (who) {
			cout << "Lucky you!";
			cout << endl << "If you want to play just press any /a-s-w-d/-key" << endl << "If you want exit press /q/";
		}
		else {
			cout << "Be careful!" << endl;
			life--;
			cout << "You have only " << life << " chance ";
		}
	}
	if (life == 3) {
		if (who) {
			cout << "Lucky you!";
			cout << endl << "If you want to play just press any /a-s-w-d/-key" << endl << "If you want exit press /q/";
		}
		else {
			cout << "Be careful!" << endl;
			life--;
			cout << "You have only " << life << " chance ";

		}
	}

}

void printMap() {
	system("CLS");
	for (auto& i : map) {
		for (int j : i) {
			if (j == 0)cout << " ";
			if (j == 8)cout << "^";
			if (j == 2)cout << "v";
			if (j == 4)cout << "<";
			if (j == 6)cout << ">";
			if (j == 18)cout << "d";
			if (j == 12)cout << "u";
			if (j == 14)cout << "l";
			if (j == 16)cout << "r";
			if (j == 68)cout << "|";
			if (j == 66)cout << "-";
		}
		cout << endl;
	}

}
