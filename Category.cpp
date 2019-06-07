#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Category.h"

Category::Category(const char* category) {
	if (category != nullptr) {
		set(category);
	}
	else {
		set("Movie");
	}

}

void Category::set(const char* category) {
	size_t length = strlen(category)+1;
	m_category = new char[length];
	strncpy(m_category, category, length);
	m_category[length-1] = '\0';
}


char* Category::get() {
	return m_category;
}

void Category::display(std::ostream& os) {
	os <<"List of " << get() << " results"<< std::endl <<std::endl;
}

Category::~Category() {
	delete[] m_category;
}
