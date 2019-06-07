#ifndef MOVIEDETAILS_H
#define MOVIEDETAILS_H
#include <string>
#include <algorithm>
#include "Movie.h"
#include "Category.h"

class MovieDetails : public Movie, public Category
{
	std::vector<std::string>m_listOfMovies;//include into display for movie object
	std::vector<std::string> m_actors;
	std::vector<std::vector<std::string>> m_storeActors;
	std::string *m_genre;
	std::string m_releaseDate;
	size_t m_rating;

public:
	MovieDetails();

	template<typename N>
	void storeMovieDetails(N& fileName, const char* category) {
		Utility utility;
		set(category);
		std::string record;
		size_t nextPos = 0;
		char delimiter = '|';
		bool multiple = true;
		storeMovieTitle(fileName, m_listOfMovies, nextPos, delimiter, multiple, m_storeActors);
		fileName.clear();
		fileName.seekg(0, ios::beg);
		multiple = false;
		utility.extractToken(fileName, nextPos, delimiter, multiple, m_actors, m_storeActors);

	}

	template<typename T>
	void displayDetails(std::ostream&os, const T groupActors) {
		display(os);
		if (searchList(m_listOfMovies)) {//if user input movie is in database
		
			for (size_t j = 0; j < m_listOfMovies.size(); ++j) {//cycle through each movie in database
				if (m_listOfMovies[j].find(getMovieTitle()) != std::string::npos) {//if movie in database matches user input
				
					displayMovie(os, m_listOfMovies, j);//display that movie
					std::cout << "Actors for " << m_listOfMovies[j] << ":" << std::endl << std::endl;
					for (size_t i = 0; i < groupActors[j].size(); ++i) {
						os << groupActors[j][i] << std::endl;
					}
					std::cout << endl << endl;
				}
			}
		}
		else {
			std::cout << "Please Enter another movie title, there is no " << getMovieTitle() << " in database!" << std::endl <<std::endl;
		}
	}
	auto getActors() -> std::vector<std::vector<std::string>> {
		return m_storeActors;
	}

	~MovieDetails();
};

#endif // !MOVIEDETAILS_H
