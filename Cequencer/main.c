//#include "Header.h"
//#include <cstddef>
#include <stdlib.h>
#include "rlutil.h"
#include <time.h>
#define MAX 35
#define X_COUNT 8
#define Y_COUNT 8
struct dat
{
	int posX;
	int posY;
	char playerChr;

	char name[MAX];

	struct date {
		int day;
		int month;
		int year;
	}date;
};

typedef struct {
	int trigger[16];
	int notenumber;
	int vel;
	int channel;
}Room;


typedef struct {
	int screenX;
	int screenY;
	Room room[3];

}House;

int playSequence(struct dat lib[9][9]);
//int input_Buffer_Events_main();
int call_raster_main();
extern int posX;
extern int posY;


int xs = X_COUNT + 1;
int ys = Y_COUNT + 1;

struct dat lib[X_COUNT + 1][Y_COUNT + 1] = { '\0' };

DWORD WINAPI ThreadFunc(void* data) {
	playSequence(lib);
	// Do stuff.  This will be the first function called on the new thread.
	// When this function returns, the thread goes away.  See MSDN for more details.
	return 0;
}

int main(int argc, char* argv) {
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	call_raster_main();
	
	//input_Buffer_Events_main();
//	setColor(10);  //				reset to white;

}

int call_raster_main() {

	

	char player[2] = { 'X','O' };
	int p = 2;
	int eingabe = 1;
	int yoffset = 1;
	//lib[1][1].posY = 1;
	//lib[1][1].posX =1;
	//lib[1][1].playerChr ='x';
	//playSequence(lib);
	do
	{
		system("cls");  // Clean the screen!
						//Print the Rastaman!
		setColor(7);
		for (int i = 0; i < yoffset; i++) {
			puts("");

		}
		for (size_t x = 1; x < xs; x++) {
			printf(" %c",'_');
		}
		puts("");
		for (size_t x = 1; x < xs; x++) {
			for (size_t y = 1; y < ys; y++) {
				printf("|");

				//printf("%c", ((lib[x][y].posX > 0 && lib[x][y].posY > 0) && (x == lib[x][y].posX && y == lib[x][y].posY)) ? lib[x][y].playerChr : '_');
				if ((lib[x][y].posX > 0 && lib[x][y].posY > 0) && (x == lib[x][y].posX && y == lib[x][y].posY)) {
					setColor(10);
					printf("%c", lib[x][y].playerChr);
					setColor(7);
				}
				else {
					printf("%c", '_');
				}

				//printf("%s", ((lib[x][y].posX >0 && lib[x][y].posY >0) && (x == lib[x][y].posX && y == lib[x][y].posY)) ? "T" :"_" );
				if (y == ys - 1) {
					printf("|");
				}
			}
		puts("");
		
		}
		/*printf("MOUSElib X: %d Y:%d\n", lib[posX][posY].posX, lib[posX][posY].posY);
		printf("MOUSEPOS X: %d Y:%d", posX, posY);*/
		do
		{
		} while (!input_Buffer_Events_main());
		//	setColor(10);
			//printf("MOUSE X: %d Y:%d",posX,posY);
		//if (input_Buffer_Events_main()) {
		//	if (posX < xs && posY < ys) {
				
				
				if (posX == 1) {
				
				}
				else if (posX > 1) {
					posX = posX - (posX/2);
				}
				posY = posY - yoffset;
				lib[posY][posX].posY = posX;
				lib[posY][posX].posX = posY;
				
				lib[posY][posX].playerChr = '*';
				
 	//}


	//	}
		//printf("MOUSE");
	} while (eingabe != 0);
	return 1;
}



int playSequence(struct dat lib[9][9]) {
	_Bool isplaying = 1;

	double time_spent = 0.0;
	
	long begin = clock();

	// do some stuff here
	Sleep(3);

	long end = clock();
	double theend = clock();

	// calculate elapsed time by finding difference (end - begin) and
	// divide by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	//	printf("Time elpased is %f seconds", time_spent);

		//
	int index = 0;

	double ms;
	double dur;
	double swing = 0;
	double theswing = 0.33;
	int thebpm = 120;

	ms = ((60000.0 / (double)thebpm) / (double)4);  //Millisecond per quarternote
	//ms = 125;  //Millisecond per quarternote
	dur = (ms / 1000) * CLOCKS_PER_SEC;
	printf("MILLIS PER QUATER:%f\n\n", ms);
	printf("ms/Clocks :%f\n\n", dur);

	//

	House myHouse = { 640,400,.room[0] = {{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},64,127,1},
							   .room[1] = {{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},64,127,1},
							   .room[2] = {{1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},64,127,1} };
	//printf("THE ROOM: %d\n", myHouse.room[1].notenumber);

	while (isplaying) {
		begin = clock();
		if ((double)begin > theend) {

			theend = (double)clock() + dur + (dur * (swing));
			swing = (index % 2) ? 0 : theswing;
			//printf("%f", swing);
			//printf("*");    //Do things...

			for (int i = 0; i < 3; i++) {
				//if (myHouse.room[i].trigger[index]) {
				if (lib[1][index].playerChr == '*') {
					SetPosition(index, i + 5);
					printf("TRIGGER");
					//	PlaySound("C:\\Users\\ATN_70\\Desktop\\C2_Ausbildung\\C2_Ausbildung\\snare.wav", NULL, SND_ASYNC);     PLAY THE SOUND using win api
				}
				else {
					//	printf("-");
				}
			}//for



			index++;
		} //if beginn > end


		if (index == 16) { //reset things
			//tickindex = 0;
			index = 0;
			//system("cls");
			//puts("");

		}

	}

}