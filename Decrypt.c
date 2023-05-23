/**
 * Use Selection Sort to sort the strings in the array provided using the first
 * character in the strings. Then use the DECRYPTION_SHIFT value to shift the
 * characters in the strings to decrypt the encrypted message and display it
 * to the user.
 *
 * @author Luis Ramirez-Zamacona, Professor Acuna
 * @version 10/22/19
 */

//INCLUDES
#include <stdio.h>
#include <string.h>

//macros: constants
#define CHUNK_LENGTH (20+1)  //each chunk has twenty characters, we add 1 so
                             //there is space for the null terminator.
#define NUMBER_OF_CHUNKS 4   //the message is spread across 4 chunks.
#define DECRYPTION_SHIFT 5   //this is the ASCII table shift used for decryption.

//forward declarations
void sort_chunks();
void decrypt_chunks();
void display_chunks();

char chunks[NUMBER_OF_CHUNKS][CHUNK_LENGTH];

int main() {
    //copy message into memory.
    strcpy(chunks[0], "2i1%fsi%fs%jstwrtzx%");
    strcpy(chunks[1], "1'H%nx%vznwp~1%kqf|j");
    strcpy(chunks[2], "4R3%Wnyhmnj%%%%%%%%%");
    strcpy(chunks[3], "3xzhhjxx3'%2%Ijssnx%");

    //the format of a chunk is a single number indicating its order in overall
    //message followed by twenty encrypted characters.
    
    // Display the encrypted message
    printf("The encrypted message is: \n");
    display_chunks();

    //reorder chunks in message by sorting them based on the first digital
    //they contain. looking above, one can see they are currently in the order
    //2, 1, 4, 3 but should be ordered 1, 2, 3, 4.
    sort_chunks();

    //shift the characters in the message to produce the original characters.
    decrypt_chunks();

    //display the decrypted message.
    printf("\nThe decrypted message is: \n");
    display_chunks();

    return 0; 
}

//given two strings, swaps their contents in memory.
void swap_strings(char* x, char* y) {
    //create a temporary holding place for the data so we don't lose it.
    char temp[CHUNK_LENGTH];

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

//sorts the strings the global chunks variable by the first character they contain.
void sort_chunks() {
    int i, j, min;
  
    // Sort the array using the first integer of string
    for(i = 0; i < NUMBER_OF_CHUNKS - 1; i++) 
    { 
        min = i;
        
        for(j = i + 1; j < NUMBER_OF_CHUNKS; j++) {
            if(*chunks[j] < *chunks[min]) {
                min = j;
            }
        }

        // Swap the found minimum element with the first element 
        swap_strings(chunks[min], chunks[i]);
    }
}

//for each string in the global chunks variable, shifts the characters in it by
//DECRYPTION_SHIFT.
void decrypt_chunks() {
    char *p;
    int i, j;
    
    // Use the DECRYPTION_SHIFT value to shift the characters in the strings
    for(i = 0; i < 4; i++) {
        p = chunks[i] + 1;

        for(j = 0; *p; j++) {
            *p = *p - DECRYPTION_SHIFT;
            p++;
        }
    }
}

//displays the strings in the global chunks variable
void display_chunks() {
    char *p;
    int i, j;
    
    // Display the strings in the arrays back to back
    for(i = 0; i < 4; i++) {
        p = chunks[i] + 1;

        for(j = 0; *p; j++) {
            printf("%c", *p);
            p++;
        }
    }
    printf("\n");
}