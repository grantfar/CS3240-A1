                                       Assignment 1
                                (Part 2 after Assignment 0)
                       Due: Oct 8 (Monday Session)/ Oct 9 (Tuesday Session)

PLEASE HONOR NAME CHOICES

You are to use the functionality of Assignment 0 to make a permanent(ish) database of the
ordered song data you have extracted from SongCSV.csv. You are to do this with two programs:

The first is BuildDataBase -- this will put the structs you have extracted from the original file
into a file called BinarySongData. In addition there will be a 'directory' that contains the
correspondence between the song names and the offset of that song struct. This directory will be
sorted. You will write the directory as a separate file. After BuildDataBase, the above information
has been created and the program terminates.

The second is UseDataBase - this will open the file(s) created above and allow a user to ask for a
song name and be presented with the song information (formatted reasonably). For both of the
above you CAN use Chapter 5 Standard I/O Library, 'F' WORDS (fopen, fwrite, fread, fseek, etc).

The UseDataBase interface will prompt the user for a song name and exit when 'ZZZ' is entered. 
Same as before. You will submit a) the two programs above along with any headers you have created, 
which MUST be named BuildDataBase.c and UseDataBase.c b) the typescript generate by the script command.

Another makefile and sample input data file has been provided. Name your programs so that the
command 'make && make build && make use' compiles and runs both programs.

                                              Discussion
This assignment will clarify the distinction between a) system calls and libraries built on top of
them (‘standard library’), and b) buffered and unbuffered I/O. c) The idea of a ‘binary’ file vs an ‘ascii’ 
file is also highlighted here. The data written to the database, and to the directory does not need to 
be read by humans so don’t waste the bytes. Please honor our name choices so we can test more easily.
