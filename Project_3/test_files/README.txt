==== Command Line Arguments and Input Files for Public and Private Test Cases ====

test1 - Some nearby business, but only one good (only one nearby business has minAvgRating=5.00)
>> ./spork test1.txt output1.txt 40.41 -80.00 0.07 5.00

test2 - Some good businesses, but none nearby
>> ./spork test2.txt output2.txt 35.56 -100 0.00 1.00

test3 - userLoc has negative coordinates (e.g., user is southwest of the origin)
>> ./spork test3.txt output3.txt -35.09 -80.83 4.00 2.00

test4 - Business with maximum adLevel is last in list (and there are no ties)
>> ./spork test4.txt output4.txt 35.15 -80.85 0.50 4.50

test5 - All businesses are good, nearby, and have same adLevel
>> ./spork test5.txt output5.txt 40.47 -79.97 1.11 5.00

test6 - All businesses are good and nearby (but one has higher adLevel)
>> ./spork test6.txt output6.txt 33.38 -111.74 100.00 0.00

test7 - Business with maximum adLevel is already first in the list (other entries may tie)
>> ./spork test7.txt output7.txt 33.72 -111.93 1.00 3.50

test8 - Input file has more than 500 valid entires
>> ./spork test8.txt output8.txt 40.46 -79.91 0.01 4.40

test9 - Invalid line with adLevel > 3
>> ./spork test9.txt output9.txt 33.30 -111.50 0.80 1.50

test10 - Multiple invalid lines (e.g., lines of all strings with no doubles or ints, empty line, lines with only business name)
>> ./spork test10.txt output10.txt 40.46 -79.90 0.04 2.00

test11 - Empty input file
>> ./spork test11.txt output11.txt 00.00 00.00 00.00 00.00