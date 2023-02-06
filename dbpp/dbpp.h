#pragma once
#include "dbIO.h"

class dbpp
{
	dbIO *io;
	std::string path;

public:
	dbpp(std::string path);

	template <typename T>
	bool add(T elem);
};

