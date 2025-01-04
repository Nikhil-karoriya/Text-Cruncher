# Huffman Compression Algorithm in C++

This repository contains an implementation of the **Huffman Compression Algorithm** in C++. The algorithm is used for lossless data compression, where the size of the file is reduced by assigning variable-length codes to characters based on their frequency of occurrence. The characters that appear more frequently are assigned shorter codes, while characters that appear less frequently are assigned longer codes.

![Huffman Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/Huffman_tree_2.svg/1920px-Huffman_tree_2.svg.png)


## Features

- **Efficient & lossless Data Compression**: The implementation uses the Huffman coding algorithm to compress input data without any data loss.
- **Compression Ratio**: Achieved a compression ratio of **57%**, meaning the compressed file size is reduced to 57% of the original size.
- **C++ Implementation**: The code is implemented in C++ and is designed to be fast and memory-efficient.
- **Easy to Use**: Simply provide an input file, and the program will output the compressed file with its meta data file.

## How it Works

The algorithm follows these general steps:

1. **Calculate Frequency**: Count the frequency of each character in the input file.
2. **Build Huffman Tree**: Construct a binary tree based on the frequency of characters. The most frequent characters will be placed closer to the root, and the less frequent ones will be deeper in the tree.
3. **Generate Codes**: Assign a binary code to each character based on its position in the Huffman tree.
4. **Compress the File**: Replace each character in the original file with its corresponding Huffman code, creating a compressed output file.
5. **Decompress the File**: The program also includes functionality to decompress the file using the stored meta data file.

## Achieved Compression Ratio

The compression algorithm achieves a **57% compression ratio**, which means the compressed file is about 57% of the size of the original file. This is a significant reduction in file size while maintaining the integrity of the original data during decompression.

### Prerequisites

To run the Huffman Compression Algorithm, you need:

- A G++ compiler
- Standard C++ libraries (C++11 or later)
- ASCII Encoded .txt file
  
**Note:** ASCII Encoded .txt files should be used for compression. If file is UTF-8 encoded, then run this command to convert it to ASCII Encoded ->  **Get-Content -Path "File/Path/to/Yourfile.txt" | Out-File -FilePath "fileASCII.txt" -Encoding ASCII** , Here *fileASCII* is ASCII encoded file and use it for compression

### How to run ?

**Download main.exe from Releases and run it**

**OR**

1) Download all the files. 
2) Go to directory containing *Main.cpp* and run following command in terminal to compile using g++ compiler -> **g++ Main.cpp -o main**
3) Then run this command in terminal-> **./main**

![Huffman Compress](https://github.com/Nikhil-karoriya/Huffman-Compression/blob/f98968ee7c6c8b45045edd8935c3536e526bd406/Images/Screenshot%202025-01-04%20145550.png)

![Huffman Decompress](https://github.com/Nikhil-karoriya/Huffman-Compression/blob/f98968ee7c6c8b45045edd8935c3536e526bd406/Images/Screenshot%202025-01-04%20145636.png)
