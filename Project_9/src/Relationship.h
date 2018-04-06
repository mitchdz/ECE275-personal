//
// Created by mitch on 11/20/17.
//

#ifndef SNA_PROJECT_RELATIONSHIP_H
#define SNA_PROJECT_RELATIONSHIP_H

#include <string>
#include "User.h"


    //forward declaring User so Relationship knows it exists.
class User;


class Relationship{
private:
    User* _following;
    User* _followed;
public:
    Relationship();

    void SetFollowing(User* temp) {_following = temp; };
    void SetFollowed(User* temp) {_followed = temp; };
    std::string GetNameFollowing();
    User* GetFollowingUser();
};

#endif //SNA_PROJECT_RELATIONSHIP_H
