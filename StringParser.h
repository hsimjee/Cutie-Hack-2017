#ifndef __STRINGPARSER_H
#define __STRINGPARSER_H

#include <string>
#include <locale>
#include <iostream>

using namespace std;

class StringParser{
    public:
        StringParser(){
        }
    private:
        string formatString(string input){
            locale loc;
            string newString = "";
            for(unsigned int i = 0; i < input.length(); i++){
                newString += tolower(input[i],loc);
            }
            if(newString.find(" the ") != string::npos){
                newString.replace(newString.find(" the ", 4, ""));
            }
            if(newString.find(" a ") != string::npos){
                newString.replace(newString.find(" a ", 2, ""))
            }
            if(newString.find(" an ") != string::npos){
                newString.replace(newString.find(" a ", 3, ""))
            }
            if(newString.find(" this ") != string::npos){
                newString.replace(newString.find(" this ", 5, ""))
            }
            if(newString.find(" that ") != string::npos){
                newString.replace(newString.find(" that ", 5, ""))
            }
            if(newString.find(" to ") != string::npos){
                newString.replace(newString.find(" to ", 3, ""))
            }
            if(newString.find(" up ") != string::npos){
                newString.replace(newString.find(" to ", 3, ""))
            }
            while(newString.find("  ") != string::npos){
                newString.replace(newString.find("  ", 1, ""))
            }
            
            return newString;
        }
        string getCommand(string input){
            if(input.find(" ") > 0){
                input = input.substr(0, input.find(" "));
                return input;
            }
            else{
                return input;
            }
        }
        string getPhrase(string input){
            if(input.find(" ") > 0){
                input = input.substr(input.find(" ") + 1, input.length - 1);
                return input;
            }
            else{
                return input;
            }
        }
};

#endif