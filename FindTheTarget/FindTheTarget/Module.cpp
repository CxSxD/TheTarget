#include "Module.h"


////////////////////////////
// Algorithm functions.
////////////////////////////
Tree* AlgorithmA(string kw[], Tree* _tree, int ArrayLength, int offset){
	if (offset <= ArrayLength - 1)
	{
		Tree* _sTree;
		_sTree = new(Tree);
		setInfo(_sTree, kw[offset]);
		_sTree->BrotherKeyWords = NULL;
		_sTree->SonKeyWords = AlgorithmA(kw, NULL, ArrayLength, ++offset);
		return _sTree;
	}
	return NULL;
}
Tree* AlgorithmB(string kw[], Tree* _tree, int ArrayLength, int offset){
	if (offset <= ArrayLength - 1)
	{
		Tree* _bTree;
		_bTree = new(Tree);
		setInfo(_bTree, kw[offset]);
		_bTree->SonKeyWords = AlgorithmA(kw, NULL, ArrayLength, ++offset);
		_bTree->BrotherKeyWords = AlgorithmB(kw, NULL, ArrayLength, ++offset);
		return _bTree;
	}
	return NULL;

}
Tree* Algorithm(string kw[], int ArrayLength){
	Tree* _mTree;
	_mTree = new(Tree);
	setInfo(_mTree, kw[0]);
	_mTree->SonKeyWords = AlgorithmA(kw, NULL, ArrayLength, 1);
	_mTree->BrotherKeyWords = AlgorithmB(kw, NULL, ArrayLength, 1);

	return _mTree;

}

void ScanTree(Tree _tree, string kw[]){

}
////////////////////////////
// File handling functions.
////////////////////////////
void createFile(const char* _filename, char *input){
	ofstream fp;
	fp.open(_filename);
	fp.write(input, strlen(input));
	fp.close();

}

void scanString(const char* _filename, string _targetText){
	std::ifstream fp;
	fp.open(_filename);
	string line;
	int LineNumber = 0;
	int AppearTimes = 0;

	if (fp.is_open())
	{
		while (!fp.eof())
		{
			//LineNumber++; // To print the Line Number.
			getline(fp, line);

			if (line.find(_targetText) != string::npos)
			{

				cout
					// << "In line : " << LineNumber << endl 
					<< "Found the Word you entered : " << _targetText << endl
					<< " At Location : " << line.find(_targetText) << endl;

				AppearTimes++;

			}
		}

		cout << "The amount of the times this word appears : " << AppearTimes << endl;

	}
}
// -- Tree handling functions

void setInfo(Tree* _tree, string kw){
	_tree->Keyword = kw;
}
void setBrotherKeyWords(Tree* _tree, Tree* _nTree){
	_tree->BrotherKeyWords = _nTree->BrotherKeyWords;
}
void setSonKeyWords(Tree* _tree, Tree* _nTree){
	_tree->SonKeyWords = _nTree->SonKeyWords;
}

