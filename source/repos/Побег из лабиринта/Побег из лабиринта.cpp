#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Функция для выравнивания по центру
/*void printCenter(const string TEXT) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int consoleWidth = 80;

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}

	int padding = (consoleWidth - TEXT.length()) / 2;
	if (padding > 0) {
		wcout << wstring(padding, L' ');
		cout << TEXT << endl;
	}
};*/

// Структура хранящая данные о лабиринте.
struct characteristicsOfTheLabyrinth {
	short labyrinthWidth = 100;
	short labyrinthHeight = 20;
} charLab;


// Функция для перемещения главного меню по центру по горизонтали.
void printCenter(const string TEXT, bool isPrintTitle = false);

// Функция для перемещения главного меню по центру по вертикали
int getConsoleHeight();

// Функция для скрытия курсора.
void clearCursor();

// Функция для отображения главного меню.
void mainMenu(short& labyrinthWidth, short& labyrinthHeight);

// Функция для отслеживания нажатий кнопок в главном меню.
short clickButton();

// Функция окна, появляющегося после выбора "Начать игру".
void startGame(short& labyrinthWidth, short& labyrinthHeight);

// Функция окна "Загрузить игру".
void loadGame(short& labyrinthWeight, short& labyrinthHeight);

// Функция окна "Настройки".
void settings(short& labyrinthWeight, short& labyrinthHeight);

// Функция окна "О программе".
void aboutProgramm(short& labyrinthWidth, short& labyrinthHeight);

// Функция, проверяющая, была ли отпущена клавиша Enter, S, W.
// Если была отпущена - возвращается 0, иначе - 1.
short was_passed_button();






int main() {
	short labyrinthWidth = 100;
	short labyrinthHeight = 20;

	clearCursor();
	cout << "Для начала игры нажмите кнопку F11";
	while (true) {
		if (GetAsyncKeyState(VK_F11) & 0x8000) {
			system("cls");
			break;
		}
	}

	mainMenu(labyrinthWidth, labyrinthHeight);
	
	while (true) {
		int c = 0;
	}
	return 0;
}






// Функция для перемещения главного меню по центру по горизонтали.
void printCenter(const string TEXT, bool isPrintTitle) {
	if (isPrintTitle) {
		cout << string(getConsoleHeight() / 2 - 6, '\n');
	}
	cout << string(65, ' ') << TEXT;
}

// Функция для перемещения главного меню по центру по вертикали
int getConsoleHeight() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	return -1;
}

// Функция для скрытия курсора.
void clearCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursoreInfo;
	GetConsoleCursorInfo(hConsole, &cursoreInfo);
	cursoreInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursoreInfo);
}

// Функция для отображения главного меню.
void mainMenu(short &labyrinthWidth, short &labyrinthHeight) {
	printCenter("Побег из лабиринта", true);
	cout << endl;
	printCenter("1. Начать игру");
	cout << endl;
	printCenter("2. Загрузить игру");
	cout << endl;
	printCenter("3. Настройки");
	cout << endl;
	printCenter("4. О программе");
	cout << endl;
	printCenter("5. Выход");

	short whatButtonWasClicked = clickButton();
	switch (whatButtonWasClicked) {
	case 1: {
		startGame(labyrinthWidth, labyrinthHeight);
		break;
	}
	case 2: {
		loadGame(labyrinthWidth, labyrinthHeight);
		break;
	}
	case 3: {
		settings(labyrinthWidth, labyrinthHeight);
		break;
	}
	case 4: {
		aboutProgramm(labyrinthWidth, labyrinthHeight);
		break;
	}
	case 5: {
		exit(0);
	}
	}
}

// Функция для отслеживания нажатий кнопок в главном меню.
short clickButton() {
	short whatButtonWasClicked = 0;
	while (true) {
		if (GetAsyncKeyState('1') & 0x8000) {
			whatButtonWasClicked = 1;
			break;
		}
		if (GetAsyncKeyState('2') & 0x8000) {
			whatButtonWasClicked = 2;
			break;
		}
		if (GetAsyncKeyState('3') & 0x8000) {
			whatButtonWasClicked = 3;
			break;
		}
		if (GetAsyncKeyState('4') & 0x8000) {
			whatButtonWasClicked = 4;
			break;
		}
		if (GetAsyncKeyState('5') & 0x8000) {
			whatButtonWasClicked = 5;
			break;
		}
	}
	if (!was_passed_button()) {
		return whatButtonWasClicked;
	}
}

// Функция окна, появляющегося после выбора "Начать игру".
void startGame(short& labyrinthWidth, short& labyrinthHeight) {
	system("cls");
	cout << R"(Начало игры
Для выхода в главное меню нажмите 1)";
	while (true) {
		if (GetAsyncKeyState('1') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
	}
	mainMenu(labyrinthWidth, labyrinthHeight);
}

// Функция окна "Загрузить игру"
void loadGame(short& labyrinthWidth, short& labyrinthHeight) {
	system("cls");
	cout << R"(Функция на данный момент не доступна.
Для выхода в главное меню нажмите 2)";
	while (true) {
		if (GetAsyncKeyState('2') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
	}
	mainMenu(labyrinthWidth, labyrinthHeight);
}

// Функция окна "Настройки".
void settings(short& labyrinthWidth, short& labyrinthHeight) {

	bool isLeft = false;
	while (true) {
		system("cls");
		printCenter("Настройки", true);
		cout << endl;
		printCenter("");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (isLeft) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "\b\b- ";
		}
		else {
			cout << "\b\b- ";
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "Размер лабиринта - ";
		cout << labyrinthWidth << "x" << labyrinthHeight;

		if (isLeft) {
			cout << " +";
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << " +";
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << endl;
		printCenter("Сложность: ");
		cout << (labyrinthWidth == 100 ? "Легко" : 
			labyrinthWidth == 130 ? "Средне" : 
			labyrinthWidth == 160 ? "Сложно" : 
			"Невозможно");

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			isLeft = false;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			isLeft = true;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (isLeft && labyrinthWidth != 100) {
				labyrinthWidth -= 30;
				labyrinthHeight -= 4;
			}
			else if (!isLeft && labyrinthWidth < 190) {
				labyrinthWidth += 30;
				labyrinthHeight += 4;
			}
		}
		Sleep(100);
	}
	mainMenu(labyrinthWidth, labyrinthHeight);
}

// Функция окна "О программе".
void aboutProgramm(short& labyrinthWidth, short& labyrinthHeight) {
	system("cls");
	cout << R"(Версия программы: 1.0.
Выполнил: Никита Довгун
Для выхода в главное меню нажмите 4)";
	while (true) {
		if (GetAsyncKeyState('4') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
	}
	mainMenu(labyrinthWidth, labyrinthHeight);
}

// Функция, проверяющая, была ли отпущена клавиша Enter, S, W.
// Если была отпущена - возвращается 0, иначе - 1.
short was_passed_button() {
	bool button = false;
	while (true) {
		// Проверка на нажатие "Enter".
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "Escape".
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "1".
		else if (GetAsyncKeyState('1') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "2".
		else if (GetAsyncKeyState('2') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "3".
		else if (GetAsyncKeyState('3') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "4".
		else if (GetAsyncKeyState('4') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "5".
		else if (GetAsyncKeyState('5') & 0x8000) {
			button = true;
		}
		else if (button) {
			button = false;
			return 0;
		}
	}
	return 1;
}