#include "dbpp.h"
#include "dbModel.h"

dbpp::dbpp(std::string path) {
	this->path = path;
	io = new dbIO(this->path);
}


template <typename T>
bool dbpp::add(T elem) {
	io->write((dbModel) T.toString());
	return true;
}