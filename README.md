# Illumio Coding Assignment 2018, PCE teams (FireWall Program)

## By Yunong_Li

### Introduction

This is a program of FireWall to check whether a certain input satify the existing rules or not

### Implementation

I first created and declared a Record class in FireWall.h file and this Record class is mainly to record the rules that we provided. 
The Record class will have a unordered_map to record all the rules information one by one.
And I also created a FireWall class which contain a Record class, and when there is a input to our FireWall, we could just check the
unordered_map stored in the Record class to see if it is satisfying the rules. The key for the unordered_map which is direction+protocol
, and the value of the unordered_map is a vector of pair of string. The first string in the pair is port and the second is Ip Address. 
The advantage of using the unordered_map is to decrease the time complexity from O(n^2) to O(n). <br/><br/>
The declaration of Record class and FireWall class is in Firewall.h<br/><br/>
The implementaion of Record class and FireWall class is in Firewall.cpp<br/><br/>
The main function is in main.cpp

### Testing
To test the program, we could just run the main function in the main.cpp. <br/>
There is a function called writecsv() to write the rules into a csv file called test.csv<br/>
And we could input in the main function to see whether our input satisfy the rules declared in the test.csv or not<br/>
If the input passes the FireWall, it will output: Your input is valid<br/>
If the input does not pass the FireWall, it will output: Your input is invalid<br/>

### Improvement

If I have more time, I would like to further decrease the space complexity by using tree instead of unordered_map<br/>
I am thinking that I could use the tree to store the information based on their characters like trie tree, and then, it will save alot of space

### Time Spend
I spend total of 75 minutes to finish this program

### Preference for Group
I indeed prefer all of three groups, and the the preferance ranking from top to bottom is: <br/>
Platform<br/>
Data<br/>
Policy<br/>

