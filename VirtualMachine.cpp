//
// Created by Guri on 01/08/2019.
//

#include "VirtualMachine.h"
#include "Utils.h"

VirtualMachine::VirtualMachine(FileParser *fp, bool verbous) {
    this->fp = fp;
    ip = 0;
    data_size = fp->GetNextWord();
    image_size = fp->GetNextWord();
    sp = data_size;
    this->verbous = verbous;
    initData();
}

void VirtualMachine::initData() {
    data = new unsigned int[data_size];
    for (int i = 0; i < image_size; ++i) {
        data[i] = fp->GetNextWord();
    }
}

VirtualMachine::~VirtualMachine() {
    if (!data) {
        delete[] data;
    }
}
/*
   f(v):
	sp = sp - 1
	data[sp] = v
 */
void VirtualMachine::f(unsigned int v) {
    sp = sp - 1;
    data[sp] = v;
}
/*
  g():
	v = data[sp]
	sp = sp + 1
	return v

 */
unsigned int VirtualMachine::g() {
    if (sp < 0 || sp >= data_size) {
        throw std::runtime_error("Seg Fault");
    }
    unsigned int v = data[sp];
    sp = sp + 1;
    return v;
}

/*
 * Run and execute the instruction until it ends
 */
void VirtualMachine::Run() {
    unsigned char operation;
    unsigned char optional_data;
    unsigned int inst = 0;
    while (true) {
        inst = data[ip];
        ip = ip + 1;
        operation = Utils::GetByte(inst, 2);
        optional_data = Utils::GetByte(inst, 0);
        if(verbous) {
            cout<<"Instruction decoded: op: "<<(unsigned int)operation<<  " op_data: " << (unsigned int)optional_data
                <<" SP: " << sp << " IP: "<<ip <<endl;
        }
        switch (operation) {
            case 0: { //  0 - "push <const>"
                f((unsigned int) optional_data);
            }
                break;
            case 1: { // 1 - "add"
                unsigned int a = g();
                unsigned int b = g();
                f(a + b);
            }
                break;
            case 2: { // 2 - "putc"
                unsigned char c = g() & 0xff;
                cout << c;
            }
                break;
            case 3: { //3 - "pop"
                sp = sp + 1;
            }
                break;
            case 4: { // 4 - "halt"
                return;
            }
        }
    }


}
