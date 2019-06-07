#ifndef MOVIE_H
#define MOVIE_H

#include <vector>
#include <iostream>
#include <string>
#include "Category.h"
#include "Utility.h"


class Movie
{
	std::string m_searchTitle;
	std::string m_placeHolderActor;
public:
	Movie();

	template<typename T, typename N>//customer constructor that takes name of file, list of movies, and category
	void storeMovieTitle(T& file, std::vector<N>&list, size_t& nextPos, char &delimiter, bool& multiple, std::vector<std::vector<std::string>> &storeActors) {
		Utility utility;
		utility.extractToken(file, nextPos, delimiter, multiple, list, storeActors);
	}

	std::string getMovieTitle();//get name of movie user inputted

	template<typename T>
	bool searchList(const T& titleList) {//check if user input matches list of movies
		for (size_t i = 0; i < titleList.size(); ++i) {
			if (titleList[i].find(getMovieTitle()) != std::string::npos) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	void displayMovie(std::ostream& os, const T& list, size_t element) {
		os  << list[element] << std::endl;
	}

	void getUserInputTitle();//get user input of the title of movie
	std::string userInputMovieTitle();
	void userInpurActors();
	std::string getActorPlaceHolder();



	~Movie();

};


#endif // !MOVIE_H
