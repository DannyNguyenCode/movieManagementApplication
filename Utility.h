#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <vector>

using namespace std;

class Utility
{
	std::string m_password;
public:
	Utility();
	template <typename T, typename N>//N is for fileName and T is for the data type of vector
	void extractToken(N& filename, size_t& next_pos, char& delimiter, bool& multiple, std::vector<T>& list, std::vector<std::vector<std::string>>&storeActor) {
		if (multiple) {
			std::string record;
			while (std::getline(filename, record)) {
				size_t length = (record.find(delimiter, next_pos)) - next_pos;
				record = record.substr(next_pos, length);
				list.push_back(record);
			}
		}
		else {
			std::string record;
			std::string str;
			const char delimiter = '|';
			while (std::getline(filename, record)) {
				size_t nextPos = next_pos;
				size_t length = 0;
				size_t firstFlag = 0;
				size_t noOfActors = 0;
				str = record;
				do {
					if (firstFlag == 0) {
						nextPos = (record.find(delimiter) + 1);
						if (record.find(delimiter, nextPos) == std::string::npos) {
							length = (record.find('?', nextPos)) - nextPos;
							record = record.substr(nextPos, length);
							extract(list, record, nextPos);
							nextPos = (nextPos + record.length() + 1);
							record = str;
							noOfActors++;
						}
						else {							
							length = (record.find(delimiter, nextPos)) - nextPos;
							record = record.substr(nextPos, length);
							extract(list, record, nextPos);
							nextPos = (nextPos + record.length() + 1);
							record = str;
							noOfActors++;
						}
						firstFlag++;
					}
					else if (record.find(delimiter, nextPos) == std::string::npos) {
						length = (record.find('?', nextPos)) - nextPos;
						record = record.substr(nextPos, length);
						extract(list, record, nextPos);
						nextPos = (nextPos + record.length() + 1);
						record = str;
						noOfActors++;

					}
					else {
						length = (record.find(delimiter, nextPos)) - nextPos;
						record = record.substr(nextPos, length);
						extract(list, record, nextPos);
						nextPos = (nextPos + record.length() + 1);
						record = str;
						noOfActors++;
					}
				} while (record.find('?', nextPos) != std::string::npos);
				store(list, storeActor, noOfActors);
				list.clear();
			}
		}
	}
	template <typename T>
	void extract(std::vector<T> &list, const std::string str, size_t& next_pos) {
		list.push_back(str);
	}

	void store(std::vector<std::string>actors, std::vector<std::vector<std::string>>&storeActor, const size_t numberOfActors) {
		storeActor.push_back(actors);
	}

	void appendFiles(ifstream &in, char choice);



	~Utility();
};

#endif // !UTILITY_H
