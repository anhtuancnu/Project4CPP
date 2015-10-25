#include <iostream>
#include <fstream>
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;


KP_FileReaderClass::FileReader::FileReader() {
	std::string		filecontents;
};

KP_FileReaderClass::FileReader::~FileReader() {
}

int KP_FileReaderClass::FileReader::getFileContents(const std::string filename, std::string &contents) {

	int RESULT = FileReader::ReadTheWholeFile(filename);
	if (!SUCCEEDED) {
		return RESULT;
	}
	else {
		contents.append(filecontents);
		return SUCCEEDED;
	}

}


int KP_FileReaderClass::FileReader::ReadTheWholeFile(const std::string &filename) {

	ifstream myInputfile;
	myInputfile.open(filename);

	if (!myInputfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	else {
		//file is open
		while (!myInputfile.eof()) {
			getline(myInputfile, filecontents);
		}
		return SUCCEEDED;
	}

}