#include "huffman.h"
#include "cli.h" 
#include<chrono>
#include<iostream>

using namespace std;

void encode(){
    string inputFile;
    
    cout<<"\nEnter file to compress:\n ->";
    cin>>inputFile;
    
    auto start = chrono::high_resolution_clock::now();

    huffman enc(inputFile);
    
    enc.compress();

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout<<"Completion Time: "<<duration.count()<<" seconds\n";
}

void decode(){
    string encodedFile, metaFile;
    
    cout<<"\nEnter Encoded file:\n ->";
    cin>>encodedFile;

    cout<<"\nEnter Meta file:\n ->";
    cin>>metaFile;

    auto start = chrono::high_resolution_clock::now();

    huffman enc(encodedFile,metaFile);
    
    enc.decompress();
    
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout<<"Completion Time: "<<duration.count()<<" seconds\n";
}

int main(){

    CLI ui;

    while(true){
        
        ui.fillScreen();

        cout<<"\n\tNote: Only ASCII Encoded file supported!\n\n";

        cout<<"\t1) COMPRESS FILE\n";
        cout<<"\t2) DECOMPRESS FILE\n";
        cout<<"\t3) Exit\n\n";

        int var= 3;

        cout<<"Enter your choice (1/2/3):\n->";
        cin>>var;

        if(var == 1){
            encode();
        }
        else if(var == 2){
            decode();
        }
        else if(var == 3){
            break;
        }
        else{
            cout<<"\nWrong choice!!\n";
        }
    }

    return 0;
}