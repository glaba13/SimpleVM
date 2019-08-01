//
// Created by glaba on 7/26/2019.
//

#include "Utils.h"
#include <map>

// can be extended
static map<string, int> color_map =      {{"black"	, 40},
                                          {"red"		, 41},
                                          {"green"	, 42},
                                          {"yellow"	, 43},
                                          {"blue"	, 44},
                                          {"violet"	, 45},
                                          {"indigo"	, 104},
                                          {"orange"	, 103},
                                          {"magenta", 45},
                                          {"cyan"	, 46},
                                          {"white"	, 47}};


//Get the code for the color or returns -1 otherwise
 int Utils::GetFormattedString(string color) {
    auto it = color_map.find(color);
    if(it != color_map.end()){
        return it->second;
    }

    return -1;
}
