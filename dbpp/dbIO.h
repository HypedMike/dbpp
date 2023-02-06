#pragma once
#include <string>
#include <fstream>
#include <list>
#include <sstream>


class dbIO
{
	std::string path;


	inline bool fileExists(const std::string& name);

public:

	dbIO();
	/*
	*	opens database or creates one if it doesn't find one
		@path: databases's path
	*/
	dbIO(std::string path);

	bool write(std::string data);

	template <typename T>
	std::list<T> read() {
		std::ifstream infile(this->path);
		std::string line;
		std::list<T> res;
		while (std::getline(infile, line)) 
		{
			std::istringstream iss(line);

			try {
				res.push_back(T(line));
			}
			catch (int n) {
				throw std::runtime_error("Something went wrong with model class constructor");
			}
		}
		return res;
	}

};