//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sporkprofile.h"
#include <string.h>

/**
 * reads data from a specified file and creates SporkProfiles for each Business to be
 * placed in the global "profiles" variable.
 * This function is implemented using several smaller
 * helper functions that are indented below this.
 *
 * @requirement returns -1 if file is invalid
 * @param filename is a character array (string) with a path to a file
 * @return numProfiles the number of profiles correctly added to the array of profiles
 */
int readSporkDataFromFile(SporkProfile profiles[], char *filename) {

    FILE* inp = fopen(filename, "r");

    if (inp == NULL)   {
        return -1;
    }
    else
    {
        int lines = 0;
        char buffer[1000];

        while(fgets(buffer, sizeof(buffer), inp)) {
            ++lines;
        }

        rewind(inp);


        for(int i = 0; i < lines; ++i)  {
            fgets(buffer, sizeof(buffer), inp);
            profiles[i] = parseLine(buffer);
        }
        return lines;

    }
}




/**
 * Creates a spork profile
 *
 * @requirement All values must be initialized to -1, a blank, NULL, or False depending on the type
 * @return SporkProfile with default values
 */
SporkProfile createSporkProfile(){
    SporkProfile newProfile;

    newProfile.isNearby = false;
    newProfile.distMiles = -1;
    newProfile.isGood = false;
    newProfile.adLevel = -1;
    newProfile .avgRating = -1;
    newProfile.locX = -1;
    newProfile.locY = -1;
    strcpy(newProfile.businessName, "");

    return newProfile;
}

/**
 * Parses a string from a file and attempts to make a spork profile
 *
 * @param a string that has been taken from a file. This can potentially end with '\n' or
 * '\r\n' depending on the operating system the file was saved in.
 *
 * @requirement Each Business is formatted as such in the file:
 *
 *    BusinessName X.XX Y.YY R.RR A
 *
 * BusinessName is the name of the restauarant/business. The buseiness name will not include any
 * whitespace characters
 * X.XX represents the X location in miles using a Cartesian coodinate system
 * Y.YY represents the Y location in miles using a Cartesian coodinate system
 * R.RR represents the average rating for the business
 * A is the advertising level
 * @requirement If the line contains any additional information other than that provided here, default sporkProfile is returned
 *
 * @return SporkProfile created from attempting to parse the line in the file.
 */
SporkProfile parseLine(char* line){


    if (line[strlen(line) - 2] == '\r')
            line[strlen(line) - 2] = '\0';
    if (line[strlen(line - 1)] == '\n')
            line[strlen(line) - 1] = '\0';

    SporkProfile newProfile;


    char buffer[250];

    if ( sscanf(line, "%s %lf %lf %lf %d %s", newProfile.businessName, &newProfile.locX, &newProfile.locY, &newProfile.avgRating, &newProfile.adLevel, buffer) == 6 )   {
        return createSporkProfile();
    }
    else
    {                           //FIXME: check if there is any extra information
        sscanf(line, "%s %lf %lf %lf %d", newProfile.businessName, &newProfile.locX, &newProfile.locY, &newProfile.avgRating, &newProfile.adLevel);
        return newProfile;
    }

}

/**
 * Verifies whether a SporkProfile is valid. This SporkProfile is presumably created by parseLine
 *
 * @param SporkProfile to verify
 *
 * @requirement AdLevel must be >= 0 and <= 2
 * @requirement Average rating must be >= 0 and <= 5
 * @requirement businessName must have length greater than 0
 *
 * @return 0 if profile is invalid, 1 otherwise
 */
int isValidProfile(SporkProfile profile){

    if (profile.adLevel >= 0 && profile.adLevel <= 2
            && profile.avgRating >= 0 && profile.avgRating <= 5
            && (strlen(profile.businessName) > 0))   {
        return 1;
    }
    else    {
        return 0;
    }

}

/**
 * Adds a profile to to global profiles and increments the total number of profiles kept
 *
 * @param Sporkprofile to add
 *
 * @requirement profile must be valid
 * @requirement must not exceed the maximum number of profiles
 * @return -1 if profile is not added, 0 otherwise
 */
int addProfile(SporkProfile profiles[], int* numProfiles,
               SporkProfile profile){
    if (isValidProfile(profile) == 1 && *numProfiles < MAX_SPORK_PROFILES)  {

        strcpy(profiles[*numProfiles].businessName, profile.businessName);
        profiles[*numProfiles].adLevel = profile.adLevel;
        profiles[*numProfiles].isNearby = profile.isNearby;
        profiles[*numProfiles].isGood = profile.isGood;
        profiles[*numProfiles].locX = profile.locY;
        profiles[*numProfiles].locY = profile.locY;
        profiles[*numProfiles].avgRating = profile.avgRating;
        profiles[*numProfiles].distMiles = profile.distMiles;
        ++*numProfiles;

        return 0;
    }
return -1;

}


/**
 * Determines if all Businesses in global profiles are nearby using
 * standard distance forumula to calculate the distance from a business to the user.
 * If this is below a maximum distance, then the profile datamember isNearby is
 * set to true. Otherwise, false.
 * This function is implemented using several smaller helper functions that are indented below this.
 *
 * @param userLocX is the user's "x" location on a grid
 * @param userLocY is the user's "y" location on a grid
 * @param maxDist is the maximum distance between a business and user for which a business
 * can be said to be "nearby."
 */
void findNearbyBusinesses(SporkProfile profiles[], int numProfiles,
                          double userLocX, double userLocY, double maxDist){
    for(int i = 0; i < numProfiles; ++i)    {               //incrementes through the SporkProfiles
        calculateDistance(&profiles[i], userLocX, userLocY);    //Calculates the distance, and determines if close.
        profiles[i].isNearby = isNearBy(profiles[i].distMiles, maxDist);    //uses isNearby to check, and change value.
    }
}

/**
 * Calculates a distance between a business and the user using the standard distance formula and assigns it to the profiles distance
 *
 * @param profile is a pointer to SporkProfile of business
 * @param userLocX is the user's "x" location on a grid
 * @param userLocY is the user's "y" location on a grid
 */
void calculateDistance(SporkProfile* profile, double userLocX, double userLocY){
    double sum; //initializes a variable called sum of type double
    sum = sqrt(pow((profile->locX - userLocX), 2) + pow((profile->locY - userLocY), 2));
    profile->distMiles = sum;   //sets profile's distance to the distance between it and the object.
}

/**
 * Discerns if a business is nearby
 *
 * @param profileDist between business and user. Presumably calculated by calculateDistance.
 * @param maxDist is the maximum distance between a business and user for which a business
 * can be said to be "nearby."
 *
 * @return true if profileDist is less than or equal to maxDist.
 */
bool isNearBy(double profileDist, double maxDist){
    return (profileDist <= maxDist);
}


/**
 * Determines if all Businesses in global profiles are "good"
 * This function is implemented using several smaller helper functions that are indented below this.
 *
 * @param minRating the minimum rating for which a Business can be said to be "good."
 */
void findGoodBusinesses(SporkProfile profiles[], int numProfiles, double minRating){
    for(int i = 0; i < numProfiles;++i) profiles[i].isGood=(isGood(profiles[i], minRating));
}

/**
 * Determines if a signal business "isGood"
 *
 * @param minRating the minimum rating for which a Business can be said to be "good."
 * @param profile SporkProfile of business to discern "goodness"
 * @return true if business is good, false otherwise.
 */
bool isGood(SporkProfile profile, double minRating){
    if (profile.avgRating >= minRating) {
        return true;
    }
    else    {
        return false;
    }
}


/**
 * Returns the index of the "best" profile.
 *
 * @requirement Business must be nearby
 * @requirement Business must be good
 * @requirement Business must have the highest adLevel out of all Businesses that are
 * both nearby and good
 * @requirement In the event of a tie, the first Business that is found is the "best"
 * @returns -1 if no Businesses are nearby and good, index of best profile otherwise
 */
int getIndexBestBusiness(SporkProfile profiles[], int numProfiles){
    int i ,j = 0;

    for(i = 0; i < numProfiles;++i) {
        if(profiles[i].isNearby == true && profiles[i].isGood == true)    {
            j = 1;
        }
    }
    if (j == 0) {
        return -1;
    }
    int indexBest = 0, bestValue = 0;

    for(i = 0; i < numProfiles; ++i)    {
        if (profiles[i].isNearby == true && profiles[i].isGood == true)  {
            if (profiles[i].adLevel > bestValue)   {
                indexBest = i;
                bestValue = profiles[i].adLevel;
            }
        }
    }
    return indexBest;
}

/** Writes all good and nearby business to an output file specified by fileName
 * This will be implemented using helper functions that are specified below
 *
 * @param filename is a character array (string) with a path to a file to write to
 * @param maxSponsorIndex determined by getIndexMaxSponsor
 *
 * @returns: -1 if the output file could not be opened, and 0 otherwise.
 */
int writeSporkResultsToFile(SporkProfile profiles[], int numProfiles, char *fileName){

    FILE* inp = fopen(fileName, "w");

    if (inp == NULL)    {
        printf("Yo diggity dog, dat profile dun exist in dis domain. Yo.\n");
        fclose(inp);
        return -1;
    }
    printProfiles(profiles, numProfiles, inp);
    fclose(inp);
    return 0;
}

/* Prints all profiles
 *
 * @requirement Business at IndexBestBusiness must be printed first, unless there is no
 * "best" Business
 * @requirement All SporkProfiles are printed in the order they were encountered.
 *
 */
void printProfiles(SporkProfile profiles[], int numProfiles,
                   FILE* outputFile){
    int bestIndex = getIndexBestBusiness(profiles, numProfiles);

    if (bestIndex >= 0) {
        printProfile(profiles[bestIndex], outputFile);
    }

    for (int i = 0; i < numProfiles; ++i)   {
        if ( (bestIndex >= 0)&&( i == bestIndex)) ++i;
        if (profiles[i].isGood == true
                && profiles[i].isNearby == true)    {
            printProfile(profiles[i], outputFile);
        }
    }
}

/* Prints a single profile
 *
 * @requirement each business must be printed in the format:
 *
 * BusinessName R.RR D.DD
 *
 *
 * where R.RR is the average rating with exactly two decimal digits of precision.
 * and D.DD is the distance in miles with exactly two decimal digits of precision.
 * Note that the spaces here are effectively "tab" characters, not merely spaces.
 */
void printProfile(SporkProfile profile, FILE* outputFile){
    fprintf(outputFile, "%s\t%.2lf\t%.2lf\n", profile.businessName, profile.avgRating, profile.distMiles);
}
