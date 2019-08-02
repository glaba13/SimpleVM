#include "FileParser.h"
#include "Utils.h"
#include "VirtualMachine.h"

using namespace std;


// Defines for arguments
#define HELP            "-h"
#define VERBOUS         "-v"
//global flags
bool verbous = false;


void Process(char *string);


/*
 * Print the helper standart text
 */
void PrintHelpText() {
    cout << " This is a simple VM ." << endl;
    cout << " The  synopsys of command is:" << endl;
    cout << " \t \t ./VM  path/to/file_name [-v |  -h ]" << endl;
    cout << " \t \t The flags are:" << endl;
    cout << " \t \t \t -v: verbouse, details output for each stage" << endl;
    cout << " \t \t \t -h: help instructions" << endl;
}


/*
 * Main function
 */
int main(int argc, char *argv[]) {

    //check for filename
    if (argc < 2) {
        cout << " Please specify filename as argument:./VM  path/to/file_name" << endl;
        return 0;
    }

    //check for additional options
    for (int i = 1; i < argc; ++i) {
        string arg = string(argv[i]);
        if (arg == HELP) {
            PrintHelpText();
        }
        if (arg == VERBOUS) {
            verbous = true;
        }
    }

    try {
        Process(argv[1]);
    } catch (std::exception &ex) {
        std::cout << "Error occured: " << ex.what() << "!\n";
        return -1;
    }

    return 0;
}

/*
 * Process and runs one time the machine
 */
void Process(char *filename) {
    FileParser fp(string(filename), verbous);
    VirtualMachine vm(&fp, verbous);
    vm.Run();
}
