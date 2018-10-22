#include <stdio.h>

/**
 * @brief returns a row (int), where two files differ. -1 if they are equal to the very end
 * 
 * @param f1 the first filename
 * @param f2 the second filename
 * @return int the row at which the files differ
 */
int compare( char *f1, char *f2 ) {
    FILE *file1 = fopen( f1, "r" );
    FILE *file2 = fopen( f2, "r" );
    int row = 0;
    int c1 = 0;
    int c2 = 0;
    do{
        c1 = fgetc(file1);
        c2 = fgetc(file2);
        if( c1 != c2 ) {
            return row;
        }
        row++;
    } while( c1 != EOF && c2 != EOF );

    // Make sure to always close all opened files
    fclose( file1 );
    fclose( file2 );
    // This means that both files are equal up intil their very ends.
    return -1;
}

/**
 * @brief outputs corresponging error messaegs. Returns 0 (false) if c != 3
 * 
 * @param c the amount of arguments given by the user on the command line
 * @return int the validity of the ammount of commands. 0 if c != 3
 */
int controlArgs( int c ) {
    if( c == 1 ) {
        printf("No arguments were given. No Files to be compared.\n");
    } else if( c == 2 ) {
        printf( "Error: need another filename to compare!\n" );
    } else if( c == 3 ) {
        return 1;
    } else {
        printf( "Error: too many arguments given!\n" );
    }
    return 0;
}

int main( int argc, char **argv ) {
    if( controlArgs( argc ) ) {
        int row = compare( argv[2], argv[3] );
        if( row != -1 ) {
            // They are different
            printf( "The files differ from each other at row %d \n", row );
        } else {
            printf( "The files are equal!\n" );
        }
    } 
}