//============================================================================
// Name        : Proj4_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "..\Include\FileReader.h"	//relative path, from PWD, go up one, then down into Include to find FileReader.h
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
#include "..\Include\stringparserclass.h"

void outputvectorrow(std::string i){
	std::cout<<i<<std::endl;
}
void foreach(std::vector<std::string> myVector){
	std::for_each(myVector.begin(), myVector.end(), outputvectorrow);
}

int main(){
	//TODO open file, if not there ask for a different file or exit

	std::string fileContents = "";
	KP_FileReaderClass::FileReader aFileReader;

	aFileReader.getFileContents(TEST_FILE_NAME, fileContents);



	//got file data, this is a bogus time and memory wasting step
	//whose sole purpose is to provide a way to pass
	//in a non const pointer to getDataBetweenTags(..) without casting
	/*vector<char> myLine;
	std::copy(filecontents.begin(), filecontents.end(), back_inserter(myLine));*/

	//TODO  create an instance of the stringparser
KP_StringParserClass::StringParserClass parser;
	//TODO set the tags
parser.setTags(START_TAG, END_TAG);
	//TODO pull out the data
char *charData = strdup(filecontents.c_str());
parser.getDataBetweenTags(charData, storageForData);
	//TODO  write to file and to screen
	if(ourFile.is_open()){
		for
	}

}



