#include"huffman.h"

int main(int argc, char* argv[])
{
	//fp state?
	char a[] = "test.txt";
	char b[] = "test1.txt";
	char c[] = "decoded.txt";
	char* dEI = a;
	char* dEO = b;
	char* dDO = c;

	if (argc == 4)
	{
		dEI = argv[1];
		dEO = argv[2];
		dDO = argv[3];
	}
	map<unsigned char, string> codes;
	compressFile(dEI, dEO, codes);
	decompressFile(dEO, dDO);
}