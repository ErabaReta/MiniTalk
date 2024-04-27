# MiniTalk
The purpose of this project is to code a small data exchange program using UNIX signals but only SIGUSR1 and SIGUSR2 allowed to use.

## the idea:
the makefile comiles the source files into  program in the form of a client and a server.
• The server  start first. After its launch, then it prints its PID.

• The client takes two parameters:

 > The server PID.

 > The string to send.
    
• The client send the string passed as a parameter to the server.

Once the string has been received, the server prints it and then it send bqck to the client a confirming message to the client.

## how it works:
because only the signals SIGUSR1 and SUGUSR2 are allowed to communicate between th clinet and the server, so the first idea is to look at the them as a binary units (like 0 and 1) since you can present any character by the binary value stored in its bytes.

so the client iterate the message and send bit by bit (chars varible are stored in one byte and each byte contain 8 bits).

the same for the server who catch the signals one by one so it prints tha character every 8 bit, but look carefully, signals don't actually take a data with them like you cant store a data in a signal then send, we just agree to take a signal to present that binary unit for example, in my project i toke the SIGUSR1 as the bit 0 and toke the SIGUSR2 as bit 1.

## using makefile:
to compile all the medatory functions into object files then archive them to a clinet and server program use the command:

    make

or you can use:

    make client;
    make server
or:
    make all

for the bonus part use:

    make bonus

to delete the object files you can use:

    make clean

and to the delete the object files and the program you can use:

    make fclean 

rebuilding the library will be done if you use:

    make re
