// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


// while(1) {
//    if(RAM[KBD] != 0) {
//       fill
//    } else {
//       clean
//    }
// }

(KBDLOOP)
  @i 
  M=0

  @KBD
  D=M 
  
  @FILL_LOOP
  D;JNE      // RAM[KBD] != 0
             // go to fill

  @CLEAN_LOOP
  0;JMP      // RAM[KBD] == 0
             // go to clean


(FILL_LOOP)
  @i
  D=M 
  @8192
  D=D-A
  @STOP 
  D;JGE // finish if i >= 8192
  
  @i
  D=M
  @SCREEN
  A=A+D
  M=-1

  @i
  M=M+1
  @FILL_LOOP
  0;JMP

(STOP)
  @KBDLOOP
  0;JMP

(CLEAN_LOOP)
  @i
  D=M 
  @8192
  D=D-A
  @STOP2 
  D;JGE // finish if i >= 8192
  
  @i
  D=M
  @SCREEN
  A=A+D
  M=0

  @i
  M=M+1
  @CLEAN_LOOP
  0;JMP
(STOP2)
  @KBDLOOP
  0;JMP


