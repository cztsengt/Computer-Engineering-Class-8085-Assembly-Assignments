// Caleb Tseng-Tham
// Mr. Wong
// October 20, 2015
// Ex.2-5

MVI A,3A  	//Move value 3A into register A         
STA 0101	//Store contents of register A into memory 0101
MVI A,1B       	//Move value 1B into register A
STA 0102        //Store contents of register A into memory 0102
LDA 0101	//Load byte at memory 0101 to register A
MOV B,A		//Move contents of register A to register B
LDA 0102 	//Load byte at memory 0102 to register A
MOV C,A		//Move contents of register A to register C
MOV A,B		//Move contents of register B to register A
ADD C		//Add the contents of register C and register and store the result in register A
STA 0103	//Store the contents of register A in memory 0103
HLT		//Stop Program

