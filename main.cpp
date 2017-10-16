#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>

char* convert(const char* text_1) {




	char* result =(char*) calloc(strlen(text_1)*2, sizeof(char));
	int j = 0;
	int ind = 0;
	for (int i = 0; i < strlen(text_1); i++) {
		if (text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�' || text_1[i] == '�') {
			result[j] = text_1[i];
			result[j + 1] = '�';
			result[j + 2] = text_1[i];
			j = j + 3;
			ind = ind + 3;
		}
		else {
			result[j] = text_1[i];
			j++;
			ind++;
		}
		
	}
	char* result_2 = (char*)realloc(result, (ind+1) * sizeof(char));
	result_2[ind] = '\0';
	return result_2;
}

float fun_izm(const char* text_1) {
	int result = 0;
	int bed = 0;
	float rez = 0;
	for (int i = 1; i < strlen(text_1)-1; i++) {
		if (text_1[i]=='�' &&  text_1[i-1]==text_1[i+1]) {
			result++;
		}
		else if (text_1[i] == '�' && text_1[i - 1] != text_1[i + 1] && ((text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�' || text_1[i + 1] == '�'))) {
			bed++;
		}
	}
	if (bed == 0 && result != 0) {
		return 100;
	}
	else if (result==0){
		return 0;
	}
	else {
		rez= bed * 100/result;
		return rez;
	}
}



char* convert_s_to_n(const char* text_1) {
	char* result = (char*)calloc(strlen(text_1), sizeof(char));
	int j = 0;
	int ind = 0;
	for (int i = 0; i < strlen(text_1)-1; i++) {
		if (text_1[i] == '�' && text_1[i - 1] == text_1[i + 1]) {
			i++;
			continue;
		}
		else {
			result[j] = text_1[i];
			j++;
			ind++;
		}
	}
	char* rez = (char*)realloc(result, (ind+1) * sizeof(char));
	rez[ind] = '\0';
	return rez;
}


char* fun_conv(const char* text_1) {
	char* str_1 = (char*)calloc(strlen(text_1), sizeof(char));
	int id = 0;
	for (int i = 0; i < strlen(text_1); i++) {
		
		if (text_1[i] != ' ') {
			str_1[i] =  text_1[i] +1 ;
		}
		else {
			str_1[i] = text_1[i];
		}
		
	}
	str_1[strlen(text_1)] = '\0';
	return str_1;
}



int main() {
	int flag_menu = 0;
	float rez = 0;
	setlocale(LC_ALL, "Rus");

	const char* text_1 = "����� ������ ����� ��� �������. ����� ������ ��� �������� �������.";

	do {
		std::cout << "\n" << "������� ����� ������� :" << "\n";
		std::cin >> flag_menu;

		if (flag_menu == 1) {
			std::cout << "\n" << "������� ������ : " << "\n";
			std::cout << "\n" << "������ ��������� ����� : " << "\n";
			std::cout << text_1;
			std::cout << "\n" << "��������� ������ � �������" << "\n";
			std::cout << convert(text_1);


		}
		if (flag_menu == 2) {
			
			std::cout << "\n" << "������� ������ : " << "\n";
			std::cout << "\n" << "������ ����� : " << "\n";
			std::cout << text_1;
			std::cout << "\n" << "���������� ��������� : " << "\n";
			rez = fun_izm(text_1);
			std::cout << "\n" << "��� ������� ������ ��������� ����� " << rez << "%"<< "\n";
			std::cout << "\n" << "�������� ����� : " << "\n";
			
			const char* str_1=convert(text_1);
			std::cout << "\n" << str_1;
			rez = fun_izm(str_1);
			std::cout << "\n" << "��� ������� ������ ��������� ����� " << rez << "%" << "\n";

		}
		if (flag_menu == 3) {
			std::cout << "\n" << "������� ������ : " << "\n";
			std::cout << "\n" << "������ ����� : " << "\n";
			const char* str_1 = convert(text_1);
			std::cout << "\n" << str_1;
			std::cout << "\n" << "������� �  ������� ����� : " << "\n";
			std::cout << "\n" << convert_s_to_n(str_1);
			
		}
		if (flag_menu == 4) {
			std::cout << "\n" << "������� ��������� : " << "\n";
			std::cout << "\n" << "������ ��������� ����� : " << "\n";
			std::cout << text_1;
			std::cout << "\n" << "����������� ������ : " << "\n";
			std::cout << fun_conv(text_1);
		}


	} while (flag_menu != 0);



}