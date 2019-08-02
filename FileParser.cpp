#include "FileParser.h"
#include <iostream>
#include <map>
#include <bitset>

using namespace std;


/**
 * Reads and parse the file and throuws exteption if error occurs
*/
FileParser::FileParser(string filename, bool verbous) {

    infile = ifstream(filename);//"C:\\Users\\glaba\\CLionProjects\\untitled\\"
    if (!infile.good())
        throw std::runtime_error("Could not open file");

    if (verbous) cout << "File opened successfuly" << endl;
    this->verbous = verbous;

}

//verify that error didn't occur
void FileParser::verify(istringstream &istringstream) {
    if (istringstream.fail()) {
        throw std::runtime_error("Wrong file format");
    }
}

//returns next word from the stream
unsigned int FileParser::GetNextWord() {
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
    if (verbous) {
        std::string binary = std::bitset<32>(x).to_string(); //to binary

        cout << "Read byte: " << x << " b: " << binary << endl;
    }
    return x;

}
