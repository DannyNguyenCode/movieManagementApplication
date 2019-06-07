#ifndef CATEGORY_H
#define CATEGORY_H


class Category {
	char* m_category;
public:
	Category() : m_category{ nullptr } {};
	Category(const char* category);
	void set(const char* category);
	char* get();
	virtual void display(std::ostream& os);
	~Category();

};
#endif // !CATEGORY_H
