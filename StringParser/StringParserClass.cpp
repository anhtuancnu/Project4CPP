
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

//TODO Fill this in

StringParserClass::StringParserClass(void){
		char	*pStartTag = new char;
		char	*pEndTag = new char;
		bool	areTagsSet = false;
		int		lastError=0;
}
StringParserClass::~StringParserClass(){}
int StringParserClass::getLastError(){

	return lastError;
}
bool StringParserClass::setTags(const char *pStartTag, const char *pEndTag){
	
				//length of both
				int sl= strlen(pStartTag)+1;
				int el = strlen(pEndTag)+1;

				//initialize memory space to both
				StringParserClass::pStartTag = (char*)malloc(sl);
				StringParserClass::pEndTag = (char*)malloc(el);

				//set memeory space to pStart
				strncpy(StringParserClass::pStartTag,pStartTag,sl);
				strncpy(StringParserClass::pEndTag,pEndTag,el);
				if(*StringParserClass::pStartTag != NULL && *StringParserClass::pEndTag != NULL){
					areTagsSet = true;
				}else{
					lastError = ERROR_DATA_NULL;
					return false;
				}
				return areTagsSet;
		}
bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myVector){
	
	char *sTag = pDataToSearchThru;
	bool notEnd = true;
	while(notEnd){
		char *eTag = 0;
		
		//find start mem space
		findTag(pStartTag, sTag, eTag);
		
		char *sTag2 = eTag;
		char *eTag2 = 0;
		
		//find end mem space
		findTag(pEndTag, sTag2, eTag2);
		
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
			myVector.push_back(data);
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
bool StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd){
	
	int i = 0;
	while(*(pStart + i) != '\0'){
		int k = i;
		int j = 0;
		if(*(pStart + k) == *(pTagToLookFor + j)){
			while(*(pStart + k) == *(pTagToLookFor + j)){
			char *t = (pStart + k);
			++k;
			++j;
			if(*(pS + k) == '>'){
				pStart = pStart + i;
				pEnd = pStart + j;
				return true;
			}
		}
	}
	++i;
}
pEnd = pStart + i;
return false;
}
void StringParser::cleanup(){
	if (pStartTag){
		delete[] pStartTag;
	}
	if(pEndTag){
		delete[] pEndTag;
	}
}
