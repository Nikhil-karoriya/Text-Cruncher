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

        Node(){
            freq= 0;
            left= right= NULL;
            code = "";
            data= '#';
        }
    
};

struct comp{
     bool operator()(Node* a, Node* b) {
        if (a->freq != b->freq) 
            return a->freq > b->freq;

        return a->data > b->data;
    }
};

class huffman{
    
    private:
        string inputFile;
        string encodedFile, decodedFile;
        string metaFile;   
        
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

        priority_queue<Node*, vector<Node*>, comp > minHeap;
        vector<Node*> arr;

    public:

        huffman(string inputFile){
            this->inputFile= inputFile;
            
            int idx;
            for(int i=0; i< this->inputFile.size(); i++){
                if(this->inputFile[i] == '.'){
                    idx= i;  
                }
            }
            string temp= this->inputFile.substr(0,idx);

            this->encodedFile= temp + "-enc.txt";
            this->metaFile= temp + "-meta.txt";

            this->arrSize= 256;

            for(int i=0; i<arrSize; i++){
                Node* temp= new Node();
                arr.push_back(temp); 
                arr[i]->data= static_cast<char>(i);
            }

        }    

        huffman(string encodedFile, string metaFile){
            this->encodedFile= encodedFile;
            this->metaFile= metaFile;

            int idx;
            for(int i=0; i< this->encodedFile.size(); i++){
                if(this->encodedFile[i] == '-'){
                    idx= i;
                }
            }
            string temp= this->encodedFile.substr(0,idx);

            this->decodedFile= temp+ "-dec.txt";

            this->arrSize= 256;

            for(int i=0; i<arrSize; i++){
                Node* temp= new Node();
                arr.push_back(temp); 
                arr[i]->data= static_cast<char>(i);
            }

        }

        void compress();
        void decompress();
};

void huffman::createArr(){

    ifstream reader(inputFile);

    if(reader.is_open() == false){
        cout<<'\n'<< inputFile + " not found!\n";
        return;
    }

    char ch;
    while(reader.get(ch)){
        arr[static_cast<int>(ch)]->freq++;
    }
    
    reader.close();
}

void huffman::constructTree(){
    
    for(int i=0; i<arrSize; i++){
        if(arr[i]->freq > 0){
            minHeap.push(arr[i]);
        }
    }

    while(minHeap.size() != 1){
        Node* first= minHeap.top();
        minHeap.pop();

        Node* second= minHeap.top();
        minHeap.pop();

        Node* sum= new Node();
        
        sum->freq= first->freq + second->freq;
        
        sum->left= first;
        sum->right= second;

        minHeap.push(sum);
    }

}

void huffman::bfs(Node* root){

    string code= "";

    queue<pair<Node*, string> > qu;
    qu.push({root,code});

    while(qu.size() != 0){
        auto fr= qu.front();
        qu.pop();

        Node* current= fr.first;

        if(current->left == NULL && current->right == NULL){
            current->code= fr.second;
        }

        if(current->left != NULL){
            string temp= fr.second;
            temp.push_back('0');
            qu.push({current->left, temp});
        }

        if(current->right != NULL){
            string temp= fr.second;
            temp.push_back('1');
            qu.push({current->right, temp});
        }

    }

}

void huffman::generateCode(){

    Node* root= minHeap.top();
    bfs(root);
}

string huffman::traverseTree(string& path){
    
    if(path.size() == 0) return "xx";

    Node* root= minHeap.top();

    for(int i=0; i< path.size(); i++){
        if(root == NULL) return "xx";

        if(path[i] == '0') root= root->left;
        else root= root->right;
    }
    
    if(root->left == NULL && root->right == NULL) return string(1, root->data);
    return "xx";
}

void huffman::encoder(){

    ifstream reader(inputFile);
    
    if(reader.is_open() == false){
        cout<<'\n'<< inputFile + " cannot be encoded!\n";
        return;
    }

    reader.clear();
    reader.seekg(0, ios::beg);

    long long totalBits= 0;

    for(int i=0; i<arrSize; i++){
        if(arr[i]->freq > 0){
            long freq= arr[i]->freq;
            long len= (arr[i]->code).size();
            totalBits = totalBits + (freq*len);
        }
    }

    int paddingBits= (8 - (totalBits%8) )%8;

    ofstream writer(encodedFile, ios::binary);

    if(writer.is_open() == false){
        cout<<'\n'<<encodedFile + " not found!\n";
        reader.close();
        return;
    }

    string s= "";
    s.append(paddingBits,'0');

    char ch;
    while(reader.get(ch)){

        string Code= arr[static_cast<int>(ch)]->code; 
        
        while(!Code.empty()){
            int remBits= 8 - s.size();

            if(remBits > 0){

                if(Code.size() <= remBits){
                    s += Code;
                    Code= "";
                }
                else{
                    s += Code.substr(0,remBits);
                    Code= Code.substr(remBits);
                }
            }

            if(s.size() == 8){
                bitset<8> bt(s);
                char asc = static_cast<char>(bt.to_ulong());
                writer.put(asc);
                
                s="";
            }
        }
        
    }
    
    if (!s.empty()) {
        bitset<8> bt(s);
        char asc = static_cast<char>(bt.to_ulong());
        writer.put(asc);
    }
    
    writer.close();
    reader.close();

    // write in metafile
    ofstream meta(metaFile);
    
    if(meta.is_open() == false){
        cout<<"\nmeta-file not found!\n";
        return;
    }

    meta<<paddingBits<<'\n';
    
    for(int i=0; i<arrSize; i++){
        if(arr[i]->freq > 0){
            char asc= arr[i]->data;
            int freq= arr[i]->freq;

            meta<<asc<<freq<<'\n';   
        }
    }

}

void huffman::readMeta(){

    ifstream reader(metaFile);
    
    if(reader.is_open() == false){
        cout<<'\n'<< metaFile + " not found !\n";
        return;
    }

    reader.clear();
    reader.seekg(0, ios::beg);

    string s;

    getline(reader,s);

    int paddingBits= static_cast<int>(s[0] - '0');

    while(getline(reader,s)){
    
        char asc;
        if(s.size()) asc= s[0];

        int freq=0;
        
        if(s.size() == 0){
            asc= '\n';
            getline(reader,s);

            for(int i=0; i<s.size(); i++){
                
                int digit= static_cast<int>(s[i] - '0');

                freq= freq*10 + digit;
            }
            
        }
        else{

            for(int i=1; i<s.size(); i++){
                
                int digit= static_cast<int>(s[i] - '0');

                freq= freq*10 + digit;
            }
        }

        arr[static_cast<int>(asc)]->freq= freq;
    }

    this->padding= paddingBits;

    reader.close();
}

void huffman::decoder(){

    ifstream reader(encodedFile, ios::binary);

    if(reader.is_open() == false){
        cout<<'\n'<<encodedFile + " not found !\n";
        return;
    }

    reader.clear();
    reader.seekg(0, ios::beg);

    ofstream writer(decodedFile);

    if(writer.is_open() == false){
        cout<<"\ndecoded file not found!\n";
        reader.close();
        return;
    }

    char ch;
    string s= "";

    while(reader.get(ch)){
        
        bitset<8> bt(ch);
        string temp= bt.to_string();

        int startIndex = (padding != 0) ? padding : 0;
        
        for(int i= startIndex; i<8; i++){
            s.push_back(temp[i]);

            string res= traverseTree(s);
            
            if(res != "xx"){

                char asc= res[0];
                writer.put(asc);
                s= "";

            }

        }

        padding= 0;

    }

    writer.close();
    reader.close();
}

void huffman::compress(){
    
    ifstream reader(inputFile);

    if(reader.is_open() == false){
        cout<<'\n'<< inputFile + " not found for compression!\n";
        return;
    }
    reader.close();
    createArr();
    constructTree();
    generateCode();

    // printTree(minHeap.top());
    encoder();

    cout<<'\n'<<inputFile + " compressed successfully!!\n";
}

void huffman::decompress(){
    
    bool flag= true;

    flag= checkFile(encodedFile);
    if(flag == false) return;
    
    flag= checkFile(metaFile);
    if(flag == false) return;

    readMeta();
    constructTree();
    generateCode();
    
    // printTree(minHeap.top());
    decoder();

    cout<<'\n'<<encodedFile + " decompressed successfully!!\n";
}

bool huffman::checkFile(string fileName){
    
    ifstream reader(fileName);

    if(reader.is_open() == false){
        cout<<'\n'<<fileName + " not found for decompression!\n";
        return false;
    }
    reader.close();

    return true;
}

void huffman::print(){

    for(int i=0; i<arrSize; i++){
        if(arr[i]->freq > 0){
            cout<<i<<" "<<arr[i]->freq<<endl;
        }
    }
    cout<<endl;
}

void huffman::printTree(Node* root){
    
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL ){
        cout<<(root->data == '\n'? "\\n": to_string(root->data))<<" ";
    }

    printTree(root->left);
    printTree(root->right);
}