#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Password.h"

using namespace std;

Password::Password()
{
}
//std::string Password::getPass(const char* prompt, bool show_asterisk) {
//	const char BACKSPACE = 8;
//	const char RETURN = 13;
//
//	string password;
//	unsigned char  ch = 0;
//
//	cout << prompt << endl;
//
//	DWORD con_mode;
//	DWORD dwRead;
//
//	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
//	GetConsoleMode(hIn, &con_mode);
//	SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
//
//	while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
//	{
//		if (ch == BACKSPACE) {
//			if (password.length() != 0) {
//				if (show_asterisk) {
//					cout << "\b \b";
//				}
//				password.resize(password.length() - 1);
//			}
//		}
//		else {
//			password += ch;
//			if (show_asterisk) {
//				cout << "*";
//			}
//		}
//	}
//	cout << endl;
//	//SetConsoleMode(hIn, con_mode & (ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
//	return password;
//}

void Password::setPassword() {
//	m_password = getPass("Please set password: ", true);
	cin >> m_password;
	if (getPassword().length() != 0) {
		ofstream inFile;
		
		inFile.open("password.dat", ios::out | ios::app);
		if (inFile.is_open()) {
			inFile << EncrpytPass(getPassword()) << '\n';
		}
		else {
			std::cerr << "Error opening up file" << endl;
		}
		inFile.close();


	}
	else {
		cerr << "Password must meet requirements";
	}
}

std::string Password::getPassword() {
	return m_password;
}


std::string Password::EncrpytPass(std::string password) {
	std::string encrypted = password;
	char key = 'V';
	for (size_t i = 0; i < password.size(); ++i) {
		encrypted[i] ^= key;
	}

	return encrypted;
}

bool Password::checkPassword(std::string password) {
	fstream file;
	std::string cyclePass;
	file.open("password.dat");
	while (std::getline(file, cyclePass)) {

		if (EncrpytPass(cyclePass) == password) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}


bool Password::enterPassword(std::istream &in) {
	std::string inputPass;
	int exit = 1;
	std::cin >> inputPass;
	if (checkPassword(inputPass)) {
		cout << "Password entered is correct" << endl;
		return true;
	}
	else {
		
		do {
			cout << "Incorrect Password" << endl;
			cout << "Please enter admin password again or 0 to exit" << endl;
			std::cin >> inputPass;
			if (checkPassword(inputPass)) {
				cout << "Password entered is correct" << endl;
				return true;
			}
		} while (inputPass != "0" || checkPassword(inputPass));
		return false;
	}
}


Password::~Password()
{
}
