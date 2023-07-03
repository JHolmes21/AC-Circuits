//These two functions act to check the user's input to make sure that it doesn't bring up any errors in the program
#ifndef INPUTVALID_H
#define INPUTVALID_H

//This input check makes sure that the input is an integer as required to navigate the menus
int get_menu_option();

//This input check makes sure that the input is a positive number, as negative values of quantities such as resistance
//are non-physical, and setting the resistance to 0 could lead to division errors
double get_positive_number();

#endif

