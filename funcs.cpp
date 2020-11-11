#include <iostream>
#include "profile.h"
#include "network.h"

//Profile Class
Profile::Profile(std::string usrn, std::string dspn){
	username = usrn;
	displayname = dspn;
}
    
Profile::Profile(){
	username = "";
	displayname = "";
}
    
std::string Profile::getUsername(){
	return username;
}
std::string Profile::getFullName(){
	return displayname + " (@" + username + ")";
}
void Profile::setDisplayName(std::string dspn){
	displayname = dspn;
}



//Network Class
Network::Network(){
	numUsers = 0;
	for(int i = 0; i < MAX_USERS; i++){
		for(int j = 0; j < MAX_USERS; j++){
			following[i][j] = false;
		}
	}
}

int Network::findID(std::string usrn){
	for(int i = 0; i < MAX_USERS; i++){
		if(profiles[i].getUsername() == usrn){
			return i;
		}
	} 
	return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
	if(numUsers > 19 || findID(usrn) >= 0 || usrn == ""){
		return false;
	}

	for(int i = 0; i < usrn.length(); i++){
		if(!isalnum(usrn[i])){
			return false;
		}
	}

	Profile p1(usrn,dspn);
	numUsers++;
	profiles[numUsers] = p1;
	return true;
}

bool Network::follow(std::string usrn1, std::string usrn2){
	if(findID(usrn1) == -1 || findID(usrn2) == -1){
		return false;
	}
	else{
		following[findID(usrn1)][findID(usrn2)] = true;
		following[findID(usrn2)][findID(usrn1)] = true;
		return true;
	}
}

void Network::printDot(){
	for(int i = 0; i < MAX_USERS; i++){
		if(profiles[i].getUsername() != ""){
			std::cout << "\"@" + profiles[i].getUsername() + "\"" << "\n";
		}
	}

	for(int i = 0; i < MAX_USERS; i++){
		for(int j = 0; j < MAX_USERS; j++){
			if(following[i][j] == true){
				std::cout << "\"@" + profiles[i].getUsername() + "\"" << " -> \"@" + profiles[j].getUsername() + "\"" << "\n";
			}
		}
	}
}

void Network::resetIt(){
	numUsers = 0;
	for(int i = 0; i < MAX_USERS; i++){
		for(int j = 0; j < MAX_USERS; j++){
			following[i][j] = false;
		}
	}
}