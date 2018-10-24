//
// Main Function to test the FireWall Class
//
// Created by Yunong_Li on 23/10/2018.
//

#include <iostream>
#include "FireWall.h"

//Function to write the rules into the csv file called "test.csv"
void writecsv(){
    ofstream file;
    file.open ("test.csv");
    file << "inbound,tcp,80,192.168.1.2\n";
    file << "outbound,tcp,10000-20000,192.168.10.11\n";
    file << "inbound,udp,53,192.168.1.1-192.168.2.5\n";
    file << "outbound,udp,1000-2000,52.12.48.92 \n";
    file << "outbound,udp,37-39,252.252.3.4\n";
    
    file.close();
}

int main(){
    //write rule into a csv file called "test.csv"
    writecsv();
    
    //Creat a FireWall Class taking the "test.csv" file path as input
    FireWall f("test.csv");
    
    //test the rule
    printf("Result: %s\n",(f.accept_packet("inbound", "tcp", 80, "192.168.1.2")==1) ? "Your input is valid":"Your input is invalid");
   
    printf("Result: %s\n",(f.accept_packet("inbound", "udp", 53, "192.168.2.1")==1) ? "Your input is valid":"Your input is invalid");
    printf("Result: %s\n",(f.accept_packet("outbound", "tcp", 10234, "192.168.10.11")==1) ? "Your input is valid":"Your input is invalid");
    printf("Result: %s\n",(f.accept_packet("inbound", "tcp", 81, "192.168.1.2")==1) ? "Your input is valid":"Your input is invalid");
    printf("Result: %s\n",(f.accept_packet("inbound", "udp", 24, "52.12.48.92")==1) ? "Your input is valid":"Your input is invalid");
    printf("Result: %s\n",(f.accept_packet("inbound", "tcp", 84, "192.168.1.2")==1) ? "Your input is valid":"Your input is invalid");
    
    return 0;
}


