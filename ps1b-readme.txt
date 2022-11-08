/**********************************************************************
 *  PS1b: LFSR - PhotoMagic (Part B)
 **********************************************************************/
Name: Jacob George
Hours to complete assignment: 4 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was using the LFSR I implemented in PS1A and using that to encrypt/decrypt a png file,
as well as display both encoded and decoded images on two rendered windows using SFML.

/**********************************************************************
 *  Functionality of Program.
 **********************************************************************/
The program fully works. It displays both the decoded and encoded images in seperate windows.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Image.php#details 
This website was used to help me understand sf::Image

https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
This website was used to help me how pixels work in SFML

https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Window.php
This website was used to help me create windows for displaying images

Class Discord Server: Dr. Daly's Class

Tutor - Benjamin F: Clarified how the transform function works

Class Code Example: pixels.cpp

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
How to run program: 
make
./PhotoMagic decode.png encode.png 1011011000110110
make clean

I used decode.png, encode.png, and 1011011000110110 as my input.png, output.png, and seed respectively.

decoded_image_in_window & encoded_image_in_window were the screenshots of my images in the
rendered windows, not the pngs that I used for my input and output.