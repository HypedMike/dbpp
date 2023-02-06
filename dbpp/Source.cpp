#include <iostream>
#include "dbIO.h"

int main() {
	dbIO db("D:\\Code\\dbpp\\data.txt");
	db.write("Hi!");
	db.write("Hi1!");
}