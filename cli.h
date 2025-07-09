#pragma once

#include <iostream>
#include <string>
#include <vector>

class CLI{

    private:
        int width ;  
        int height ;  

        void printBorder(int,bool); 

        void printHuffman();
        
        void printPadding(int);

    public:

        CLI();

        void fillScreen();
};