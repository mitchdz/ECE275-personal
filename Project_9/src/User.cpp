//
// Created by mitch on 11/20/17.
//

#include "User.h"
#include <algorithm>
User::User(std::string name)    {
    _username = name;
    _numFollowers = 0;
    _isDepthOf3 = false;
}

User::User()    {
    _username = "";
    _numFollowers = 0;
    _isDepthOf3 = false;
}

void User::InsertFollowedRelationship(Relationship *relationship) {
    _followedRelationships.push_back(relationship);
}

void User::InsertFollowingRelationship(Relationship *relationship) {
    _followingRelationships.push_back(relationship);

}

    /*
     * Determines if a user is less than another.
     * 1. numFollowers needs to be less,
     * 2. name is alphabetically less than the other.
     *
     */
bool User::operator<(const User& rhs) const {
    if (this->GetNumFollowers() > rhs.GetNumFollowers())
            return true;
    std::string thisString = this->GetName();
    std::string rhsString  = rhs.GetName();
            //changes the strings to lowercase for comparison.
    std::transform(thisString.begin(), thisString.end(), thisString.begin(), ::tolower);
    std::transform(rhsString.begin(), rhsString.end(), rhsString.begin(), ::tolower);
        //compares the names alphabetically
    if ((this->GetNumFollowers() == rhs.GetNumFollowers())
        &&(thisString < rhsString))
            return true;

    return false;
}

std::string User::GetNameRelationshipAtIndex(int index) {
    return _followingRelationships[index]->GetNameFollowing();

}


void User::SetIsDepthof3(int i) {
    _isDepthOf3 = i;
}

int User::GetIsDepthof3() {
    return _isDepthOf3;
}


User* User::GetUserAtIndex(int index) {
        //FIXME: potentially change to _followedRelationships
    return _followingRelationships[index]->GetFollowingUser();
//      return _followingRelationships[index]->GetFollowingUser();
}


unsigned int User::GetSizeRelationship() {
    return _followingRelationships.size();
}


unsigned int User::GetSizeFollowedRelationship() {
    return _followedRelationships.size();


}

