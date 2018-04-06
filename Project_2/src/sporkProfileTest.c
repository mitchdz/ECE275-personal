//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "sporkProfileTest.h"

void testSporkProfile(){
    testCreateProfileHasCorrectDefaults();
    testParseLineDiscardsWhenExtraInfo();
    testParseLineWorksWithFormat();
    testIsValidProfileAdLevelThree();
    testIsValidProfileAvgRatingNegative();
    testAddProfileWithMaxSporkProfiles();
    testAddProfileExceedsMaxSporkProfiles();
    testReadSporkProfileInvalidFile();
    
    testfindNearbyBusinessesTwoBusinesses();
    testCalculateDistanceIsCorrect();
    testfindNearbyBusinessesWithMinDistanceEqualToDistMiles();
    testfindGoodBusinessesTwoBusinesses();
    
    testGetBestBusinessAdLevelZero();
    testGetBestBusinessAdLevelOne();
    testGetBestBusinessAdLevelTwo();
    testGetBestBusinessListsFirstBusinessAdLevelTwo();
    testGetBestBusinessNoBestBusiness();
}

/*
 * @requirement pass if all members of profile are set to defaults
 * @return pass: 1, fail: 0
 */
int testCreateProfileHasCorrectDefaults(){


    SporkProfile newProfile = createSporkProfile();


   int j = 0, k = 0, b = 0;

    if (newProfile.locX == -1 && newProfile.locY == -1 && newProfile.distMiles == -1 && newProfile.avgRating == -1) {
        j = 1;
    }

    if (strlen(newProfile.businessName) == 0) {
        k = 1;
    }

    if (newProfile.isNearby == false && newProfile.isGood == false) {
        b = 1;
    }


   if (j == 1 && k == 1 && b == 1)    {
       return 1;
   }
   else
   {
       return 0;
   }
}

/*
 * @requirement pass if default profile is returned when extra info is included
 * BusinessName 1.0 2.0 3.0 1 extra
 * @return pass: 1, fail: 0
 */
int testParseLineDiscardsWhenExtraInfo(){
    /*BusinessName X.XX Y.YY R.RR Aa
     *BusinessName is the name of the restauarant/business. The buseiness name will not include any whitespace characters
     *X.XX represents the X location in miles using a Cartesian coodinate system
     *Y.YY represents the Y location in miles using a Cartesian coodinate system
     *R.RR represents the average rating for the business
     *A is the advertising level
    */


    char Profile[50] = "BusinessName 1.00 2.00 3.00 4 extra";

    SporkProfile newProfile = parseLine(Profile);

    if(strlen(newProfile.businessName) == 0
        && newProfile.locX == -1
        && newProfile.locY == -1
        && newProfile.adLevel == -1
        && newProfile.adLevel == -1)
    {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * @requirement pass if all members of profile correctly when line is formatted as:
 * BusinessName 1.0 2.0 3.0 1
 * @return pass: 1, fail: 0
 */
int testParseLineWorksWithFormat(){

    char profile[50] = "BusinessName 1.0 2.0 3.0 1";

    SporkProfile newProfile = parseLine(profile);

    if(strcmp(newProfile.businessName, "BusinessName") == 0
            && newProfile.locX == 1
            && newProfile.locY == 2
            && newProfile.avgRating == 3
            && newProfile.adLevel == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }




    return 0;
}

/*
 * @requirement pass if profile with ad level three returns 0 from isValidProfile
 * @return pass: 1, fail: 0
 */
int testIsValidProfileAdLevelThree(){

    SporkProfile newProfile = { .adLevel = 3}; //initializes a SporkProfile with an adLevel of 3.

//    newProfile.adLevel = 3;

    int result = isValidProfile(newProfile);

    if (result == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * @requirement pass if profile with negative rating returns 0 from isValidProfile
 * @return pass: 1, fail: 0
 */
int testIsValidProfileAvgRatingNegative(){

    SporkProfile  newProfile = { .avgRating = -1}; //creates a SporkProfile with an avgRating of -1.

    int result = isValidProfile(newProfile);

    if (result == 0)    {
        return 1;
    }
    else    {
        return 0;
    }
}

/*
 * @requirement pass if numProfiles is MAX_SPORK_PROFILES when exactly MAX_SPORK_PROFILES valid profiles are given to addProfile
 * @return pass: 1, fail: 0
 */
int testAddProfileWithMaxSporkProfiles(){


    SporkProfile newProfile[MAX_SPORK_PROFILES];

    SporkProfile newerProfile = {.adLevel = 1, .avgRating = 2, .businessName = "Potato"};

    int x = 499;
    int* ProfileNumbers = &x;


   // int numProfile = MAX_SPORK_PROFILES;  //don't need this!
    if (isValidProfile(newerProfile) == 0) {
        return 0;
    }
    else    {
    addProfile(newProfile, ProfileNumbers, newerProfile);
    ProfileNumbers++;
        }
    if (x == MAX_SPORK_PROFILES) {
        return 1;
    }
    else
    {
        return 0;
    }




}

/*
 * @requirement pass if addProfile returns -1 when MAX_SPORK_PROFILES + 1 valid profiles are passed to addProfile
 * @return pass: 1, fail: 0
 */
int testAddProfileExceedsMaxSporkProfiles(){

    SporkProfile newProfile[MAX_SPORK_PROFILES+1];
    SporkProfile newerProfile = {};

    int x = MAX_SPORK_PROFILES + 1;

    int* numProfiles = &x;

    //int numProfile = MAX_SPORK_PROFILES + 1;      //Don't need this


    int result = addProfile(newProfile, numProfiles, newerProfile);

    if (result == -1) {
        printf("----Test Passed. Value from addProfile is %d, expected -1\n", result);
        return 1;
    } else {
        printf("--/\\--Test Failed, value returned: %d, expected -1.\n", result);
        return 0;
    }


}

/*
 * @requirement pass if readSporkDataFromFile returns -1 when file does not exist
 * @return pass: 1, fail: 0
 */
int testReadSporkProfileInvalidFile(){

    //char* inputFile = NULL;
    //SporkProfile newProfile[1];

    SporkProfile newProfile[1];

    char x[50] = "NULL";

    int result = readSporkDataFromFile(newProfile, x);

    if (-1 == result) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * @requirement pass if findNearbyBusinesses properly sets two profile's isNearby when one is nearby and the other is not
 * @return pass: 1, fail: 0
 */
int testfindNearbyBusinessesTwoBusinesses() {

    SporkProfile newProfiles[2];

    newProfiles[0].locX = 0;
    newProfiles[0].locY = 0;
    newProfiles[1].locX = 24;
    newProfiles[1].locY = 25;



    double maxDistance = 10.0;

    double locationX = 0;
    double locationY = 0;

    findNearbyBusinesses(newProfiles, 2, locationX, locationY, maxDistance);

    if(newProfiles[0].isNearby == true && newProfiles[1].isNearby == false)  {
        return 1;
    }
    else{
        return 0;
    }
}
/*
 * @requirement pass if findNearbyBusinesses determines a business is near when distance is exactly the same as minDist
 * @return pass: 1, fail: 0
 */
int testfindNearbyBusinessesWithMinDistanceEqualToDistMiles(){


    SporkProfile newProfiles[1];
    //newProfiles->distMiles = 1;
    newProfiles[0].locX = 1;
    newProfiles[0].locY = 0;

    double maxDistance = 1.0;

    double locationX = 1.0;
    double locationY = 0.0;

    findNearbyBusinesses(newProfiles, 1, locationX, locationY, maxDistance);


    if (newProfiles[0].isNearby == true)  {
        return 1;
    }
    else{
        return 0;
    }


}

/*
 * @requirement pass if calculate distance correctly calculates distance
 * @hint you will need to make the distance is calculated within a margin of error of about .001. You may use the math library.
 * @return pass: 1, fail: 0
 */
int testCalculateDistanceIsCorrect(){

    SporkProfile newProfile[1];

    /*
     * X = 3
     * Y = 4
     * Z = 5
     */

    newProfile[0].locY = 4.0;
    newProfile[0].locX = 3.0;


    double locationX = 0.0;
    double locationY = 0.0;

    double distance = 5.0;

    calculateDistance(newProfile, locationX, locationY);

        //checks for if the function returns the correct value to a certain margin of error.
        //returns 1 if the function was successful, 0 otherwise.
    if ((newProfile[0].distMiles >= distance * 0.99) && (newProfile[0].distMiles <= distance * 1.01)) {
        return 1;
    } else {
        return 0;
    }

}

/*
 * @requirement pass if isNearby correctly returns nearby when distMiles is already calculated for the profile
 * @return pass: 1, fail: 0
 */
int testIsNearbyIsCorrect(){

    double ProfileDistance = 5.0;
    double maxDistance = 10.0;

    bool result = isNearBy(ProfileDistance, maxDistance);

    if (result == true) {
        return 1;
    }
    else{
        return 0;
    }
}

/*
 * @requirement pass if findGoodBusinesses correctly determines isGood for two businesses. One business should be good and another not good
 * @return pass: 1, fail: 0
 */
int testfindGoodBusinessesTwoBusinesses() {

    SporkProfile newProfile[2];

    newProfile[0].avgRating = 5;
    newProfile[1].avgRating = 1;

    int minRating = 2;


    findGoodBusinesses(newProfile, 2, minRating);

    if (newProfile[0].isGood == true && newProfile[1].isGood == false)   {
        return 1;
    }
    else{
        return 0;
    }


}



/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and both ad levels are zero
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelZero(){

    SporkProfile newProfile[2]; //creates an array of two SporkProfiles.

    newProfile[0].adLevel = 0;  //sets both sporkprofiles adLevel to 0.
    newProfile[0].isNearby = true;
    newProfile[0].isGood = true;
    newProfile[1].adLevel = 0;
    newProfile[1].isGood = true;
    newProfile[1].isNearby = true;


    int result = getIndexBestBusiness(newProfile, 2);   //execute the function getIndexBestBusiness to compare profiles.

    if (result == 0)    {   //check if the first result is the result that the function returns.
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and one ad level is zero and another is 1
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelOne(){


    SporkProfile newProfile[2]; //creates an array of two SporkProfiles.

    newProfile[0].adLevel = 1;  //sets both SporkProfiles to different adLevels.
    newProfile[0].isNearby = true;
    newProfile[0].isGood = true;
    newProfile[1].adLevel = 3;
    newProfile[1].isNearby = true;
    newProfile[1].isGood = true;

    int result = getIndexBestBusiness(newProfile, 2);   //execute the function getIndexBestBusiness to compare profiles.

    if (result == 1)    {   //check if the first result is the result that the function returns.
        return 1;
    }
    else {
        return 0;
    }

}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and one ad level is zero and another is 2
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelTwo(){


    SporkProfile newProfile[2]; //creates an array of two SporkProfiles.

    newProfile[0].adLevel = 2;  //sets both SporkProfiles to different adLevels.
    newProfile[0].isGood = true;
    newProfile[0].isNearby = true;
    newProfile[1].adLevel = 0;
    newProfile[1].isNearby = true;
    newProfile[1].isGood = true;


    int result = getIndexBestBusiness(newProfile, 2);   //execute the function getIndexBestBusiness to compare profiles.

    if (result == 0)    {   //check if the first result is the result that the function returns.
        return 1;
    }
    else {
        return 0;
    }


}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and both ad levels are 2.
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessListsFirstBusinessAdLevelTwo(){


    SporkProfile newProfile[2]; //creates an array of two SporkProfiles.

    newProfile[0].adLevel = 2;  //sets both SporkProfiles to an adLevel of 2.
    newProfile[0].isNearby = true;
    newProfile[0].isGood = true;
    newProfile[1].adLevel = 2;
    newProfile[1].isGood = true;
    newProfile[1].isNearby = true;


    int result = getIndexBestBusiness(newProfile, 2);   //execute the function getIndexBestBusiness to compare profiles.

    if (result == 0)    {   //check if the first result is the result that the function returns.
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * @requirement pass if getIndexBestBusiness returns -1 when no business isGood and isNearby
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessNoBestBusiness(){

    SporkProfile newProfile[2];
    newProfile[0].adLevel  = 0;
    newProfile[0].isGood = false;
    newProfile[1].isGood = false;
    newProfile[1].adLevel = 0;
    newProfile[0].isNearby = false;
    newProfile[1].isNearby = false;

    int result = getIndexBestBusiness(newProfile, 2);

    if (result == -1)   {
        return 1;
    }
    else{
        return 0;
    }

}
