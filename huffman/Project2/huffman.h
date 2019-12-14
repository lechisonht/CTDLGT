#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <locale>
#include <direct.h>
#include <filesystem>
using namespace std;
struct Tree
{
	int frequency;
	unsigned char character;
	Tree* left = NULL;
	Tree* right = NULL;
};

class TreeComparator
{
public:
	bool operator()(Tree* a, Tree* b)
	{
		return a->frequency > b->frequency;
	}
};
Tree* buildHuffmanTree(vector<pair<unsigned char, int> > freqtable);
string toBinary(unsigned  char a);
void traverseHuffmanTree(Tree* root, string prev, string toAppend, map<unsigned char, string>& codemap);
unsigned char* readFileIntoBuffer(char* path, int& sz);
void writeFileFromBuffer(char* path, unsigned char* buffer, int sz, int flag);
vector<pair<unsigned char, int> > convertToVector(map<unsigned char, int> codes);
string getHuffmanBitstring(unsigned char* buffer, map<unsigned char, string> codes, int sz, int& paddedBits);
unsigned char* getBufferFromString(string bitstring, vector<unsigned char>& outputBuffer, int& sz);
string getStringFromBuffer(unsigned char* buffer, int sz);
unsigned char* getDecodedBuffer(string bitstring, vector<unsigned char>& buffer, map<unsigned char, string> codes, int& sz, int paddedBits);
void writeHeader(char* path, map<unsigned char, string> codes, int paddedBits);
unsigned char* readHeader(unsigned char* buffer, map<unsigned char, string>& codes, int& paddedBits, int& sz);
void compressFile(char* path, char* output_path, map<unsigned char, string>& codes);
void decompressFile(char* inputPath, char* outputPath);