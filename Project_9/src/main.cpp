//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"

int main(){
    
    EndToEndTester test;
    test.RunTests();
    
    return 0;
}






//
//## Suggested Classes
//### User
//        Users are essentially nodes/vertices in your graph. These need to be able to hold:
//
//1. A username
//2. A list of users following this user, you can decide which container to use for this.
//3. A list of users being followed, you can decide which container to use for this.
//
//### Relationship
//        Relationship is essentially and edge. This should at least have:
//
//1. A copy, pointer, or reference to the "followed" User
//2. A copy, pointer, or reference to the "following" User
//
//### SocialNetwork
//        SocialNetwork is essentially the graph itself. This should at least have:
//
//1. A list of users, you can decide which container to use for this. You may want to hold users in more than one container for computational efficiency ^_^. It's best to start with one first.

