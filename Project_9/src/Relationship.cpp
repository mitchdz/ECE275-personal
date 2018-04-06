//
// Created by mitch on 11/20/17.
//
#include "Relationship.h"


Relationship::Relationship() {
    _followed = nullptr;
    _following = nullptr;
}

std::string Relationship::GetNameFollowing() {
    return _following->GetName();
}

User* Relationship::GetFollowingUser() {
    return _following;
}

