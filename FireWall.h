//
//  FireWall.h
//
//
//  Created by Yunong_Li on 23/10/2018.
//  
//

#ifndef FireWall_h
#define FireWall_h

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdint>

using namespace std;


//Create a Record class to record the rule and compare the input with the rules
class Record{
public:
    
    //Member Function addvalue
    void addvalue(string key, string port, string Ip);
    
    
    //check whether the key exit in the record
    bool checkkey(string key);
    
    
    //check whether the value exit in the record
    bool checkpattern(string key, int port, string Ip);
    
    
private:
    unordered_map<string, vector<pair<string,string>>> record;
    
};



//Create a FireWall class
class FireWall{
public:
    
    //Constructor
    FireWall(string path);
    
    //Accept_packet function
    bool accept_packet(string direction, string protocol, int port, string Ip);
    
private:
    string Urlpath;
    Record record;
    
};




#endif /* FireWall_h */
