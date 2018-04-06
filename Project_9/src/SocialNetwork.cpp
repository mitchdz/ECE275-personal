//
// Created by mitch on 11/20/17.
//

#include "SocialNetwork.h"
#include <string>
#include <vector>
#include <ostream>
#include <fstream>

#include <iostream>
#include <algorithm>
using namespace std;


SocialNetwork::SocialNetwork(std::string name){
    _centralUser = name;
    _isGood = true;
}   //end of SocialNetwork constructor

SocialNetwork::SocialNetwork() {
    _centralUser = "";
    _isGood = true;
}   //end of default constructor for SocialNetwork

User* SocialNetwork::SearchUsers(std::string name) {

    unordered_map<string, User*>::const_iterator Iterator = _users.find(name);
        if (Iterator == _users.end())
            return nullptr;
    return Iterator->second;

}   //end of SearchUsers

void SocialNetwork::InsertUser(std::pair<std::string, User*> userPair) {
    _users.insert(userPair);
}   //end of InsertUser


void SocialNetwork::InsertRelationship(User* Followed, User *Following) {
    Relationship* newRelationship;
    newRelationship = new Relationship;

    newRelationship->SetFollowed(Followed);
    newRelationship->SetFollowing(Following);
        //creates a user ptr to add a relationship for the user
        //and to increment the count of people following said user.
    User* UserPtr = SearchUsers(Followed->GetName());
    UserPtr->InsertFollowedRelationship(newRelationship);
    UserPtr->IncrementNumFollowers();

    Relationship* SecondnewRelationship;
    SecondnewRelationship = new Relationship;

        //sets the relationship around for the person following
    SecondnewRelationship->SetFollowed(Following);
    SecondnewRelationship->SetFollowing(Followed);
        //inserts the relationship for the user following the other one.
    UserPtr = SearchUsers(Following->GetName());
    UserPtr->InsertFollowingRelationship(SecondnewRelationship);
}   //end of InsertRelationship

int SocialNetwork::GetNumFollowers(std::string name) {
        //creates a user ptr to get to the user in the unordered_map.
    User* userPtr;
    userPtr = SearchUsers(name);
    //returns the number of followers.
    return userPtr->GetNumFollowers();
}   //end of GetNumFollowers

void SocialNetwork::SortSocialUsers() {
        //creates an iterators for the unordered_map
    unordered_map<string, User *>::const_iterator Iterator = _users.begin();
    User *CentralUserPtr;
    CentralUserPtr = SearchUsers(_centralUser);

    unsigned int flag = 0, i = 0;
    User* UserPtr;

        //populates the first depth.
    for (i = 0; i < CentralUserPtr->GetSizeRelationship(); ++i) {
        UserPtr = CentralUserPtr->GetUserAtIndex(i);
        UserPtr->SetIsDepthof3(true);   //depth of three just says user is within 3.
        _depthOne.push_back(UserPtr);   //adds the users to the first depth.
    }

    unsigned int j = 0;
    unsigned int sizeofRelationship;

        //populates the second depth.
    for (i = 0; i < _depthOne.size(); ++i)    {
        CentralUserPtr = _depthOne[i    ];
        sizeofRelationship = CentralUserPtr->GetSizeRelationship();
        for (j = 0; j < sizeofRelationship; ++j) {
            UserPtr = CentralUserPtr->GetUserAtIndex(j);
            UserPtr->SetIsDepthof3(true);
            _depthTwo.push_back(UserPtr);   //adds user to the second depth.
        }
    }

    for (i = 0; i < _depthTwo.size(); ++i)  {
        CentralUserPtr = _depthTwo[i];
        sizeofRelationship = CentralUserPtr->GetSizeRelationship();
        for (j = 0; j < sizeofRelationship; ++j)    {
            UserPtr = CentralUserPtr->GetUserAtIndex(j);
            UserPtr->SetIsDepthof3(true);   //shows user is within depth 3.
            //I do not push anything to a _depthThree vector because
            //I don't need to access the users, just need to know if
            //they are within the 3 depth limit.
        }
    }
        //creating strings for the names given from the file.
    string tempUserName;
    string CentralRelationshipName;
        //changing the Ptr to the central user.
    CentralUserPtr = SearchUsers(_centralUser);

    while (Iterator != _users.end()) {
        flag = 0;
            //sizeofRelationship is actually the size of the people the user is following.
        sizeofRelationship = CentralUserPtr->GetSizeRelationship();
        for (i = 0; i < sizeofRelationship; ++i) {
            tempUserName = Iterator->second->GetName();
            CentralRelationshipName = CentralUserPtr->GetNameRelationshipAtIndex(i);
            if (tempUserName == CentralRelationshipName)    {
                flag = 1;   //sets a flag if the user is already being followed by central.
            }
        }

        if (Iterator->second->GetIsDepthof3() == false) {
            flag = 1;
        }
            //I don't know why, but for some reason
            //The unordered_map included the central user sometimes.
            //this line fixes that. Don't remove plz.
        if (Iterator->second->GetName() == _centralUser)
            flag = 1;
            //checks if the user should be added to the sorted list.
        if (flag == 1) {
            Iterator++;
        } else {
            _sortedUsers.push_back(*Iterator->second);
            Iterator++;
        }
    }
}   //end of SortSocialUsers

void SocialNetwork::PrintSortedUsers(std::string outputFilePath, std::string name, int numFollowers) {

    sort(_sortedUsers.begin(), _sortedUsers.end()); //sorts users using std::sort
//    reverse(_sortedUsers.begin(), _sortedUsers.end());

    ofstream outputFS(outputFilePath);  //open output file

    outputFS << "Looking for new accounts for "
             << name
             << " (" << numFollowers
             << ") to follow" << endl;
        //go through and list off the sorted list of users.
    for (unsigned int i = 0; i < _sortedUsers.size(); ++i) {
        outputFS << _sortedUsers[i].GetName()
                 << " ("
                 << _sortedUsers[i].GetNumFollowers()
                 << ")" << endl;
    }
    outputFS.close();   //close outputFile
}   //end of PrintSortedUsers



