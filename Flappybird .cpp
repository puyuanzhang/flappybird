#include <graphics.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <math.h>


#pragma comment(lib,"Winmm.lib")

IMAGE img_bk,img_bk2,startborn1,startborn2;
IMAGE getready1,getready2;
IMAGE score[10][2];
IMAGE bird1[4],bird2[4];
IMAGE img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;
IMAGE tudi;
IMAGE gameoverimg1,gameoverimg2;
IMAGE score_panel;

#define Width         350
#define High          600
#define score_panel_x 50
#define score_panel_y 300
#define tudi_x        0
#define tudi_y        500
#define gameoverimg_x 68  
#define gameoverimg_y 100

double bird_x, bird_y;
int    i,k;
double bral_y, bral_xTop, bral_xDown;
double bird_flyingtime;
double gametime;
double x;
int    score_num;
int    birdfill_top;
bool   gamestart;
bool   gameing;
bool   gameover;




void startup() {
	initgraph(Width, High);
	loadimage(&img_bk, _T("resource/background.jpg"));
	loadimage(&img_bk2, _T("resource/background2.jpg"));
	loadimage(&bird2[0], "resource/bird1-2.gif");
	loadimage(&bird1[0], "resource/bird1-1.gif");
	loadimage(&bird2[1], "resource/bird2-2.gif");
	loadimage(&bird1[1], "resource/bird2-1.gif");
	loadimage(&bird2[2], "resource/bird3-2.gif");
	loadimage(&bird1[2], "resource/bird3-1.gif");
	loadimage(&bird2[3], "resource/bird4-2.gif");
	loadimage(&bird1[3], "resource/bird4-1.gif");
	loadimage(&img_bar_up1, _T("resource/bar_up1.gif"));
	loadimage(&img_bar_up2, _T("resource/bar_up2.gif"));
	loadimage(&img_bar_down1, _T("resource/bar_down1.gif"));
	loadimage(&img_bar_down2, _T("resource/bar_down2.gif"));
	loadimage(&gameoverimg1, _T("resource/gameover1.png"));
	loadimage(&gameoverimg2, _T("resource/gameover2.png"));
	loadimage(&tudi, _T("resource/tudi.jpg"));
	loadimage(&startborn1,_T("resource/start_1.png"));
	loadimage(&startborn2,_T("resource/start_2.png"));
	loadimage(&getready1,_T("resource/getready1.png"));
	loadimage(&getready2,_T("resource/getready2.png"));
	loadimage(&score[0][0], _T("resource/score0_1.jpg"));
	loadimage(&score[0][1], _T("resource/score0_2.jpg"));
	loadimage(&score[1][0], _T("resource/score1_1.jpg"));
	loadimage(&score[1][1], _T("resource/score1_2.jpg"));
	loadimage(&score[2][0], _T("resource/score2_1.jpg"));
	loadimage(&score[2][1], _T("resource/score2_2.jpg"));
	loadimage(&score[3][0], _T("resource/score3_1.jpg"));
	loadimage(&score[3][1], _T("resource/score3_2.jpg"));
	loadimage(&score[4][0], _T("resource/score4_1.jpg"));
	loadimage(&score[4][1], _T("resource/score4_2.jpg"));
	loadimage(&score[5][0], _T("resource/score5_1.jpg"));
	loadimage(&score[5][1], _T("resource/score5_2.jpg"));
	loadimage(&score[6][0], _T("resource/score6_1.jpg"));
	loadimage(&score[6][1], _T("resource/score6_2.jpg"));
	loadimage(&score[7][0], _T("resource/score7_1.jpg"));
	loadimage(&score[7][1], _T("resource/score7_2.jpg"));
	loadimage(&score[8][0], _T("resource/score8_1.jpg"));
	loadimage(&score[8][1], _T("resource/score8_2.jpg"));
	loadimage(&score[9][0], _T("resource/score9_1.jpg"));
	loadimage(&score[9][1], _T("resource/score9_2.jpg"));
	loadimage(&score_panel,_T("resource/score_panel.png"));
	gametime        =    1 ;
	bird_flyingtime =    1 ;
	x               =    0 ;
	i               =    0 ;
	k               =    0;
	bird_x          =   50 ;
	bird_y          =  250 ;
	bral_y          =  400 ;
	bral_xTop       = -400 ;
	bral_xDown      =  400 ;
	score_num       =    0 ;
	mciSendString(_T("open resource/background.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
}

void putscore(int score_num,int x,int y) {
	if (score_num < 10) {
		putimage(x, y, &score[score_num][0],NOTSRCERASE);
		putimage(x, y, &score[score_num][1],SRCINVERT);
	}
	else if (score_num >= 10) {
		int SW_NUM = score_num / 10;
		int GW_NUM = score_num - SW_NUM*10;
		putimage(x - 8, y, &score[SW_NUM][0],NOTSRCERASE);
		putimage(x - 8, y, &score[SW_NUM][1],SRCINVERT);
		putimage(x + 9, y, &score[GW_NUM][0],NOTSRCERASE);
		putimage(x + 9, y, &score[GW_NUM][1],SRCINVERT);
	}
}

void putbg(){
	if(sin(score_num*0.2 )>=0){
		putimage(0, 0, &img_bk);
	}else{
		putimage(0,0,&img_bk2);
	}
}

void startshow(){
	putimage(0, 0, &img_bk);
	putimage(0, 500, &tudi, SRCCOPY);
	putimage(110,250,&startborn1, NOTSRCERASE);
	putimage(110,250,&startborn2, SRCINVERT);
	putimage(70,150,&getready1, NOTSRCERASE);
	putimage(70,150,&getready2, SRCINVERT);
	putimage(bird_x, bird_y,&bird1[i%3],NOTSRCERASE);
	putimage(bird_x, bird_y,&bird2[i%3],SRCINVERT);
	if(k%5==0)
		i++;
	k++;

	x = x + 0.04*3.14;
	if(sin(x)>0)
		bird_y++;
	if(sin(x)<0)
		bird_y--;
	Sleep(50);
	char input;
	if (_kbhit()) {
		input = _getch();
		if (input == ' ') {
			gamestart = true;
		}
	}

}


void gamingshow() {
	putbg();
	putimage(bral_y, bral_xTop, &img_bar_up1, NOTSRCERASE);
	putimage(bral_y, bral_xTop, &img_bar_up2, SRCINVERT);
	putimage(bral_y, bral_xDown, &img_bar_down1, NOTSRCERASE);
	putimage(bral_y, bral_xDown, &img_bar_down2, SRCINVERT);
	putimage(bird_x, bird_y,&bird1[i%3],NOTSRCERASE);
	putimage(bird_x, bird_y,&bird2[i%3],SRCINVERT);
	if(k%5==0)
		i++;
	k++;
	putimage(tudi_x, tudi_y, &tudi, SRCCOPY);
	putscore(score_num,150,5);
	Sleep(50);
}

void updatewithoutinput() {
	if (bird_y < 500) {
		bird_y = bird_y + ( 0.1*(bird_flyingtime*bird_flyingtime) );
		bird_flyingtime = bird_flyingtime + 1.5;
	}

	bral_y = bral_y - 3*gametime;
	gametime = gametime + 0.01;

	if (bral_y <= -140) {
		bral_y = Width;
		int num = 300 + rand() % 250;
		bral_xTop = -num;
		bral_xDown = bral_xTop + 600 + 200;
		score_num ++;
	}
	
	if (
		(((bird_x + 34 >= bral_y) && (bird_x <= bral_y + 140)) &&
		((bird_y < bral_xTop + 600) || (bird_y + 24 > bral_xDown))) ||
			(bird_y > 500)
			){
			gameing = true;
			bird_y = bird_y - 50;
			birdfill_top = bird_y - 100;
			gametime = 0;
		
	}
	
}

void updatewithinput() {
	char input;
	if (_kbhit()) {
		input = _getch();
		if (input == ' ' && bird_y > 20) {
			bird_flyingtime = 1;
			bird_y = bird_y - 80;
			mciSendString(_T("close jpmusic"), NULL, 0, NULL);
			mciSendString(_T("open resource/Jump.mp3 alias jpmusic"), NULL, 0, NULL);
			mciSendString(_T("play jpmusic"), NULL, 0, NULL);
		}
	}
}

void gameovershow() {
			
			cleardevice();
			putbg();
			putimage(bral_y, bral_xTop, &img_bar_up1, NOTSRCERASE);
			putimage(bral_y, bral_xTop, &img_bar_up2, SRCINVERT);
			putimage(bral_y, bral_xDown, &img_bar_down1, NOTSRCERASE);
			putimage(bral_y, bral_xDown, &img_bar_down2, SRCINVERT);
			putimage(tudi_x, tudi_y, &tudi, SRCCOPY);
			putimage(bird_x, bird_y,&bird1[3],NOTSRCERASE);
			putimage(bird_x, bird_y,&bird2[3],SRCINVERT);
			
		
			if(bird_y + 34 < 483)
				bird_y = bird_y + 50;
			
			
			if(bird_y + 34 >= 483){
					putimage(gameoverimg_x, gameoverimg_y, &gameoverimg1, NOTSRCERASE);
					putimage(gameoverimg_x, gameoverimg_y, &gameoverimg2, SRCINVERT);
					putimage(score_panel_x,score_panel_y,&score_panel);
					putscore(score_num,230,335);
					gametime = 0;
			}

			char input;
			if (_kbhit()) {
				input = _getch();
				if (input == ' ') {
				gameover = true;
				}
			}
			Sleep(50);
}

int main() {
	startup();
	while(gamestart != true){
		startshow();
	}
	
	while (gameing != true) {
		gamingshow();
		updatewithoutinput();
		updatewithinput();
	}

	while(gameover != true){
		gameovershow();
	}
		
	cleardevice();
	return 0;
}

