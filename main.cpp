#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "Category.h"
#include "Movie.h"
#include "Password.h"
using namespace std;

int main(int argc, char **argv) {
	Password setpass;
	char choice;
	std::cout << "Would you like to set a password? Enter [Y]es or [N]o" << endl;
	std::cin >> choice;
	if (choice == 'Y') {
		setpass.setPassword();
	}
	select(argv);





	//TEST MOVIE CLASS
	return 0;
}

