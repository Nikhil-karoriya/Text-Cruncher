#include "cli.h"

using namespace std;

CLI::CLI(){
    
    this->width= 35;
    this->height= 9;
}

void CLI::fillScreen(){

    printBorder(width,true);

    for (int i = 0; i < height - 4; ++i) {
        
        if(i != 2){

            printPadding(9);
            cout << "~~";
        }

        if (i == 2 ) {  
            printHuffman();
        } 
        else {
            for (int j = 0; j < 2*width - 4; ++j) { 
                cout << " ";
            }
            cout << "~~" << endl;
        }
    }

    printBorder(width,false);

}

void CLI::printBorder(int width, bool flag){

    if(flag) cout << endl;

    printPadding(9);
    for (int i = 0; i < width; ++i) {
        cout << "~~";
    }
    cout << endl;

    printPadding(9);
    for (int i = 0; i < width; ++i) {
        cout << "~~";
    }
    cout << endl;
}

void CLI::printHuffman() {

    vector<string> huffman = {
        " H   H  U   U  FFFFF  FFFFF  M   M   AAAAA   N   N ",
        " H   H  U   U  F      F      MM MM  A     A  NN  N ",
        " HHHHH  U   U  FFFF   FFFF   M M M  A A A A  N N N ",
        " H   H  U   U  F      F      M   M  A     A  N  NN ",
        " H   H   UUU   F      F      M   M  A     A  N   N "
    };

    for (const string& line : huffman) {
        printPadding(9);
        for(int j=0; j<10; j++){
            cout<<' ';
        }
        cout << line << endl;
    }
}

void CLI::printPadding(int height){

    for(int i=0; i<height; i++){
        cout<<' ';
    }
}