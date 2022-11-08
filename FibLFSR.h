/*
 *Name: Jacob George
 *Course name: COMP.2040
 *Assignment: PS1B
 *Instructor's name: Dr. James Daly
 *Date: 
 *Sources Of Help: 
************************************************************/
#pragma once
#ifndef FIBLFSR_H
#define FIBLFSR_H
#include <string>
#include <iostream>

class FibLFSR
{
public:
    FibLFSR(std::string seed);
    int step();
    int generate(int k);
    ~FibLFSR();
    int getLength(void);
    int getNumResult(void);
    int* getArray(void);

    friend std::ostream& operator<< (std::ostream& out, const FibLFSR& fibLFSR);

private:
    int lengthOfSeed;
    int newBit;
    int* seedArray;
    int numResult;
};

#endif