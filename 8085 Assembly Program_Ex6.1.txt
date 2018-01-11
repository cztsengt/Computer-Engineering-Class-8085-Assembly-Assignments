// Caleb Tseng-Tham
// Mr.Wong
// November 5, 2015
// Ex.6_1

MAIN: 	CALL SETUP
	CALL SORT
	//CALL SEARCH
	HLT

SETUP:  
	MVI A,05	//Number of elements specified
	STA 1110	
		// First block of memory
	MVI B,00	// Set B to 0
	LXI B,1120 	// Store location in B,C
	LXI D,12A3	// Store Value in D,E
	MOV A,D		// Move first half of number to A
	STAX B		// Store A in first memory location
	INR C		// Increment by 1
	MOV A,E
	STAX B		// Store B in first memory location

		// Second block of memory
	INR C
	LXI D,12A4	// Store Value in D,E
	MOV A,D		// Move first half of number to A
	STAX B		// Store A in first memory location
	INR C		// Increment by 1
	MOV A,E
	STAX B		// Store B in first memory location
	
		// Third Block of memory
	INR C
	LXI D,01BD	// Store Value in D,E
	MOV A,D		// Move first half of number to A
	STAX B		// Store A in first memory location
	INR C		// Increment by 1
	MOV A,E
	STAX B		// Store B in first memory location
	
		// Fourth block of memory
	INR C
	LXI D,12A5	// Store Value in D,E
	MOV A,D		// Move first half of number to A
	STAX B		// Store A in first memory location
	INR C		// Increment by 1
	MOV A,E
	STAX B		// Store B in first memory location

		// Fifth block of memory
	INR C
	LXI D,12A7	// Store Value in D,E
	MOV A,D		// Move first half of number to A
	STAX B		// Store A in first memory location
	INR C		// Increment by 1
	MOV A,E
	STAX B		// Store B in first memory location
	RET
SORT: 	LDA 1110
	MOV B,A
	
COMPARE:	LXI H,1120
	MOV C,B
BEGIN:	MOV A,M
	INX H	
	INX H
	CMP M
	JC LOWER	// If FIRST HALF number is LOWER, skip swapping
	JZ CHECK	// if FIRST HALF numbers are the same, check SECOND HALF
			// Swapping
SWAPFULL:	MOV D,M	// Move memory (H,L) to D (temporary storage)
	MOV M,A		// Move old # into new memory	
	DCX H		// Go back 1 memory block
	DCX H		// Go back 1 memory block
	MOV M,D 	// Move new # into old memory
	INX H		// Go forward 1 memory block
	INX H		// Go forward 1 memory block (Everything has reset to neutral position now)
	DCX H		// Go back 1 memory block
	MOV A,M		// Set second half of first number into A
	INX H 		// Go forward 1 memory block
	INX H 		// Go forward 1 memory block
	MOV D,M		// Move memory (H,L) to D (temporary storage)
	MOV M,A		// Move old # into new memory	
	DCX H		// Go back 1 memory block
	DCX H		// Go back 1 memory block
	MOV M,D 	// Move new # into old memory
	DCX H		// Go back 1 memory block
LOWER: 	DCR C		//Decrement # of comparasions
	JNZ BEGIN	// Jump to BEGIN if comparasions =/= 0
	DCR B		// Decrement # of passes
	JNZ COMPARE	// Jump to COMPARE if passes =/= 0
	RET

CHECK:	DCX H 
	MOV A,M
	INX H
	INX H
	CMP M
	DCX H
	JC LOWER	// If FIRST HALF number is LOWER, skip swapping
	JZ LOWER	// if numbers being compared are the same then go to LOWER 
	JMP SWAPFULL 	// If it's not lower, and it's not equal, it must be higher, thus we should swap the numbers

	
RETURN:	RET


