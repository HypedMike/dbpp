# DATABASEPP

Experimental project: a database fully built in C++.

## how to

This database will create a file (if it doesn't exist already in the specified directory).
Each function of the class needs the typename and eevry type inserted inside the class will have to implemhent

`toRow()` -> this will return a `std::string` consisting of all the properties of the class seprated by a comma (,)
`T(std::string info)` -> a constructor capable of accepting and using the result of `toRow()` to build a fully functional object