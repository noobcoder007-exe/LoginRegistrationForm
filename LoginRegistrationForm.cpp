//---------------------------------------------------------------------------

#include <fmx.h>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#pragma hdrstop

#include "LoginRegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyLogin *myLogin;
//---------------------------------------------------------------------------
__fastcall TmyLogin::TmyLogin(TComponent* Owner)
	: TForm(Owner)
{
}

std::vector<std::string> parseCommaDelimitedString(std::string line){
		std::vector<std::string> result;
		std::stringstream s_stream(line);
		while (s_stream.good()){
			 std::string substr;
			 getline(s_stream,substr,',');
			 result.push_back(substr);
		}
		return result;
}
//---------------------------------------------------------------------------
void __fastcall TmyLogin::LoginButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUsers.txt", ios::in);
	if(myFile.is_open()){
		std::string line ;

		while(getline(myFile,line)){
		std::vector<std::string> parsedLine = parseCommaDelimitedString(line);
		const char* username = parsedLine.at(2).c_str();

		AnsiString editUserName = UserNameEdit->Text;
		const char* usernameString = editUserName.c_str();

		if(std::strcmp(username, usernameString)==0){
			const char* password = parsedLine.at(3).c_str();

			 AnsiString editPassword = PassEdit->Text;
			 const char* passwordString = editPassword.c_str();

			 if(std::strcmp(password,passwordString)==0){
				messageLabel->Text="Logged In..";
			 }  else{
				 messageLabel->Text="Log In Failed!";
             }

		}
		}

	}
}
//---------------------------------------------------------------------------
