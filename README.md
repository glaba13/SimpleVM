# Randomized Bulb Color  Simulator

The program simulates the random color choose from the file provided.

**Note**: the exe file is located in __release_exe__ folder

The command general structure is:
```sh
$ ./bulbColorRandomizer path/to/file_name  [-v | -c | -h | -ex | -ex[N]]
```

As it can be seen it takes file as main argument and optional flags, which are :
  - **-v** : Verbous mode, where all the steps are printed in details, suitable when more infor is nessesery or need be seen all steps
  - **-c** : Colorized output mode, where the output characters are presented in color for better visualisation
  - **-ex**  Extended simulation to determine the expected number of unique colours in this scenario (N=1000)
  - **-ex[N]**  Extended simulation with specifing number. _example: -ex7000_
  - **-h** : help instructions, *can be called without filename


## Architecture
The solution consists of two classes, Utility function and main module.

The parser class parses the file and stores results as color names, numbers and random selected number. 

If file doesn't exist or there is an error in file format, it throws an descriptive xtention which is hendeled and logged externally.
Note: that there is a  _STRICT_CHECK_ Compiler flag, which controls the how strict is format checked. Even if color is twise in the file it is combined and doesn't affect to output.

![Architecture_struct](https://raw.githubusercontent.com/glaba13/ImageResources/master/structs.PNG)

The RadomSelector class simulates and randomizes the solution and have two main functions:
1) for standart randomize which gives number of unique color selected, it uses piecewise_constant_distribution which get the bulbs according to the distribution and numbers as weight provided.
2) Extended mode for determition of the average output of the simulation

Utility namespace contains static mapper of color name to color code and main module integrates everything together and operates according to the flag modes.

## Specification
The solution is implemented with C++ and using Clion IDE

## Outputs
The standad output the program shows how many number is chosed from each color.
the number of start and __i/M__ is shown for each color where M number of rrandomly select bulbs from file (!not the number of each available color!)
![Standart Output](https://raw.githubusercontent.com/glaba13/ImageResources/master/1.PNG)



The colorized and verbous output shows the simulation by colors which are presented and predefined in the map:
![img](https://raw.githubusercontent.com/glaba13/ImageResources/master/5.PNG)


Extended mode in verbous shows each step and samples of randomisation, **which is fun**:
![img](https://raw.githubusercontent.com/glaba13/ImageResources/master/3.png)

Another example for the file input:

![img](https://raw.githubusercontent.com/glaba13/ImageResources/master/sfile.PNG)

![img](https://raw.githubusercontent.com/glaba13/ImageResources/master/ezgif-1-e386dc3227ac.gif)


### Timeline

- The basic requred function was quite easy and implemented in ~1 hour,as it can be seen from the commit.
- Additinal time was spent for the cleaner and better structural code, documentation, additinal features and testing for edge cases.

