# ClientServerUDP
This repository contains client server communication using UDP protocol. This contains two questions.

# Question 1
Write a pair of UDP client/server programs showing the two-way communication between client and server. Each message should display the number of bytes of the message received.

# Question 2
Design UDP iterative Client Server application to reverse the given input string. An iterative server is the one that deals with one client at a time but never Exit. (Client will send the string, server will reverse and display the output)

# OS Dependency
Ubuntu/Linux

# Import and Run
Firstly run server using following commnds.

For compiling:
  
  gcc -o s.out server.c

For running:

  ./s.out
  
After creating server, here comes the command for compiling and running client.

For compiling:  
  
  gcc -o c.out client.c

For running:
  
  ./c.out
