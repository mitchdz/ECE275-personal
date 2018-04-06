//
// Created by mitch on 11/20/17.
//

#ifndef SNA_PROJECT_USER_H
#define SNA_PROJECT_USER_H

#include <string>
#include <unordered_map>
#include <string>
#include "Relationship.h"
#include <vector>
    //forward declaring Relationship, so User know it exists.
class Relationship;


class User{
private:
    std::string _username;
    std::vector<Relationship*> _followingRelationships;
    std::vector<Relationship*> _followedRelationships;

    int _numFollowers;
    bool _isDepthOf3;

public:
    User();
    User(std::string name);
    void InsertFollowedRelationship(Relationship* relationship);
    void InsertFollowingRelationship(Relationship* relationship);
    std::string GetName() const {return _username; };
    void IncrementNumFollowers() {_numFollowers += 1; };
    int GetNumFollowers() const {return _numFollowers; };
    bool operator<(const User& rhs) const;
    unsigned int GetSizeRelationship();
    unsigned int GetSizeFollowedRelationship();
    std::string GetNameRelationshipAtIndex(int index);
    User* GetUserAtIndex(int index);
    void SetIsDepthof3(int i);
    int GetIsDepthof3();
};

#endif //SNA_PROJECT_USER_H
