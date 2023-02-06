#include "dbpp.h"


dbpp::dbpp(std::string path) {
	this->path = path;
	io = new dbIO(this->path);
}