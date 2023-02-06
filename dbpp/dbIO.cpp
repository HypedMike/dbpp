#include "dbIO.h"

inline bool dbIO::fileExists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}


dbIO::dbIO(){}
/*
*	opens database or creates one if it doesn't find one
	@path: databases's path
*/
dbIO::dbIO(std::string path) {
	this->path = path;
	if (!fileExists(path)) {
		// if database doesn't exist create one
		std::ofstream outfile(this->path);
	}

}

bool dbIO::write(std::string data) {
	std::ofstream outfile;
	outfile.open(this->path, std::ios_base::app);
	outfile << data << std::endl;
	return true;
}

template <typename T>
std::list<T> dbIO::read() {
	std::ifstream infile(this->path);
	std::string line;
	std::list<T> res;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int a, b;
		if (!(iss >> a >> b)) { break; } // error

		try {
			res.push_back(T(line));
		}
		catch (int n) {
			throw std::runtime_error("Something went wrong with model class constructor");
		}
	}
}

