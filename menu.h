#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Category.h"
#include "Movie.h"
#include "MovieDetails.h"
#include "Utility.h"
#include "Password.h"

using namespace std;

template<typename T>
void select(T& file) {
	int choice;
	try {
		do {
			cout << "Select 1, 2, or 0 (exit): " << endl;
			cout << "1. Search Movie Titles" << endl;
			cout << "2. Search TV Series Titles" << endl;
			cout << "3. Add Movies" << endl;
			cout << "4. Add TV Series" << endl;
			cout << "5. Confirm Updates" << endl;
			cout << "0. Exit" << endl;

			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				MovieDetails movie;
				ifstream fileName(file[1]);
				movie.storeMovieDetails(fileName, "Movie");
				movie.getUserInputTitle();
				movie.displayDetails(std::cout, movie.getActors());
				break;
			}
			case 2:
			{
				MovieDetails movie;
				ifstream fileName(file[2]);
				movie.storeMovieDetails(fileName, "TV Series");
				movie.getUserInputTitle();
				movie.displayDetails(std::cout, movie.getActors());
				break;
			}
			case 3:
			{
				MovieDetails movie;
				std::ofstream outfile;
				std::string replaceHolder;
				std::string replaceString;
				outfile.open("addMovie.dat", std::ios::out | std::ios::app);
				outfile << movie.userInputMovieTitle() << "|";
				std::cout << "Please enter Actors for movies. Hit 0 when finished" << endl;
				while (movie.getActorPlaceHolder() != "0") {
					movie.userInpurActors();

					if (movie.getActorPlaceHolder() == "0") {
						//outfile.close();
						ifstream inFile;
						inFile.open("addMovie.dat", std::ios::out | std::ios::binary);
						while (getline(inFile, replaceHolder)) {
							replaceString = replaceHolder;
							replaceString[replaceString.find_last_of('|')] = '?';
						}

						inFile.close();
						//outfile.open("addMovie.dat", std::ios::out | std::ios::app);
						outfile << replaceString << endl;
					}
					else
					{
						outfile << movie.getActorPlaceHolder() << "|";
					}

				}

				break;
			}
			case 4:
			{
				MovieDetails movie;
				std::ofstream outfile;
				std::string replaceHolder;
				std::string replaceString;
				outfile.open("addTVSeries.dat", std::ios::out | std::ios::app);
				outfile << movie.userInputMovieTitle() << "|";
				std::cout << "Please enter Actors for movies. Hit 0 when finished" << endl;
				while (movie.getActorPlaceHolder() != "0") {
					movie.userInpurActors();
					if (movie.getActorPlaceHolder() == "0") {
						outfile.close();
						ifstream inFile;
						inFile.open("addMovie.dat", std::ios::out | std::ios::binary);
						while (getline(inFile, replaceHolder)) {
							replaceString = replaceHolder;
							replaceString[replaceString.find_last_of('|')] = '?';
						}
						inFile.close();
						outfile.open("addMovie.dat", std::ios::out | std::ios::binary);
						outfile << replaceString << endl;
					}
					else
					{
						outfile << movie.getActorPlaceHolder() << "|";
					}

				}

				break;
			}
			case 5:
			{
				Password pass;
				string enter;
				char select;
				string temp;
				ifstream inFile;
				std::cout << "Please select which file to review: [M]ovie or [T]VSeries" << endl;
				do {
					cin >> select;
					if (select == 'M') {
						inFile.open("addMovie.dat");
						if (inFile.is_open()) {
							while (getline(inFile, temp))
							{
								cout << temp << endl;
							}
						}
						else {
							cerr << "Could not open file addMovie.dat";
						}
					}
					else if (select == 'T') {
						inFile.open("addTVSeries.dat");
						if (inFile.is_open()) {
							while (getline(inFile, temp))
							{
								cout << temp << endl;
							}
						}
						else {
							cerr << "Could not open file addTVSeries.dat";
						}
					}
					else {
						cout << "Please select M for movie branch and T for TVSeries branch" << endl;
					}
				} while (select != 'M' && select != 'T');
				std::cout << "Press Enter to Continue" << endl;
				std::cin.ignore(2);

				std::cout << "Enter Admin password to include new data entered by users" << endl;
				if (pass.enterPassword(std::cin)) {
					Utility util;
					inFile.close();
					util.appendFiles(inFile, select);
				}


			}
			default:
				break;
			}
		} while (choice != 0);
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}

#endif // !MENU_H
