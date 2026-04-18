// copyleft(c) lihaoqian,LiJunyi
//版权所有，亲全必究
//任何试图盗窃此代码的人会被JC
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
// 请在编译时添加命令"-std=c++11"！！！
#define _GLIBCXX_COMPLEX "Have a nice day."
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
		"|Es|  |F1|F2|F3|F4|F5|F6|F7|F8|F9|F0|F1|F2| |PS|SL|PB|\n",
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
	for (int i = 2; i <= 66; i++) {
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
	system("cls");
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
bool intable[255];    // interact able,It should be map<char,bool>
bool wall[255];       // pass ability, It should be map<char,bool>
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
ofstream out;
ifstream in;
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

//item system
struct slot{
	int item=0,qutt=0;
	int weight(){
		return itemsize[item]*qutt;
	}
	void refresh(){
		if(qutt<=0||item==0){
			qutt=0;
			item=0;
		}
	}
	void wrt(){
		out<<" "<<item<<" "<<qutt<<" ";
	}
	void rid(){
		in>>item>>qutt;
	}
}tpltslt,tempslt,tempslot;
struct vult{
	vector<slot> slots;
	string name="口袋";
	int weight(){
		int totwt=0;
		for(slot sl:slots){
			totwt+=sl.weight();
		}
		return totwt;
	}
	void refresh(){
		for(unsigned i=0;i<slots.size();i++){
			slots[i].refresh();
		}
	}
	void wrt(){
		out<<" "<<name<<" "<<slots.size()<<" ";
		for(unsigned i=0;i<slots.size();i++){
			slots[i].wrt();
		}
	}
	void rid(){
		int x;
		slot y;
		in>>name>>x;
		for(int i=1;i<=x;i++){
			y.rid();
			slots.push_back(y);
		}
	}
}tpltvlt,tempvlt;
struct ivtr{
	slot hand;
	vult hcl;
	slot cp;
	vector<vult> vaults;
	int weight=0;
	void rfwt(){ //refresh weight
		int totwt=hand.weight();
		for(vult vt:vaults){
			totwt+=vt.weight();
		}
		totwt+=hcl.weight();
		totwt+=cp.weight();
		weight=totwt;
	}
	void refresh(){
		for(unsigned i=0;i<vaults.size();i++){
			vaults[i].refresh();
		}
		hand.refresh();
		hcl.refresh();
		cp.refresh();
	}
	void wi(){//write inventory
		out<<endl;
		hand.wrt();
		hcl.wrt();
		cp.wrt();
		out<<" "<<vaults.size()<<" ";
		for(unsigned i=0;i<vaults.size();i++){
			vaults[i].wrt();
		}
	}
	void ri(){
		hand.rid();
		hcl.rid();
		cp.rid();
		int x;
		vult y;
		in>>x;
		for(int i=1;i<=x;i++){
			y.rid();
			vaults.push_back(y);
		}
	}
}inventory;
int ivtrmx; //max weight
bool slotcmp(slot x,slot y){
	return x.item>y.item;
}
void itemsystem(bool showtempvlt=0){
	anicls();
	setpos(0,0);
	int vps=0;
	slot hcl[10],cp;
	ing usingin(0,0,0,0,0,0,0,0,0,0,0);
	char _1='?',_2='?';
	memset(hcl,0,sizeof(hcl));
	while(1){
		setpos(0,0);
		cout<<"上一个容器[,] 目前"<<vps+1<<"号容器-"<<inventory.vaults[vps].name<<" 下一个容器[.]            \n";
		for(int i=0;i<inventory.vaults[vps].slots.size();i++){
			if(_1==char(i+'1')) scta(6);else scta(15);
			cout<<"第"<<i+1<<"个物品槽:             "<<
				itemname[inventory.vaults[vps].slots[i].item]<<"x"<<
				inventory.vaults[vps].slots[i].qutt<<"["<<i+1<<"]            \n";
			detect(char(i+'1')){
				if(_1!=char(i+'1'))
				if(_1!='?') _2=char(i+'1');
				else _1=char(i+'1');
			}
		}
		if(showtempvlt){
			scta(15);
			cout<<"\n地上(退出界面后消失):            \n";
			for(int i=0;i<tempvlt.slots.size();i++){
				if(_1==char(i+'I')) scta(6);else scta(15);
				cout<<"第"<<i+1<<"个物品:            "<<
				itemname[tempvlt.slots[i].item]<<"x"<<
				tempvlt.slots[i].qutt<<"["<<char(i+'I')<<"]            \n";
				detect(char(i+'I')){
					if(_1!=char(i+'I'))
						if(_1!='?') _2=char(i+'I');
						else _1=char(i+'I');
				}
			}
		}
		cout<<endl;
		for(int i=0;i<inventory.hcl.slots.size();i++){
			if(_1==char(i+'X')) scta(6);else scta(15);
			cout<<"合成栏第"<<i+1<<"个物品槽:            "<<
			itemname[inventory.hcl.slots[i].item]<<"x"<<
			inventory.hcl.slots[i].qutt<<"["<<char(i+'X')<<"]            \n";
			detect(char(i+'X')){
				if(_1!=char(i+'X'))
				if(_1!='?') _2=char(i+'X');
				else _1=char(i+'X');
			}
		}
		scta(8);
		cout<<"预估成品："<<itemname[cp.item]<<"x"<<cp.qutt<<"            \n";
		if(_1=='C') scta(6);else scta(15);
		cout<<"成品栏："<<itemname[inventory.cp.item]<<"x"<<inventory.cp.qutt<<"[C]            \n";
		detect('C'){
			if(_1!='C')
			if(_1!='?') _2='C';
			else _1='C';
		}
		if(_1=='H') scta(6);else scta(15);
		cout<<"\n手持物品："<<itemname[inventory.hand.item]<<"x"<<inventory.hand.qutt<<"[H]            \n";
		detect('H'){
			if(_1!='H') 
			if(_1!='?') _2='H';
			else _1='H';
		}
		scta(15);
		
		if(_1=='?') cout<<"按Q退出,按W合成,或按下按键执行操作                        ";
		else        cout<<"按E丢掉,按R撤回,或按下另一个按键执行交换、堆叠操作        ";
		
		if(_1!='?'&&_2!='?'){
			//first, _1->tempslt
			if(_1>='1'&&_1<='9'){
				tempslt.item=inventory.vaults[vps].slots[_1-'1'].item;
				tempslt.qutt=inventory.vaults[vps].slots[_1-'1'].qutt;
			}
			if(_1>='I'&&_1<='M'){
				tempslt.item=tempvlt.slots[_1-'I'].item;
				tempslt.qutt=tempvlt.slots[_1-'I'].qutt;
			}
			if(_1>='X'&&_1<='Z'){
				tempslt.item=inventory.hcl.slots[_1-'X'].item;
				tempslt.qutt=inventory.hcl.slots[_1-'X'].qutt;
			}
			if(_1=='C'){
				tempslt.item=inventory.cp.item;
				tempslt.qutt=inventory.cp.qutt;
			}
			if(_1=='H'){
				tempslt.item=inventory.hand.item;
				tempslt.qutt=inventory.hand.qutt;
			}
			//second, _2->tempslot
			if(_2>='1'&&_2<='9'){
				tempslot.item=inventory.vaults[vps].slots[_2-'1'].item;
				tempslot.qutt=inventory.vaults[vps].slots[_2-'1'].qutt;
			}
			if(_2>='I'&&_2<='M'){
				tempslot.item=tempvlt.slots[_2-'I'].item;
				tempslot.qutt=tempvlt.slots[_2-'I'].qutt;
			}
			if(_2>='X'&&_2<='Z'){
				tempslot.item=inventory.hcl.slots[_2-'X'].item;
				tempslot.qutt=inventory.hcl.slots[_2-'X'].qutt;
			}
			if(_2=='C'){
				tempslot.item=inventory.cp.item;
				tempslot.qutt=inventory.cp.qutt;
			}
			if(_2=='H'){
				tempslot.item=inventory.hand.item;
				tempslot.qutt=inventory.hand.qutt;
			}
			
			//One more thing...
			if(tempslt.item==tempslot.item){
				if(_2>='1'&&_2<='9'){
					inventory.vaults[vps].slots[_2-'1'].qutt+=tempslt.qutt;
				}
				if(_2>='I'&&_2<='M'){
					tempvlt.slots[_2-'I'].qutt+=tempslt.qutt;
				}
				if(_2>='X'&&_2<='Z'){
					inventory.hcl.slots[_2-'X'].qutt+=tempslt.qutt;
				}
				if(_2=='C'){
					inventory.cp.qutt+=tempslt.qutt;
				}
				if(_2=='H'){
					inventory.hand.qutt+=tempslt.qutt;
				}
				
				if(_1>='1'&&_1<='9'){
					inventory.vaults[vps].slots[_1-'1'].item=0;
				}
				if(_1>='I'&&_1<='M'){
					tempvlt.slots[_1-'I'].item=0;
				}
				if(_1>='X'&&_1<='Z'){
					inventory.hcl.slots[_1-'X'].item=0;
				}
				if(_1=='C'){
					inventory.cp.item=0;
				}
				if(_1=='H'){
					inventory.hand.item=0;
				}
				inventory.refresh();
				goto testforhecheng;
			}
			
			//third, tempslot->_1
			if(_1>='1'&&_1<='9'){
				inventory.vaults[vps].slots[_1-'1'].item=tempslot.item;
				inventory.vaults[vps].slots[_1-'1'].qutt=tempslot.qutt;
			}
			if(_1>='I'&&_1<='M'){
				tempvlt.slots[_1-'I'].item=tempslot.item;
				tempvlt.slots[_1-'I'].qutt=tempslot.qutt;
			}
			if(_1>='X'&&_1<='Z'){
				inventory.hcl.slots[_1-'X'].item=tempslot.item;
				inventory.hcl.slots[_1-'X'].qutt=tempslot.qutt;
			}
			if(_1=='C'){
				inventory.cp.item=tempslot.item;
				inventory.cp.qutt=tempslot.qutt;
			}
			if(_1=='H'){
				inventory.hand.item=tempslot.item;
				inventory.hand.qutt=tempslot.qutt;
			}
			//last, tempslt->_2
			if(_2>='1'&&_2<='9'){
				inventory.vaults[vps].slots[_2-'1'].item=tempslt.item;
				inventory.vaults[vps].slots[_2-'1'].qutt=tempslt.qutt;
			}
			if(_2>='I'&&_2<='M'){
				tempvlt.slots[_2-'I'].item=tempslt.item;
				tempvlt.slots[_2-'I'].qutt=tempslt.qutt;
			}
			if(_2>='X'&&_2<='Z'){
				inventory.hcl.slots[_2-'X'].item=tempslt.item;
				inventory.hcl.slots[_2-'X'].qutt=tempslt.qutt;
			}
			if(_2=='C'){
				inventory.cp.item=tempslt.item;
				inventory.cp.qutt=tempslt.qutt;
			}
			if(_2=='H'){
				inventory.hand.item=tempslt.item;
				inventory.hand.qutt=tempslt.qutt;
			}
			while(press(_2));
			_1='?';
			_2='?';
			
			goto testforhecheng;
		}
		
		if(_1!='?'&&press('E')){
			if(_1>='1'&&_1<='9'){
				inventory.vaults[vps].slots[_1-'1'].item=0;
			}
			if(_1>='I'&&_1<='M'){
				tempvlt.slots[_1-'I'].item=0;
			}
			if(_1>='X'&&_1<='Z'){
				inventory.hcl.slots[_1-'X'].item=0;
			}
			if(_1=='C'){
				inventory.cp.item=0;
			}
			if(_1=='H'){
				inventory.hand.item=0;
			}
			inventory.refresh();
			_1='?';
			goto testforhecheng;
		}
		
		if(0){
			testforhecheng:;
			inventory.refresh();
			hcl[1]=inventory.hcl.slots[0];
			hcl[2]=inventory.hcl.slots[1];
			hcl[3]=inventory.hcl.slots[2];
			sort(hcl+1,hcl+1+3,slotcmp);
			for(ing in:ings){
				if(!in.unlock) continue;
				if(in.item1!=hcl[1].item||in.num1>hcl[1].qutt) continue;else;
				if(in.have2)
				if(in.item2!=hcl[2].item||in.num2>hcl[2].qutt) continue;else;
				else if(hcl[2].item!=0) continue;
				if(in.have3)
				if(in.item3!=hcl[2].item||in.num3>hcl[3].qutt) continue;else;
				else if(hcl[3].item!=0) continue;
				cp.item=in.dest;
				cp.qutt=in.num;
				usingin=in;
				goto updatedchengping;
			}
			cp.item=0;
			cp.qutt=0;
			usingin=ing(0,0,0,0,0,0,0,0,0,0,0);
			updatedchengping:;
		}
		
		detect('W'){
			inventory.refresh();
			if(inventory.cp.item==0||inventory.cp.item==cp.item){
				for(int i=0;i<=2;i++){
					if(inventory.hcl.slots[i].item==usingin.item1){
						inventory.hcl.slots[i].qutt-=usingin.num1;
					}else if(inventory.hcl.slots[i].item==usingin.item2){
						if(usingin.have2){
							inventory.hcl.slots[i].qutt-=usingin.num2;
						}
					}else if(inventory.hcl.slots[i].item==usingin.item3){
						if(usingin.have3){
							inventory.hcl.slots[i].qutt-=usingin.num3;
						}
					}
				}
				if(inventory.cp.item==0) inventory.cp=cp;
				else inventory.cp.qutt+=cp.qutt;
				while(press('W'));
				goto testforhecheng;
			}
		}
		if(_1!='?'&&press('R')) _1='?';
		
		detect('Q'){
			break;
		}
		detect(','){
			vps=(vps-1+vps)%inventory.vaults.size();
			Sleep(100);
		}
		detect('.'){
			vps=(vps+1)%inventory.vaults.size();
			Sleep(100);
		}
	}
}
void takeanitem(int item,int qutt=1){
	tempvlt=tpltvlt;
	tempvlt.name="地上(退出界面后消失)";
	tempvlt.slots.push_back(tpltslt);
	tempvlt.slots[0].item=item;
	tempvlt.slots[0].qutt=qutt;
	itemsystem(1);
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
					cout << "Q:丢弃手上物品(已移除)";
				} else if (pntx == 11 && pnty == 6) {
					cout << "E:使用手上物品";
				} else if (pntx == 14 && pnty == 6) {
					cout << "R:物品系统(合成物品)";
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
			cout << "空:      背包的这个位置空着，可以放一个lihaoqian，lihaoqian能不能吃问他。\n";//Oh LJY
			cout << "小石子:  无关紧要，不能吃\n";
			cout << "横木：   超级重，不能吃\n";
			cout << "酸果：   和小石子一样重，能吃，吃了回复20点体力。（终于有一个能吃的了）\n";
			cout << "石斧：   拿在手上造成的伤害+3\n";
			cout << "木块：   可以放置的  阻挡通行的木头\n";
			cout << "木板：   可以放置的不阻挡通行的木头\n";
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
void build(char c,int returns){
	//fixme
	system("cls");
	cout<<"在键盘上选择摆放的位置\n";
	cout<<"7 8 9\n";
	cout<<"4 @ 6\n";
	cout<<"1 2 3\n";
	cout<<"0(取消)";
	while(1){
		detects(VK_NUMPAD0,'0'){
			takeanitem(returns);
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


void inittheworld(bool reset=1) {
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
	ings.push_back(ing(1, 3, 1, 1, 1, 1, 0, 0, 0, 5));
	ings.push_back(ing(1, 3, 1, 1, 2, 1, 0, 0, 0, 6, 3));
	ings.push_back(ing(1, 2, 1, 0, 0, 0, 0, 0, 0, 7, 4));
	printf("吃石化其他变量\n");
	if(reset){
		inventory.vaults.clear();
		tpltvlt.slots.push_back(tpltslt);
		tpltvlt.slots.push_back(tpltslt);
		tpltvlt.slots.push_back(tpltslt);
		inventory.vaults.push_back(tpltvlt);
		tpltvlt.slots.clear();
		inventory.hand=tpltslt;
		inventory.hcl.name="合成栏";
		inventory.hcl.slots.push_back(tpltslt);
		inventory.hcl.slots.push_back(tpltslt);
		inventory.hcl.slots.push_back(tpltslt);
		posx = 2500;
		posy = 2500;
	}
	inventory.rfwt();
	alive = 1;
	speed = 1;
	force = 500;
	//    posx = 0;
	//    posy = 0;
	showed = false;
	if(!reset) goto heyhello;
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
	heyhello:;
	printf("设立边界\n");
	for (int i = uborder; i <= dborder; i++) world[i][lborder] = '#';
	for (int i = uborder; i <= dborder; i++) world[i][rborder] = '#';
	for (int j = lborder; j <= rborder; j++) world[uborder][j] = '#';
	for (int j = lborder; j <= rborder; j++) world[dborder][j] = '#';
	
	printf("启动！\n");
	
	//devmode
//	inventory.vaults[0].slots[0].item=1;
//	inventory.vaults[0].slots[0].qutt=1;
//	inventory.vaults[0].slots[1].item=2;
//	inventory.vaults[0].slots[1].qutt=2;
//	inventory.vaults[0].slots[2].item=3;
//	inventory.vaults[0].slots[2].qutt=3;
	
	system("cls");
}

void savetheworld(){
	anicls();
	setpos(0,0);
	cout<<"为您的存档命名:";
	string name;
	cin>>name;
	cout<<"正在保存";
	out.open((name+".jc6").c_str());
	for(int i=uborder;i<=dborder;i++){
		for(int j=lborder;j<=rborder;j++){
			out<<world[i][j];
		}out<<endl;
		if(i%100==0) cout<<'.';
	}
	inventory.wi();
	out<<" "<<posx<<" "<<posy;
	out.close();
	cout<<endl<<"保存完毕。";
	Sleep(100);
	anicls();
	setpos(0,0);
}

void loadtheworld(){
	anicls();
	setpos(0,0);
	cout<<"拖入存档(.jc6)文件:";
	string name;
	cin>>name;
	cout<<"正在导入";
	in.open(name.c_str());
	for(int i=uborder;i<=dborder;i++){
		for(int j=lborder;j<=rborder;j++){
			in>>world[i][j];
		}
		if(i%100==0) cout<<'.';
	}
	inventory.ri();
	in.close();
	in>>posx>>posy;
	cout<<endl<<"加载完毕。";
	Sleep(100);
	anicls();
	setpos(0,0);
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
		scta(0x8E);
		for(effect i:status){
			cout<<WEname[i.name]<<i.value<<" ";
		}
		scta(0xF);
		cout<<"                                                                       ";
		cout<<"\n手持物品："<<itemname[inventory.hand.item]<<"x"<<inventory.hand.qutt<<"            \n";
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
		
		detect('R'){//item system
			itemsystem();
		}
		
		if (inventory.hand.item==5){
			damage=4;
			if(showed==0){
				message = "持有石斧";
				showed = true;
			}
		}else{
			damage=1;
		}
		if(press('E')&&inventory.hand.item==6){
			inventory.hand.qutt--;
			inventory.refresh();
			build('=',6);
		}
		if(press('E')&&inventory.hand.item==7){
			inventory.hand.qutt--;
			inventory.refresh();
			build('-',7);
		}
		
//		detect('R') {
//			bool nxtok=0;
//			for (ing it : ings) {
//				bool canmade = it.unlock;
//				if (!have(it.item1, it.num1))
//					canmade = 0;
//				if (it.have2)
//					if (!have(it.item2, it.num2))
//						canmade = 0;
//				if (it.have3)
//					if (!have(it.item3, it.num3))
//						canmade = 0;
//				if(nxtok&&!canmade) continue;
//				else nxtok=0;
//				anicls();
//				setpos(0, 0);
//				cout << "目前查看" << itemname[it.dest] << "的配方\n";
//				if (it.unlock) {
//					cout << "你需要：\n";
//					cout << itemname[it.item1] << "x" << it.num1 << "\n";
//					if (it.have2)
//						cout << itemname[it.item2] << "x" << it.num2 << "\n";
//					if (it.have3)
//						cout << itemname[it.item3] << "x" << it.num3 << "\n";
//					cout<<"一次合成"<<it.num<<"个\n";
//				} else {
//					cout << "你没解锁所以看不到，很正常，对吧？。\n";
//				}
//				while (1) {
//					if (!have(it.item1, it.num1))
//						canmade = 0;
//					if (it.have2)
//						if (!have(it.item2, it.num2))
//							canmade = 0;
//					if (it.have3)
//						if (!have(it.item3, it.num3))
//							canmade = 0;
//					setpos(5, 0);
//					if (canmade)
//						cout << "[制作(P)] ";
//					cout << "[下一个(Q)] [退出(W)] [下一个可以合成的(E)]                      ";
//					detect('P') {
//						if (canmade) {
//							throwoutitem(it.item1, it.num1);
//							if (it.have2)
//								throwoutitem(it.item2, it.num2);
//							if (it.have3)
//								throwoutitem(it.item3, it.num3);
//							for(int i=1;i<=it.num;i++) take(it.dest);
//						}
//					}
//					detect('Q') break;
//					detect('W') goto ohmygod;
//					detect('E'){
//						nxtok=1;
//						break;
//					}
//				}
//			}
//		}
//		ohmygod:;
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
				cout << "* 保存\n";
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
						savetheworld();
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
				takeanitem(2);
				world[posy][posx] = ',';
			}
		}
		if (world[posy][posx] == 'o') {
			detect('P') {
				takeanitem(1);
				world[posy][posx] = ',';
			}
		}
		if (world[posy][posx] == 'w') {
			detect('P') {
				srand(rand());
				takeanitem(rand() % 2 + 3);
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
				loadtheworld();
				inittheworld(0);
				The_World();
				return 0;
			}
			if (pointer == 2) {
				anicls();
				setpos(0, 0);
				cout << "ver 0.0.6 “铲屎更新 Pt.1”,06/04/26\n";
				cout << "* 更新了物品系统。\n";
				cout << "* 更新了合成系统。\n";
				cout << "* 更新了存档系统。\n";
				cout << "更多版本请查看源代码。\n";
				if ("收起此部分" == "I AK I0I.") {
					cout << "ver 0.0.5,12/02/26 11:58\n";
					cout << "* 新功能：放置方块！\n";
					cout << "* 我们有木块和木板！\n";
					cout << "更多版本请查看源代码。\n";
					
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

