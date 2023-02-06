#include <iostream>
#include "dbpp.h"

class user{
	int id = -1;
	std::string name;
	std::string surname;
public:
	user(std::string info) {
		int pos = 0;
		id = std::stoi(info.substr(0, info.find(',', pos) - pos));
		pos = info.find(",", pos) + 1;
		name = info.substr(pos, info.find(',', pos) - pos);
		pos = info.find(",", pos);
		surname = info.substr(pos + 1, info.length() - pos);
	}

	user(int id, std::string name, std::string surname) {
		this->id = id;
		this->name = name;
		this->surname = surname;
	}

	std::string toString() {
		return name + " " + surname;
	}

	std::string toRow() {
		if (id != -1) {
			return  std::to_string(id) + "," + name + "," + surname;
		}
		return "0," + name + "," + surname;
	}
};

int main() {
	dbpp<user> db("D:\\Code\\dbpp\\test.txt");

	user users[] = { user(0, "Michele", "Saladino"), user(1, "Marco", "Livolsi"), user(2, "Yuri", "Batini") };
	
	/*for (int i = 0; i < 3; i++) {
		db.add(users[i]);
	}*/

	std::list<user> lst = db.query();

	for (auto it = lst.begin(); it != lst.end(); it++) {
		std::cout << (*it).toString() << std::endl;
	}
}