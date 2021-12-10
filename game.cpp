#include <iostream>

using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

void draw_board(){
     cout<<"------";cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j   <3;j++){
            cout<<board[i][j]<<"|";
        }cout<<endl;
        cout<<"------";cout<<endl;
    }
}
void placeMarker(int slot){
    
    int row,col;
    if(slot%3==0){
        row=slot/3-1;
        col=2;
    }else{
        row=slot/3;
        col=slot%3-1;
    }
  
  board[row][col]=current_marker;
}
int winner(){
   
   for(int i=0;i<3;i++){
       if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
           return current_player;
       }
        if (board[0][i]==board[1][i] && board[2][i]==board[1][i]){
           return current_player;
       }
   }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
           return current_player;
       }
    
     if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){
           return current_player;
       }
       return 0;
}
void swap(){
    if(current_marker=='X'){
        current_marker='O';
    }else{
        current_marker='X';
    }
     if(current_player==1){
        current_player=2;
    }else{
        current_player=1;
    }
}
void game(){
     draw_board();
    cout<<"player one,choose marker";
    current_player=1;
    char marker1;
    cin >>marker1;
    int win;
    current_marker=marker1;
    
    for(int i=0;i<9;i++){
        int slot;
        cout<<"Its player"<<current_player<<"'s turn ,mark your turf";
        cin>>slot;
          placeMarker(slot);
             draw_board();
          win=winner();
          if(win==1){
              cout<<"player one won!Congratulations!";
              break;
          }
            if(win==2){
                cout<<"player two won!Congratulations!";
                break;
          }
            
       
          swap();
          
    }
    if(win==0){
        cout<<"aw it is a tie";
    }
    
}
int main()
{
    
game();
}
