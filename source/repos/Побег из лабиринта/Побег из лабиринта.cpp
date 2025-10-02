#include <iostream>
#include <windows.h>
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
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
	string complexity = "Легко";
} charLab;


// Функция для перемещения главного меню по центру по горизонтали.
void printCenter(const string TEXT, bool isPrintTitle = false);

// Функция для перемещения главного меню по центру по вертикали
int getConsoleHeight();

// Функция для скрытия курсора.
void clearCursor();

// Функция для отображения главного меню.
void mainMenu();

// Функция для отслеживания нажатий кнопок в главном меню.
short clickButton();

// Функция окна, появляющегося после выбора "Начать игру".
void startGame();

// Функция окна "Загрузить игру".
void loadGame();

// Функция окна "Настройки".
void settings();

// Функция окна "О программе".
void aboutProgramm();

// Функция для начала работы с файлом.
void fileStart();

// Функция для конца работы с файлом.
void fileEnd();

// Функция, проверяющая, была ли отпущена клавиша Enter, S, W.
// Если была отпущена - возвращается 0, иначе - 1.
short was_passed_button();






int main() {
	

	fileStart();

	clearCursor();
	cout << "Для начала игры нажмите кнопку F11";
	while (true) {
		if (GetAsyncKeyState(VK_F11) & 0x8000) {
			system("cls");
			break;
		}
	}

	mainMenu();
	
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
void mainMenu() {
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
		startGame();
		break;
	}
	case 2: {
		loadGame();
		break;
	}
	case 3: {
		settings();
		break;
	}
	case 4: {
		aboutProgramm();
		break;
	}
	case 5: {
		fileEnd();
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
void startGame() {
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
	mainMenu();
}

// Функция окна "Загрузить игру"
void loadGame() {
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
	mainMenu();
}

// Функция окна "Настройки".
void settings() {

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
		cout << charLab.labyrinthWidth << "x" << charLab.labyrinthHeight;

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
		cout << charLab.complexity;

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
			if (isLeft && charLab.labyrinthWidth != 100) {
				charLab.labyrinthWidth -= 30;
				charLab.labyrinthHeight -= 4;
				charLab.complexity = charLab.labyrinthWidth == 100 ? "Легко" :
					charLab.labyrinthWidth == 130 ? "Средне" :
					charLab.labyrinthWidth == 160 ? "Сложно" :
					"Невозможно";
			}
			else if (!isLeft && charLab.labyrinthWidth < 190) {
				charLab.labyrinthWidth += 30;
				charLab.labyrinthHeight += 4;
				charLab.complexity = charLab.labyrinthWidth == 100 ? "Легко" :
					charLab.labyrinthWidth == 130 ? "Средне" :
					charLab.labyrinthWidth == 160 ? "Сложно" :
					"Невозможно";
			}
		}
		Sleep(100);
	}
	mainMenu();
}

// Функция окна "О программе".
void aboutProgramm() {
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
	mainMenu();
}

// Функция для работы с файлом.
void fileStart() {
	const string PATH = "settings.json";
	fstream file(PATH, ios::in);
	if (!file.is_open()) {
		file.open(PATH, ios::out);
		if (!file.is_open()) {
			cout << "Ошибка при запуске приложения! Повторите попытку.";
			exit(0);
		}
		json data;
		data["labyrinthWidth"] = 100;
		data["labyrinthHeight"] = 20;
		data["complexity"] = "Легко";

		file << data.dump(4);	
		file.close();
	}
	else {
		json data;
		file >> data;
		file.close();
		charLab.labyrinthHeight = data["labyrinthHeight"];
		charLab.labyrinthWidth = data["labyrinthWidth"];
		charLab.complexity = data["complexity"];
	}
}

// Функция для конца работы с файлом.
void fileEnd() {
	const string PATH = "settings.json";
	json data;

	data["labyrinthWidth"] = charLab.labyrinthWidth;
	data["labyrinthHeight"] = charLab.labyrinthHeight;
	data["complexity"] = charLab.complexity;

	fstream file(PATH);
	if (!file.is_open()) {
		cout << "Ошибка сохранения";
		exit(0);
	}

	file << data.dump(4);
	file.close();

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