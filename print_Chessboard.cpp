/**********************************************************************
** Auther: Frank Smith
** Date: 4/1/2017
** Description: CS211 Queens College assignment to print a chessboard
** representation for each of the 92 8 Queens configurations possible
**********************************************************************/ 
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

bool ok(int q[], int c){
   for (int i = 0; i < c; i++)
      if (q[i] == q[c] || c - i == abs(q[c] - q[i])) return false;
   return true;
}

int backtrack(int &c){
   c--;
   if (c == -1) exit(1);
}

void print (int q[]){
   static int count = 0;
   cout << "Fancy 8 Queens configuration answer # " << ++count << endl;
   int i, j, k, l;
   typedef char box[5][7];
   box bb,wb,*board[8][8];
   box bq = {
char(219),char(219),char(219),char(219),char(219),char(219),char(219),
char(219),' ',char(219),' ',char(219),' ',char(219),
char(219),' ',' ',' ',' ',' ',char(219),
char(219),' ',' ','Q',' ',' ',char(219),
char(219),char(219),char(219),char(219),char(219),char(219),char(219)};
   box wq = {
' ',' ',' ',' ',' ',' ',' ',
' ',char(219),' ',char(219),' ',char(219),' ',
' ',char(219),char(219),'Q',char(219),char(219),' ',
' ',char(219),char(219),char(219),char(219),char(219),' ',
' ',' ',' ',' ',' ',' ',' ',};
    

  //fill in bb=black box and wb=whitebox
   for(i=0;i<5;i++)
      for( j=0;j<7;j++){
        wb[i][j]=' ';
        bb[i][j]=char(219);
      }

   for(i=0;i<8;i++)
      for(j=0;j<8;j++)
         if((i+j)%2 ==0){
            if(q[i]==j){
               board[i][j]=&wq;
            }
            else{
               board[i][j]=&wb;
            }
         }
         else{
           if(q[i]==j){
              board[i][j]=&bq;
           }
           else{
              board[i][j]=&bb;
           }
         }

   //print the board via the pointers in array board
   // first print upper border
   cout << "   ";
   for(i=0; i<7*8;i++)
      cout<<'_';
   cout <<endl;

   //now print the board
   for (i=0; i <8; i++)
     for(k=0; k<5; k++){
       cout <<"   " << char(179); // print left border
       for(j=0; j<8; j++)
          for(l=0;l<7;l++)
             cout<<(*board[i][j])[k][l];
          cout << char(179) << endl; //at end of line print bar and then newline 
          }
   //before exiting print lower border
   cout<<"   ";
   for(i=0;i<7*8;i++)
      cout<<char(196);
   cout<<endl;

}

int main(){
   int q[8], c = 0; // board setup
   q[0] = 0;
   bool from_backtrack=false; // variable from_backtrack declared
   while(true){
      while( c < 8){ // column section, while column is not past 7
         if (!from_backtrack) q[c] = -1;
         from_backtrack=false;
         while( q[c] <8){ // row section, while less then row 8
            q[c]++; // increase row number
            if (q[c] == 8){ // check row number, queen can't be placed
                from_backtrack=true; // backtrack condition is true
                backtrack(c);
                break;
            }
            if (ok(q,c)){ // call ok function
                from_backtrack=false; // backtrack condition is false
                c++; // go to next column
                break;
            }
         }
      }
      print(q); // column is greater than 7, solution found, call print function
      from_backtrack=true; // backtrack condition is true, need to check for more solutions
      backtrack(c); // call backtrack function
   }   
  return 0;
}


