// Copyleft(c) lihaoqian,LiJunyi
// 版权所有，亲全必究
// 任何试图盗窃此代码的人会被线上/线下真实，并被JC
// luyiming将会永远被钉在某处的耻辱柱上(by copying benghuai·dongbeitiedao)
// 请在编译时添加命令"-std=c++11"！！！
// extern的作用是让部分可以收起
#define bigver 0
#define midver 0
#define smaver 8
#define snpsot 3
extern "C++"{//头文件
#define _GLIBCXX_COMPLEX "Have a nice day."
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <wincon.h>
#include <time.h>
#include <direct.h>
}
extern "C++"{//其他预处理
	using namespace std;
// For faster,we will do optimize.
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#if __cplusplus < 201103L
#error 主菜单->工具[T]->编译选项[C]->代码生成/优化->代码生成->语言标准(-std)->ISO C++11
#endif
#define press(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define lborder 100
#define uborder 100
#define rborder 900
#define dborder 900
#define detect(VK_NONAME) if (press(VK_NONAME))
#define detects(VK_NONAME, int) if (press(VK_NONAME) || press(int))
#define time(int) ((chrono::steady_clock::now().time_since_epoch().count()))
}
extern "C++"{//更新日志
	struct version{
		int y,m,d;
		string detail="";
		vector<string> intro;
		void init(int yy,int mm,int dd,string dt){
			y=yy;
			m=mm;
			d=dd;
			detail=dt;
		}
		void addintro(string intr){
			intro.push_back(intr);
		}
		void print(int _1,int _2,int _3,int _4){
			cout<<"ver "<<_1<<"."<<_2<<"."<<_3<<(_4?"."+to_string(_4):"")<<" "<<detail<<endl;
			if(!y){
				cout<<"没有这个版本！！\n";
				return;
			}
			cout<<"发布时间："<<y<<"/"<<(m<10?"0":"")<<m<<"/"<<(d<10?"0":"")<<d<<endl;
			for(string i:intro){
				cout<<"* "<<i<<endl;
			}
		}
	};
	version versions[30][30][30][300]; 
	void versioninit(){
		versions[0][0][1][0].init(25,7,14,"");
		versions[0][0][1][0].addintro("我们有菜单！");
		versions[0][0][1][0].addintro("我们有更新日志！");
		versions[0][0][1][0].addintro("我们有SunriseLJY！");
		versions[0][0][1][0].addintro("该版本的唯一近似链接已失效：sdfzoj.top/submission/125394");
		versions[0][0][2][0].init(25,7,21,"");
		versions[0][0][2][0].addintro("更新了物品配方。");
		versions[0][0][2][0].addintro("该版本的唯一近似链接已失效：sdfzoj.top/submission/128737");
		versions[0][0][3][0].init(25,7,21,"");
		versions[0][0][3][0].addintro("更新了暂停菜单。");
		versions[0][0][3][0].addintro("修复了一个无足轻重(划掉)重如泰山的bug。");
		versions[0][0][3][0].addintro("该版本的唯一近似链接已失效：sdfzoj.top/submission/128934");
		versions[0][0][4][0].init(25,12,6,"");
		versions[0][0][4][0].addintro("新功能：效果！");
		versions[0][0][4][0].addintro("我们有水！");
		versions[0][0][5][0].init(26,2,12,"");
		versions[0][0][5][0].addintro("新功能：放置方块！");
		versions[0][0][5][0].addintro("我们有木块和木板！");
		versions[0][0][6][0].init(26,4,6,"“铲屎更新 Pt.1”");
		versions[0][0][6][0].addintro("更新了物品系统。");
		versions[0][0][6][0].addintro("更新了合成系统。");
		versions[0][0][6][0].addintro("更新了存档系统。");
		versions[0][0][6][1].init(26,4,18,"");
		versions[0][0][6][1].addintro("更新了喂鸡百科中的物品介绍。");
		versions[0][0][6][2].init(26,5,30,"");
		versions[0][0][6][2].addintro("美化了代码。");
		versions[0][0][6][2].addintro("更新了版本的记录方式。");
		versions[0][0][6][3].init(26,6,6,"");
		versions[0][0][6][3].addintro("增加了拆开物品的功能。");
		versions[0][0][7][0].init(26,7,9,"“铲屎更新 Pt.2”");
		versions[0][0][7][0].addintro("加入了实体。");
		versions[0][0][7][0].addintro("目前的实体类型：牛、猫（这就是为什么它叫做铲屎更新）");
		versions[0][0][7][0].addintro("新物品：生牛肉，毛线");
		versions[0][0][7][1].init(26,7,11,"");
		versions[0][0][7][1].addintro("你现在可以食用生牛肉了。");
		versions[0][0][7][1].addintro("对luyiming的无耻盗窃行为进行了强烈谴责。");
		versions[0][0][7][1].addintro("加入了血条。");
		versions[0][0][7][2].init(26,7,11,"普罗米修斯更新");
		versions[0][0][7][2].addintro("加入了石炉。");
		versions[0][0][7][2].addintro("加入了熟牛肉。");
		versions[0][0][7][2].addintro("显示了血条。");
		versions[0][0][7][3].init(26,7,14,"一周年更新");
		versions[0][0][7][3].addintro("修复了Bug。");
		versions[0][0][7][3].addintro("加入了生物的喂鸡百科内容。");
		versions[0][0][7][3].addintro("使游戏更有一周年氛围。");
		versions[0][0][8][0].init(26,7,14,"图文声象更新 Pt.“图”");
		versions[0][0][8][0].addintro("修复了Bug。");
		versions[0][0][8][0].addintro("更新了菜单。");
		versions[0][0][8][0].addintro("更新了暂停菜单。");
		versions[0][0][8][0].addintro("添加了入场动画。");
		versions[0][0][8][0].addintro("使游戏更没有一周年氛围。");
		versions[0][0][8][1].init(26,7,16,"图文声象更新 Pt.“文”");
		versions[0][0][8][1].addintro("修复了Bug。");
		versions[0][0][8][1].addintro("修复了存取存档无法正常使用的Bug。");
		versions[0][0][8][1].addintro("加入了C11的兼容性修复。");
		versions[0][0][8][1].addintro("更新了简介（原版权声明）。");
		versions[0][0][8][1].addintro("新功能：设置。");
		versions[0][0][8][1].addintro("新功能：存档列表。");
		versions[0][0][8][1].addintro("更改了菜单（和暂停菜单）的内容。");
		versions[0][0][8][1].addintro("真够累人的，不是吗？（我甚至想把这次更新分成两个部分）");
		versions[0][0][8][2].init(26,7,18,"神谕更新");
		versions[0][0][8][2].addintro("修复了Bug。");
		versions[0][0][8][2].addintro("新功能：成就。");
		versions[0][0][8][3].init(26,7,23,"");
		versions[0][0][8][3].addintro("修复了Bug。");
		versions[0][0][8][3].addintro("加入了皮革、口袋。");
		versions[0][0][8][3].addintro("更改了存档的格式。");
//		versions[0][0][8][2].init(26,67,67,"图文声象更新 Pt.“声”");
//		versions[0][0][8][2].addintro("修复了Bug。");
//		versions[0][0][8][2].addintro("加入了调音界面。");
//		versions[0][0][8][2].addintro("加入了五首音乐：");
//		versions[0][0][8][2].addintro("Batty McFaddin - Kevin MacLeod");
//		versions[0][0][8][2].addintro("Doh De Doh - Kevin MacLeod");
//		versions[0][0][8][2].addintro("Thatched Villagers - Kevin MacLeod");
//		versions[0][0][8][2].addintro("The Builders - Kevin MacLeod");
//		versions[0][0][8][2].addintro("A Very Brady Special - Kevin MacLeod");
	}
	void showversion(){
		int _1=bigver,_2=midver,_3=smaver,_4=snpsot;
		changedshowedversion:
		system("cls");
		versions[_1][_2][_3][_4].print(_1,_2,_3,_4);
		cout<<"按1增加大版本，按2增加版本，按3增加小版本，按4增加快照，按5切换下一个版本\n";
		cout<<"按Shift改为减少/上一个,按Q退出\n";
		while(1){
			if(press(VK_SHIFT)){
				detect('1') _1--;
				detect('2') _2--;
				detect('3') _3--;
				detect('4') _4--;
				_1=max(_1,0);
				_2=max(_2,0);
				_3=max(_3,0);
				_4=max(_4,0);
				detect('5'){
					int code=_1*270000+_2*9000+_3*300+_4;
					_1=_2=_3=_4=0;
					while(code--){
						int kode=code;
						_4=code%300;
						code/=300;
						_3=code%30;
						code/=30;
						_2=code%30;
						code/=30;
						_1=code;
						if(versions[_1][_2][_3][_4].y) break;
						code=kode;
					}
					if(code==-1) _1=bigver,_2=midver,_3=smaver,_4=snpsot;
				}
				Sleep(100);
				goto changedshowedversion;
			}
			detect('1') _1++;
			detect('2') _2++;
			detect('3') _3++;
			detect('4') _4++;
			detect('5'){
				_4++;
				if(!versions[_1][_2][_3][_4].y){
					_4=0;_3++;
					if(!versions[_1][_2][_3][_4].y){
						_3=0;_2++;
						if(!versions[_1][_2][_3][_4].y){
							_2=0;_1++;
							if(!versions[_1][_2][_3][_4].y){
								_1=_2=_4=0;_3=1;
							}
						}
					}
				}
			}
			detect('Q') break;
			Sleep(100);
			goto changedshowedversion;
		}
	}
}
extern "C++"{//喂鸡百科预处理
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
	map<int,string> WIintro;
	map<int,string> WIusage;
	map<int,string> WIsourc;
	int WIcount;
	map<char,string> WMname;
	map<char,string> WMintro;
	vector<char> WMlist;
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
		WBname['O'] = "石炉";
		WBintro['O'] = "你知道吗？三块石头（其实两块）就可以生火了……";
		WBlist.push_back('.');
		WBlist.push_back(',');
		WBlist.push_back(';');
		WBlist.push_back('T');
		WBlist.push_back('o');
		WBlist.push_back('w');
		WBlist.push_back('_');
		WBlist.push_back('=');
		WBlist.push_back('-');
		WBlist.push_back('O');
		WEname["swim"]="涉水";
		WEintro["swim"]="进入水源时获得，每在水中移动一次，效果+1，直到离开";
		WEeffect["swim"]="移动时，额外失去 X的立方 点体力，x>4时溺亡";
		WElist.push_back("swim");
		WIintro[0]="背包的这个位置空着，可以放一个lihaoqian，lihaoqian能不能吃问他。";//Oh LJY
		WIusage[0]="联系lihaoqian来更改这里的用途。";
		WIsourc[0]="你有一背包的空气，不是吗？";
		WIintro[1]="无关紧要，不能吃";
		WIusage[1]="合成物品";
		WIsourc[1]="在泥土或草坪上可以捡到";
		WIintro[2]="超级重，不能吃";
		WIusage[2]="合成物品";
		WIsourc[2]="在草坪或草丛上砍树获得";
		WIintro[3]="a.k.a. 林昆";
		WIusage[3]="合成物品";
		WIsourc[3]="在草坪或草丛上采摘灌木丛获得";
		WIintro[4]="和小石子一样重，能吃，吃了回复20点体力。";
		WIusage[4]="食用恢复体力";
		WIsourc[4]="在草坪或草丛上采摘灌木丛获得";
		WIintro[5]="夏姬霸砍!!";
		WIusage[5]="拿在手上造成的伤害+3";
		WIsourc[5]="合成获得";
		WIintro[6]="可以放置的  阻挡通行的木头";
		WIusage[6]="放置木块";
		WIsourc[6]="合成获得";
		WIintro[7]="可以放置的不阻挡通行的木头";
		WIusage[7]="放置木板";
		WIsourc[7]="合成获得";
		WIintro[8]="生的牛肉";
		WIusage[8]="吃（但是没熟）";
		WIsourc[8]="杀死牛获得";
		WIintro[9]="字符串（？）";
		WIusage[9]="合成物品";
		WIsourc[9]="杀死猫获得";
		WIintro[10]="熟的牛肉";
		WIusage[10]="吃（熟辣）";
		WIsourc[10]="烤制生牛肉获得";
		WIintro[11]="And he sacrificed...";
		WIusage[11]="放置石炉";
		WIsourc[11]="合成获得";
		WIintro[12]="牛皮";
		WIusage[12]="合成物品";
		WIsourc[12]="杀死牛获得";
		WIintro[13]="大僵 Pocket 3";
		WIusage[13]="增加背包物品槽";
		WIsourc[13]="合成获得";
		WIcount=13;
		WMname['V'] = "牛";
		WMintro['V'] = "字符画的牛太大，这里放不下，所以没有介绍，";
		WMlist.push_back('V');
		WMname['Q'] = "猫";
		WMintro['Q'] = "我们会在不久的二周年增加撸猫功能……";
		WMlist.push_back('Q');
	}
}  // WeijiPedia
extern "C++"{//设置预处理
	bool raisecolor=1;
	bool samsara=0;
	bool clsanimation=1;
}
extern "C++"{//成就预处理
	map<string,string> achname;
	map<string,string> achintro;
	map<string,bool> achieved;
	vector<string> achievements;
	int achicnt=0;
	int justfinished;
	void achinit(){
		achname               ["studyToWalk"]="蹒跚学步";
		achintro              ["studyToWalk"]="使用WASD或方向键移动";
		achievements.push_back("studyToWalk");
		achname               ["checkout"]="检查装备";
		achintro              ["checkout"]="按下R进入物品系统";
		achievements.push_back("checkout");
		achname               ["deepSeek"]="深度求索";
		achintro              ["deepSeek"]="在灌木丛'w'上按下P，获得酸果或树枝";
		achievements.push_back("deepSeek");
		achname               ["emeraldLike"]="打水漂时间";
		achintro              ["emeraldLike"]="在小石头'o'上按下P，获得小石子";
		achievements.push_back("emeraldLike");
		achname               ["handwork"]="手工业";
		achintro              ["handwork"]="将树枝和小石子放入合成栏，并合成出石斧";
		achievements.push_back("handwork");
		achname               ["informationTechnology"]="信息科技";
		achintro              ["informationTechnology"]="按下Z或Esc，进入喂鸡百科";
		achievements.push_back("informationTechnology");
		achname               ["deletion"]="斯大林的名单";
		achintro              ["deletion"]="把石斧放在手上，靠近一只生物并杀死";
		achievements.push_back("deletion");
		achname               ["cooking"]="状态火热";
		achintro              ["cooking"]="使用三个小石子合成石炉，并按下E放下";
		achievements.push_back("cooking");
		achname               ["wellDone"]="美拉德反应";
		achintro              ["wellDone"]="烹饪生牛肉并拿在手上，按下E食用";
		achievements.push_back("wellDone");
		achname               ["theHomeDepot"]="家得宝";
		achintro              ["theHomeDepot"]="使用横木(和树枝)合成木板或木块";
		achievements.push_back("theHomeDepot");
		achname               ["pocketVersion"]="口袋版";
		achintro              ["pocketVersion"]="使用皮革和毛线合成口袋并按E装备";
		achievements.push_back("pocketVersion");
		achname               ["waitingForUpdate"]="等待更新";
		achintro              ["waitingForUpdate"]="当然，一时半会儿更新不了";
		achievements.push_back("waitingForUpdate");
		achname               ["JCerGame"]="JCerGame";
		achintro              ["JCerGame"]="你被JC了";
		achievements.push_back("JCerGame");
	}
	void achieve(string s){
		if(s==achievements[achicnt]&&!achieved[s]){
			achieved[s]=1;
			justfinished=30;
		}
	}
}
extern "C++"{//有用？的函数
	int main();
	int ti(float a) { return ((int)(a * 10 + 5)) / 10; }
	void setpos(float x, float y) {
		COORD pos;
		pos.X = ti(y * 4) / 2;
		pos.Y = ti(x);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	
	void scta(int x) {
		if(raisecolor||x==0||x==7||x==8||x==15) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  // set console color
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	
	void anicls() {
		if(clsanimation==0){
			system("cls");
			Sleep(200);
			return;
		}
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
	void banquan() {
		anicls();
		setpos(0, 0);
		cout << "             ━┳━┏━━┏━━┏━┓┏━━┏━┓┏┳┓┏━━\n";
		cout << "               ┃  ┃    ┣━━┣┳┛┃  ┓┣━┫┃┃┃┣━━\n";
		cout << "             ━┛  ┗━━┗━━┃┗━┗━┛┃  ┃┃┃┃┗━━\n\n";
		cout << "《JCerGame》是由 ";
		scta(0x9c0f);
		cout<<"JCer";
		scta(0xf);
		cout<<" Lihaoqian & LiJunyi制作发行的一款开放世界冒险游戏，于1939年1月底立项，原初测试于1945年6月21日开启，再临测试于1967年3月19日开启，启程测试于1978年6月11日开启，PC版技术性开放测试于1991年9月15日开启，公测于2025年7月14日开启。在数据方面，";
		scta(0x9c0f);
		cout<<"iOS、 ";
		scta(0xf);
		cout<<"PC";
		scta(0x9c0f);
		cout<<" 、Android、鸿蒙平台";
		scta(0xf);
		cout<<"之间的账号数据并不互通，玩家不可以在同一账号下切换设备";
		scta(0x9c0f);
		cout<<" （而且没有账号） ";
		scta(0xf);
		cout<<"。游戏发生在一个被称作“world”的幻想世界，在这里，被“玩家”选中的人将被授予“喂鸡百科”，导引“查资料”之力。玩家将扮演一位名为“@”的神秘角色，在自由的旅行中邂逅 ";
		scta(0x9c0f);
		cout<<"性格各异";
		scta(0xf);
		cout<<" 、能力独特的东西们， ";
		scta(0x9c0f);
		cout<<"和他们一起击败老牧师，找回失散的浮木——同时，逐步发掘“十八码”的真相。";
		scta(0xf);
		cout<<"总结：当我的世界玩\n\n";
		cout << "                   ︵ \n";
		cout << "版权所有 Copyleft (Ｃ) 2025-2026 lihaoqian & LiJunyi 所有右重新服务。\n";
		cout << "                   ︶ \n";
		cout << "此外，使用由该游戏源代码特定函数的，应当在源码中标注。\n";
		cout << "感谢wangbohan,wangzhenglong等人的随机数种子及生物战斗的灵感。\n";
		cout << "Email:lihaoqian12@outlook.com Luogu:veryCoolUsername Acwing:滚木\n";
		cout << "按 ESC 退出。";
		while (true) {
			detect(VK_ESCAPE) {
				anicls();
				return;
			}
		}
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
			detect('Q') { 
				if(samsara){
					system("start jcergame.exe");
				}exit(0);
			}
			Sleep(10);
		}
	}
}
extern "C++"{//结构体
	struct effect{
		string name;
		int value;
	};
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
	struct dropsheet{
		int item1,min1,max1;
		int item2,min2,max2;
		int item3,min3,max3;
		void init(int a,int c,int d,
				  int e,int g,int h,
				  int i,int k,int l){
			item1=a;
			min1=c;
			max1=d;
			item2=e;
			min2=g;
			max2=h;
			item3=i;
			min3=k;
			max3=l;
		}
	};
	struct entity{
		bool be=0;
		char type='V';
		int hp=10;
	};
}
extern "C++"{//变量
	string message;
	string archiveslot,archivename;
	map<char, int> color;
	map<int, string> itemname;
	map<int, int> itemsize;
	map<char, int> eco;   // entity color
	map<int, string> enttname;
	map<char, dropsheet> eds; 
	vector<ing> ings;
	bool intable[255];    // interact able,It should be map<char,bool>
	bool wall[255];       // pass ability, It should be map<char,bool>
	bool bad[255];        // pass ability, It should be map<char,bool>
	int burnresult[255];  // burn ability, It should be map<char,bool>
	bool alive = 1;       // is alive
	int speed = 1;        // delay between movements (ms)
	int force = 114514;   // -1 per movement
	int hp = 50;   
	int cooldown=0;
	vector<effect> status;// status
	double showed;
	int damage = 1;
	int vision = 0x0000;
	char world[1000][1000];
	char copwd[1000][1000];
	entity entty[1000][1000];
//	vult rfitm[5000][5000]; //refer item,但是类型没有定义
	int posx, posy;
	ofstream out;
	ifstream in;
}//item system
extern "C++"{//物品系统
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
		slot(int a=0,int b=0){
			item=a;
			qutt=b;
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
	void itemsystem(bool showtempvlt=0,bool furnace=0){
		anicls();
		setpos(0,0);
		int vps=0;
		slot hcl[10],cp;
		ing usingin(0,0,0,0,0,0,0,0,0,0,0);
		char _1='?',_2='?';
		if(furnace){
			tempvlt=tpltvlt;
			tempvlt.name="地上(退出界面后消失)";
			tempvlt.slots.push_back(tpltslt);
			tempvlt.slots[0].item=0;
			tempvlt.slots[0].qutt=0;
		}
		int burning=0;
		for(int i=0;i<10;i++) hcl[i]=tpltslt;
		while(1){
			setpos(0,0);
			cout<<"上一个容器[←] 目前"<<vps+1<<"号容器-"<<inventory.vaults[vps].name<<" 下一个容器[→]            \n";
			for(unsigned i=0;i<inventory.vaults[vps].slots.size();i++){
				if(_1==char(i+'1')) scta(6);else scta(15);
				cout<<"第"<<i+1<<"个物品槽:             "<<
				itemname[inventory.vaults[vps].slots[i].item]<<"x"<<
				inventory.vaults[vps].slots[i].qutt<<"["<<i+1<<"]            \n";
				detect(char(i+'1')){
					if(_1!=char(i+'1')){
						if(_1!='?') _2=char(i+'1');
						else _1=char(i+'1');
					}
				}
			}
			if(showtempvlt){
				scta(15);
				cout<<"\n地上(退出界面后消失):            \n";
				for(unsigned i=0;i<tempvlt.slots.size();i++){
					if(_1==char(i+'I')) scta(6);else scta(15);
					cout<<"第"<<i+1<<"个物品:            "<<
					itemname[tempvlt.slots[i].item]<<"x"<<
					tempvlt.slots[i].qutt<<"["<<char(i+'I')<<"]            \n";
					detect(char(i+'I')){
						if(_1!=char(i+'I')){
							if(_1!='?') _2=char(i+'I');
							else _1=char(i+'I');
						}
					}
				}
			}
			if(furnace){
				scta(15);
				if(_1==char('I')) scta(6);else scta(15);
				cout<<"\n炉内物品:            "<<
				itemname[tempvlt.slots[0].item]<<"x"<<
				tempvlt.slots[0].qutt<<"["<<char('I')<<"]            \n";
				cout<<"烧制进度："<<burning<<"%    \n";
				detect(char('I')){
					if(_1!=char('I')){
						if(_1!='?') _2=char('I');
						else _1=char('I');
					}
				}
				if(tempvlt.slots[0].item==0){
					burning=0;
				}else{
					if(burnresult[tempvlt.slots[0].item]){
						srand(time(0));
						if(rand()%6==0){
							burning++;
						}
						if(burning>=(tempvlt.slots[0].qutt)*100){
							burning=0;
							tempvlt.slots[0].item=burnresult[tempvlt.slots[0].item];
						}
					}else burning=0;
				}
			}
			cout<<endl;
			for(unsigned i=0;i<inventory.hcl.slots.size();i++){
				if(_1==char(i+'X')) scta(6);else scta(15);
				cout<<"合成栏第"<<i+1<<"个物品槽:            "<<
				itemname[inventory.hcl.slots[i].item]<<"x"<<
				inventory.hcl.slots[i].qutt<<"["<<char(i+'X')<<"]            \n";
				detect(char(i+'X')){
					if(_1!=char(i+'X')){
						if(_1!='?') _2=char(i+'X');
						else _1=char(i+'X');
					}
				}
			}
			scta(8);
			cout<<"预估成品："<<itemname[cp.item]<<"x"<<cp.qutt<<"            \n";
			if(_1=='C') scta(6);else scta(15);
			cout<<"成品栏："<<itemname[inventory.cp.item]<<"x"<<inventory.cp.qutt<<"[C]            \n";
			detect('C'){
				if(_1!='C'){
					if(_1!='?') _2='C';
					else _1='C';
				}
			}
			if(_1=='H') scta(6);else scta(15);
			cout<<"\n手持物品："<<itemname[inventory.hand.item]<<"x"<<inventory.hand.qutt<<"[H]            \n";
			detect('H'){
				if(_1!='H'){
					if(_1!='?') _2='H';
					else _1='H';
				}
			}
			scta(15);
			
			if(_1=='?') cout<<"按Q退出,按W合成,或按下按键执行操作                 \n                                     ";
			else        cout<<"按E丢掉,按R撤回,或按下另一个按键执行交换、堆叠操作,\n同时按下Tab分割一半,按下Shift分割一个";
			
			detect(VK_LEFT){
				vps=(vps-1+inventory.vaults.size())%inventory.vaults.size();
				Sleep(100);
			}
			detect(VK_RIGHT){
				vps=(vps+1)%inventory.vaults.size();
				Sleep(100);
			}
			
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
					detect(VK_TAB){
						int __1=tempslt.qutt/2;
						int __2=tempslt.qutt-__1;
						if(_2>='1'&&_2<='9'){
							inventory.vaults[vps].slots[_2-'1'].qutt+=__2;
						}
						if(_2>='I'&&_2<='M'){
							tempvlt.slots[_2-'I'].qutt+=__2;
						}
						if(_2>='X'&&_2<='Z'){
							inventory.hcl.slots[_2-'X'].qutt+=__2;
						}
						if(_2=='C'){
							inventory.cp.qutt+=__2;
						}
						if(_2=='H'){
							inventory.hand.qutt+=__2;
						}
						
						if(_1>='1'&&_1<='9'){
							inventory.vaults[vps].slots[_1-'1'].qutt=__1;
						}
						if(_1>='I'&&_1<='M'){
							tempvlt.slots[_1-'I'].qutt=__1;
						}
						if(_1>='X'&&_1<='Z'){
							inventory.hcl.slots[_1-'X'].qutt=__1;
						}
						if(_1=='C'){
							inventory.cp.qutt=__1;
						}
						if(_1=='H'){
							inventory.hand.qutt=__1;
						}
					}else detect(VK_SHIFT){
						if(_2>='1'&&_2<='9'){
							inventory.vaults[vps].slots[_2-'1'].qutt++;
						}
						if(_2>='I'&&_2<='M'){
							tempvlt.slots[_2-'I'].qutt++;
						}
						if(_2>='X'&&_2<='Z'){
							inventory.hcl.slots[_2-'X'].qutt++;
						}
						if(_2=='C'){
							inventory.cp.qutt++;
						}
						if(_2=='H'){
							inventory.hand.qutt++;
						}
						
						if(_1>='1'&&_1<='9'){
							inventory.vaults[vps].slots[_1-'1'].qutt--;
						}
						if(_1>='I'&&_1<='M'){
							tempvlt.slots[_1-'I'].qutt--;
						}
						if(_1>='X'&&_1<='Z'){
							inventory.hcl.slots[_1-'X'].qutt--;
						}
						if(_1=='C'){
							inventory.cp.qutt--;
						}
						if(_1=='H'){
							inventory.hand.qutt--;
						}
					}else{
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
					}
					inventory.refresh();
					while(press(_2));
					_1='?';
					_2='?';
					goto testforhecheng;
				}
				
				//Two more things...
				if(tempslot.item==0){
					detect(VK_TAB){
						int __1=tempslt.qutt/2;
						int __2=tempslt.qutt-__1;
						tempslot.item=tempslt.item;
						
						if(_2>='1'&&_2<='9'){
							inventory.vaults[vps].slots[_2-'1'].qutt=__2;
							inventory.vaults[vps].slots[_2-'1'].item=tempslt.item;
						}
						if(_2>='I'&&_2<='M'){
							tempvlt.slots[_2-'I'].qutt=__2;
							tempvlt.slots[_2-'I'].item=tempslt.item;
						}
						if(_2>='X'&&_2<='Z'){
							inventory.hcl.slots[_2-'X'].qutt=__2;
							inventory.hcl.slots[_2-'X'].item=tempslt.item;
						}
						if(_2=='C'){
							inventory.cp.qutt=__2;
							inventory.cp.item=tempslt.item;
						}
						if(_2=='H'){
							inventory.hand.qutt=__2;
							inventory.hand.item=tempslt.item;
						}
						
						if(_1>='1'&&_1<='9'){
							inventory.vaults[vps].slots[_1-'1'].qutt=__1;
						}
						if(_1>='I'&&_1<='M'){
							tempvlt.slots[_1-'I'].qutt=__1;
						}
						if(_1>='X'&&_1<='Z'){
							inventory.hcl.slots[_1-'X'].qutt=__1;
						}
						if(_1=='C'){
							inventory.cp.qutt=__1;
						}
						if(_1=='H'){
							inventory.hand.qutt=__1;
						}
						inventory.refresh();
						while(press(_2));
						_1='?';
						_2='?';
						goto testforhecheng;
					}
					
					detect(VK_SHIFT){
						tempslot.item=tempslt.item;
						
						if(_2>='1'&&_2<='9'){
							inventory.vaults[vps].slots[_2-'1'].qutt=1;
							inventory.vaults[vps].slots[_2-'1'].item=tempslt.item;
						}
						if(_2>='I'&&_2<='M'){
							tempvlt.slots[_2-'I'].qutt=1;
							tempvlt.slots[_2-'I'].item=tempslt.item;
						}
						if(_2>='X'&&_2<='Z'){
							inventory.hcl.slots[_2-'X'].qutt=1;
							inventory.hcl.slots[_2-'X'].item=tempslt.item;
						}
						if(_2=='C'){
							inventory.cp.qutt=1;
							inventory.cp.item=tempslt.item;
						}
						if(_2=='H'){
							inventory.hand.qutt=1;
							inventory.hand.item=tempslt.item;
						}
						
						if(_1>='1'&&_1<='9'){
							inventory.vaults[vps].slots[_1-'1'].qutt--;
						}
						if(_1>='I'&&_1<='M'){
							tempvlt.slots[_1-'I'].qutt--;
						}
						if(_1>='X'&&_1<='Z'){
							inventory.hcl.slots[_1-'X'].qutt--;
						}
						if(_1=='C'){
							inventory.cp.qutt--;
						}
						if(_1=='H'){
							inventory.hand.qutt--;
						}
						inventory.refresh();
						while(press(_2));
						_1='?';
						_2='?';
						goto testforhecheng;
					}
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
				inventory.refresh();
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
			
			inventory.refresh();
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
					if(cp.item==5) achieve("handwork");
					if(cp.item==6||cp.item==7) achieve("theHomeDepot");
					while(press('W'));
					goto testforhecheng;
				}
			}
			if(_1!='?'&&press('R')) _1='?';
			
			detect('Q'){
				break;
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
	void takeadropsheet(dropsheet ds){
		tempvlt=tpltvlt;
		tempvlt.name="地上(退出界面后消失)";
		srand(time(0));
		tempvlt.slots.push_back({ds.item1,ds.min1+rand()%(ds.max1-ds.min1+1)});
		srand(time(0));
		tempvlt.slots.push_back({ds.item2,ds.min2+rand()%(ds.max2-ds.min2+1)});
		srand(time(0));
		tempvlt.slots.push_back({ds.item3,ds.min3+rand()%(ds.max3-ds.min3+1)});
		itemsystem(1);
	}
}
extern "C++"{//游戏内使用函数
	void weijipedia() {
		anicls();
		system("cls");
		setpos(0, 0);
		achieve("informationTechnology");
		cout << "                    \n";
		cout << "      喂鸡百科      \n";
		cout << "                    \n";
		cout << "*查看地块----------Q\n";
		cout << "*查看物品及配方----W\n";
		cout << "*查看生物----------E\n";
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
					} 
//					else if (pntx == 4 && pnty == 4) {
//						cout << "1:指向背包的第1个物品";
//					} else if (pntx == 7 && pnty == 4) {
//						cout << "2:指向背包的第2个物品";
//					} else if (pntx == 10 && pnty == 4) {
//						cout << "3:指向背包的第3个物品";
//					} else if (pntx == 13 && pnty == 4) {
//						cout << "4:指向背包的第4个物品";
//					} else if (pntx == 16 && pnty == 4) {
//						cout << "5:指向背包的第5个物品";
//					} else if (pntx == 19 && pnty == 4) {
//						cout << "6:指向背包的第6个物品";
//					} else if (pntx == 22 && pnty == 4) {
//						cout << "7:指向背包的第7个物品";
//					} else if (pntx == 25 && pnty == 4) {
//						cout << "8:指向背包的第8个物品";
//					} else if (pntx == 28 && pnty == 4) {
//						cout << "9:指向背包的第9个物品";
//					} else if (pntx == 31 && pnty == 4) {
//						cout << "0:指向背包的第10个物品";
//					} 
					else if (pntx == 1 && pnty == 1) {
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
				setpos(0,0);
				int vps=0;
				bool sysclr=0;
				char _1='?';
				while(1){
					setpos(0,0);
					scta(7);
					cout<<"按ESC退出\n";
					scta(15);
					cout<<"上一个容器[←] 目前"<<vps+1<<"号容器-"<<inventory.vaults[vps].name<<" 下一个容器[→]            \n";
					for(unsigned i=0;i<inventory.vaults[vps].slots.size();i++){
						if(_1==char(i+'1')) scta(6);else scta(15);
						cout<<"第"<<i+1<<"个物品槽:             "<<
						itemname[inventory.vaults[vps].slots[i].item]<<"x"<<
						inventory.vaults[vps].slots[i].qutt<<"["<<i+1<<"]            \n";
						detect(char(i+'1')){
							_1=char(i+'1');
							sysclr=1;
						}
					}
					cout<<endl;
					for(unsigned i=0;i<inventory.hcl.slots.size();i++){
						if(_1==char(i+'X')) scta(6);else scta(15);
						cout<<"合成栏第"<<i+1<<"个物品槽:            "<<
						itemname[inventory.hcl.slots[i].item]<<"x"<<
						inventory.hcl.slots[i].qutt<<"["<<char(i+'X')<<"]            \n";
						detect(char(i+'X')){
							_1=char(i+'X');
							sysclr=1;
						}
					}
					if(_1=='C') scta(6);else scta(15);
					cout<<"成品栏："<<itemname[inventory.cp.item]<<"x"<<inventory.cp.qutt<<"[C]            \n";
					detect('C'){
						if(_1!='C'){
							_1='C';
						}
						sysclr=1;
					}
					if(_1=='H') scta(6);else scta(15);
					cout<<"\n手持物品："<<itemname[inventory.hand.item]<<"x"<<inventory.hand.qutt<<"[H]            \n";
					detect('H'){
						if(_1!='H'){
							_1='H';
						}
						sysclr=1;
					}
					scta(15);
					
					detect(VK_LEFT){
						vps=(vps-1+inventory.vaults.size())%inventory.vaults.size();
						Sleep(100);
					}
					detect(VK_RIGHT){
						vps=(vps+1)%inventory.vaults.size();
						Sleep(100);
					}
					
					if(_1=='?'){
						cout<<"按下按键查看物品信息\n\n\n\n\n\n\n\n";
					}
					else{
						cout<<"物品名称："<<itemname[tempslt.item]<<endl;
						cout<<WIintro[tempslt.item]<<endl;
						cout<<"用途："<<WIusage[tempslt.item]<<endl;
						cout<<"来源："<<WIsourc[tempslt.item]<<endl;
						cout<<"相关配方："<<endl;
						bool flag=1;
						if(tempslt.item!=0)
							for(ing in:ings){
								if(in.item1==tempslt.item
								   ||in.item2==tempslt.item
								   ||in.item3==tempslt.item
								   ||in.dest==tempslt.item){
									if(in.unlock){
										cout<<itemname[in.item1]<<"x"<<in.num1<<" ";
										if(in.have2)
											cout<<itemname[in.item2]<<"x"<<in.num2<<" ";
										if(in.have3)
											cout<<itemname[in.item3]<<"x"<<in.num3<<" ";
										cout<<"-> "<<itemname[in.dest]<<"x"<<in.num<<endl;
										flag=0;
									}
								}
							}
						if(flag) cout<<"无";
					}
					
					if(_1!='?'){
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
					}
					
					if(sysclr){
						system("cls");
						sysclr=0;
					}
					
					detect(VK_ESCAPE) return;
				}
			}
			detect('E') {
				anicls();
				for (unsigned i = 0; i < WMlist.size(); i++) {
					setpos(0, 0);
					scta(eco[WMlist[i]]);
					for (int a = 0; a < 5; a+=2) {
						for (int b = 0; b < 9; b+=2) {
							cout <<" "<< WMlist[i];
						}
						cout << endl;
						cout << endl;
					}
					scta(0xF);
					cout << WMname[WMlist[i]] << endl
					<< WMintro[WMlist[i]] << endl
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
	void settings(){
		anicls();
		int pntr=0;
		while(1){
			setpos(0,0);
			scta((pntr==0)?6:15);
			cout<<"渲染颜色------------------------------------------"<<(raisecolor  ?"[  [开]":"[关]  ]")<<endl;
			scta((pntr==1)?6:15);
			cout<<"轮回（死亡后重新开始游戏）------------------------"<<(samsara     ?"[  [开]":"[关]  ]")<<endl;
			scta((pntr==2)?6:15);
			cout<<"清屏动画------------------------------------------"<<(clsanimation?"[  [开]":"[关]  ]")<<endl;
			scta((pntr==3)?6:15);
			cout<<"退出设置";
			detect(VK_UP) pntr=(pntr+3)%4,Sleep(100);
			detect(VK_DOWN) pntr=(pntr+5)%4,Sleep(100);
			detect(VK_RETURN){
				if(pntr==0) raisecolor=!raisecolor;
				if(pntr==1) samsara=!samsara;
				if(pntr==2) clsanimation=!clsanimation;
				if(pntr==3) break;
				Sleep(100);
			}
		}
		anicls();
	}
	void whenmove() {
		achieve("studyToWalk");
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
		if(c=='O') achieve("cooking");
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
	void battle(int tx,int ty){//x!=x y!=y x=y y=x
		anicls();
		achieve("deletion");
		while(entty[tx][ty].hp>0){
			cout<<"你遭遇了 "<<enttname[entty[tx][ty].type]<<" ！！\n\n("<<hp<<")";
			scta(0xf6);
			cout<<"@";
			scta(0xf);
			cout<<"            ";
			scta(eco[entty[tx][ty].type]);
			cout<<entty[tx][ty].type;
			scta(0xf);
			cout<<"("<<entty[tx][ty].hp<<")\n[轻击(Q)] [重击(W)] [跳过(E)]\n";
			while(1){
				detect('Q'){
					entty[tx][ty].hp-=damage;
					force-=1;
					cout<<"造成了"<<damage<<"点伤害，体力-1\n";
					Sleep(1000);
					break;
				}
				detect('W'){
					entty[tx][ty].hp-=ceil(damage*1.5);
					force-=2;
					cout<<"造成了"<<ceil(damage*1.5)<<"点伤害，体力-2\n";
					Sleep(1000);
					break;
				}
				detect('E'){
//					entty[tx][ty].hp-=ceil(damage*1.5);
//					force-=2;
					cout<<"你跳过了回合\n";
					Sleep(1000);
					break;
				}
			}
			
			if(entty[tx][ty].hp<=0){
				cout<<enttname[entty[tx][ty].type]<<" 死了！！\n";
				Sleep(1000);
				entty[tx][ty].be=0;
				takeadropsheet(eds[entty[tx][ty].type]);
				return;
			}
			system("cls");
			cout<<"这只 "<<enttname[entty[tx][ty].type]<<" 开始疯狂地撕咬！！\n\n("<<hp<<")";
			scta(0xf6);
			cout<<"@";
			scta(0xf);
			cout<<"            ";
			scta(eco[entty[tx][ty].type]);
			cout<<entty[tx][ty].type;
			scta(0xf);
			cout<<"("<<entty[tx][ty].hp<<")\n";
			Sleep(1000);
			cout<<"咬到了你，造成了2点伤害\n";
			hp-=2;
			if(hp<0){
				dead("失血过多");
			}
			Sleep(1000);
			system("cls");
		}
	}
}
extern "C++"{//游戏
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
		color['O'] = 0x87;     // stone furnace
		printf("临摹生物\n");
		eco['V']=0xe6;
		enttname['V']="牛";
		eds['V'].init( 8, 1, 3,12, 0, 2, 0, 0, 0);
		eco['Q']=0xe8;
		enttname['Q']="猫";
		eds['Q'].init( 9, 2, 5, 0, 0, 0, 0, 0, 0);
		printf("安装导航\n");
		bad['=']=1;
		bad['_']=1;
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
		itemname[8] = "生牛肉";
		itemsize[8] = 1;
	  burnresult[8] = 10;
		itemname[9] = "毛线";
		itemsize[9] = 1;
		itemname[10]= "熟牛肉";
		itemsize[10]= 1;
		itemname[11]= "石炉";
		itemsize[11]= 1;
		itemname[12]= "皮革";
		itemsize[12]= 1;
		itemname[13]= "口袋";
		itemsize[13]= 1;
		printf("进行神秘操作\n");
		intable['T'] = 1;
		intable['o'] = 1;
		intable['w'] = 1;
		intable['O'] = 1;
		message = "";
		printf("搭建碰撞箱\n");
		wall['=']=1;
		printf("定义配方\n");
		ings.push_back(ing(1, 3, 1, 1, 1, 1, 0, 0, 0, 5));
		ings.push_back(ing(1, 3, 1, 1, 2, 1, 0, 0, 0, 6, 3));
		ings.push_back(ing(1, 2, 1, 0, 0, 0, 0, 0, 0, 7, 4));
		ings.push_back(ing(1, 1, 3, 0, 0, 0, 0, 0, 0,11, 1));
		ings.push_back(ing(1,12, 1, 1, 9, 1, 0, 0, 0,13, 1));
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
			posx = 500;
			posy = 500;
			hp=50;
			force=500;
		}
		alive = 1;
		speed = 1;
		showed = false;
		inventory.rfwt();
		if(!reset) goto heyhello;
		printf("初始化地图\n");
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
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
			if (i % 20 == 0)
				cout << '#';
		}
		printf("\n生成可交互的地块\n");
		for (int i = uborder + 1; i < dborder; i++) {
			for (int j = lborder + 1; j < rborder; j++) {
				if (copwd[i][j])
					world[i][j] = copwd[i][j];
			}
		}
		printf("保护生物多样性\n");
		for (int i = uborder + 1; i < dborder; i++) {
			for (int j = lborder + 1; j < rborder; j++) {
				srand(time(0));
				if(rand()%2==0) entty[i][j].type='V';
				if(rand()%2==1) entty[i][j].type='Q';
			}
			if (i % 20 == 0)
				cout << '#';
		}
		heyhello:;
		printf("\n设立边界\n");
		for (int i = uborder; i <= dborder; i++) world[i][lborder] = '#';
		for (int i = uborder; i <= dborder; i++) world[i][rborder] = '#';
		for (int j = lborder; j <= rborder; j++) world[uborder][j] = '#';
		for (int j = lborder; j <= rborder; j++) world[dborder][j] = '#';
		
		printf("启动！\n");
		
		//devmode
//	inventory.vaults[0].slots[0].item=1;
//	inventory.vaults[0].slots[0].qutt=10;
//	inventory.vaults[0].slots[1].item=2;
//	inventory.vaults[0].slots[1].qutt=20;
//	inventory.vaults[0].slots[2].item=3;
//	inventory.vaults[0].slots[2].qutt=30;
		
//		inventory.vaults[0].slots[0].item=9;
//		inventory.vaults[0].slots[0].qutt=6767;
//		inventory.vaults[0].slots[1].item=12;
//		inventory.vaults[0].slots[1].qutt=6767;
		system("cls");
	}
	void savetheworld(){
		anicls();
		setpos(0,0);
//		cout<<"为您的存档命名:";
//		string name;
//		cin>>name;
		cout<<"正在保存";
		out.open((archiveslot+".jc8").c_str());
		out<<archivename<<endl;
		for(int i=uborder;i<=dborder;i++){
			for(int j=lborder;j<=rborder;j++){
				out<<world[i][j];
			}out<<endl;
			if(i%20==0) cout<<'.';
		}
		inventory.wi();
		out<<" "<<posx<<" "<<posy<<" "<<hp<<" "<<force<<" "<<achicnt;
		out.close();
		cout<<endl<<"保存完毕。";
		Sleep(100);
		anicls();
		setpos(0,0);
	}
	void loadtheworld(){
		string name;
		cout<<"正在导入";
		in.open((archiveslot+".jc8").c_str());
		in>>name;
		archivename=name;
		for(int i=uborder;i<=dborder;i++){
			for(int j=lborder;j<=rborder;j++){
				in>>world[i][j];
			}
			if(i%20==0) cout<<'.';
		}
		inventory.ri();
		in>>posx>>posy>>hp>>force>>achicnt;
		in.close();
		cout<<endl<<"加载完毕。";
		Sleep(100);
		anicls();
		setpos(0,0);
	}
	void The_World() {
		weijiinit();
		achinit();
		while (alive) {
			setpos(0, 0);
			scta(0x85);
			printf("[坐标:<%d,%d>] ", posx, posy);
			scta(0x8A);
			printf("[体力:%d] ", force);
			scta(0x8C);
			printf("[血量:%d] ", hp);
			
			scta(0x8F);
			if ((showed -= 0.05) > 0) {
				cout << message << "\n";
			} else {
				scta(0x0);
				cout << "                                 "
				<< "\n";
			}
			scta(0x8e);
			if(!justfinished){
				cout<<"<成就> "<<achname[achievements[achicnt]]<<":"<<achintro[achievements[achicnt]];
			}else{
				cout<<"<成就> "<<achname[achievements[achicnt]]<<" 达成！！";
				justfinished--;
				if(!justfinished) achicnt++;
			}
			scta(0xF);
			cout<<"               \n";
			for (int i = posy - 10; i <= posy + 10; i++) {
				for (int j = posx - 25; j <= posx + 25; j++) {
					if (i == posy && j == posx) {
						scta(0xF6 | vision);
						printf("@");
					} else if (entty[i][j].be){
						scta(eco[entty[i][j].type] | vision);
						printf("%c", entty[i][j].type);
					}else{
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
			cout<<"                             ";
			cout<<"\n手持物品："<<itemname[inventory.hand.item]<<"x"<<inventory.hand.qutt<<"            ";
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
			
			detect('Z'){//weijipedia
				weijipedia();
			}
			
			detect('R'){//item system
				achieve("checkout");
				itemsystem();
			}
			
			//load entity
			for (int i = posy - 10; i <= posy + 10; i++) {
				for (int j = posx - 25; j <= posx + 25; j++) {
					if(entty[i][j].be){
						if(entty[i][j].type=='V'){
							srand(time(0)+rand()+45);
							if(rand()%5==1){
								srand(time(0)+rand()+523);
								if(rand()%4==0&&!bad[world[i+1][j]]) swap(entty[i+1][j],entty[i][j]);
								if(rand()%4==1&&!bad[world[i-1][j]]) swap(entty[i-1][j],entty[i][j]);
								if(rand()%4==2&&!bad[world[i][j+1]]) swap(entty[i][j+1],entty[i][j]);
								if(rand()%4==3&&!bad[world[i][j-1]]) swap(entty[i][j-1],entty[i][j]);
							}
						}if(entty[i][j].type=='Q'){
							srand(time(0)+rand()+45);
							if(rand()%3==1){
								srand(time(0)+rand()+523);
								if(rand()%4==0&&!bad[world[i+1][j]]) swap(entty[i+1][j],entty[i][j]);
								if(rand()%4==1&&!bad[world[i-1][j]]) swap(entty[i-1][j],entty[i][j]);
								if(rand()%4==2&&!bad[world[i][j+1]]) swap(entty[i][j+1],entty[i][j]);
								if(rand()%4==3&&!bad[world[i][j-1]]) swap(entty[i][j-1],entty[i][j]);
							}
						}
					}
				}
			}
			for (int i = posy - 10; i <= posy + 10; i++) {
				srand(time(0)+rand()+1431);
				if(!bad[world[i][posx-26]]) entty[i][posx-26].be=(rand()%700==1);
				srand(time(0)+rand()+2343);
				if(!bad[world[i][posx+26]]) entty[i][posx+26].be=(rand()%700==1);
			}
			for (int j = posx - 25; j <= posx + 25; j++) {
				srand(time(0)+rand());
				if(!bad[world[posy-11][j]]) entty[posy-11][j].be=(rand()%700==1);
				srand(time(0)+rand());
				if(!bad[world[posy+11][j]]) entty[posy+11][j].be=(rand()%700==1);
			}
			if(entty[posy][posx].be) battle(posy,posx);
			
			if (inventory.hand.item==5){
				damage=4;
				if(showed==0){
					message = "持有石斧";
					showed = true;
				}
			}else{
				damage=1;
			}
			if(cooldown) cooldown--;
			detect('E'){
				if(cooldown){
					message="冷却中……";
					showed=1;
				}else{
					if(inventory.hand.item==6){
						inventory.hand.qutt--;
						inventory.refresh();
						build('=',6);
					}
					if(inventory.hand.item==7){
						inventory.hand.qutt--;
						inventory.refresh();
						build('-',7);
					}
					if(inventory.hand.item==4){
						inventory.hand.qutt--;
						inventory.refresh();
						message="太酸了,血量+5,体力+5";
						showed=1;
						hp+=5;
						force+=5;
					}
					if(inventory.hand.item==8){
						inventory.hand.qutt--;
						inventory.refresh();
						message="没熟,血量-2,体力+50";
						showed=1;
						hp-=2;
						force+=50;
					}
					if(inventory.hand.item==10){
						achieve("wellDone");
						inventory.hand.qutt--;
						inventory.refresh();
						message="血量+10,体力+200";
						showed=1;
						hp+=10;
						force+=200;
					}
					if(inventory.hand.item==11){
						inventory.hand.qutt--;
						inventory.refresh();
						build('O',11);
					}
					if(inventory.hand.item==13){
						achieve("pocketVersion");
						inventory.hand.qutt--;
						tempvlt=tpltvlt;
						tempvlt.slots.push_back(tpltslt);
						tempvlt.slots.push_back(tpltslt);
						tempvlt.slots.push_back(tpltslt);
						inventory.vaults.push_back(tempvlt);
						message="装备口袋";
						showed=1;
						inventory.refresh();
					}
					cooldown=10;
				}
			}
			
			detect(VK_ESCAPE) {
				anicls();
				int pointer = 0;
				while (1) {
					setpos(0, 0);
					scta(0xF);
					cout << "                      ┏━┓┏━┓┃  ┃┏━━┏━━\n";
					cout << "                      ┣━┛┣━┫┃  ┃┗━┓┣━━\n";
					cout << "                      ┃    ┃  ┃┗━┛━━┛┗━━\n";
					cout<<endl;
					scta(pointer == 0 ? 0x6 : 0xF);
					cout << "                      ______________________________         \n";
					cout << "                      |        继 续  游 戏        |         \n";
					cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
					cout<<endl;
					scta(pointer == 1 ? 0x6 : 0xF);
					cout << "                      ______________________________         \n";
					cout << "                      |查看喂鸡百科(游戏中按Ｚ打开)|         \n";
					cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
					cout<<endl;
					scta(pointer == 2 ? 0x6 : 0xF);
					cout << "                      ______________________________         \n";
					cout << "                      |           滚  木           |         \n";
					cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
					cout<<endl;
					scta(pointer == 3 ? 0x6 : 0xF);
					cout << "                      ______________________________         \n";
					cout << "                      |           设  置           |         \n";
					cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
					cout<<endl;
					scta(pointer == 4 ? 0x6 : 0xF);
					cout << "                      ______________________________         \n";
					cout << "                      |       保 存 并 退 出       |         \n";
					cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
					cout<<endl;
					scta(0xF);
//					cout << "*使用↑↓选择，Enter以确定";
					detect(VK_DOWN) pointer = (pointer + 6) % 5, Sleep(100);
					detect(VK_UP) pointer = (pointer + 4) % 5, Sleep(100);
					detect(VK_RETURN) {
						if (pointer == 0) {
							anicls();
							break;
						}
						if (pointer == 1) {
							weijipedia();
							anicls();
						}
						if (pointer == 2) {
							MessageBox(0,"I AK IOI","JCerMessage",MB_ICONEXCLAMATION|MB_OK);
						}
						if (pointer == 3) {
							settings();
						}
						if (pointer == 4) {
							savetheworld();
							exit(0);
						}
					}
				}
			}
			if (world[posy][posx] == 'T') {
				detect('P') {
					int progress = 0;
					anicls();
					while (progress < 30) {
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
						printf("进度:%d/30 体力:%d 一次伤害%d\n", progress, force, damage);
						detect('P') {
							srand(rand());
							if (rand() % 3 == 2) {
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
					achieve("emeraldLike");
					takeanitem(1);
					world[posy][posx] = ',';
				}
			}
			if (world[posy][posx] == 'w') {
				detect('P') {
					achieve("deepSeek");
					srand(rand());
					takeanitem(rand() % 2 + 3);
					world[posy][posx] = '.';
				}
			}
			if (world[posy][posx] == 'O') {
				detect('P') {
					itemsystem(0,1);
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
}
int main() {//菜单
	versioninit();
	system("title JCerGame");
	system("color 0F");
	system("mode con lines=25 cols=75");
	int pointer = 0;
	for(int i=1;i<=7;i++){
		if(i==1) scta(0x0);
		if(i==2) scta(0x8);
		if(i==3) scta(0x7);
		if(i==4) scta(0xf);
		if(i==5) scta(0x7);
		if(i==6) scta(0x8);
		if(i==7) scta(0x0);
		cout<<endl<<endl<<endl;
		cout<<"                                  ┏━┓\n";
		cout<<"                                  ┣━┫\n";
		cout<<"                                  ┃  ┃\n";
		cout<<"                         ┏━━┏━┓┏┳┓┏━━\n";
		cout<<"                         ┃  ┓┣━┫┃┃┃┣━━\n";
		cout<<"                         ┗━┛┃  ┃┃┃┃┗━━\n";
		cout<<"          ┏━┓┏━┓┏━━┏━━┏━━┏┓┃━┳━┏━━┏┓  \n";
		cout<<"          ┣━┛┣┳┛┣━━┗━┓┣━━┃┃┃  ┃  ┣━━┃┗┓\n";
		cout<<"          ┃    ┃┗━┗━━━━┛┗━━┃┗┛  ┃  ┗━━┗━┛\n";
		cout<<"                               ┏┓  ┃  ┃\n";
		cout<<"                               ┣┻┓┗┳┛\n";
		cout<<"                               ┗━┛  ┃\n";
		cout<<"          ┃    ━┳━┃  ┃┏━┓┏━┓┏━┓━┳━┏━┓┏┓┃\n";
		cout<<"          ┃      ┃  ┣━┫┣━┫┃  ┃┃━╋  ┃  ┣━┫┃┃┃\n";
		cout<<"          ┗━━━┻━┃  ┃┃  ┃┗━┛┗━┛━┻━┃  ┃┃┗┛\n";
		cout<<"               ┏┓      ┏━┓━┳━┃  ┃┏━━┏━┓┏━━\n";
		cout<<"             ┏╋┛      ┃  ┃  ┃  ┣━┫┣━━┣┳┛┗━┓\n";
		cout<<"             ┗╋━      ┗━┛  ┃  ┃  ┃┗━━┃┗━━━┛\n";
		if(i==4) Sleep(1500);
		Sleep(50);
		setpos(0,0);
	}
	Sleep(200);
	for(int i=1;i<=7;i++){
		if(i==1) scta(0x0);
		if(i==2) scta(0x8);
		if(i==3) scta(0x7);
		if(i==4) scta(0xf);
		if(i==5) scta(0x7);
		if(i==6) scta(0x8);
		if(i==7) scta(0x0);
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                               ┏━━━━┓\n";
		cout<<"                               ┣━┓    ┃\n";
		cout<<"                               ┗━┛    ┃\n";
		if(i==4) Sleep(1000);
		Sleep(50);
		setpos(0,0);
	}
	Sleep(200);
	for(int i=1;i<=4;i++){
		if(i==1) scta(0x0);
		if(i==2) scta(0x8);
		if(i==3) scta(0x7);
		if(i==4) scta(0xf);
		cout << "             ━┳━┏━━┏━━┏━┓┏━━┏━┓┏┳┓┏━━\n";
		cout << "               ┃  ┃    ┣━━┣┳┛┃  ┓┣━┫┃┃┃┣━━\n";
		cout << "             ━┛  ┗━━┗━━┃┗━┗━┛┃  ┃┃┃┃┗━━\n";
		cout<<endl;
		cout << "                      ______________________________         \n";
		cout << "                      |        开 始  游 戏        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		cout << "                      ______________________________         \n";
		cout << "                      |           设  置           |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		cout << "                      ______________________________         \n";
		cout << "                      |        更 新  日 志        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		cout << "                      ______________________________         \n";
		cout << "                      |        游 戏  简 介        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		cout << "                      ______________________________         \n";
		cout << "                      |           退  出           |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		Sleep(50);
		setpos(0,0);
	}
	while (1) {
		setpos(0, 0);
		scta(0xF);
		cout << "             ━┳━┏━━┏━━┏━┓┏━━┏━┓┏┳┓┏━━\n";
		cout << "               ┃  ┃    ┣━━┣┳┛┃  ┓┣━┫┃┃┃┣━━\n";
		cout << "             ━┛  ┗━━┗━━┃┗━┗━┛┃  ┃┃┃┃┗━━\n";
		cout<<endl;
		scta(pointer == 0 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |        开 始  游 戏        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 1 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |           设  置           |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 2 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |        更 新  日 志        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 3 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |        游 戏  简 介        |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 4 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |           退  出           |         \n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(0xF);
//		cout << "*使用↑↓选择，Enter以确定";
		detect(VK_DOWN) pointer = (pointer + 6) % 5, Sleep(100);
		detect(VK_UP) pointer = (pointer + 4) % 5, Sleep(100);
		detect(VK_RETURN) {
			if (pointer == 0) {
				break;
			}
			if (pointer == 1) {
				settings();
			}
			if (pointer == 2) {
				anicls();
				setpos(0, 0);
				showversion();
				anicls();
			}
			if (pointer == 3) {
				banquan();
			}
			if (pointer == 4) {
//				MessageBox(NULL,"你这个怪兽！！！","Not JCerGame by lihaoqian & LiJunyi",MB_OK|MB_ICONWARNING);
				return 0;
			}
		}
	}
	anicls();
	setpos(0, 0);
	string archives[67];
	ifstream jc;
	jc.open("1.jc8"); if(jc.fail()) archives[1]="空"; else jc>>archives[1]; jc.close();
	jc.open("2.jc8"); if(jc.fail()) archives[2]="空"; else jc>>archives[2]; jc.close();
	jc.open("3.jc8"); if(jc.fail()) archives[3]="空"; else jc>>archives[3]; jc.close();
	jc.open("4.jc8"); if(jc.fail()) archives[4]="空"; else jc>>archives[4]; jc.close();
	jc.open("5.jc8"); if(jc.fail()) archives[5]="空"; else jc>>archives[5]; jc.close();
	while (1) {
		setpos(0, 0);
		scta(0xF);
		cout << "             ━┳━┏━━┏━━┏━┓┏━━┏━┓┏┳┓┏━━\n";
		cout << "               ┃  ┃    ┣━━┣┳┛┃  ┓┣━┫┃┃┃┣━━\n";
		cout << "             ━┛  ┗━━┗━━┃┗━┗━┛┃  ┃┃┃┃┗━━\n";
		cout<<  "                                 选择存档\n";
		scta(pointer == 0 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |"<<archives[1];for(unsigned i=28;i>archives[1].size();i--)cout<<" ";cout<<"|\n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 1 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |"<<archives[2];for(unsigned i=28;i>archives[2].size();i--)cout<<" ";cout<<"|\n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 2 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |"<<archives[3];for(unsigned i=28;i>archives[3].size();i--)cout<<" ";cout<<"|\n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 3 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |"<<archives[4];for(unsigned i=28;i>archives[4].size();i--)cout<<" ";cout<<"|\n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(pointer == 4 ? 0x6 : 0xF);
		cout << "                      ______________________________         \n";
		cout << "                      |"<<archives[5];for(unsigned i=28;i>archives[5].size();i--)cout<<" ";cout<<"|\n";
		cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         \n";
		cout<<endl;
		scta(0xF);
//		cout << "*使用↑↓选择，Enter以确定";
		detect(VK_DOWN) pointer = (pointer + 6) % 5, Sleep(100);
		detect(VK_UP) pointer = (pointer + 4) % 5, Sleep(100);
		detect(VK_RETURN) {
			pointer++;
			archiveslot=to_string(pointer);
			if(archives[pointer]=="空") break;
			else{
				anicls();
				setpos(0, 0);
				loadtheworld();
				inittheworld(0);
				The_World();
				return 0;
			}
		}
	}
	anicls();
	setpos(0, 0);
	cout<<"为存档命名：";
	cin>>archivename;
	inittheworld();
	The_World();
	return 0;
}
