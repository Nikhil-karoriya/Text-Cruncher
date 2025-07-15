# Huffman Compression Algorithm in C++

This repository contains a C++ implementation of the Huffman Compression Algorithm — a widely-used, lossless data compression technique. Huffman coding reduces file size by assigning shorter binary codes to frequently occurring characters and longer codes to less frequent ones.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/Huffman_tree_2.svg/1920px-Huffman_tree_2.svg.png" alt="Huffman Tree" width="600">
</p>

---

## Features

- **Lossless Compression**: Guarantees that decompressed files are identical to the original input.
- **High Performance**: Efficient and memory-friendly C++ implementation.
- **Compression Efficiency**: Achieves up to 57% file size reduction depending on input.
- **Metadata Support**: Stores frequency map or tree structure for accurate decompression.
- **Text File Compatibility**: Supports all ASCII-based formats, including `.txt`, `.cpp`, `.json`, `.csv`, etc.

---

## Screenshots

### Compression Interface

<img src="https://github.com/Nikhil-karoriya/Huffman-Compression/blob/f98968ee7c6c8b45045edd8935c3536e526bd406/Images/Screenshot%202025-01-04%20145550.png" alt="Compression Screenshot" width="600"/>

### Decompression Interface

<img src="https://github.com/Nikhil-karoriya/Huffman-Compression/blob/f98968ee7c6c8b45045edd8935c3536e526bd406/Images/Screenshot%202025-01-04%20145636.png" alt="Decompression Screenshot" width="600"/>

---

## Compression Statistics

- **Best Case:** Up to 57% size reduction  
- **Average Case:** 40–45% reduction depending on file content  
- **Lossless Guarantee:** Decompressed files are byte-exact replicas of the original

---

## Supported File Types

This tool supports compression of any ASCII-based text file, including but not limited to:

- `.txt`, `.log`, `.md`
- `.cpp`, `.java`, `.py`, `.js`
- `.csv`, `.json`, `.xml`
- `.html`, `.ini`, `.yml`, `.conf`

**Tip:** Convert files to ASCII if necessary using PowerShell:

```powershell
Get-Content -Path "Path/To/YourFile" | Out-File -FilePath "ConvertedFile.txt" -Encoding ASCII
```

---

## How It Works

1. Frequency Analysis
      - Reads the input file and calculates the frequency of each character.

2. Huffman Tree Construction
      - Builds a binary tree with frequent characters closer to the root.

3. Code Generation
      - Assigns variable-length binary codes to each character.

4. Compression
      - Replaces characters with their codes and writes the compressed output.

5. Decompression
      - Uses stored metadata to reconstruct the original file.

---

## Project Structure
```
Huffman-Compression/
├── main.cpp
├── huffman.cpp
├── cli.cpp
├── huffman.hpp
├── cli.hpp
├── README.md
├── Images/
│   ├── Screenshot_1.png
│   └── Screenshot_2.png

```

---

## Usage

### Option 1: Download Executable

   - Go to the Releases section.

   - Download main.exe.

   - Run it and follow on-screen instructions.

### Option 2: Compile and Run Manually

1. Clone this repository.

2. Open a terminal and navigate to the folder containing main.cpp.

3. Compile the project:

   ```bash
   g++ main.cpp huffman.cpp cli.cpp -o main
   ./main

## Prerequisites
- G++ Compiler (C++11 or later)

- Terminal or Command Prompt

- Input file (preferably ASCII-encoded)
