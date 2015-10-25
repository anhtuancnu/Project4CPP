
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

//TODO Fill this in

StringParserClass::StringParserClass(void){
		char	*pStartMem = new char;
		char	*pEndMem = new char;
		bool	areTagsSet = false;
		int		lastError=0;
}
StringParserClass::~StringParserClass(){}
int StringParserClass::getLastError(){

	return lastError;
}
bool StringParserClass::setTags(const char *pStartMem, const char *pEndMem){
	
				//length of both
				int sl= strlen(pStartMem)++;
				int el = strlen(pEndMem)++;

				//initialize memory space to both
				StringParserClass::pStartMem = (char*)malloc(sl);
				StringParserClass::pEndMem = (char*)malloc(el);

				//set memeory space to pStart
				strncpy(StringParserClass::pStartMem,pStartMem,sl);
				strncpy(StringParserClass::pEndMem,pEndMem,el);
				if(*StringParserClass::pStartMem != NULL && *StringParserClass::pEndMem != NULL){
					areTagsSet = true;
				}else{
					lastError = ERROR_DATA_NULL;
					return false;
				}
				return areTagsSet;
		}
bool StringParserClass::getDataBetweenTags(char *pDataSearch, vector<string> &myVect){
	
	char *sTag = pDataSearch;
	bool notEnd = true;
	while(notEnd){
		char *eTag = 0;
		
		//find start mem space
		findTag(pStartMem, sTag, eTag);
		
		char *sTag2 = eTag;
		char *eTag2 = 0;
		
		//find end mem space
		findTag(pEndMem, sTag2, eTag2);
		
		int i = 1;
		
		//store data
		std::string data = "";
		
		while (*(eTag + i) != *(sTag2)){
			if(*eTag == '\0' || *sTag == '\0'){
			break;
		}
		data += *(eTag + i);
		++i;
		}
		if (data != ""){
			//add data
			myVect.push_back(data);
		}
		else{
			lastError = ERROR_DATA_NULL;
		}
		if (*eTag2 == '\0'){
			notEnd = false;
		}
		else{
			sTag = eTag2;
		}
	}
	cleanup();
	return SUCCEEDED;
}
bool StringParserClass::findTag(char *pLookForSpace, char *&pS, char *&pE){
	
	int i = 0;
	while(*(pS + i) != '\0'){
		int k = i;
		int j = 0;
		if(*(pS + k) == *(pLookForSpace + j)){
			while(*(pS + k) == *(pLookForSpace + j)){
			char *t = (pStart + k);
			++k;
			++j;
			if(*(pS + k) == '>'){
				pS = pS + i;
				pE = pS + j;
				return true;
			}
		}
	}
	++i;
}
pE = pS + i;
return false;
}
void StringParser::cleanup(){
	if (pStartMem){
		delete[] pStartMem;
	}
	if(pEndMem){
		delete[] pEndMem;
	}
}
