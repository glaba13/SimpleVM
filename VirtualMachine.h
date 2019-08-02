//
// Created by Guri on 01/08/2019.
//

#ifndef UNTITLED_VIRTUALMACHINE_H
#define UNTITLED_VIRTUALMACHINE_H

#include "FileParser.h"

using namespace std;


class VirtualMachine {

public:
    /**
     * Constuctor, takes the file parser as an input which is stream of words
     * @param fp
     */
    VirtualMachine(FileParser *fp, bool verbous);
    /*
     * Destuctor for dealocation memory
     */
    ~VirtualMachine();
    /*
     * Run and execute the instruction until it ends
     */
    void Run();

private:
    unsigned int ip;
    unsigned int sp;
    unsigned int data_size;
    unsigned int image_size;
    FileParser *fp;
    bool verbous;
    unsigned int *data;
    /**
     * Internal initialisation of data
     */
    void initData();

    void f(unsigned int v);
    unsigned int g();
};


#endif //UNTITLED_VIRTUALMACHINE_H
