# author: Your Name
# NetID: Your NetID
# Date: 06 January 2016
# Project Number: 

# This file is an exception to the Code of Academic Integrity, and may be reused without
# the need to request permission for future assignments **as long as all edits are made by
# the submitting student**. Once a student modifies the file, they may not share it with
# any other student; sharing it in any way is a violation of the Code of Academic Integrity.


# Windows does weird things sometimes. This helps control the madness.
# adds debug information for all other OSs
add_definitions(-Wall -g)

# The following file GLOB command will search for all files within the current directory
# that match the specified expressions (*.c and *.h), and assign the resulting files
# to the variable SRCS. Thus, SRCS is a list a all C source and header files in the 
# current directory.

file( GLOB SRCS *.c *.h )

# Define the target application executable (named echoer) and the list of C source
# and header files needed for the executable.
add_executable( ececms ${SRCS} )
# set_property(TARGET echo PROPERTY C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
