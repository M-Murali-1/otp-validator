
#define LT          201
#define RT          187
#define LB          200
#define RB          188
#define TT          203
#define BT          202
#define LST         204
#define RST         185
#define VL          186
#define HL          205
#define CROSS       206
#define SPACE        32
#define BACKSPACE     8
#define TOTCOLS      80
#define TOTROWS      25
#define DIM           7
#define WIDTH         5
#define HEIGHT        1
#define UP           72
#define DOWN         80
#define LEFT         75
#define RIGHT        77
#define HOME
#define END
#define RETURN
#define ESC         27
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+-----+
*/
int isLeap(int year)
{
    return ( ( (year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0)) ? 1 : 0;
}



int DayOfWeek( int y, int m, int d ) /* returns Day of Week:
0 = Sunday, 1= Monday...
*/
{
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
y -= m < 3;
return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
} /*--DayOfWeek( )--------*/


void cleanCalendar()
{
    int row;
     int col;
     int month_day_ctr;
     int week_day_num_ctr;

     col = ( TOTCOLS - ( ( WIDTH * DIM ) + (DIM + 1) ) ) / 2;
     row = ( TOTROWS - ( ( HEIGHT * DIM ) + (DIM + 1)) ) / 2;
     row+=3;
     col+=3;
     for( month_day_ctr  = 1,week_day_num_ctr = 0; month_day_ctr  <= \
         42 ; month_day_ctr+=1)
     {
         gotoxy(col + ( (week_day_num_ctr) * (WIDTH+1)), row );
          printf("  " );
          week_day_num_ctr +=1;
          if (week_day_num_ctr == DIM)
          {
              week_day_num_ctr=0;
              row+=2;
          }
     }

//getch();
}



void printCalendar(int mm, int year)
{
    int days_in_months [] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
 char monthNames [ ]  [ 10 ]   = {"", "January","February","March","April","May","June","July","August",\
    "September","October","November","December"};
     int row;
     int col;
     int month_day_ctr;
     int week_day_num_ctr;
     if (mm == 2)
         days_in_months [ 2 ] += isLeap(year);
     col = ( TOTCOLS - ( ( WIDTH * DIM ) + (DIM + 1) ) ) / 2;
     row = ( TOTROWS - ( ( HEIGHT * DIM ) + (DIM + 1)) ) / 2;
     row+=3;
     col+=3;
     gotoxy(31, 3);
     printf("%10s , %d",  monthNames[ mm ], year);
     for( month_day_ctr  = 1,week_day_num_ctr = DayOfWeek(year,mm,1); month_day_ctr  <= \
     days_in_months [ mm ] ; month_day_ctr+=1)
     {
         gotoxy(col + ( (week_day_num_ctr) * (WIDTH+1)), row );
          printf("%02d", month_day_ctr);
          week_day_num_ctr +=1;
          if (week_day_num_ctr == DIM)
          {
              week_day_num_ctr=0;
              row+=2;
          }
     }


}
void make_column_headings()
{
     int row;
     int col;
     char dayname [ 7 ] [ 4 ] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
     int dayname_ctr;
     col = ( TOTCOLS - ( ( WIDTH * DIM ) + (DIM + 1) ) ) / 2;
     row = ( TOTROWS - ( ( HEIGHT * DIM ) + (DIM + 1)) ) / 2;
     row+=1;
     col+=2;
     for( dayname_ctr = 0; dayname_ctr < DIM; dayname_ctr+=1)
     {
         gotoxy(col + (dayname_ctr * (WIDTH+1)), row );
          printf("%s", dayname[ dayname_ctr]);
     }
}
void drawDabba()
{
     int row;
     int col;
     int ctr1;
     int ctr2;
     int ctr3;
     int ctr4;

     col = ( TOTCOLS - ( ( WIDTH * DIM ) + (DIM + 1) ) ) / 2;
     row = ( TOTROWS - ( ( HEIGHT * DIM ) + (DIM + 1)) ) / 2;

     gotoxy(col, row);
     printf("%c", LT);
     for( ctr2 = 0; ctr2 < DIM; ctr2+=1)
     {
         for( ctr1 = 0 ; ctr1 < WIDTH; ctr1+=1)
         {
             printf("%c", HL);
         }
         printf("%c", TT);
     }
     printf("%c%c", BACKSPACE, RT);
     // first line
     for( ctr3 = 0 ; ctr3 < DIM; ctr3+=1)
     {
         row+=1;
         gotoxy(col, row);
         for( ctr2 = 0; ctr2 <= DIM; ctr2+=1)
         {
            printf("%c", VL);
            for( ctr1 = 0 ; ctr1 < WIDTH; ctr1+=1)
             {
                 printf("%c", SPACE);
             }
         }
         row+=1;
         gotoxy(col, row);
         printf("%c", LST);
         for(ctr2 = 0; ctr2 < DIM; ctr2+=1 )
         {
            for( ctr1 = 0 ; ctr1 < WIDTH; ctr1+=1)
             {
                 printf("%c", HL);
             }
             printf("%c", CROSS);
         }
            printf("%c%c", BACKSPACE, RST);
     }
     gotoxy(col, row);
     printf("%c", LB);
     for( ctr2 = 0; ctr2 < DIM; ctr2+=1)
     {
         for( ctr1 = 0 ; ctr1 < WIDTH; ctr1+=1)
         {
             printf("%c", HL);
         }
         printf("%c", BT);
     }
     printf("%c%c", BACKSPACE, RB);
     //getchar();
}
int main()
{
     int key;
     int mm;
     int yyyy;
     mm = 3;
     yyyy = 2023;
     drawDabba();
     make_column_headings();
     do
     {
         cleanCalendar();
         printCalendar(mm,yyyy);
         key = getch();
         if ( key == ESC) break;
         key = getch();
         switch ( key )
         {
             case LEFT : mm -= 1; break;
             case RIGHT : mm += 1; break;
             case UP : yyyy +=1; break;
             case DOWN : yyyy -=1 ;
         }
         if ( mm == 13)
         {
             yyyy += 1;
             mm = 1;

         }
         else if ( mm == 0)
         {
             mm = 12;
             yyyy -=1;
         }
     } while ( 1 );
	gotoxy(70,50);
    //getchar();
     return EXIT_SUCCESS;
}













