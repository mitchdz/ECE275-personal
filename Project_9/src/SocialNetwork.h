//
// Created by mitch on 11/20/17.
//

#ifndef SNA_PROJECT_SOCIALNETWORK_H
#define SNA_PROJECT_SOCIALNETWORK_H
#include "User.h"
#include <vector>
#include <unordered_map>
#include "Relationship.h"


class SocialNetwork {

private:
    std::unordered_map<std::string, User*> _users;
    std::string _centralUser;
    std::vector<User> _sortedUsers;
    std::vector<User*> _depthOne;
    std::vector<User*> _depthTwo;
    bool _isGood;   //isGood is a flag to see if the file is good.
public:
    SocialNetwork(std::string name);
    SocialNetwork();
    void SetCentralUser(std::string name) {_centralUser = name; };
    void SetIsGood(bool good) {_isGood = good; };
    bool GetIsGood() {return _isGood; };
    std::string GetCentralUser() {return _centralUser; };
    User* SearchUsers(std::string name);
    int GetNumFollowers(std::string name);
    void InsertRelationship(User* Followed, User* Following);
    void InsertUser(std::pair<std::string, User*> userPair);
    void SortSocialUsers();
    void PrintSortedUsers(std::string outputFilePath, std::string name, int numFollowers);
};

#endif //SNA_PROJECT_SOCIALNETWORK_H
