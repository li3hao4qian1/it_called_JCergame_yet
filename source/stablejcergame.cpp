// copyleft(c) lihaoqian,LiJunyi
//版权所有，亲全必究
//任何试图盗窃此代码的人会被JC
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <wincon.h>
#include <time.h>
#include <direct.h>
// For faster ,we will do optimize.
// For stabler,we wont do optimize.
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#define press(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define lborder 10
#define uborder 10
#define rborder 90
#define dborder 90
#define detect(VK_NONAME) if (press(VK_NONAME))
#define detects(VK_NONAME, int) if (press(VK_NONAME) || press(int))
using namespace std;
// extern的作用是让这一部分可以收起(WeijiPedia)
extern "C++" {
	string keyboard[114] = { "",
		"------------------------------------------------------\n",
		"|Es|  |F1|F2|F3|F4|F5|F6|F7|F8|F9|FA|FB|FC| |PS|SL|PB|\n",
		"------------------------------------------------------\n",
		"|~ |1 |2 |3 |4 |5 |6 |7 |8 |9 |0 |- |= |Bksp|In|Ho|PU|\n",
		"------------------------------------------------------\n",
		"|Tab|Q |W |E |R |T |Y |U |I |O |P |[ |] |Ent|De|En|PD|\n",
		"------------------------------------------------------\n",
		"|Caps|A |S |D |F |G |H |J |K |L |; |' |\\ |er|  |↑|  |\n",
		"------------------------------------------------------\n",
		"|Shift|Z |X |C |V |B |N |M |, |. |/ |RShift |←|↓|→|\n",
		"------------------------------------------------------\n",
		"|Ct|Win|Al|     S p a c e     |RA|Fn|RMB|RCt| 退出|  |\n",
		"------------------------------------------------------\n" };
	map<char, string> WBname;
	map<char, string> WBintro;
	vector<char> WBlist;
	map<string,string> WEname;
	map<string,string> WEintro;
	map<string,string> WEeffect;
	vector<string> WElist;
	void weijiinit() {
		WBname['.'] = "草坪";
		WBintro['.'] = "思穿盆底。";
		WBname[','] = "泥土";
		WBintro[','] = "璜土糕圆。";
		WBname[';'] = "草丛";
		WBintro[';'] = "董楠秋玲。";
		WBname['T'] = "树（可交互）";
		WBintro['T'] = "木又寸。兑。";
		WBname['o'] = "小石头（可交互）";
		WBintro['o'] = "据考察，这是1e5年前从冰川飘来的石头。";
		WBname['w'] = "灌木丛（可交互）";
		WBintro['w'] = "然而没人知道什么品种能产出这么酸的果子。";
		WBname['_'] = "水（可交互）";
		WBintro['_'] = "含盐量未知。";
		WBname['='] = "木块";
		WBintro['='] = "墙。";
		WBname['-'] = "木板";
		WBintro['-'] = "桥。";
		WBlist.push_back('.');
		WBlist.push_back(',');
		WBlist.push_back(';');
		WBlist.push_back('T');
		WBlist.push_back('o');
		WBlist.push_back('w');
		WBlist.push_back('_');
		WBlist.push_back('=');
		WBlist.push_back('-');
		WEname["swim"]="涉水";
		WEintro["swim"]="进入水源时获得，每在水中移动一次，效果+1，直到离开";
		WEeffect["swim"]="移动时，额外失去 X的立方 点体力，x>4时溺亡";
		WElist.push_back("swim");
	}
}  // WeijiPedia
int ti(float a) { return ((int)(a * 10 + 5)) / 10; }
void setpos(float x, float y) {
	COORD pos;
	pos.X = ti(y * 4) / 2;
	pos.Y = ti(x);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void scta(int x) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void anicls() {
	system("cls");
}
void delaymsg(string msg, int ms = 50) {  // Show a string slowly.
	cout<<msg;
}
struct ing {
	bool unlock;
	int item1, num1;
	bool have2;
	int item2, num2;
	bool have3;
	int item3, num3;
	int dest, num;
	ing(bool a, int b, int c, bool d, int e, int f, bool g, int h, int i, int j, int k=1) {
		unlock = a;
		item1 = b, num1 = c;
		have2 = d; 	
		item2 = e, num2 = f;
		have3 = g;
		item3 = h, num3 = i;
		dest = j;
		num=k;
	}
};
struct effect{
	string name;
	int value;
};
string message;
map<char, int> color;
map<int, string> itemname;
map<int, int> itemsize;
vector<ing> ings;
int hand[15];         // objects on hand
//int handnum[15];    // TODO
bool intable[255];    // interact able,It should be map<char,bool>
bool wall[255];       // pass ability, It should be map<char,bool>
int handmax;          // max number of objects on hand
int handsize;         // number of objects on hand
int handind;          // the index of the object which shows now
bool alive = 1;       // is alive
int speed = 1;        // delay between movements (ms)
int force = 114514;   // -1 per movement
vector<effect> status;// status
double showed;
int damage = 1;
int vision = 0x0000;
char world[100][100];
char copwd[100][100];
int posx, posy;
void take(int item) {
	if (handsize + 1 > handmax) {
		message = "装不下...";
		showed = true;
	} else {
		int ind = 0;
		while (hand[++ind] != 0);
		handsize -= itemsize[hand[ind]] * 2;
		hand[ind] = item;
		message = "将" + itemname[item] + "装进背包的第" + char(ind + '0') + "个位置！";
		showed = true;
		handsize += itemsize[item];
	}
}
void throwout(int x) {
	message = "扔掉" + itemname[hand[x]] + "！";
	showed = true;
	handsize -= itemsize[hand[x]];
	hand[x] = 0;
}
void throwoutitem(int x, int t, bool show = 0) {
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		if (hand[i] == x) {
			message = "扔掉" + itemname[hand[i]] + "！";
			showed = show;
			handsize -= itemsize[hand[i]];
			hand[i] = 0;
			if ((++cnt) >= t) {
				return;
			}
		}
	}
}
bool have(int x, int t) {
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		if (hand[i] == x)
			cnt++;
	}
	return cnt >= t;
}
bool handempty() {
	for (int i = 1; i <= 10; i++) {
		if (hand[i] > 0)
			return false;
	}
	return true;
}
void dead(string msg) {
	anicls();
	setpos(0, 0);
	scta(0xF);
	delaymsg("你死了！\n");
	delaymsg("死因：");
	delaymsg(msg);
	delaymsg("\n");
	delaymsg("按Q退出\n");
	while (1) {
		detect('Q') { exit(0); }
		Sleep(10);
	}
}

void weijipedia() {
	anicls();
	system("cls");
	setpos(0, 0);
	cout << "                    \n";
	cout << "      喂鸡百科      \n";
	cout << "                    \n";
	cout << "*退出--------------U\n";
	while (1) {
		detect('U') { return; }
	}
}
void whenmove() {
	force--;
	Sleep(speed);
}
bool move() {
	detects(VK_UP, 'W') {
		if(wall[world[posy-1][posx]]) return 0;
		whenmove();
		posy--;
		return 1;
	}
	detects(VK_DOWN, 'S') {
		if(wall[world[posy+1][posx]]) return 0;
		whenmove();
		posy++;
		return 1;
	}
	detects(VK_LEFT, 'A') {
		if(wall[world[posy][posx-1]]) return 0;
		whenmove();
		posx--;
		return 1;
	}
	detects(VK_RIGHT, 'D') {
		if(wall[world[posy][posx+1]]) return 0;
		whenmove();
		posx++;
		return 1;
	}
	return 0;
}
void build(char c){
	system("cls");
	cout<<"在键盘上选择摆放的位置\n";
	cout<<"7 8 9\n";
	cout<<"4 @ 6\n";
	cout<<"1 2 3\n";
	cout<<"0(取消)";
	while(1){
		detects(VK_NUMPAD0,'0'){
			take(6);
			break;
		}
		detects(VK_NUMPAD7,'7'){
			world[posy-1][posx-1]=c;
			break;
		}
		detects(VK_NUMPAD8,'8'){
			world[posy-1][posx]=c;
			break;
		}
		detects(VK_NUMPAD9,'9'){
			world[posy-1][posx+1]=c;
			break;
		}
		detects(VK_NUMPAD4,'4'){
			world[posy][posx-1]=c;
			break;
		}
		detects(VK_NUMPAD6,'6'){
			world[posy][posx+1]=c;
			break;
		}
		detects(VK_NUMPAD1,'1'){
			world[posy+1][posx-1]=c;
			break;
		}
		detects(VK_NUMPAD2,'2'){
			world[posy+1][posx]=c;
			break;
		}
		detects(VK_NUMPAD3,'3'){
			world[posy+1][posx+1]=c;
			break;
		}
	}
}


void inittheworld() {
	printf("定义颜色\n");  //当成注释就行别删
	color['.'] = 0xA0;     // grass
	color[','] = 0x60;     // dirt
	color[';'] = 0x20;     // bush
	color['#'] = 0x70;     // border
	color['?'] = 0x7F;     // border outside
	color['T'] = 0xF6;     // tree
	color['o'] = 0x67;     // rock
	color['w'] = 0xFA;     // intabush
	color['X'] = 0xFA;     // droopy looks in a cave, no one is there
	color['_'] = 0x3F;     // water
	color['='] = 0x6E;     // wood
	color['-'] = 0xE6;     // plank
	printf("定义物品\n");
	itemname[0] = "空";
	itemsize[0] = 0;
	itemname[1] = "小石子";
	itemsize[1] = 1;
	itemname[2] = "横木";
	itemsize[2] = 3;
	itemname[3] = "树枝";
	itemsize[3] = 1;
	itemname[4] = "酸果";
	itemsize[4] = 1;
	itemname[5] = "石斧";
	itemsize[5] = 2;
	itemname[6] = "木块";
	itemsize[6] = 1;
	itemname[7] = "木板";
	itemsize[7] = 1;
	itemname[8] = "稳定碎片";
	itemsize[8] = 1;
	itemname[9] = "很稳定碎片";
	itemsize[9] = 1;
	itemname[10] = "非常稳定碎片";
	itemsize[10] = 1;
	itemname[11] = "Stable!";
	itemsize[11] = 3;
	intable['T'] = 1;
	intable['o'] = 1;
	intable['w'] = 1;
	intable['X'] = 1;
	message = "";
	printf("搭建碰撞箱\n");
	wall['=']=1;
	printf("定义配方\n");
	ings.push_back(ing(1, 8, 1, 1, 9, 1, 1,10, 1,11, 1));
	ings.push_back(ing(0, 1, 1, 1, 3, 1, 0, 0, 0, 5));
	ings.push_back(ing(0, 2, 1, 0, 0, 0, 0, 0, 0, 6, 3));
	ings.push_back(ing(0, 2, 1, 0, 0, 0, 0, 0, 0, 7, 4));
	printf("吃石化其他变量\n");
	memset(hand, 0, sizeof hand);
	handind = 1;
	handmax = 10;
	handsize = 0;
	alive = 1;
	speed = 100;
	force = 114514;
	posx = 50;
	posy = 50;
	//    posx = 0;
	//    posy = 0;
	showed = false;
	printf("初始化地图\n");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			world[i][j] = '?';
		}
	}
	printf("使用大炮算法生成地图\n");
	for (int i = uborder + 1; i < dborder; i++) {
		for (int j = lborder + 1; j < rborder; j++) {
			srand(time(0) + rand() + i + j + j / i + i / j);
			int k = rand() + 123;
			if (k % 2 == 1)
				world[i][j] = world[i - 1][j];
			if (k % 2 == 0)
				world[i][j] = world[i][j - 1];
			if (i == uborder + 1) {
				if (j == lborder + 1) {
					if (k % 4 == 0)
						world[i][j] = '.';
					if (k % 4 == 1)
						world[i][j] = ',';
					if (k % 4 == 2)
						world[i][j] = ';';
					if (k % 4 == 3)
						world[i][j] = '_';
				} else {
					if (k % 50 >= 4)
						world[i][j] = world[i][j - 1];
					if (k % 50 == 3)
						world[i][j] = '.';
					if (k % 50 == 2)
						world[i][j] = ',';
					if (k % 50 == 1)
						world[i][j] = ';';
					if (k % 50 == 0)
						world[i][j] = '_';
				}
			} else {
				if (j == lborder + 1) {
					if (k % 50 >= 4)
						world[i][j] = world[i - 1][j];
					if (k % 50 == 3)
						world[i][j] = '.';
					if (k % 50 == 2)
						world[i][j] = ',';
					if (k % 50 == 1)
						world[i][j] = ';';
					if (k % 50 == 0)
						world[i][j] = '_';
				} else {
					if (k % 100 >= 50)
						world[i][j] = world[i - 1][j];
					else if (k % 100 >= 4)
						world[i][j] = world[i][j - 1];
					if (k % 100 == 3)
						world[i][j] = '.';
					if (k % 100 == 2)
						world[i][j] = ',';
					if (k % 100 == 1)
						world[i][j] = ';';
					if (k % 100 == 0)
						world[i][j] = '_';
				}
			}
			// tree
			if (world[i][j] == ';') {
				srand(rand());
				if (rand() % 75 == 1)
					copwd[i][j] = 'T';
			}
			if (world[i][j] == '.') {
				srand(rand());
				if (rand() % 100 == 1)
					copwd[i][j] = 'T';
			}
			// rock
			if (world[i][j] == ',') {
				srand(rand());
				if (rand() % 75 == 1)
					copwd[i][j] = 'o';
			}
			if (world[i][j] == '.') {
				srand(rand());
				if (rand() % 100 == 1)
					copwd[i][j] = 'o';
			}
			// bush
			if (world[i][j] == ';') {
				srand(rand());
				if (rand() % 75 == 1)
					copwd[i][j] = 'w';
			}
			if (world[i][j] == '.') {
				srand(rand());
				if (rand() % 100 == 1)
					copwd[i][j] = 'o';
			}
		}
		if (i % 100 == 0)
			cout << '#';
	}
	printf("\n生成可交互的地块\n");
	for (int i = uborder + 1; i < dborder; i++) {
		for (int j = lborder + 1; j < rborder; j++) {
			if (copwd[i][j])
				world[i][j] = 'X';
		}
	}
	printf("设立边界\n");
	for (int i = uborder; i <= dborder; i++) world[i][lborder] = '#';
	for (int i = uborder; i <= dborder; i++) world[i][rborder] = '#';
	for (int j = lborder + 1; j < rborder; j++) world[uborder][j] = '#';
	for (int j = lborder + 1; j < rborder; j++) world[dborder][j] = '#';
	
	printf("启动！\n");
	system("cls");
}

void savetheworld(){
	anicls();
	setpos(0,0);
	cout<<"为您的存档命名:";
	string name;
	cin>>name;
	ofstream out((name+".jcs").c_str());
	//TODO
}

void The_World() {
	weijiinit();
	while (alive) {
		system("cls");
		setpos(0, 0);
		scta(0x85);
		printf("[坐标:<%d,%d>] ", posx, posy);
		scta(0x8A);
		printf("[体力:%d] ", force);
		cout<<endl;
		scta(0x8F);
		if ((showed -= 0.05) > 0) {
			cout << message << "\n";
		} else {
			scta(0x0);
			cout << "                        "
			<< "\n";
		}
		scta(0xF);
		for (int i = posy - 2; i <= posy + 2; i++) {
			for (int j = posx - 5; j <= posx + 5; j++) {
				if (i == posy && j == posx) {
					scta(0xF6 | vision);
					printf("@");
				} else {
					scta(color[world[i][j]] | vision);
					printf("%c", world[i][j]);
				}
			}
			printf("\n");
		}
		scta(0xF);
		cout<<endl;
		scta(0x8E);
		for(effect i:status){
			cout<<WEname[i.name]<<i.value<<" ";
		}
		scta(0xF);
		cout<<"                                                                       ";
		
		scta(0xF);
//		setpos(0, 27);
		cout<<endl;
		printf("背包容量:%d/%d", handsize, handmax);
		cout<<endl;
		cout << "第" << handind << "个物品，" << itemname[hand[handind]] << "";
		
		vision = 0x0;
		bool moved=0;
		if(move()){
			moved=1;
		}
		for(effect i:status){
			if(i.name=="swim"&&moved){
				if(i.value>4) dead("认为自己可以水下呼吸");
				force-=(i.value*i.value%10000*i.value%10000);
			}
		}
		detect('1') handind = 1;
		detect('2') handind = 2;
		detect('3') handind = 3;
		detect('4') handind = 4;
		detect('5') handind = 5;
		detect('6') handind = 6;
		detect('7') handind = 7;
		detect('8') handind = 8;
		detect('9') handind = 9;
		detect('0') handind = 10;
		detect('Z') { weijipedia(); }
		if (press('E') && hand[handind] == 4) {
			force += 20;
			
			hand[handind] = 0;
			message = "吃了一个酸果！";
			handsize -= 2;
			showed = true;
		}
		if (press('E') && hand[handind] == 6) {
			build('=');
			hand[handind] = 0;
			handsize -= 1;
		}
		if (press('E') && hand[handind] == 7) {
			build('-');
			hand[handind] = 0;
			handsize -= 1;
		}
		if (press('E') && hand[handind] == 11) {
			srand(rand());
			if(rand()%3==0) build('T');
			if(rand()%3==1) build('w');
			if(rand()%3==2) build('o');
			hand[handind] = 0;
			handsize -= 1;
		}
		
		if (hand[handind] == 5) {
			damage=4;
//			message = "持有石斧";
//			showed = true;
		}else{
			damage=1;
//			message = "赤手空拳";
//			showed = true;
		}
		detect('Q') {
			throwout(handind);
			handsize--;
			if (handsize < 0)
				handsize = 0;
		}
		detect('R') {
			bool nxtok=0;
			for (ing it : ings) {
				bool canmade = it.unlock;
				if (!have(it.item1, it.num1))
					canmade = 0;
				if (it.have2)
					if (!have(it.item2, it.num2))
						canmade = 0;
				if (it.have3)
					if (!have(it.item3, it.num3))
						canmade = 0;
				if(nxtok&&!canmade) continue;
				else nxtok=0;
				anicls();
				setpos(0, 0);
				cout << "目前查看" << itemname[it.dest] << "的配方\n";
				if (it.unlock) {
					cout << "你需要：\n";
					cout << itemname[it.item1] << "x" << it.num1 << "\n";
					if (it.have2)
						cout << itemname[it.item2] << "x" << it.num2 << "\n";
					if (it.have3)
						cout << itemname[it.item3] << "x" << it.num3 << "\n";
					cout<<"一次合成"<<it.num<<"个\n";
				} else {
					cout << "你没解锁所以看不到，很正常，对吧？。\n";
				}
				while (1) {
					setpos(5, 0);
					if (canmade)
						cout << "[制作  (P)] ";
					cout << "[下一个(Q)] [退出(W)] [下一个可以合成的(E)]                      ";
					detect('P') {
						if (canmade) {
							throwoutitem(it.item1, it.num1);
							if (it.have2)
								throwoutitem(it.item2, it.num2);
							if (it.have3)
								throwoutitem(it.item3, it.num3);
							for(int i=1;i<=it.num;i++) take(it.dest);
						}
					}
					detect('Q') break;
					detect('W') goto ohmygod;
					detect('E'){
						nxtok=1;
						break;
					}
				}
			}
		}
		ohmygod:;
		detect(VK_ESCAPE) {
			anicls();
			while (1) {
				setpos(0, 0);
				cout << "游戏已暂停\n";
				cout << "-> 继续游戏\n";
				cout << "使用↑↓选择，Enter以确定";
				detect(VK_RETURN) {
					break;
				}
			}
		}
		if (world[posy][posx] == 'T') {
			detect('P') {
				int progress = 0;
				anicls();
				while (progress < 10) {
					scta(0xF);
					setpos(0, 0);
					printf("按下P砍树\n");
					printf("进度:%d/10 体力:%d 一次伤害%d\n", progress, force, damage);
					detect('P') {
						srand(rand());
						if (rand() % 3 == 1) {
							printf("没砍到");
						} else {
							printf("砍到了");
							progress += damage;
						}
						force--;
						if (force <= 0) {
							dead("砍树然后被树砍死");
							return;
						}
						Sleep(1000);
					}
				}
				take(2);
				world[posy][posx] = ',';
			}
		}
		if (world[posy][posx] == 'o') {
			detect('P') {
				take(1);
				handsize++;
				world[posy][posx] = ',';
			}
		}
		if (world[posy][posx] == 'w') {
			detect('P') {
				srand(rand());
				take(rand() % 2 + 3);
				handsize++;
				world[posy][posx] = '.';
			}
		}
		if (world[posy][posx] == 'X') {
			detect('P') {
				srand(rand());
				if(rand()%3==0) take(8);
				if(rand()%3==1) take(9);
				if(rand()%3==2) take(10);
				message="太不稳定了！";
				showed=true;
				world[posy][posx] = '?';
			}
		}
		if (force > 100)
			;  //不能删！
		else if (force >= 50) {
			srand(rand());
			if (rand() % 5 == 0)
				vision = 0x4000;
		} else if (force >= 20) {
			srand(rand());
			if (rand() % 3 == 0)
				vision = 0x4000;
		} else if (force > 0) {
			srand(rand());
			if (rand() % 2 == 0)
				vision = 0x4000;
		} else {
			dead("肌无力");
			return;
		}
	}
	Sleep(10);
}
int main() {
	system("title Stable JCerGame");
	system("color 0F");
	while (1) {
		setpos(0, 0);
		cout << "欢迎来到 稳定JCerGame!\n";
		cout << "-> 开始新游戏\n";
		cout << "使用↑↓选择，Enter以确定";
		detect(VK_RETURN) {
			break;
		}
	}
	anicls();
	setpos(0, 0);
	inittheworld();
	The_World();
	return 0;
}