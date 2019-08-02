

#include "Utils.h"

//Utility function for geting byte
unsigned char Utils::GetByte(unsigned int val, int num) {
    if (num < 0 || num > 3) return 0;
    return (val >> (num * 8)) & 0xFF;
}
