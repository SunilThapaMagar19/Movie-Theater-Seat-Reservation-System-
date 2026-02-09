//Sunil Thapa Magar  1002148333


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define TICKET_LIMIT 4

void FillMovieTheater(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols, char movie[MAX_ROWS*MAX_COLS]) 
{
    int a =0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            MovieTheater[i][j] = movie[a];
            a++;
        }
    }
}

void PrintSeatMap(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols) 
{
    printf("       ");
    for (int i = 1; i <= cols; i++) 
    {
        printf(" Seat %d", i);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) 
    {
        printf("Row %c ", 'A' + i);

        for (int j = 0; j < cols; j++) 
        {
            printf("%7c", MovieTheater[i][j]);
        }
        printf("\n");
    }
}

int IsSeatSold(char MovieTheater[MAX_ROWS][MAX_COLS], int row, int col) 
{
    int Check;
    if (MovieTheater[row][col] == 'X') 
    {
        Check = 1; 
    } 
    else 
    {
        MovieTheater[row][col] = 'X'; 
        Check = 0; 
    }
    return Check;
}



void WriteMovieTheater(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    char outputFileName[20];
    FILE *OUT = NULL;
    
    printf("Enter output filename: ");
    scanf("%s", outputFileName);

    OUT = fopen(outputFileName, "w+");

    if (OUT == NULL) 
    {
        printf("File did not open...exiting\n");
        exit(0);
    }

    fprintf(OUT, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            fprintf(OUT, "%c", MovieTheater[i][j]);
        }
    }

    fclose(OUT);
}


int main() 
{
    int purchasedTickets = 0;
    int ticketsSold = 0;
    int arrayRow; 
    int arrayCol;
    int numRows; 
    int numCols;
    char userRow;
    int userCol;
    char MovieTheater[MAX_ROWS][MAX_COLS] = {};

    FILE *Ufile = NULL;
    char userinputfile[20]={};
    char movie[MAX_ROWS*MAX_COLS]={};
    printf("Enter the name of your Movie Theater file: ");
    scanf("%s", userinputfile);
    Ufile= fopen(userinputfile,"r+");
    if (Ufile == NULL)
    {
        printf("The file did not open. Exiting...");
        exit(0);
    }
    fscanf(Ufile, "%d %d \n", &numRows, &numCols);
    fgets(movie, sizeof(movie)-1, Ufile);
    fclose(Ufile);

    
    FillMovieTheater(MovieTheater, numRows, numCols,movie);

    printf("How many tickets would you like to purchase? (limit %d) ", TICKET_LIMIT);
    scanf("%d", &purchasedTickets);

    while (purchasedTickets < 0 || purchasedTickets > TICKET_LIMIT)
    {
        printf("This is a special showing - limit of %d tickets per purchase\n", TICKET_LIMIT);
        printf("How many tickets would you like to purchase? (limit %d) ", TICKET_LIMIT);
        scanf("%d", &purchasedTickets);
    }

    if (purchasedTickets == 0)
    {
        printf("No movie for you!\n");
    }
    else
    {
        while (ticketsSold < purchasedTickets) 
        {
            PrintSeatMap(MovieTheater, numRows, numCols);

            printf("Enter seat choice by entering the row and seat\n");
            printf("Please pick a seat ");

            scanf(" %c%d", &userRow, &userCol);

            userRow = toupper(userRow);

            arrayRow = userRow - 'A';
            arrayCol = userCol - 1;

            if (arrayRow < 0 || arrayRow >= numRows || arrayCol < 0 || arrayCol >= numCols) 
            {
                printf("That seat is not in this theater!!\n");
            } 
            else if (IsSeatSold(MovieTheater, arrayRow, arrayCol)) 
            {
                printf("Seat %c%d is already sold. Pick a different seat.\n", userRow, userCol);
            } 
            else 
            {
                ticketsSold++;
            }
        }

        printf("Please find your way to your seats using this map...\n");
        PrintSeatMap(MovieTheater, numRows, numCols);
        printf("Enjoy your movie!\n");
    }
    
    WriteMovieTheater(MovieTheater, numRows, numCols);

    return 0;
}