#pragma once

#include<iostream>
#include<string>
#include<bitset>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
        char data;
        string code;
        int freq;
        Node* left;
        Node* right;

        Node();
};

struct comp{
     bool operator()(Node* a, Node* b);
};

class huffman{
    
    private:
        string inputFile;
        string encodedFile, decodedFile;
        string metaFile;   
        string fileExtension;

        unsigned int padding;
        unsigned int arrSize; 

        // create arr
        void createArr();
        // create Tree
        void constructTree();
        // traverse Tree
        string traverseTree(string&);
        // generate code
        void generateCode();
        // bfs 
        void bfs(Node*); 
        // encode file
        void encoder();
        // decode file
        void decoder();
        // read meta-file
        void readMeta();

        bool checkFile(string);

        void printTree(Node*);    
        void print();

        void setExtension();

        priority_queue<Node*, vector<Node*>, comp > minHeap;
        vector<Node*> arr;

    public:

        huffman(string inputFile); 

        huffman(string encodedFile, string metaFile);

        void compress();
        void decompress();
};