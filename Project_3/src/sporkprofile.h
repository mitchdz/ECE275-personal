//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef SPORKPROFILE_H
#define SPORKPROFILE_H

#include <stdbool.h>

#define MAX_BUSINESSNAME_LEN 100
#define MAX_SPORK_PROFILES 500

/**
 * @datamember businessName is the name of the Business
 * @datamember locX is the "x" location on a grid
 * @datamember locY is the "y" location on a grid
 * @datamember distMiles is the distance of the Business to the user
 * @datamember avgRating is the average rating of the Business
 * @datamember adLevel is the ad level of the Business
 * @datamember isNearby is a bool describing the Business is "nearby" the user
 * @datamember isGood is a bool describing the Business is "good" to the user
 */
typedef struct SporkProfile_struct {
   char businessName[MAX_BUSINESSNAME_LEN];
   double locX;
   double locY;
   double distMiles;
   double avgRating;
   int adLevel;
   bool isNearby;
   bool isGood;
} SporkProfile;

int readSporkDataFromFile(SporkProfile profiles[], char *filename);

    SporkProfile createSporkProfile();
    SporkProfile parseLine(char* line);
    int isValidProfile(SporkProfile profile);
    int addProfile(SporkProfile profiles[], int *numProfiles, SporkProfile profile);

void findNearbyBusinesses(SporkProfile profiles[], int numProfiles, double userLocX, double userLocY, double maxDist);

    void calculateDistance(SporkProfile *profile, double userLocX, double userLocY);

    bool isNearBy(double profileDist, double maxDist);

void findGoodBusinesses(SporkProfile profiles[], int numProfiles, double minRating);

    bool isGood(SporkProfile profile, double minRating);

int getIndexBestBusiness(SporkProfile profiles[], int numProfiles);

int writeSporkResultsToFile(SporkProfile profiles[], int numProfiles,
                            char *fileName);

    void printProfiles(SporkProfile profiles[], int numProfiles,
                       FILE* outputFile);
    void printProfile(SporkProfile profile, FILE* outputFile);

#endif
