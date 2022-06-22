#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	cout << "Совпадение строк в файлах" << endl;

	char* file1 = new char[256];
	char* file2 = new char[256];
	char* line1 = new char[128];
	char* line2 = new char[128];
	cout << "Введите наименование файла 1" << endl;
	cin >> file1;
	cout << "Введите наименование файла 2" << endl;
	cin >> file2;

	FILE* f1;
	f1 = fopen(file1, "r");

	if (f1 == NULL) {
		cout << "Невозможно открыть файл " << f1 << endl;
		return 0;
	}

	FILE* f2;
	f2 = fopen(file2, "r");

	if (f2 == NULL) {
		cout << "Невозможно открыть файл " << f2 << endl;
		return 0;
	}
	int len1 = 0;
	while (!feof(f1)) {
		fgets(line1, 127, f1);
		len1 = strlen(line1);
		if (line1[len1 - 1] == '\n') {
			line1[len1 - 1] = '\0';
		}
		int len2 = 0;
		while (!feof(f2)) {
			fgets(line2, 127, f2);
			len2 = strlen(line2);
			if (line2[len2 - 1] == '\n') {
				line2[len2 - 1] = '\0';
			}

			if (strcmp(line1, line2) != 0) {
				cout << "Строки что не совпадают: " << endl;
				cout << "Строка из файла: " << file1 << ": " << line1 << endl;
				cout << "Строка из файла: " << file2 << ": " << line2 << endl;
			}
		}
		fseek(f2, 0, SEEK_SET);
	}

	fclose(f1);
	fclose(f2);

	_getch();


	return 0;
}

