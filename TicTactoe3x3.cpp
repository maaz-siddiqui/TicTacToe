#include<iostream>
#include<conio.h>
#include<string>
#include<cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

//functions
string players(int i);
char marker(string x);
void setdetails();
void display(int x);
void continuefun();
void reset();
void set(int i, char x);
void turn(int p);
int Random();
void clear();
bool valid(int x);
void check(int x);
void initialize();
void restartchoice();
void rematch();
void winner(string chname, int x);
void scoreboardupdate(int x);
void scoreboard();
void color(int c);
void rules();
void rule_1 ();
void points_criteria ();

//structures
struct player{
	int no;
	string name;
	char mark;
	int score;
};

struct scoringdata{
	int winno, losno;
	string winname, losname;
	char winmark, losmark;
	int winscore, losscore;
};

//global variables
struct player p1, p2;
struct scoringdata scoring[30];
int score = 0, hi_score = 0, moves = 0, games = 0, playerno = 0;
char save[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}, pos[3][3];

	
int main(){	
	display(3);
	getch();
	rules();
	color(15);
	getch();
	points_criteria ();
	getch();
	cout<<"\nPress enter to start the game!";
	clear();
	cout<<"PLAYER DETAILS : ";
	cout<<"\n================";
	setdetails();
	//basic display
	initialize(); 	//initialize 3x3 array to base values
	clear();	
	display(1);
	continuefun();
}

void setdetails(){
		//setting player names and marker
	p1.no = playerno+1;
	p1.name = players(p1.no);	
	p1.mark = marker(p1.name);	
	p1.score = 0;
	p2.score = 0;
	p2.no = playerno+2;
	p2.name = players(p2.no);
	playerno = playerno + 2;
	if(p1.mark == 'x' || p1.mark == 'X'){
		p2.mark = 'O';
	}
	else if(p1.mark == 'o' || p1.mark == 'O'){
		p2.mark = 'X';
	}
}

string players(int i){
	cin.ignore();
	string x;
	color(3);
	cout<<"\nPlayer # "<<i<<" Enter Your name = "; getline(cin, x);
	return x;
}

void clear(){
	system("cls");
}

char marker(string x){
	char mark;
	color(11);
	cout<<"\nChooser your marker "<<x;
	cout<<"\n O or X : ";
	cin>>mark;
	if(mark != 'x' && mark != 'X' && mark != 'o' && mark != 'O'){
		cout<<"\nINCORRECT MARKER!"<<endl;
		cout<<"SYSTEM ASSIGNED 'X'"<<endl;
		mark = 'X';
	}
	return mark;
}

void display(int x){
	switch (x){
		case 1:
			color(9);
			cout<<"======================================TIC TAC TOE=================================="<<endl;
			color(10);
			cout<<"\n\nPlayer 1 : "<<p1.name<<" = "<<p1.mark<<endl;
			cout<<"Player 2 : "<<p2.name<<" = "<<p2.mark<<endl;

			color(15);
	
			cout << "\n   -------------\n";
			for (int i = 0; i < 3; i++)
			{
				cout << "   | ";
				for (int j = 0; j < 3; j++)
				{
						
					if(pos[i][j] == p1.mark ){
						color(10);					
					}
					else if(pos[i][j] == p2.mark){
						color(9);
					}
					else{
						color(12);
					}
					cout << pos[i][j];
					color(15);			
					cout << " | " ;
				}
				cout << "\n   -------------\n";
			}
					break;
		case 2:
			color(9);
			cout<<"======================================TIC TAC TOE=================================="<<endl;
			color(12);
			cout<<"\n=======================================MAIN MENU=================================="; 
			color(15);
			cout<<"\nSELECT YOUR CHOICE.";
			cout<<"\n\n 1) NEW GAME";
			cout<<"\n 2) CONTINUE GAME";
			cout<<"\n 3) SCOREBOARD.";
			cout<<"\n 4) EXIT"<<endl;
			break;
		case 3:
			color(10);
			cout << "\n\t\t*************************************************";
			cout << "\n\t\t|||                                           |||";
			cout << "\n\t\t|||                TIC-TAC-TOE                |||";
			cout << "\n\t\t|||                                           |||";
			cout << "\n\t\t*************************************************"<<endl; color(8);
			break;
	}
}

void reset(){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pos[i][j] = '-';
		}
	}
}
void set(int l, char x){
	int i, j;
	switch (l){
		case 1:
			i = 0;
			j = 0;
			break;
		case 2:
			i = 0;
			j = 1;
			break;
		case 3:
			i = 0;
			j = 2;
			break;
		case 4:
			i = 1;
			j = 0;
			break;
		case 5:
			i = 1;
			j = 1;
			break;
		case 6:
			i = 1;
			j = 2;
			break;
		case 7:
			i = 2;
			j = 0;
			break;
		case 8:
			i = 2;
			j = 1;
			break;
		case 9:
			i = 2;
			j = 2;
			break;
	}
	pos[i][j] = x;	
}

void turn(int p){
	int pos;
	color(15);
	if(p == 1){
		cout<<"\n Turn of Player #"<<p1.no;
	}else if(p == -1){
		cout<<"\n Turn of Player #"<<p2.no;
	}
	bool loop;
	//player 1
	if( p == 1){
		
	do{	
		cout<<"\n Player : "<<p1.name;
		cout<<"\n Enter in which position u want to mark : "; cin>>pos;
		if(pos<=9 && pos>=1 ){
			if(valid(pos) == true){
			loop = false;
			set(pos, p1.mark);
			break;
			}else{
			clear();
			cout<<"\nPosition used!";
			getch();
			clear();
			display(1);
			loop = true;
			}
		}
		clear();
		cout<<"\nPOSITION INVALID!";
		getch();
		clear();
		display(1);
	}while(loop = true);
	
	//PLayer 2
	}else if( p == -1){
	do{
			
		cout<<"\n Player : "<<p2.name;
		cout<<"\n Enter in which position u want to mark : "; cin>>pos;
		if(pos<=9 && pos>=1  ){
			if(valid(pos) == true){
			loop = false;
			set(pos, p2.mark);
			break;
			}else{
			clear();
			cout<<"\nPosition used!";
			getch();
			clear();
			display(1);
			loop = true;
			}
		}
		clear();
		cout<<"\nPOSITION INVALID!";
		getch();
		clear();
		display(1);
	}while(loop = true);
	}
	
}

int Random(){
	int random ;
	srand(time(NULL));
	random = ((rand() % 10) * 0.1) + 0.1;
	if (random == 0){
		return 1;
	}
	else if(random == 1){
		return -1;
	}
}

bool valid(int x){
	int i, j;
		switch (x){
		case 1:
			i = 0;
			j = 0;
			break;
		case 2:
			i = 0;
			j = 1;
			break;
		case 3:
			i = 0;
			j = 2;
			break;
		case 4:
			i = 1;
			j = 0;
			break;
		case 5:
			i = 1;
			j = 1;
			break;
		case 6:
			i = 1;
			j = 2;
			break;
		case 7:
			i = 2;
			j = 0;
			break;
		case 8:
			i = 2;
			j = 1;
			break;
		case 9:
			i = 2;
			j = 2;
			break;
	}
		int locate;
		locate = x-1;
		if(pos[i][j] == save[locate]){
			
			return true;
		}
		else {
			return false;
		}
}

void check(int x){
	int d = 0, count_c1 = 0, count_r1 = 0, count_d = 0;
	char chmark;
	string chname;
	if(x == 1){
		chmark = p1.mark;
		chname = p1.name;
	}
	if(x == -1){
		chmark = p2.mark;
		chname = p2.name;
	}
	for(int i = 0; i<3; i++){
		count_c1 = 0, count_r1 = 0;	
		for(int j = 0; j<3; j++){	
			if(pos[i][j] == chmark ){
				count_c1++;
				if(count_c1 == 3){
					winner(chname, x);
						break;
				}
			}			
		}
		for(int j = 0; j<3; j++){	
			if(pos[j][i] == chmark){
				count_r1++;
				if(count_r1 == 3){
					winner(chname, x);
						break;
				}
			}			
		}
	}
	for(int i = 0; i<3; i++){
		if(pos[i][d] == chmark){
			count_d = count_d + 1;
			if(count_d == 3){
				winner(chname, x);
				break;
			}
		}
		d = d + 1;
	}
	d = 2;
	count_d = 0;
	for(int i = 0; i<3; i++){
		if(pos[i][d] == chmark){
			count_d = count_d + 1;
			if(count_d == 3){
				winner(chname, x);
				break;
			}
		}
		d = d - 1;
	}
}

void initialize(){
	int i = 0, j = 0, l = 0;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pos[i][j] = save[l];
			l++;
		}
	}
}


void restartchoice(){
	int user_choice;
	display(2);
	cout<<"\nCHOICE : ";
	cin>>user_choice;
	
	switch( user_choice){
		case 1:
			clear();
			main();
			break;
		case 2:
			clear();
			cout<<"Game Continued!"<<endl;
			initialize();
			display(1);
			continuefun();
			break;
		case 3:
			scoreboard();
			break;
		case 4:
			exit(1);
	}
}

void continuefun(){
	//first turn random
	int turnno = Random();
	char rematchchoice = 'n';
	//start
	turn(Random());
	check(Random());
	display(1);	
	games = games + 1;
	//this loops keep the game running until one wins or game tie!
	for(int l = 0; l<8; l++){
	clear();
	display(1);
	turnno = turnno*-1;	
	turn(turnno);
	clear();	
	display(1);
	moves = l;
	check(turnno);
	}
	clear();
	display(1);
	cout<<"\nGAME TIE!";
	cout<<"\nRematch!";
	scoreboardupdate(0);
	cout<<"\nWanna Have a rematch? [y/n]"; cin>>rematchchoice;
	if(rematchchoice == 'y' || rematchchoice == 'Y'){
		rematch();	
	}
	else{
		clear();
		restartchoice();
	}
		
}

void rematch(){
	clear();
	cout<<"LAST MATCH WAS TOUGH!"<<endl;
	initialize();
	display(1);
	continuefun();
}

void winner(string chname, int x){
	if(x == 1){
		p1.score = p1.score + 10;
		score = p1.score;
	}
	if(x == -1){
		p2.score = p2.score + 10;
		score = p2.score;
	}
	color(12);
	cout<<"\nThe WINNER is "<<chname; 	color(15);
	cout<<"\n\nPRESS ENTER TO CONTINUE.......";
	cout<<"\nSCORED  = "<<score<<" XP";
	getch();
	clear();
	scoreboardupdate(x);
	restartchoice();
	getch();
}

void scoreboardupdate(int x){
	string looser, winner;
	int hi_scorer, losno, winno,  winscore, losscore;
	if(x == 1){
		winno = p1.no;
		losno = p2.no;
		winner = p1.name;
		score = p1.score;
		looser = p2.name;
		winscore = p1.score;
		losscore = p2.score;
	}
	if(x == -1){
		winno = p2.no;
		losno = p1.no;
		winner = p2.name;
		looser = p1.name;
		winscore = p2.score;
		losscore = p1.score;
		
	}
	if(x == 0){
		winno = p2.no;
		winner = "-TIE-";
		looser = "-TIE-";
		winscore = p2.score;
		losscore = p1.score;
		
	}
	scoring[games-1].winno = winno;
	scoring[games-1].winname = winner;
	scoring[games-1].winscore = winscore;
	scoring[games-1].losno = losno;
	scoring[games-1].losname = looser;
	scoring[games-1].losscore = losscore;
}

void scoreboard(){
	clear();
	cout<<"\n"; color(4);
	cout<<"\n============================================================================================================";
	cout<<"\n                                                SCOREBOARD                                                     ";
	cout<<"\n============================================================================================================";
	color(7);
	cout<<"\nMATCH NO:\tPLAYER NO\tWINNER NAME\tWINNER SCORE\tPLAYER NO\tLOOSER NAME\tLOOSER SCORE"<<endl;
	color(14);
	for(int i = 0; i<games; i++){
		int loc  = i;
		cout<<"\n#"<<i+1<<"\t\t"<<scoring[loc].winno<<"\t\t"<<scoring[loc].winname<<"\t\t"<<scoring[loc].winscore<<" XP"<<"\t\t"<<scoring[loc].losno<<"\t\t"<<scoring[loc].losname<<"\t\t"<<scoring[loc].losscore<<" XP";
	}
	color(4);
	cout<<"\n============================================================================================================";
	color(15);
	cout<<"\n\nMAIN MENU PRESS ENTER.....";
	getch();
	clear();
	restartchoice();
}

void color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void rules(){
	cout << endl;
	color(2);	
	cout << "\nRULES:";
	cout << "\n======";
	color(15);
	cout << "\n   i. You have to enter your position number at your turn, everytime.\n";
	rule_1 ();
	cout << "\n  ii. In the first round, first turn would be provided to anyone randomly.\n";
	cout << "\n iii. In each next round, first turn would be provided to one who looses.\n";	
	cout << endl;
}
void rule_1 (){
	char positions [3][3];
	
	int number = 0;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "   \t\t\t   ";
		
		for (int j = 0; j < 3; j++)
		{
			number += 1;
			
			cout << "   " << number ;
		}
		
		cout << "\n";
	}
}

void points_criteria (){
	color(2);
	cout << "\nPOINTS CRITERIA:";
	cout << "\n================";	
	color(15);	
	cout << "\n a. Winner would be awarded 10 Points.";
	cout << "\n b. Looser would be awarded 0 Points.";
	cout<<  "\n c. No points would be awarded to anyone on match draw.";
	cout << endl;
}
