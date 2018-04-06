//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef SPORKPROFILETEST_H
#define SPORKPROFILETEST_H

#include <stdio.h>
#include "sporkprofile.h"
#include <string.h>
#include <math.h>


void testSporkProfile();
int testCreateProfileHasCorrectDefaults();
int testParseLineDiscardsWhenExtraInfo();
int testParseLineWorksWithFormat();
int testIsValidProfileAdLevelThree();
int testIsValidProfileAvgRatingNegative();
int testAddProfileWithMaxSporkProfiles();
int testAddProfileExceedsMaxSporkProfiles();
int testReadSporkProfileInvalidFile();

int testfindNearbyBusinessesTwoBusinesses();
int testCalculateDistanceIsCorrect();
int testfindNearbyBusinessesWithMinDistanceEqualToDistMiles();
int testIsNearbyIsCorrect();

int testfindGoodBusinessesTwoBusinesses();

int testGetBestBusinessAdLevelZero();
int testGetBestBusinessAdLevelOne();
int testGetBestBusinessAdLevelTwo();
int testGetBestBusinessListsFirstBusinessAdLevelTwo();
int testGetBestBusinessNoBestBusiness();

#endif
