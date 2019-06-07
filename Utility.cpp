#include <iostream>
#include <fstream>
#include <string>
#include "Utility.h"
using namespace std;


Utility::Utility()
{
}

void Utility::appendFiles(ifstream &in, char choice) {
	std::string storeLine;
	std::ofstream file;
	std::string fileName;
	if (choice == 'M') {
		fileName = "addMovie.dat";
		file.open("movieList.dat", std::ios::out | std::ios::app);
	}
	else {
		fileName = "addTVSeries.dat";
		file.open("TVSeriesList.dat", std::ios::out | std::ios::app);
	}
	if (file.is_open()) {
		in.open(fileName);
		while (getline(in, storeLine))
		{
			file << storeLine << endl;
		}
		in.close();
		file.close();
		file.open(fileName, std::ios::out | std::ios::trunc);
		file.close();
	}
	else {
		cerr << "Error file could not open to append" <<endl;
	}

}





Utility::~Utility()
{
}
