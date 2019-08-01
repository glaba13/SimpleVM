//
// Created by glaba on 7/26/2019.
//

#include "FileParser.h"

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


/**
 * Reads and parse the file and throuws exteption if error occurs
*/
FileParser::FileParser(string filename, bool verbous) {

    infile = ifstream(filename);//"C:\\Users\\glaba\\CLionProjects\\untitled\\"
    if (!infile.good())
        throw std::runtime_error("Could not open file");

    if(verbous) cout<<"File opened successfuly"<<endl;


}

//verify that error didn't occur
void FileParser::verify(istringstream &istringstream) {
    if (istringstream.fail()) {
        throw std::runtime_error("Wrong file format");
    }
}
//returns total available number of bulb
unsigned int FileParser::GetNextByte() {
    string line;
    if (!std::getline(infile, line)) {
        throw std::runtime_error("Wrong file format");
    }
    if (line.length() == 0) {
        throw std::runtime_error("Wrong file format");
    }

    unsigned int x;
    std::stringstream ss;
    ss << std::hex << line;
    ss >> x;
    if (ss.fail()) {
        throw std::runtime_error("Wrong file format");
    }

    return x;

}
