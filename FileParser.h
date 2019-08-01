//
// Created by glaba on 7/26/2019.
//


#include <iostream>
#include <random>
#include <iterator>
#include <ctime>
#include <type_traits>
#include <cassert>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
#ifndef UNTITLED_FILEPARSER_H
#define UNTITLED_FILEPARSER_H

class FileParser {

public:

    /**
    * File Parser Constructor
    * @param filename read and parse the file and throuws exteption if error occurs
    * @param verbous verous mode
    */
    FileParser(string filename, bool verbous);

    unsigned int GetNextByte();

private:
    ifstream infile;
    void verify(istringstream &istringstream);
};

#endif //UNTITLED_FILEPARSER_H
