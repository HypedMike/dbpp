#pragma once
#include "dbIO.h"

class dbpp
{
	dbIO *io;
	std::string path;

	//std::list<T> cached_lst;

	bool updated = false;

public:
	dbpp(std::string path);

	template <typename T>
	bool add(T elem) {
		io->write(elem.toRow());
		updated = false;
		return true;
	}

	template <typename T>
	std::list<T> query() {
		updated = true;
		return io->read<T>();
	}


};

