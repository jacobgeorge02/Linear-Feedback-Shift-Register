/*
 *Name: Jacob George
 *Course name: COMP.2040
 *Assignment: PS1B
 *Instructor's name: Dr. James Daly
 *Date: 
 *Sources Of Help: 
************************************************************/
#include <iostream>
#include <string>
#include "FibLFSR.h"

FibLFSR::FibLFSR(std::string seed)
{
    lengthOfSeed = seed.length();
    seedArray = new int[lengthOfSeed];

    int num = 0;

    int j = 0;

    for (int i = lengthOfSeed - 1; i >= 0; i--)
    {
        num = seed[j] - 48;
        seedArray[i] = num;
        j++;
    }
}

int FibLFSR::step()
{
    int j;

    newBit = (seedArray[15] ^ seedArray[13]) ^ (seedArray[12] ^ seedArray[10]);

    for (j = lengthOfSeed - 1; j > 0; --j)
    {
        seedArray[j] = seedArray[j - 1];
    }

    seedArray[0] = newBit;

    return newBit;
}

int FibLFSR::generate(int k)
{
    numResult = 0;

    for (int i = 0; i < k; ++i)
    {
        numResult *= 2;
        numResult += step();
    }

    return numResult;
}

int FibLFSR::getLength(void)
{
    return lengthOfSeed;
}

int FibLFSR::getNumResult(void)
{
    return numResult;
}

int* FibLFSR::getArray(void)
{
    return seedArray;
}


std::ostream& operator<< (std::ostream& out, const FibLFSR& fibLFSR)
{
    int  j;

    for (j = fibLFSR.lengthOfSeed - 1; j > 0; --j)
    {
        out << fibLFSR.seedArray[j];
    }

    out << fibLFSR.seedArray[0];
    out << " " << fibLFSR.newBit;

    return out;
}

FibLFSR::~FibLFSR()
{
    delete[]seedArray;
}
