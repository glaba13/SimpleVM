# Simple Virtual Machine

The program simulates machine instruction execution and output the processed file/

**Note**: the exe file is located in __release_exe__ folder

The command general structure is:
```sh
$ ./VM  path/to/file_name [-v |  -h ]
```

As it can be seen it takes file as main argument and optional flags, which are :
  - **-v** : Verbous mode, where all the steps are printed in details, suitable when more information is nessesery or need be seen all steps
  - **-h** : help instructions, *can be called without filename


## Architecture
The solution consists of two main classes, Utility function and main module.

The parser class parses the file and stores results read word (32 bits) when it is requested.
If file doesn't exist or there is an error in file format, it throws an descriptive xtention which is hendeled and logged externally.


![Architecture_struct](https://raw.githubusercontent.com/glaba13/ImageResources/master/1.PNG)

the VirualMachine class
1) initilise data and fills it in constructior
2) fetches, decodes and executes the instruction until termination in run function
3) release the dynamiclya llocated memory in destructor

Utility namespace contains helper functions which one of them is accesing the byte depending on the postion, binary conversion and etc.

## Specification
The solution is implemented with C++ and using Clion IDE on Windows
Using MingGW-w64 version 5.0 toolchain.


## Outputs
The output for cvi.bin is in output.txt

if the programm is run in verbous mode (-v) it prins all steps for deatailed analyse which is shown below as an example:



