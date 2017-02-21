#include <iostream>
#include "help.h"
#include <cmath>
#include <fstream>

using namespace std;

void instruction();
void pencolor(char number[], int& color1,int& color2, int& color3);
void console(int& width);
void forward(int a, int angle, int &x, int &y, int& color1,int& color2,int& color3, int& width);
void backward(int a, int angle, int &x, int &y, int& color1,int& color2, int& color3, int& width);
void right_turn(int a, int &angle);
void left_turn(int a, int &angle);
void circle(int a, int x, int y, int& width,int& color1,int& color2, int& color3);
void square(int a, int x, int y, int& width,int& color1,int& color2, int& color3);
void penup(int& x, int& y, int &color1,int& color2, int& color3, int& width);
void pendown(int& x, int &y, int &color1,int& color2,int& color3, int& width);
void threeDsquare(int a, int x, int y, int& width,int& color1,int& color2, int& color3);
void threeDcircle(int a, int x, int y, int& width,int& color1,int& color2, int& color3);
void solidcr(int a, int x, int y, int& width,int& color1,int& color2, int& color3);
void input(char a[], int b);
void main_program(int x, int y, int angle, int& width,int& color1, int& color2, int& color3);
int UserInput(char number[]);
void readCommands(char number[],char copy[],int length,ifstream &fin,ofstream &fout,char store[][100],int row, int &x, int &y, int& angle, int& color1,int& color2,int& color3, int& width);
void repeat1(char a[], int length,ifstream &fin,ofstream &fout,char store[][100],int row, int &x, int &y, int& angle, int &color1,int &color2,int &color3, int& width);
void equaltriangle(int a,int &x,int &y,int angle,int& width,int& color1,int &color2,int &color3);
void load (ifstream &fin,ofstream &fout,char store[][100],int row,int &x,int &y,int& angle,int &color1,int &color2,int &color3,int &width);
void save (char store[][100],int row,ofstream &fout);

void clearscreen(int& x, int& y,int& angle)
{
	x=0,y=0;
	int x1=800,y1=300,width=1;
	myRectone(x,y,x1,y1,0,width);
	x=300,y=200,angle=90;
}



int main(){
	instruction();
}

void instruction(){
	int x = 300, y = 200, angle = 90, color1 = 255,color2 = 255,color3 = 255, width=2;
	char n;
	gotoxy(0, 0);
		cout << "*********************Welcome to TABLET************************" << endl;
		cout << "Following commands should be written(in exact same form) in order to draw." << endl<<endl;
		cout << "INSTRUCTIONS:" << endl<<endl;
		cout << "1. fd # or forward #" << endl << "2. bk # or backward #" << endl << "3. lt # or left #" << endl <<
			"4. rt # or right #" << endl << "5. pen up or pu (no drawing)" << endl << "6. pendown or pd (drawing)" << endl << "7. sq # or square #" << endl <<
			"8. circle # or cr #" << endl << "9. repeat n[command1 # command2 # ...]" << endl << "10. tdsq # or tdsquare # (draws a 3d square of white color)" << endl <<
			"11. tdcr # or tdcircle # (draws a 3d circle of yellow colour)" << endl << "12. solidcr # (draws a doughnut shape)" << endl << "13. save and load \"abc.txt\"" << endl
			<< "15. triangle #" << endl << "16. cs (clear screen)" << endl << "17. color BLACK/YELLOW/GREEN/RED/WHITE (changes pen color)" << endl << "18. width #" << endl <<
			"19. instructions (to load this page again)"<<endl<<endl;
		cout << "Hit 1 and enter to start drawing: " ;
		while (1){
		cin >> n;
		if (n=='1')
			break;
		else
			cout<<"Sorry this command is not recognized, press 1 and enter to exit and start drawing: ";
		}
		system("CLS");
		cin.ignore();
		main_program(x, y, angle, width,color1,color2,color3);
		
}
void equaltriangle(int a,int &x,int &y,int angle,int& width,int &color1,int& color2,int& color3){
	//draws an equaliteral triangle
	angle=angle+90;
	angle=angle%360;
	forward(a,angle,x,y, color1,color2,color3,width);
	right_turn(120,angle);
	forward(a,angle,x,y, color1,color2,color3,width);
	right_turn(120,angle);
	forward(a,angle,x,y, color1,color2,color3,width);
	right_turn(120,angle);
}

void console(int& width)
{    //It creates the user interface
	system("CLS");
	myLine(0, 250, 700, 250, 255, 255,255, width);
	gotoxy(0, 22);
}


void forward(int a, int angle, int &x, int &y, int& color1,int &color2,int &color3, int& width){
	//uses trignometry to calculate the x,y coordinates and uses that in myLine function.
	int x_increment=a*cos(0.01745329251*angle);
	int y_increment=a*sin(0.01745329251*angle);
	myLine(x, y, x + x_increment, y - y_increment, color1,color2,color3, width);
	y=y-y_increment;
	x=x+x_increment;
}
void backward(int a, int angle, int &x, int &y, int &color1,int &color2,int &color3,int& width){
	angle = angle + 180;
	angle = angle % 360;
	forward(a, angle, x, y, color1,color2,color3, width);
}

void right_turn(int a, int &angle){
	angle = angle - a;
	angle = angle % 360;
}

void left_turn(int a, int &angle){
	angle = angle + 360;
	angle = angle + a;
	angle = angle % 360;
}

void circle(int a, int x, int y, int& width,int& color1,int& color2, int& color3)
{
	myEllipse(x - a, y - a, x + a, y + a, color1,color2,color3, width);
}

void square(int a, int x, int y, int& width,int& color1,int& color2, int& color3)
{
	myRect(x - a, y - a, x + a, y + a, color1,color2,color3, width);
}

void penup(int& x, int& y, int& color1,int &color2,int &color3, int& width)
{
	color1=0,color2=0,color3 = 0;
	myLine(x, y, x, y,  color1,color2,color3, width);
}

void pendown(int& x, int &y, int &color1,int &color2,int &color3, int& width)
{
	color1 = 255,color2=255,color3=255;
	myLine(x, y, x, y,  color1,color2,color3, width);
}

void threeDsquare(int a, int x, int y, int& width,int& color1,int& color2, int& color3)
{
	int i = 0;
	while (i != a){
		Sleep(50);
		myRect(x - a, y - a, x + a, y + a, color1 - a * 2,color2-a*2,color3-a*2, width);
		a--;
	}
}

void threeDcircle(int a, int x, int y, int& width,int& color1,int& color2, int& color3)
{
	int i = 0;
	while (i != a){
		Sleep(50);
		myEllipse(x - a, y - a, x + a, y + a, color1-a*2 , color2-a*2 , color3*0, width);
		a--;
	}
}

void solidcr(int a, int x, int y, int& width,int& color1,int& color2, int& color3)
{
	int i = 0;
	while (i<10){
		Sleep(50);
		myEllipse(x - a, y - a, x + a, y + a, color1 - a, color2 - a, color3, width);
		a++;
		i++;
	}
}
void filename(char a[]){
	/* For save,load and repeat function. If we get ",[ , ( in the string, it modifies that input string to the thing inside.*/
	char b[150]={0};
	int j=0,i=0;
	for (;a[i]!='"' && a[i]!='[' && a[i]!='(';i++);
	i++;
	a[j]=a[i];
	for (;a[i]!='\0';i++,j++)
		a[j]=a[i];
	j--;
	a[j]='\0';
}
void save (char store[][100],int row,ofstream &fout){
	if (fout.is_open()){
		for (int i=0;i<row-1;i++){
				fout<<store[i]<<endl;
		}
	}
}
void load (ifstream &fin,ofstream &fout,char store[][100],int row,int &x,int &y,int& angle,int &color1,int &color2,int &color3,int &width){
	char a[100]={0},copy[100];
	int z=0;
	if (fin.is_open()){
		while(fin.eof()==false){
			fin.getline(a,100);
			strcpy_s(copy,a);
			z=UserInput(a);
			readCommands(a,copy,z,fin,fout,store,row,x,y,angle, color1,color2,color3,width);
		}
	}
}
int UserInput(char number[])
{ /*Takes one string as input and separte the length and the command. It returns the length and modifies the input string as the command.
	If no length is given, it returns -1.*/
	int i, strength,k=strlen(number);

	char value[20];
	for (i = 0; number[i] >= 92 && number[i] <= 122; i++);
	while (number[i]==' '){
		number[i] = 0;
		i++;}
	if (i==k)
		return -1;
	for (int j=0; number[i] >='0' && number[i]<='9'; i++,j++)
	{
		value[j] = number[i];
		number[i] = 0;
	}
	strength = atoi(value);
	return strength;
}

void input(char a[], int b){
	gets_s(a, b);
}

void readCommands(char number[],char copy[],int length,ifstream &fin,ofstream &fout,char store[][100],int row, int &x, int &y, int& angle, int& color1,int &color2,int &color3, int& width){
	// Reads the commands and executes the relevant function.
	int cursor_width=1;
	int color_black=0;
	if(strcmp(number,"cs")==0)
	{
		clearscreen(x,y,angle);
		myEllipse(x-5,y-5,x+5,y+5,255,0,255,cursor_width);
	}
	else if (strcmp(number, "fd") == 0 || (strcmp(number, "forward") == 0)){
		if (length==-1)
			cout<<"Incomplete command. Length was not specified.";
		else{
			myEllipse(x-5, y-5, x + 5, y + 5, 0, 0, 0, cursor_width); //This will draw a black circle at the Initial position...
			forward(length, angle, x, y, color1,color2,color3, width);
			myEllipse(x-5, y-5, x + 5, y + 5, 228, 0, 228, cursor_width);
			}
		}
	else if (strcmp(number, "bk") == 0 || (strcmp(number, "backward") == 0)){
		if (length==-1)
			cout<<"Incomplete command. Length was not specified.";
		else {
			myEllipse(x-5, y-5, x + 5, y + 5, 0, 0, 0, cursor_width);
			backward(length, angle, x, y,  color1,color2,color3, width);
			myEllipse(x-5, y-5, x + 5, y + 5, 228, 0, 228, cursor_width);
			}
		}
	else if(strcmp(number, "instructions") == 0 || (strcmp(number, "instruction") == 0)){
		//gotoxy(0,0);
		clearscreen(x,y,angle);
		instruction();
	}
	else if (strcmp(number, "rt") == 0 || (strcmp(number, "right") == 0)){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			right_turn(length, angle);
		}
	else if (strcmp(number, "lt") == 0 || (strcmp(number, "left") == 0)){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			left_turn(length, angle);
	}
	else if (strcmp(number, "circle") == 0 || (strcmp(number, "cr") == 0)){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			circle(length, x, y, width,color1,color2,color3);
	}
	else if (strcmp(number, "square") == 0 || (strcmp(number, "sq") == 0)){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			square(length, x, y, width,color1,color2,color3);
	}

	else if (strcmp(number, "solid") == 0){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			solidcr(length, x, y, width,color1,color2,color3);
	}
	else if (strcmp(number, "triangle") == 0){
		if (length==-1)
			cout<<"Incomplete command.";
		else
			equaltriangle(length, x, y,angle, width,color1,color2,color3);
	}
	else if (strcmp(number, "tdcircle") == 0 || (strcmp(number, "tdcr") == 0))
		threeDcircle(length, x, y, width,color1,color2,color3);
	else if (strcmp(number, "color") == 0)
			pencolor(copy, color1,color2,color3);
	else if (strcmp(number, "width") == 0)
		width = length;
	else if (strcmp(number, "solidcr") == 0 || (strcmp(number, "sdcr") == 0))
		solidcr(length, x, y, width,color1,color2,color3);
	else if (strcmp(number, "tdsq") == 0 || (strcmp(number, "tdsquare") == 0))
		threeDsquare(length, x, y, width,color1,color2,color3);
	else if (strcmp(number, "penup") == 0 || (strcmp(number, "pu") == 0))
		penup(x, y,  color1,color2,color3, width);
	else if (strcmp(number, "pendown") == 0 || (strcmp(number, "pd") == 0))
		pendown(x, y,  color1,color2,color3, width);
	else if (strcmp(number, "repeat")==0){
			filename(copy);
			repeat1(copy, length,fin,fout,store,row, x, y, angle,  color1,color2,color3, width);}
	else if (strcmp(number, "load")==0){
			filename(copy);
			fin.open(copy);
			load(fin,fout,store,row,x,y,angle,color1,color2,color3,width);}
	else if (strcmp(number, "save")==0){
			filename(copy);
			fout.open(copy);
			save(store,row,fout);}
	else
		cout << "Wrong Command Entered..." << endl;
}

void repeat1(char a[],int length,ifstream &fin,ofstream &fout,char store[][100],int row,int &x,int &y,int &angle,int &color1,int &color2,int &color3,int &width){
	//Takes input string which contains the commands to execute. Also takes length and execute the commands that number of times.
	char b[100],copy[100]={0};
	int z=strlen(a),g=0,l=0;
	for (int f=0;f<length;f++){
		int j=0;
		while (j<z){
			g=0,l=0;
			for (;a[j]>='a' && a[j]<='z' && j<z;l++,j++)
				b[l]=a[j];
			for(;(a[j]<'a' || a[j]>'z') && j<z;l++,j++){
				b[l]=a[j];}
			b[l]='\0';
			strcpy_s(copy,b);
			int h=UserInput(b);
			readCommands(b,copy,h,fin,fout,store,row,x,y,angle,color1,color2,color3,width);
		}
	}
}
void pencolor(char color_array[], int& color1,int &color2,int &color3)
	//It separates the command and the color from the input string and changes the color of pen as required.
{	int j=0,l=0,z=strlen(color_array);
	for (;color_array[j]>='a' && color_array[j]<='z';j++);
	j++;
	for(;(color_array[j]<'a' || color_array[j]>'z') && j<z;l++,j++){
		color_array[l]=color_array[j];}
	color_array[l]='\0';
	if	(strcmp(color_array, "BLACK") == 0)
		{
			color1 = 0;
			color2=0;
			color3=0;
		}
	else if (strcmp(color_array, "WHITE") == 0)
		{
			color1 = 255;
			color2=255;
			color3=255;
	}
	else if (strcmp(color_array, "GRAY") == 0)
		{
			color1 = 150;
			color2=150;
			color3=150;
	}
	else if (strcmp(color_array, "GREEN") == 0)
		{
			
		color1 = 0;
		color2 = 255;
		color3 = 0;
	}
	else if (strcmp(color_array, "BLUE") == 0)
		{
		color1 = 0;
		color2 = 0;
		color3 = 255;
	}
	else if (strcmp(color_array, "RED") == 0)
		{	
		color1 = 255;
		color2 = 0;
		color3 = 0;
	}
	else if (strcmp(color_array, "YELLOW") == 0)
	{
		color1=255;
		color2=255;
		color3=0;
	}
}

void main_program(int x, int y, int angle, int& width,int& color1,int& color2, int &color3){
	char store[100][100]={0};
	color1 = 255,color2=255,color3=255;
	int i=0;
	int cursor_width=1;
	ofstream fout;
	ifstream fin;
	myEllipse(x -5, y -5, x + 5, y + 5, 228, 0, 228, cursor_width);
	char number[100] = { 0 };
	char copy[100]= { 0 };
	while (1)
	{
		console(width);
		input(number, 100);
		strcpy_s(store[i],number);
		i++;
		strcpy_s(copy,number);
		int length = UserInput(number);
		readCommands(number,copy,length,fin,fout,store,i, x, y, angle, color1,color2,color3, width);	
	}
}