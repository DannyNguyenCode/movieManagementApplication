#include <string>
#include <vector>
#include <iostream>
#include "Utility.h"
#include "Movie.h"


using namespace std;

Movie::Movie() {};

std::string Movie::getMovieTitle() {
	return m_searchTitle;
}

void Movie::getUserInputTitle() {
	cout << "Input title to search for: ";
	std::getline(std::cin >> std::ws, m_searchTitle);
}

std::string Movie::userInputMovieTitle() {
	std::string movieTitleHolder;
	std::cout << "Please enter Movie Title: ";
	std::getline(std::cin >> std::ws, movieTitleHolder);
	return movieTitleHolder;
}

void Movie::userInpurActors() {
	std::string actorHolder;
	std::getline(std::cin >> std::ws, actorHolder);
	m_placeHolderActor = actorHolder;

}
std::string Movie::getActorPlaceHolder() {
	return m_placeHolderActor;
}



Movie::~Movie()
{
}
