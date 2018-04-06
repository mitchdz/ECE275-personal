Course Name: ece275 <br>
Author: <br>
NetID: <br>
Date: <br>
Project Name: project_9

# Description:
## High-Level Description
In this assignment you will calculate describe a social network of Twitter users as a graph and suggest friends to a specified user within that graph.

## Social Network Analysis
As social networking is becoming more and more popular among people, there is a growing interest in the study of extracting information from these networks, the so-called social network analysis (SNA). The usage of social network analysis, however, is far beyond that of Facebook or Twitter. The principle of SNA can be applied to other things; such as, finding the source and flow of an infectious disease, and scheduling the optimal production-market distribution for a globalized company.
The basic structure of SNA is a graph. To evaluate the characteristics of a graph and the nodes inside, people gradually develop a set of metrics, some of them are:

### Degree of Centrality
In an undirected graph, the degree centrality of a node i (denoted by CD(i)) is the node degree (number of edges), denoted by deg (i).

> CD(i) = deg (i)

Centrality captures “how connected" a node is in general. In a directed graph, the degree of centrality comes in two types: the in-degree centrality and the out-degree centrality. The in-degree centrality is number of edges that end at the node (i.e., the number of edges going to the node). The out-degree centrality is the number edges starting at the node (i.e., the number of edges leaving the node).

## Classes
You will be given **one** class to begin with. It is up to you to create other classes to represent the social network as a graph.

The class provided is called **SocialNetworkAnalysis** and represents the entire program that you intend to run. The purpose of this class is similar to CarSimulator and Chars in previous projects except that it has only one function called *Run* which takes in only file paths. In this function, you need to call all of the functions you need to run the program from beginning to end. A good program design would be evident by this function calling only a few other select functions that do the bulk of the work of the program just as the endToEnd tests did in the past.

The reason you are given this kind of class is mostly for the sake of grading your projects based on the end-to-end functionality. Since you are now given the freedom to write any functions or classes you choose, it is necessary for the grader to have a common function to call for all submissions in order to grade your project. So, you can think of this function, **Run** as your *main* function.

## Suggested Classes
### User
Users are essentially nodes/vertices in your graph. These need to be able to hold:

1. A username
2. A list of users following this user, you can decide which container to use for this.
3. A list of users being followed, you can decide which container to use for this.

### Relationship
Relationship is essentially and edge. This should at least have:

1. A copy, pointer, or reference to the "followed" User
2. A copy, pointer, or reference to the "following" User

### SocialNetwork
SocialNetwork is essentially the graph itself. This should at least have:

1. A list of users, you can decide which container to use for this. You may want to hold users in more than one container for computational efficiency ^_^. It's best to start with one first.

# Important Requirements
First and foremost, your project will be graded only on the end-to-end functionality. Writing unit tests are optional, but testing and developing your program in smaller steps will save you, and instructors, loads of time. You have been shown examples on how to do this until now.

Second, your program must finish in 5 seconds or less **on the server**. This has actually always been a requirement until now, but in this project, you will be handling substantially larger files at times. Therefore, having efficient algorithms actually becomes important. It is up to you to find the most computationally complex part of this assignment. My suggestion is that you make your program work first, then find the ineffeciencies later through debugging.

Third, **you must represent your social network as a graph structure for which a standard breadth-first or depth-first search can be used to search it.**

# Input File
## Formatting
The first line in the inputFilePath will contain the “**root user**” for which suggested friends will be found to follow.

The *inputFilePath* will consist of real Twitter accounts with their friends and for each friend his/hers friends etc. By using this data build up a graph and calculate the *in-degree centrality* for each user. The input file will have the following format:

```
github   john_stewart
github   microsoft
microsoft   oracle
```

Each line contains two usernames separated by three spaces.
Each username is no longer than 15 characters and contain only alphanumeric characters (letters A-Z,a-z, numbers 0-9) with the exception of underscores.
The two columns define the relationship between two accounts. The user in the second column is following the user in the first column. Thus, this is a directed graph.
For an empty file, a file that does not have the correct format, or if the specified **root user** is not found in the graph, the program should create an empty output file.

You can also assume that the input graph will be connected. Starting at any node, your program will be able to visit all other nodes using a breadth-first or depth-first search, or a variant thereof.

## Processing
As each line is read from the input text file, your program must keep track of users, their relationship, and their *in-degree centrality.* The *in-degree centrality* of a user is the number of users following it.

# Output File
The program should create a file using the *outputFilePath* with an output consisting of a list of all the users within a depth of 3 of the specified root user that are *not already being followed by that user.*
The list should be printed in descending order of in-degree of centrality.
In case of ties, the users should be output alphabetically by username (case-insensitive).
inDegreeofCentrality should be output using the default precision.
The output file should have the following format:

```
Looking for new accounts for rootUserName (inDegreeofCentrality) to follow
userName1 (inDegreeofCentrality)
userName2 (inDegreeofCentrality)
```
