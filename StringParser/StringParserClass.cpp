
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
