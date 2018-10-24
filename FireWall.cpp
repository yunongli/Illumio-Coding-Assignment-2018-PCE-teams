//
//  FireWall.cpp
//
//
//  Created by Yunong_Li on 24/10/2018.
//
//

#include "FireWall.h"

//the function to seperate a string by a  character
vector<string> seperate(string s, char c){
    vector<string> sep;
    stringstream s2(s);
    string s3;
    while(getline(s2,s3,c)){
        sep.push_back(s3);
    }
    
    return sep;
}

//the function to transfer to the ip address to unsigned int
uint32_t transferIp(const std::string ip) {
    int p1;
    int p2;
    int p3;
    int p4;
    
    uint32_t res = 0;
    
    if (sscanf(ip.c_str(), "%d.%d.%d.%d", &p1, &p2, &p3, &p4) != 4){
        return 0;
    }
    
    res = p1 << 24;
    res |= p2 << 16;
    res |= p3 << 8;
    res |= p4;
    return res;
}

//the function to check whther the the given Ip in the range of two other Ip
bool checkIpRange(string ip1, string ip2, string compare){
    uint32_t comparet = transferIp(compare);
    uint32_t ip1t = transferIp(ip1);
    uint32_t ip2t = transferIp(ip2);
    uint32_t lowerBound = (ip1t & ip2t);
    uint32_t upperBound = (ip1t | (~ip2t));
    
    if (comparet >= lowerBound && comparet <= upperBound){
        return true;
    }
    return false;
}

//Implement the member funtion addvalue of Record class
void Record::addvalue(string key, string port, string Ip){
    if(checkkey(key)){
        record[key].push_back(make_pair(port,Ip));
    }
    else{
        vector<pair<string,string>> v;
        v.push_back(make_pair(port,Ip));
        record.insert(pair<string,vector<pair<string,string>>>(key, v));
    }
}

//Implement the member funtion checkkey of Record class
bool Record::checkkey(string key){
    if(record.find(key)!=record.end()){
        return true;
    }
    return false;
}

//Implement the member funtion checkpattern of Record class
bool Record::checkpattern(string key, int port, string Ip){
    
    if(checkkey(key)){
        vector<pair<string, string>> temp;
        temp=record[key];
        bool portfind=false;
        bool Ipfind=false;
        
        //itrate through the vector
        for(auto item : temp){
            //check the port
            if(item.first.find('-')!=string::npos){
                vector<string> sep=seperate(item.first,'-');
                if(port>=stoi(sep[0])&&port<=stoi(sep[1])){
                    portfind=true;
                }
            }
            else{
                if(stoi(item.first)==port){
                    portfind=true;
                }
            }
            
            //check the Ip
            if(item.second.find('-')!=string::npos){
                vector<string> sep=seperate(item.second,'-');
                if(checkIpRange(sep[0],sep[1],Ip)){
                    Ipfind=true;
                }
            }
            else{
                vector<string> inputIp=seperate(Ip,'.');
                vector<string> compare=seperate(item.second,'.');
                if(inputIp==compare){
                    Ipfind=true;
                }
            }
            
        }
        return Ipfind&&portfind;
    }
    return false;
}

//Implement the constructor of FireWall class
FireWall::FireWall(string path){
    
    ifstream file(path);
    if(!file.is_open()){
        cout<<"The file is not Open"<<endl;
    }
    string direction;
    string protocol;
    string port;
    string Ip;
    string key;
    
    while(file.good()){
        
        getline(file,direction,',');
        getline(file,protocol,',');
        getline(file,port,',');
        getline(file,Ip);
        key=direction+protocol;
        record.addvalue(key,port,Ip);
    }
    
    file.close();
}

//Implement the member function accept_packet of FireWall class
bool FireWall::accept_packet(string direction, string protocol, int port, string Ip){
    string key=direction+protocol;
    return record.checkpattern(key,port,Ip);
}



