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
// For faster,we will do optimize.
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define press(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define lborder 500
#define uborder 500
#define rborder 4500
#define dborder 4500
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  // set console color
}

void anicls() {
	scta(0x0);
	for (int i = 2; i <= 65; i++) {
		for (int j = 1; j <= i; j++) {
			int k = i - j;
			if (j > 0 && j < 25 && k > 0 && k < 40) {
				setpos(j - 1, k - 1);
				cout << "  ";
			}
		}
		Sleep(8);
	}
	scta(0xF);
}
void delaymsg(string msg, int ms = 50) {  // Show a string slowly.
	for (char i : msg) {
		cout << i;
		Sleep(ms);
	}
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
char world[5000][5000];
char copwd[5000][5000];
int posx, posy;
void banquan() {
	anicls();
	setpos(0, 0);
	cout << "                   ︵ \n";
	cout << "版权所有 Copyleft (Ｃ) 2025-2026 lihaoqian & LiJunyi 所有右重新服务。\n";
	cout << "                   ︶ \n";
	cout << "此外，使用由该游戏源代码特定函数的，应当在源码中标注。";
	cout << "按 ESC 退出。";
	while (true) {
		detect(VK_ESCAPE) {
			anicls();
			return;
		}
	}
}
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
	cout << "*查看地块----------Q\n";
	cout << "*查看物品----------W\n";
	cout << "*查看生物(未开放)--E\n";
	cout << "*查看键位----------R\n";
	cout << "*查看效果----------T\n";
	cout << "*版权声明----------Y\n";
	cout << "*退出--------------U\n";
	while (1) {
		detect('Q') {
			anicls();
			
			bool decide = 0;
			while (1) {
				setpos(0, 0);
				scta(0xF);
				if (!decide)
					scta(0xE);
				cout << "查看脚下地块" << endl;
				scta(0xF);
				if (decide)
					scta(0xE);
				cout << "查看所有地块" << endl;
				scta(0xD);
				cout << "空格选择，Q确定" << endl;
				detect(VK_SPACE) {
					decide = !decide;
					Sleep(100);
				}
				detect('Q') {
					if (decide) {
						anicls();
						for (unsigned i = 0; i < WBlist.size(); i++) {
							setpos(0, 0);
							scta(color[WBlist[i]]);
							for (int a = 0; a < 5; a++) {
								for (int b = 0; b < 9; b++) {
									cout << WBlist[i];
								}
								cout << endl;
							}
							scta(0xF);
							cout << WBname[WBlist[i]] << endl
							<< WBintro[WBlist[i]] << endl
							<< "按空格下一个，按Q继续游戏";
							while (1) {
								detect(VK_SPACE) { break; }
								detect('Q') {
									anicls();
									return;
								}
							}
							anicls();
						}
					} else {
						anicls();
						char i = world[posy][posx];
						setpos(0, 0);
						scta(color[i]);
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 9; b++) {
								cout << i;
							}
							cout << endl;
						}
						scta(0xF);
						cout << WBname[i] << endl << WBintro[i] << endl << "按Q继续游戏";
						while (1) {
							detect('Q') {
								anicls();
								return;
							}
						}
					}
				}
			}
		}
		detect('R') {
			anicls();
			int pntx = 4, pnty = 2;
			while (1) {
				setpos(0, 0);
				for (int i = 1; i <= 13; i++) {
					for (int j = 0; j < keyboard[i].size(); j++) {
						if (i == pnty && j == pntx)
							scta(0xF6);
						if (keyboard[i][j] == '|')
							scta(0xF);
						cout << keyboard[i][j];
					}
				}
				detects(VK_UP, 'W') {
					pnty -= 2;
					pntx = 1;
					Sleep(30);
				}
				if (pnty < 2)
					pnty = 2;
				detects(VK_DOWN, 'S') {
					pnty += 2;
					pntx = 1;
					Sleep(30);
				}
				if (pnty > 12)
					pnty = 12;
				detects(VK_LEFT, 'A') {
					pntx--;
					while (keyboard[pnty][--pntx] != '|')
						;
					pntx++;
					Sleep(30);
				}
				if (pntx < 1)
					pntx = 1;
				detects(VK_RIGHT, 'D') {
					while (keyboard[pnty][++pntx] != '|')
						;
					pntx++;
					Sleep(30);
				}
				if (pntx > keyboard[1].size() - 4)
					pntx = keyboard[1].size() - 4;
				if (pntx == 8 && pnty == 6) {
					cout << "W:向上走";
				} else if (pntx == 6 && pnty == 8) {
					cout << "A:向左走";
				} else if (pntx == 9 && pnty == 8) {
					cout << "S:向下走";
				} else if (pntx == 12 && pnty == 8) {
					cout << "D:向右走";
				} else if (pntx == 48 && pnty == 8) {
					cout << "↑:向上走";
				} else if (pntx == 45 && pnty == 10) {
					cout << "←:向左走";
				} else if (pntx == 48 && pnty == 10) {
					cout << "↓:向下走";
				} else if (pntx == 51 && pnty == 10) {
					cout << "→:向右走";
				} else if (pntx == 5 && pnty == 6) {
					cout << "Q:丢弃手上物品";
				} else if (pntx == 11 && pnty == 6) {
					cout << "E:使用手上物品";
				} else if (pntx == 14 && pnty == 6) {
					cout << "R:合成物品";
				} else if (pntx == 32 && pnty == 6) {
					cout << "P:与地块交互";
				} else if (pntx == 7 && pnty == 10) {
					cout << "Z:查看喂鸡百科";
				} else if (pntx == 45 && pnty == 12) {
					cout << "按下空格回到游戏";
					detect(VK_SPACE) {
						anicls();
						return;
					}
				} else if (pntx == 4 && pnty == 4) {
					cout << "1:指向背包的第1个物品";
				} else if (pntx == 7 && pnty == 4) {
					cout << "2:指向背包的第2个物品";
				} else if (pntx == 10 && pnty == 4) {
					cout << "3:指向背包的第3个物品";
				} else if (pntx == 13 && pnty == 4) {
					cout << "4:指向背包的第4个物品";
				} else if (pntx == 16 && pnty == 4) {
					cout << "5:指向背包的第5个物品";
				} else if (pntx == 19 && pnty == 4) {
					cout << "6:指向背包的第6个物品";
				} else if (pntx == 22 && pnty == 4) {
					cout << "7:指向背包的第7个物品";
				} else if (pntx == 25 && pnty == 4) {
					cout << "8:指向背包的第8个物品";
				} else if (pntx == 28 && pnty == 4) {
					cout << "9:指向背包的第9个物品";
				} else if (pntx == 31 && pnty == 4) {
					cout << "0:指向背包的第10个物品";
				} else if (pntx == 1 && pnty == 1) {
					cout << "Escape:打开菜单";
				}
				
				else {
					cout << "按WASD或方向键选择要查看的键位";
				}
				cout << "                                            ";
			}
		}
		detect('W') {
			anicls();
			setpos(0, 0);
			cout << "空:      背包的这个位置空着，可以放一个lihaoqian，lihaoqian能不能吃问他。\n";
			cout << "小石子:  无关紧要，不能吃\n";
			cout << "横木：   超级重，不能吃\n";
			cout << "酸果：   和小石子一样重，能吃，吃了回复20点体力。（终于有一个能吃的了）\n";
			cout << "石斧：   使用后造成的伤害+3\n";
			cout << "木块：   可以放置的阻挡通行的木头\n";
			cout << "按 ESC 回到游戏。\n";
			
			while (true) {
				detect(VK_ESCAPE) {
					anicls();
					return;
				}
			}
		}
		
		detect('T'){
			anicls();
			setpos(0, 0);
			
			for(string i:WElist){
				cout<<WEname[i]<<"："<<WEintro[i]<<"\n\t"<<WEeffect[i]<<endl;
			}
			system("pause");
			anicls();
			return;
		}
		
		detect('U') { return; }
		detect('Y') { banquan(); return;}
		// TODO
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
	intable['T'] = 1;
	intable['o'] = 1;
	intable['w'] = 1;
	message = "";
	printf("搭建碰撞箱\n");
	wall['=']=1;
	printf("定义配方\n");
	ings.push_back(ing(1, 1, 1, 1, 3, 1, 0, 0, 0, 5));
	ings.push_back(ing(1, 2, 1, 0, 0, 0, 0, 0, 0, 6, 3));
	ings.push_back(ing(1, 2, 1, 0, 0, 0, 0, 0, 0, 7, 4));
	printf("吃石化其他变量\n");
	memset(hand, 0, sizeof hand);
	handind = 1;
	handmax = 10;
	handsize = 0;
	alive = 1;
	speed = 1;
	force = 500;
	posx = 2500;
	posy = 2500;
	//    posx = 0;
	//    posy = 0;
	showed = false;
	printf("初始化地图\n");
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
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
					copwd[i][j] = 'w';
			}
		}
		if (i % 100 == 0)
			cout << '#';
	}
	printf("\n生成可交互的地块\n");
	for (int i = uborder + 1; i < dborder; i++) {
		for (int j = lborder + 1; j < rborder; j++) {
			if (copwd[i][j])
				world[i][j] = copwd[i][j];
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
		setpos(0, 0);
		scta(0x85);
		printf("[坐标:<%d,%d>] ", posx, posy);
		scta(0x8A);
		printf("[体力:%d] ", force);
		
		scta(0x8F);
		if ((showed -= 0.05) > 0) {
			cout << message << "\n";
		} else {
			scta(0x0);
			cout << "                        "
			<< "\n";
		}
		scta(0xF);
		for (int i = posy - 10; i <= posy + 10; i++) {
			for (int j = posx - 25; j <= posx + 25; j++) {
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
		setpos(0, 27);
		printf("背包容量:%d/%d", handsize, handmax);
		setpos(1, 27);
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
		
		if (hand[handind] == 5) {
			damage=4;
			message = "持有石斧";
			showed = true;
		}else{
			damage=1;
			// message = "赤手空拳";
			// showed = true;
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
			int pointer = 0;
			while (1) {
				setpos(0, 0);
				scta(0xF);
				cout << "游戏已暂停\n";
				scta(pointer == 0 ? 0x6 : 0xF);
				cout << "* 继续游戏\n";
				scta(pointer == 1 ? 0x6 : 0xF);
				cout << "* 查看喂鸡百科（游戏中按Z）\n";
				scta(pointer == 2 ? 0x6 : 0xF);
				cout << "* I AK IOI.\n";
				scta(pointer == 3 ? 0x6 : 0xF);
				cout << "* 孔子不玩了，老子也不玩了\n";
				scta(0xF);
				cout << "*使用↑↓选择，Enter以确定";
				detect(VK_DOWN) pointer = (pointer + 5) % 4, Sleep(100);
				detect(VK_UP) pointer = (pointer + 3) % 4, Sleep(100);
				detect(VK_RETURN) {
					if (pointer == 0) {
						break;
					}
					if (pointer == 1) {
						weijipedia();
						anicls();
					}
					if (pointer == 2) {
						// I AK IOI.
					}
					if (pointer == 3) {
						exit(0);
					}
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
					scta(0xA);
					printf("        XXX \n");
					printf("       XXXXX\n");
					printf("       XXXXX\n    ");
					scta(0xF6);
					printf("@");
					scta(0x6);
					printf("   ||| \n");
					scta(0xF);
					printf("   /\\   ");
					scta(0x6);
					printf("||| \n");
					scta(0xF);
					printf("   ||  ");
					scta(0x6);
					printf(" ||| \n");
					scta(0xF);
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
		if (world[posy][posx] == '_') {
			if(moved){
				for(unsigned i=0;i<status.size();i++){
					if(status[i].name=="swim"){
						status[i].value++;
						goto addedswim;
					}
				}
				if(1){
					status.push_back({"swim",1});
				}
				addedswim:;
			}
		}else if(moved){
			for(unsigned i=0;i<status.size();i++){
				if(status[i].name=="swim"){
					status.erase(status.begin()+i);
				}
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
	system("title JCerGame");
	system("color 0F");
	int pointer = 0;
	while (1) {
		setpos(0, 0);
		scta(0xF);
		cout << "欢迎来到 JCerGame!\n";
		scta(pointer == 0 ? 0x6 : 0xF);
		cout << "* 开始新游戏\n";
		scta(pointer == 1 ? 0x6 : 0xF);
		cout << "* 翻存档\n";
		scta(pointer == 2 ? 0x6 : 0xF);
		cout << "* 更新日志\n";
		scta(pointer == 3 ? 0x6 : 0xF);
		cout << "* 版权声明\n";
		scta(pointer == 4 ? 0x6 : 0xF);
		cout << "* 我不玩\n";
		scta(0xF);
		cout << "*使用↑↓选择，Enter以确定";
		detect(VK_DOWN) pointer = (pointer + 6) % 5, Sleep(100);
		detect(VK_UP) pointer = (pointer + 4) % 5, Sleep(100);
		detect(VK_RETURN) {
			if (pointer == 0) {
				break;
			}
			if (pointer == 1) {
				//				break;
			}
			if (pointer == 2) {
				anicls();
				setpos(0, 0);
				cout << "ver 0.0.5,12/02/26 11:58\n";
				cout << "* 新功能：放置方块！\n";
				cout << "* 我们有木块和木板！\n";
				cout << "更多版本请查看源代码。\n";
				if ("收起此部分" == "I AK I0I.") {
					cout << "ver 0.0.4,06/12/25 21:35\n";
					cout << "* 新功能：效果！\n";
					cout << "* 我们有水！\n";
					
					cout << "ver 0.0.3,21/07/25 17:24\n";
					cout << "* 更新了暂停菜单。\n";
					cout << "* 修复了一个无足轻重(划掉)重如泰山的bug。\n";
					
					cout << "ver 0.0.2,19/07/25 05:00 p.m.\n";
					cout << "* 更新了物品配方。\n";
					
					cout << "ver 0.0.1,14/07/25 06:01 p.m.\n";
					cout << "* 我们有菜单！\n";
					cout << "* 我们有更新日志！\n";
					cout << "* 我们有SunriseLJY！\n";
				}
				system("pause");
				anicls();
			}
			if (pointer == 3) {
				banquan();
			}
			if (pointer == 4) {
				return 0;
			}
		}
	}
	anicls();
	setpos(0, 0);
	inittheworld();
	The_World();
	return 0;
}
