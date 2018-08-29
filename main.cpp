/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//this function draws the board
void drawBoard(char board[45]) {
    for(int i=0; i<45; i++){
        cout << board[i];
    }
}



//this functio determines if there is a draw
bool drawDeterminor(char board[45], int boardCoordinates[9]){
            int drawcounter = 0;
            for (int i = 0; i<9;i++){
                if (board[boardCoordinates[i]]=='X' or board[boardCoordinates[i]]=='O'){
                    drawcounter++;
                }
            }
            if (drawcounter==9){
                return true;
            }
            else{
                return false;
            }
}
//this function checks if any of the players have won
bool WincheckX(char board[45]){
    // all win conditions with a piece in a1
        if ((board[9]=='X')  and (board[11]=='X') and (board[13]=='X')) {
            return true ;
        }
        if ((board[9]=='X')  and (board[23]=='X') and (board[37]=='X')) {
            return true ;
        }
        if ((board[9]=='X')  and (board[25]=='X') and (board[41]=='X')) {
            return true ;
        }
        //all win conditions starting in a2
        if ((board[11]=='X')  and (board[25]=='X') and (board[39]=='X')) {
            return true ;
        }
        //all win conditions starting in A3
        if ((board[13]=='X')  and (board[27]=='X') and (board[41]=='X')) {
            return true ;
        }
        if (board[13]=='X' and board[25]=='X' and board[37] =='X'){
            return true;
        }
        //all win conditions starting in B1
        if ((board[23]=='X')  and (board[25]=='X') and (board[27]=='X')) {
            return true ;
        }
        // all win conditions starting in C1
        if ((board[37]=='X')  and (board[39]=='X') and (board[41]=='X')) {
            return true ;
        }
        return false ;
}
bool WincheckO(char board[45]){
    // all win conditions with a piece in a1
        if ((board[9]=='O')  and (board[11]=='O') and (board[13]=='O')) {
            return true ;
        }
        if ((board[9]=='O')  and (board[23]=='O') and (board[37]=='O')) {
            return true ;
        }
        if ((board[9]=='O')  and (board[25]=='O') and (board[41]=='O')) {
            return true ;
        }
        //all win conditions starting in a2
        if ((board[11]=='O')  and (board[25]=='O') and (board[39]=='O')) {
            return true ;
        }
        //all win conditions starting in A3
        if ((board[13]=='O')  and (board[27]=='O') and (board[41]=='O')) {
            return true ;
        }
        if (board[13]=='O' and board[25]=='O' and board[37] =='O'){
            return true;
        }
        //all win conditions starting in B1
        if ((board[23]=='O')  and (board[25]=='O') and (board[27]=='O')) {
            return true ;
        }
        // all win conditions starting in C1
        if ((board[37]=='O')  and (board[39]=='O') and (board[41]=='O')) {
            return true ;
        }
        return false;
}




//A function used by  player to determine if space is being used before making move, and records the turn
char* Checkspace(char board[45],int position,bool moveX){
    if ((board[position]=='X') or (board[position]=='O') or (board[position]=='-') or (board[position]=='|')){
        cout << "Space already occupied please select another move";
    }
    else{
        if (moveX== true){
            board[position] ='X';
            
        }
        else{
            board[position] ='O';
        }
    return board;
    }
    
}

//This function handles the "AI"
//The "AI" works with random number generation
char* aiTurn(char board[45],bool AIx){
   // cout << "AI turn started";
    int aiGuess = 0;
    bool aiHit = false;
    
    //the user X bool will be flipped for the AI purpose, making it comptaible with checkspace
    if(AIx==true){
        AIx=false;
    }
    else if(AIx==false){
        AIx=true;
    }
    //initalizes random seed
    srand (time(NULL));
    //cout << "random number initialized";
    while (aiHit== false){
    //generates random number 0 through 8(9 playable spaces)
    aiGuess = rand() % 8;
        if (aiGuess==0){
            if (board[9]!='X' and board[9]!='O'){
                strcpy(board,Checkspace(board,9,AIx));
                cout <<"the ai moved to a1";
                return board;    
            }
        }
        else if (aiGuess==1){
            if (board[11]!='X' and board[11]!='O'){
                strcpy(board,Checkspace(board,11,AIx));
                                cout <<"the ai moved to a2";
                return board;  
            }
        }
        else if (aiGuess==2){
            if (board[13]!='X' and board[13]!='O'){
                strcpy(board,Checkspace(board,13,AIx));
                                cout <<"the ai moved to a3";
                return board;   
            }
        }
        else if (aiGuess==3){
            if (board[23]!='X' and board[23]!='O'){
                strcpy(board,Checkspace(board,23,AIx));
                                cout <<"the ai moved to b1";
                return board;  
            }
        }
        else if (aiGuess==4){
            if (board[25]!='X' and board[25]!='O'){
                strcpy(board,Checkspace(board,25,AIx));
                                cout <<"the ai moved to b2";
                return board; 
            }
        }
        else if (aiGuess==5){
            if (board[27]!='X' and board[27]!='O'){
                strcpy(board,Checkspace(board,27,AIx));
                                cout <<"the ai moved to b3";
                return board;    
            }
        }
        else if (aiGuess==6){
            if (board[37]!='X' and board[37]!='O'){
                strcpy(board,Checkspace(board,37,AIx));
                                cout <<"the ai moved to c1";
                return board;    
            }
        }
        else if (aiGuess==7){
            if (board[39]!='X' and board[39]!='O'){
                strcpy(board,Checkspace(board,39,AIx));
                                cout <<"the ai moved to c2";
                return board;    
            }
        }
        else if (aiGuess==8){
            if (board[41]!='X' and board[41]!='O'){
                strcpy(board,Checkspace(board,41,AIx));
                                cout <<"the ai moved to c3";
                return board;  
            }
        }
    }
            
        
}

// This function handles player turns
char* userTurn(char board[45],bool userX){
    string UserInputTurn;
    bool playerTurnComplete = false;
    int moveCoordinates = 0;
    cout <<"In coordinates, where do you want to mark?";
    cin>>UserInputTurn;
    while(playerTurnComplete==false){
        if ((UserInputTurn=="A1") and (board[9]!='X') and (board[9]!='O')){
            strcpy(board,Checkspace(board,9,userX));
            return board;
            
        }
        else if ((UserInputTurn=="A2") and (board[11]!='X') and (board[11]!='O')){
            strcpy(board,Checkspace(board,11,userX));
            return board;
            
        }
        else if ((UserInputTurn=="A3") and (board[13]!='X') and (board[13]!='O')){
            strcpy(board,Checkspace(board,13,userX));
            return board;
        }
        else if ((UserInputTurn=="B1") and (board[23]!='X') and (board[23]!='O')){
            strcpy(board,Checkspace(board,23,userX));
            return board;
            
        }
        else if ((UserInputTurn=="B2") and (board[25]!='X') and (board[25]!='O')){
            strcpy(board,Checkspace(board,25,userX));
            return board;
            
        }
        else if ((UserInputTurn=="B3") and (board[27]!='X') and (board[27]!='O')){
            strcpy(board,Checkspace(board,27,userX));
            return board;
        }
        else if ((UserInputTurn=="C1") and (board[37]!='X') and (board[37]!='O')){
            strcpy(board,Checkspace(board,37,userX));
            return board;
            
        }
        else if ((UserInputTurn=="C2") and (board[39]!='X') and (board[39]!='O')){
            strcpy(board,Checkspace(board,39,userX));
            return board;
            
        }
        else if ((UserInputTurn=="C3") and (board[41]!='X') and (board[41]!='O')){
            strcpy(board,Checkspace(board,41,userX));
            return board;
        }
            
        else{
            cout<<"Coordinates invalid, please retype informat A1:";
            cin>>UserInputTurn;
        }
    }

    
}

int main()
{
    //variables for team
    bool userX;
    bool userTeamset = false;
    
    //variables for go first or second
    bool userFirst = false;
    bool userSecond = false;
    string Userinput;
    
    bool win=false ;
    bool playerwin = false;
    bool draw = false;
    bool aiWin= false;
    int boardCoordinates[9] ={9,11,13,23,25,27,37,39,41};
    
    //game board 
    // for some reason string aray didn't work?    
    char board[45] = {' ','1',' ','2',' ','3' ,' ','\n'
                    ,'A',' ', '|', ' ', '|', ' ', '\n'
                    ,' ', '-', '-', '-', '-', '-', '\n'
                    ,'B', ' ', '|', ' ', '|', ' ', '\n'
                    ,' ', '-', '-', '-', '-', '-', '\n'
                    ,'C', ' ', '|', ' ', '|', ' ', '\n'};
    
    
    //Handles user team
    cout << "Do you want to be X or Os? ";
    
    while(userTeamset == false){
        cin >> Userinput;
        
        if(Userinput == "X"){
            userX = true;
            userTeamset = true;
        }
        else if(Userinput == "O") {
            userX = false;
            userTeamset = true;
        }
        else{
             cout << "Please specify the letter X or O: ";
        }
    }
    //handles if user goes first or second
     cout << "Do you want go first or second? ";
     
    while((userFirst == false) and (userSecond == false)){
        cin >> Userinput;
        
        if(Userinput == "first"){
            userFirst = true;
            userSecond = false;
        }
        else if(Userinput == "second") {
            userFirst = false;
            userSecond = true;
        }
        else{
             cout << "Please specify first or second: ";
        }
    }
    //draws game board 
    drawBoard(board);
    //deals with user turns
    // both bools are needed for user first and second to tell if one is set
    if (userFirst==false){
        cout<< "------The AI makes his turn-----"<<endl;
        strcpy(board,aiTurn(board,userX));
        drawBoard(board);
    }
    while(win== false){
       // if(userFirst== true){
        draw = drawDeterminor(board,boardCoordinates);
        if (draw== true){
            win= true;
        }
        if (win==false){
            strcpy(board,userTurn(board,userX));
            drawBoard(board);
        }
        win = WincheckX(board);
        if (win== false){
            draw = drawDeterminor(board,boardCoordinates);
        }
        if (win== true){
            if (userX== true){
                playerwin= true;
            }
        }
        if (win ==false){
            win = WincheckO(board);
        }
        if (win== true){
            if (userX== false){
                playerwin= true;
            }
        }
        if ((win == false) and draw== false){
            cout<< "------The AI makes his turn-----"<<endl;
            strcpy(board,aiTurn(board,userX));
            drawBoard(board);
            win = WincheckX(board);
            if (win== true){
                if (userX== true){
                    playerwin= false;
                    aiWin= true;
                }
            }
        if (win ==false){
            win = WincheckO(board);
        }
        if (win== true){
            if (userX== false){
                playerwin= false;
                aiWin= true;
            }
        }
        }
        if (draw==true){
            win = true;
        }
    
    }
    if (draw== true){
        cout<<"draw!";
    }
    else if (playerwin== true){
        cout <<"Congradulations player!";
    }
    else{
        cout<<"better luck next time";
    }
    

    return 0;
}


