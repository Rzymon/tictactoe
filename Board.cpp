#include "Board.h"

Board::Board()
{
    for (int i=0; i<(9*9); i++)
        grid[i/9][i%9] = nothing;

    currentSubgrid = 0;
}

void Board::show()
{
    /*int a = -1, b = 9;
    for (int i=0 ; i<81 ; i++, b++)
    {

    	if (!( i % 3))	{ printf("  ");	a++;	b-=3; }
    	if (!( i % 9))	{ printf(" || "); a-=3;	b+=3; }
    	if (!( i % 27)) { printf("\n"); a+=3;	b-=9; }
        printf("(%i%i)", a, b);
    ;		printf("%c", grid[a][b]);
    }*/
    int a=0, b=0;
    for(int i=0; i<81; i++, b++)
    {
        if(i!=0 && !(i%3)) {printf(" || "); a++; b-=3; }
        if(i!=0 && !(i%9)) {printf("\n"); a-=3; b+=3; }
        if(i!=0 && !(i%27)) {printf("  "); for(int p=0; p<21; p++){printf("=");} printf("\n"); a=3; b=0;}
        if(i!=0 && !(i%54)) {a=6; b=0;};
        //printf("(%i%i)", a, b);
        if(!(i%9)) {printf(" || ");}
        printf("%c", grid[a][b]);
        if(i==80) {printf(" || ");}
    }
}

bool Board::play(int space, enum figures figure)
{
    printf("ruch %i:%i:%c\n", currentSubgrid,space,figure);
    if ( currentSubgrid >= 0 && grid[currentSubgrid][space] == nothing )
    {
        grid[currentSubgrid][space] = figure;
        for (int i = 0; i<9; i++)
            if( grid[space][i] == nothing )
            {
                currentSubgrid = space;
                return true;
            }
        return true;
    }
    else return false;
}
