#include "PontoonCard.h"
#include "GuessCard.h"
#include <iostream>
#include <string>

PontoonCard::PontoonCard(std::string f, std::string s):GuessCard(f, s)
{
    if (f == "ace")
        setValue(1);
    if (f == "two") 
        setValue(2);
    if (f == "three") 
        setValue(3);
    if (f == "four") 
        setValue(4);
    if (f == "five")
        setValue(5);
    if (f == "six") 
        setValue(6);
    if (f == "seven") 
        setValue(7);
    if (f == "eight") 
        setValue(8);
    if (f == "nine") 
        setValue(9);
    if (f == "ten") 
        setValue(10);
    if (f == "jack") 
        setValue(10);
    if (f == "queen") 
        setValue(10);
    if (f == "king") 
        setValue(10);

    //Could not use case expressions 
    //could not use map due to values having to be unique
}

int PontoonCard::getValue()
{
	return value;
}

void PontoonCard::setValue(int v)
{
	value = v;
}


