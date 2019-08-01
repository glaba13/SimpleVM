#include "FileParser.h"
#include "Utils.h"

using namespace std;


//global flags
bool verbous = false;


void Process(char *string);

/*
 * Main function
 */
int main(int argc, char *argv[]) {

    try {
        Process(argv[1]);
    } catch (std::exception &ex) {
        std::cout << "Error occured: " << ex.what() << "!\n";
        return -1;
    }

    return 0;
}


void f( unsigned int v, unsigned int*data, unsigned int & sp ) {
    sp = sp - 1;
    data[sp] = v;
}

unsigned int g(  unsigned int * data, unsigned int & sp ) {
    unsigned int v = data[sp];
    sp = sp + 1;
    return v;
}



void Process(char *filename) {
    FileParser fp(string(filename), true);
    unsigned int data_size = fp.GetNextByte();
    unsigned int image_size = fp.GetNextByte();

    auto * data = new unsigned int[data_size];
    for (int i = 0; i < image_size; ++i) {
        data[i] =  fp.GetNextByte();
    }
    unsigned int  ip = 0;
    unsigned int  sp = data_size;

    unsigned char operation;
    unsigned char optional_data;
    unsigned int inst = 0;

    while(true) {
        inst = data[ip];
        ip = ip + 1;
        operation = (inst >> 16) & 0xFF;
        optional_data = inst & 0xFF;
        switch (operation) {
            case 0: {
                f((unsigned int) optional_data, data, sp);

            }
                break;
            case 1: {
                unsigned int a = g(data, sp);
                unsigned int b = g(data, sp);
                f(a + b, data, sp);
            }
                break;
            case 2: {
                unsigned char c = g(data, sp) & 0xff;
                cout << c;
            }
                break;
            case 3: {
                sp = sp + 1;

            }
                break;
            case 4: {
                return;
            }
                break;
        }
    }

}
