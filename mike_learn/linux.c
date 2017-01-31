/********************* Answer for Exam 1 Question 2 ********************
************************************************************************

2a. Command: mkdir my-projects

2b. This might have been because the permission set for the my-projects
directory was such that the user's group cannot gain access (read or 
write). Although I set the file permission of robot-moves.c with
chmod command such that the user's group and everyone else can only
read and execute the file (5 = 4 + 1), this is not the root cause since
permission to read the file essentially gives the permission to copy the
file. Perhaps only I, the user, can have access to the directory contain-
ing the robot-moves.c file with all three permissions: reading, writing
and execution. 

To resolve this particular difficulty, I could use the chmod command
again to set the permission for the user's group at 7 (all three 
permissions granted). The corresponding Linux command is as follows:

cd
cd my-projects
chmod 755 .. //setting permission for home directory.
chmod 755 . //setting permission for current directory.

//setting permission for file in case my lab in case she/he needs to 
modify the file. 
chmod 775 robot-moves.c 


In this way, the user's group, which includes my lab partner, would
be able to copy the file as she/he wants since she/he gets the permi-
ssion to read and execute the my-projects directory.

******************************* THE END *******************************/

