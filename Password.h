#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

using namespace std;

class Password
{
	std::string m_password;
public:
	Password();
	std::string getPass(const char *prompt, bool show_asterisk=true);
	std::string getPassword();
	std::string EncrpytPass(std::string password);
	void setPassword();
	bool checkPassword(std::string password);
	bool enterPassword(std::istream &in);

	~Password();
};

#endif