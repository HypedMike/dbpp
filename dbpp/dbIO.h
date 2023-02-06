#pragma once
#include <string>
#include <fstream>
#include <list>
#include <sstream>
#include "dbModel.h"


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
	std::list<T> read();

};