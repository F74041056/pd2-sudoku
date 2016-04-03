#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;

int map[10][10];
int add;
int ats[10][10];

Sudoku::Sudoku()
{
	add=0;
	int i,j;
    for(i=1;i<10;i++)
     for(j=1;j<10;j++)
      ats[i][j]=0;
}

void Sudoku::giveQuestion()     //create my own sukodu board
{
	int i,j;		 
	int giveQue[9][9]={{0,4,0,2,1,0,0,0,0},
					   {8,0,7,0,0,0,0,9,0},
					   {2,0,0,8,0,0,4,0,1},
					   {3,0,0,0,0,2,9,0,5},
					   {0,0,5,7,0,8,6,0,0},
					   {7,0,6,5,0,0,0,0,4},
					   {5,0,1,0,0,4,0,0,9},
					   {0,6,0,0,0,0,7,0,8},
					   {0,0,0,0,2,7,0,5,0}};
			
	for(i=0;i<9;i++)        //ouput 81 digits and all the digits invided by space
	{
	    for(j=0;j<9;j++)
	     cout << giveQue[i][j] << " ";
	    cout << endl;
    }
}

void Sudoku::readIn()
{
	int i,j;                
    for(i=1;i<10;i++)        //input 81 digits for Sudoku
	 for(j=1;j<10;j++)
	  cin >> map[i][j];
}

int Sudoku::col_check(int num,int j)
{
    int k;
    for(k=1;k<10;k++)
    {
        if(num==map[k][j])
            return -1;
    }
    return 1;
}
      	
int Sudoku::row_check(int num,int i)
{
    int k;
    for(k=1;k<10;k++)
    {
        if(num==map[i][k])
        	return -1;
    }
    return 1;
}

int Sudoku::squ_check(int num,int i,int j)
{
    int k=0,l=0,m=0,n=0;
    
    if(i<=3)
	 k=1;
    else if(i>6)
	      k=7;
         else
		  k=4;
    
    if(j<=3)
	 l=1;
    else if(j>6)
		  l=7;
         else
		  l=4;

    for(m=k;m<(k+3);m++)
     for(n=l;n<(l+3);n++)
     {
        if(num==map[m][n])
            return -1;
     }
    
    return 1;      
}


void Sudoku::solve1()
{
	int i,j,k;
	int check=0;
            
    for(i=1;i<10;i++)     //計算map[][]中有多少元素為0，數量由check做計算 
    {
        for(j=1;j<10;j++)
        {
            if(map[i][j]==0)
				check++;
        }
    }
        	
    if(check==0)    //若check為0時 
    {
        add++;      //解多一組，所以add++ 
        if(add>2) 
		 return;   //add>2，直接return 
        if(add==2)    //add==2時，printf "2"，並return 
        {
			cout << "2" <<endl;
           	return;
		}
				 
        for(i=1;i<10;i++)   //add==1時，將解設給ats[][]，在return 
          for(j=1;j<10;j++)
            ats[i][j]=map[i][j];
            
        return;
    }
        	
    for(i=1;i<10;i++)
    {
        for(j=1;j<10;j++)
        {
            if(map[i][j]==0)
            {
                for(k=1;k<10;k++)
                {
                    if(row_check(k,i)==1 && col_check(k,j)==1 && squ_check(k,i,j)==1)
                    {
                       	map[i][j]=k;
                       	solve1();
                       	map[i][j]=0;
                    }
                    if(add==2) {return;}
                }
                return;
            }
        }
    }			  
}


void Sudoku::solve()
{
    int i,j,k,l;
	
	for(i=1;i<9;i++)                 
	 for(k=i+1;k<10;k++)
	  for(j=1;j<10;j++)
	  {
		if(map[j][i]!=0 && map[j][k]!=0 && map[j][i]==map[j][k])
		{
			cout << "0" << endl;
			return;
		}
	  }
	  
	for(i=1;i<9;i++)                   
	 for(k=i+1;k<10;k++)
	  for(j=1;j<10;j++)
	  {
		if(map[i][j]!=0 && map[k][j]!=0 && map[i][j]==map[k][j])
		{
			cout << "0" << endl;
			return;
		}
	  }
	  
	for(l=1;l<10;l=l+3)       // judge：judge every nonzero number in every cell are all different, if there are the same numbers, output "0", and end the program
	{                                  // 確認每一個九宮格的數字皆不重複，若重複output 0，並結束程式
		for(i=l;i<l+3;i++)    
		{                             
			for(j=l;j<l+2;j++)
			 for(k=j+1;k<l+3;k++)
			  if(map[i][j]!=0 && map[i][k]!=0 && map[i][j]==map[i][k])
			  {
				cout << "0" << endl;
				return;	 
			  }   	
		}	
	}       
			
	solve1();
       		
    if(add==2)
	 goto noprint;
    if(ats[1][1]==0)
    {
        cout<<"0"<<endl;
        goto noprint;
    }
            
    noprint:
    if(add==1)
    {
		cout<<"1"<<endl;
		for(i=1;i<10;i++)
        {
            for(j=1;j<10;j++)
            { 
                cout<<ats[i][j]<<" ";
            }
            cout<<endl;
        }
	}
}


void Sudoku::changeNum(int a, int b)   //exange number a and b in the sudoku board
{
	int i,j;
//	printf("changeNum: a=%d,b=%d\n",a,b);
	for(i=1;i<10;i++)
	 for(j=1;j<10;j++)
	 {
		if(map[i][j]==a)
		 map[i][j]=b;
		else if(map[i][j]==b)
		 map[i][j]=a;
	 }	
}
		
void Sudoku::changeRow(int a, int b)     //exange row set a and b in the sudoku board
{
	int i,j,k;
	int firstchange[4][10];
//	printf("changeRow: a=%d,b=%d\n",a,b);
	if((a==0 && b==1) || (a==1 && b==0))    //exange row 1~3 and row 4~6
	{
		for(i=1;i<4;i++)      //store the numbers which in row 1~3 to array firstchange
	     for(j=1;j<10;j++)
	 	  firstchange[i][j]=map[i][j];	      
		k=4;
		for(i=1;i<4;i++)       //put the numbers which in row 4~6 to row 1~3
		{
			for(j=1;j<10;j++)
			 map[i][j]=map[k][j];
			k++;
		}
        k=1;
        for(i=4;i<7;i++)        //store the numbers which in array firstchange to row 4~6
		{
			for(j=1;j<10;j++)
			 map[i][j]=firstchange[k][j];
			k++;
		}       
	}
    else if((a==0 && b==2) || (a==2 && b==0) )   //exange row 1~3 and row 7~9
    	 {
			for(i=1;i<4;i++)       //store the numbers which in row 1~3 to array firstchange
		 	 for(j=1;j<10;j++)
		  	  firstchange[i][j]=map[i][j];
			k=7;
			for(i=1;i<4;i++)       //put the numbers which in row 7~9 to row 1~3
			{
				for(j=1;j<10;j++)
			 	 map[i][j]=map[k][j];
				k++;
			}
        	k=1;
        	for(i=7;i<10;i++)        //store the numbers which in array firstchange to row 7~9
			{
				for(j=1;j<10;j++)
			 	 map[i][j]=firstchange[k][j];
				k++;
			}
		 }
		 else if((a==2 && b==3) || (a==3 && b==2))   //exange row 4~6 and row 7~9
			  {
				k=1;
				for(i=4;i<7;i++)      //store the numbers which in row 4~6 to array firstchange
				{
					for(j=1;j<10;j++)
			         firstchange[k][j]=map[i][j];
			        k++;
				}
			    k=7;
			    for(i=4;i<7;i++)       //put the numbers which in row 7~9 to row 4~6
			    {
			   		for(j=1;j<10;j++)
			     	 map[i][j]=map[k][j];
				    k++;
			    }
                k=1;
                for(i=7;i<10;i++)       //store the numbers which in array firstchange to row 7~9
			    {
			    	for(j=1;j<10;j++)
			     	 map[i][j]=firstchange[k][j];
			     	k++;
				}
			  }
}
		
void Sudoku::changeCol(int a, int b)         //exange column set a and b in the sudoku board
{
	int i,j,k;
	int secondchange[10][4];
//	printf("changeCol: a=%d, b=%d\n",a,b);
	if((a==0 && b==1) || (a==1 && b==0))    //exange column 1~3 and column 4~6
	{
		for(i=1;i<4;i++)         //store the numbers which in column 1~3 to array secondchange
		 for(j=1;j<10;j++)
		  secondchange[j][i]=map[j][i];  
	    k=4;
	    for(i=1;i<4;i++)        //put the numbers which in column 4~6 to column 1~3
		{
			for(j=1;j<10;j++)
			 map[j][i]=map[j][k];
			k++;
		}
        k=1;
        for(i=4;i<7;i++)        //store the numbers which in array secondchange to column 4~6
		{
			for(j=1;j<10;j++)
			 map[j][i]=secondchange[j][k];
			k++;
		}    
	}
    else if((a==0 && b==2) || (a==2 && b==0) )   //exange column 1~3 and column 7~9
         {
			for(i=1;i<4;i++)      //store the numbers which in column 1~3 to array secondchange
			 for(j=1;j<10;j++)
			  secondchange[j][i]=map[j][i];
			k=7;
			for(i=1;i<4;i++)      //put the numbers which in column 7~9 to column 1~3
			{
				for(j=1;j<10;j++)
			     map[j][i]=map[j][k];
				k++;
			}
            k=1;
            for(i=7;i<10;i++)       //store the numbers which in array secondchange to column 7~9
			{
			    for(j=1;j<10;j++)
			     map[j][i]=secondchange[j][k];
			    k++;
			}
		 }
		 else if((a==2 && b==3) || (a==3 && b==2))   //exange column 4~6 and column 7~9
			  {
				k=1;
				for(i=4;i<7;i++)       //store the numbers which in column 4~6 to array secondchange
				{
					for(j=1;j<10;j++)
			         secondchange[j][k]=map[j][i];
			        k++;
				}
			    k=7;
			    for(i=4;i<7;i++)     //put the numbers which in column 7~9 to column 4~6
			    {
			    	for(j=1;j<10;j++)
			     	 map[j][i]=map[j][k];
				    k++;
			    }
                k=1;
                for(i=7;i<10;i++)     //store the numbers which in array secondchange to column 7~9
			    {
			    	for(j=1;j<10;j++)
			     	 map[j][i]=secondchange[j][k];
			     	k++;
				}
			  }
}
		
void Sudoku::rotate(int n)     //Rotate the board 90 degrees n times in clockwise direction
{
	int i,j,k,l;
	int thirdchange[10][10];
//	printf("rotate: n=%d\n",n);
	for(i=1;i<10;i++)           //put the original answer into array thirdchange
	 for(j=1;j<10;j++)
	  thirdchange[i][j]=map[i][j];
	if(n%4==1)      //Rotate the board 90 degrees
	{
		k=1; 
		for(i=9;i>=1;i--)
		{
			for(j=1;j<10;j++)
			 map[j][i]=thirdchange[k][j];
			k++;
		}
	}
	else if(n%4==2)         //Rotate the board 180 degrees
		 {
			k=1,l=1;
			for(i=9;i>=1;i--)
			{
				for(j=9;j>=1;j--)
				{
				 	map[i][j]=thirdchange[k][l];
				 	l++;
				}
				l=1;
				k++; 
			}
		 }
		 else if(n%4==3)    //Rotate the board 270 degrees
			  {
				k=1,l=1;
				for(i=1;i<10;i++)
				{
					for(j=9;j>=1;j--)
				    {
				    	map[j][i]=thirdchange[k][l];
				    	l++;
					}
				    l=1;
					k++; 
				}
			  }
}
		
void Sudoku::flip(int n)    //flip the sudoku board vertically or horizontally
{
	int i,j,k,l;
	int fourthchange[10][10];
//	printf("flip: n=%d\n",n);
	for(i=1;i<10;i++)           //put the original answer into array fourthchange
	 for(j=1;j<10;j++)
	  fourthchange[i][j]=map[i][j];
	if(n==0)        //flip the sudoku board vertically
	{
		k=1;
		for(i=9;i>=1;i--)
		{
			for(j=1;j<10;j++)
			 map[i][j]=fourthchange[k][j];
			k++;
		}
	}
	else             //flip the sudoku board horizontally
	{
		k=1;
		for(i=9;i>=1;i--)
		{
			for(j=1;j<10;j++)
			 map[j][i]=fourthchange[j][k];
			k++;
		}	
	}
}

		
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
		
void Sudoku::printOut()   //output array map1 to map5
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		 cout << map[i][j] << " ";
		cout << endl;
	}
}

void Sudoku::transform()
{
	change();
	printOut();
}
