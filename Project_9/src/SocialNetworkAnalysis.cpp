//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "SocialNetworkAnalysis.h"
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include "User.h"
#include "Relationship.h"
#include "SocialNetwork.h"
#include <algorithm>
#include <ostream>
#include <sstream>



using namespace std;

SocialNetworkAnalysis::SocialNetworkAnalysis(string inputFilePath, string outputFilePath){
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
    _socialNetwork.SetIsGood(true);
    _socialNetwork.SetCentralUser("");
}

void SocialNetworkAnalysis::Run(){


    ReadFromFile();
//    SortUsers();
    PrintSuggestions();
}
/*
 * Each username is no longer than 15 characters
 * and contain only alphanumeric characters
 * (letters A-Z,a-z, numbers 0-9) with the exception
 * of underscores.
 *
 */
bool IsValid(std::string name)  {
    if (!(name.length() < 16))    {
        return false;
    }
    int flag = 0;
    for (unsigned int i = 0; i < name.length(); ++i)   {
        if (!((isalnum(name.at(i)) || (name.at(i) == '_'))))
                flag = 1;
    }
    if (flag == 1)  {
        return false;
    }
    return true;
}

void SocialNetworkAnalysis::ReadFromFile() {
    ifstream inputFS;
    inputFS.open(_inputFilePath);

    cout << "Opening file " << _inputFilePath << endl;

    if(!inputFS.is_open())   {
        cout << "yo man we got ourselves an issue "
             << _inputFilePath
             << " won't open." << endl;
        return;
    }

    string line;
    inputFS >> line;
    cout << "Central user is: " << line << endl;

    if (!IsValid(line)) {
        cout << "name " << line << " Is not valid. Exiting" << endl;
        _socialNetwork.SetIsGood(false);
        return;
    }

    _socialNetwork.SetCentralUser(line);

    User *tempFollowedUser;
    User *tempFollowingUser;

    tempFollowedUser = new User(line);

    pair<std::string, User *> temp1Pair(line, tempFollowedUser);
    _socialNetwork.InsertUser(temp1Pair);

    string followedTemp;
    string followingTemp;

    while(!inputFS.eof())  {
            //extracts from the file.
        inputFS >> followedTemp >> followingTemp;
            //checks if there is a bad bit or not.
        if (inputFS.good()) {
                //checks if the person being followed is a valid name.
            if (!IsValid(followedTemp)) {
                cout << "name " << followedTemp << " Is not valid. Exiting" << endl;
                _socialNetwork.SetIsGood(false);
                return;
            }
                //checks if the person following is a valid name.
            if (!IsValid(followingTemp)) {
                cout << "name " << followingTemp << " Is not valid. Exiting" << endl;
                _socialNetwork.SetIsGood(false);
                return;
            }
                //if the person being followed can not be found, add them to the map.
            if (_socialNetwork.SearchUsers(followedTemp) == nullptr) {
                tempFollowedUser = new User(followedTemp);
                pair<std::string, User *> tempPair(followedTemp, tempFollowedUser);
                _socialNetwork.InsertUser(tempPair);
            }
                //if the person following can not be found, add them to the map.
            if (_socialNetwork.SearchUsers(followingTemp) == nullptr) {
                tempFollowingUser = new User(followingTemp);
                pair<std::string, User *> potato(followingTemp, tempFollowingUser);
                _socialNetwork.InsertUser(potato);
            }
                //inserts the relationship for both users.
            _socialNetwork.InsertRelationship(
                    _socialNetwork.SearchUsers(followedTemp),
                    _socialNetwork.SearchUsers(followingTemp));
        } else{ //this is the case if there is a bad bit.
                //.clear() will clear the flag.
            inputFS.clear();
                //ignore tells us to ignore the characters until eof.
            inputFS.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "The file stream is incorrect." << endl;

        }
    }
}

void SocialNetworkAnalysis::SortUsers() {
        //calls the sort function in the SocialNetwork class
        //because it is easier to mess with the Users directly
        //in that class.
    _socialNetwork.SortSocialUsers();
}

void SocialNetworkAnalysis::PrintSuggestions() {
    User* tempUser;
    tempUser = _socialNetwork.SearchUsers(_socialNetwork.GetCentralUser());

   if ((_socialNetwork.GetIsGood() == false) ||
           ( (tempUser->GetSizeRelationship() == 0)
            && (tempUser->GetSizeFollowedRelationship() == 0)
           )) {
//       cout << "File is no bueno" << endl;
       ofstream outputFS;
       outputFS.open(_outputFilePath);

       if(!outputFS.is_open())  {
           cout << "Yo my man, we got a problemo "
                << _outputFilePath
                << " will not open." << endl;
       }

       outputFS << "";
       outputFS.close();

   } else {

       SortUsers();
        //calls a function to print the users, because it is easier to
        //deal with the users in the SocialNetwork class.
    _socialNetwork.PrintSortedUsers(_outputFilePath,
                _socialNetwork.GetCentralUser(),
                _socialNetwork.GetNumFollowers(_socialNetwork.GetCentralUser()));
   }

}   //end of PrintSuggestions

