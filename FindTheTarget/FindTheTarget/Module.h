#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Tree Structure.
typedef struct Tree {
	std::string Keyword;
	Tree* BrotherKeyWords;
	Tree* SonKeyWords;
	int Count;
};

// -- Search Algorithm functions --
Tree* AlgorithmA(string kw[], Tree* _tree, int ArrayLength, int offset);
Tree* AlgorithmB(string kw[], Tree* _tree, int ArrayLength, int offset);
Tree* Algorithm(string kw[], int ArrayLength);
// -- Tree handling functions
void setInfo(Tree* _tree, string kw);
void setSonKeyWords(Tree* _tree, Tree* _nTree);
void setBrotherKeyWords(Tree* _tree, Tree* _nTree);
// -- File Handling functions --
void createFile(const char* _filename, char *input);
void scanString(const char* _filename, string _targetText);
