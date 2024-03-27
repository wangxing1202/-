#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<windows.h>
using namespace std;

void colorprint(const char* s, int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
//0 = 黑色 8 = 灰色
//1 = 蓝色 9 = 淡蓝色
//2 = 绿色 10 = 淡绿色
//3 = 浅绿色 11 = 淡浅绿色
//4 = 红色 12 = 淡红色
//5 = 紫色 13 = 淡紫色
//6 = 黄色 14 = 淡黄色
//7 = 白色 15 = 亮白色

struct node {
	int no;
	int data;
	string a;
	node* next;
};

int mymin(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

bool find_it(string s1, string s2) {
	if (s1.find(s2) != string::npos && s1 != s2)
		return 1;
	else
		return 0;
}//在s1中找s2

void line(string start, string terminal, node* current, int* s, int* distance) {
	string start1 = start;
	string term1 = terminal;
	while (current != NULL) {
		if (current->a == terminal) {
			string temp = terminal;
			terminal = start;
			start = temp;
		}
		if (current->a == start) {
			while (current->a != terminal) {
				*distance += current->data;
				*s = *s + 1;
				current = current->next;
			}
			break;
		}
		current = current->next;
	}
	cout << start1 << "--" << term1 << endl;
}

int price(int distance) {
	if (distance <= 10000)
		return 2;
	if (distance > 10000 && distance <= 16000)
		return 3;
	if (distance > 16000 && distance <= 22000)
		return 4;
	if (distance > 22000 && distance <= 30000)
		return 5;
	if (distance > 30000 && distance <= 38000)
		return 6;
	if (distance > 38000 && distance <= 48000)
		return 7;
	if (distance > 48000 && distance <= 58000)
		return 8;
	if (distance > 58000 && distance <= 70000)
		return 9;
	if (distance > 70000)
		return 9 + (distance - 70000) / 14000 + 1;
}

int main() {
	ifstream in_file("subway.txt", ios::in);
	if (!in_file)
		exit(-1);
	node* Node1 = NULL, * tail1 = NULL;
	for (int i = 0; i < 27; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Node1 == NULL) {
			Node1 = p;
			tail1 = p;
		}
		else {
			tail1->next = p;
			tail1 = p;
		}
	}
	tail1->next = NULL;
	node* Node2 = NULL, * tail2 = NULL;
	for (int i = 0; i < 26; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Node2 == NULL) {
			Node2 = p;
			tail2 = p;
		}
		else {
			tail2->next = p;
			tail2 = p;
		}
	}
	tail2->next = NULL;
	node* Node3 = NULL, * tail3 = NULL;
	for (int i = 0; i < 29; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Node3 == NULL) {
			Node3 = p;
			tail3 = p;
		}
		else {
			tail3->next = p;
			tail3 = p;
		}
	}
	tail3->next = NULL;
	node* Node4 = NULL, * tail4 = NULL;
	for (int i = 0; i < 18; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Node4 == NULL) {
			Node4 = p;
			tail4 = p;
		}
		else {
			tail4->next = p;
			tail4 = p;
		}
	}
	tail4->next = NULL;
	node* Node10 = NULL, * tail10 = NULL;
	for (int i = 0; i < 14; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Node10 == NULL) {
			Node10 = p;
			tail10 = p;
		}
		else {
			tail10->next = p;
			tail10 = p;
		}
	}
	tail10->next = NULL;
	node* Nodeair = NULL, * tailair = NULL;
	for (int i = 0; i < 8; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Nodeair == NULL) {
			Nodeair = p;
			tailair = p;
		}
		else {
			tailair->next = p;
			tailair = p;
		}
	}
	tailair->next = NULL;
	node* Nodehe = NULL, * tailhe = NULL;
	for (int i = 0; i < 19; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Nodehe == NULL) {
			Nodehe = p;
			tailhe = p;
		}
		else {
			tailhe->next = p;
			tailhe = p;
		}
	}
	tailhe->next = NULL;
	node* Nodeli = NULL, * tailli = NULL;
	for (int i = 0; i < 10; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Nodeli == NULL) {
			Nodeli = p;
			tailli = p;
		}
		else {
			tailli->next = p;
			tailli = p;
		}
	}
	tailli->next = NULL;
	node* Nodetian = NULL, * tailtian = NULL;
	for (int i = 0; i < 17; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Nodetian == NULL) {
			Nodetian = p;
			tailtian = p;
		}
		else {
			tailtian->next = p;
			tailtian = p;
		}
	}
	tailtian->next = NULL;
	node* Nodes9 = NULL, * tails9 = NULL;
	for (int i = 0; i < 6; i++) {
		node* p = new node;
		in_file >> p->a;
		in_file >> p->data;
		p->no = i;
		if (Nodes9 == NULL) {
			Nodes9 = p;
			tails9 = p;
		}
		else {
			tails9->next = p;
			tails9 = p;
		}
	}
	tails9->next = NULL;

	colorprint("南京地铁票务系统", 2);
	cout << endl;
	int a = 0, b1 = 0;
	while (1) {
		a = -1, b1 = 0;
		cout << "输入0退出" << endl;
		while (a != 1 && a != 2 && a != 0) {
			colorprint("地铁信息查询，请输入1", 9);
			cout << endl;
			colorprint("地铁票务查询，请输入2", 9);
			cout << endl;
			cin >> a;
		}
		if (a == 0)
			break;
		if (a == 1) {
			while (b1 != 1 && b1 != 2) {
				colorprint("线路查询，请输入1", 13);
				cout << endl;
				colorprint("站点查询，请输入2", 13);
				cout << endl;
				cin >> b1;
			}
			if (b1 == 1) {
				int b = 0;
				while (b > 10 || b < 1) {
					cout << "请输入您要查询的线路：一号线请输入1、二号线请输入2、三号线请输入3、四号线请输入4、十号线请输入5、机场线请输入6、宁和线请输入7、宁溧线请输入8、宁天线请输入9、s9线请输入10" << endl;
					cin >> b;
				}
				if (b == 1) {
					node* cur = Node1;
					for (int i = 0; i < 27; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 2) {
					node* cur = Node2;
					for (int i = 0; i < 26; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 3) {
					node* cur = Node3;
					for (int i = 0; i < 29; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 4) {
					node* cur = Node4;
					for (int i = 0; i < 18; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 5) {
					node* cur = Node10;
					for (int i = 0; i < 14; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 6) {
					node* cur = Nodeair;
					for (int i = 0; i < 8; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 7) {
					node* cur = Nodehe;
					for (int i = 0; i < 19; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 8) {
					node* cur = Nodeli;
					for (int i = 0; i < 10; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 9) {
					node* cur = Nodetian;
					for (int i = 0; i < 17; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
				if (b == 10) {
					node* cur = Nodes9;
					for (int i = 0; i < 6; i++) {
						cout << cur->a << " ";
						cur = cur->next;
					}
				}
			}
			if (b1 == 2) {
				int cou = 0, cou1 = 0;
				string c1;
				while (cou1 == 0) {
					cout << "请输入站点名称" << endl;
					cin >> c1;
					node* cur = Node1;
					cou = 0;
					for (int i = 0; i < 27; i++) {
						if (c1 == cur->a) {
							cout << "一号线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Node2;
					for (int i = 0; i < 26; i++) {
						if (c1 == cur->a) {
							cout << "二号线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Node3;
					for (int i = 0; i < 29; i++) {
						if (c1 == cur->a) {
							cout << "三号线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Node4;
					for (int i = 0; i < 18; i++) {
						if (c1 == cur->a) {
							cout << "四号线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Node10;
					for (int i = 0; i < 14; i++) {
						if (c1 == cur->a) {
							cout << "十号线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Nodeair;
					for (int i = 0; i < 8; i++) {
						if (c1 == cur->a) {
							cout << "机场线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Nodehe;
					for (int i = 0; i < 19; i++) {
						if (c1 == cur->a) {
							cout << "宁和线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Nodeli;
					for (int i = 0; i < 10; i++) {
						if (c1 == cur->a) {
							cout << "宁溧线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Nodetian;
					for (int i = 0; i < 17; i++) {
						if (c1 == cur->a) {
							cout << "宁天线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					cur = Nodes9;
					for (int i = 0; i < 6; i++) {
						if (c1 == cur->a) {
							cout << "s9线 ";
							cou1++;
							break;
						}
						else if (find_it(cur->a, c1)) {
							cou++;
							cout << cur->a << endl;
						}
						cur = cur->next;
					}
					if (cou > 0)
						cout << "请精确站点名称" << endl;
					else if (cou1 == 0)
						cout << "没有找到呢，再输入一次罢" << endl;
				}
			}
		}
		//票务查询
		if (a == 2) {
			int cou = 0, cou1 = 0;
			int tsta[4] = { 0 };
			int term[4] = { 0 };
			string start;
			while (cou1 == 0) {
				cout << "请输入起点站" << endl;
				cin >> start;
				cou = 0;
				node* cur = Node1;
				for (int i = 0; i < 27; i++) {
					if (start == cur->a) {
						tsta[cou1] = 1;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node2;
				for (int i = 0; i < 26; i++) {
					if (start == cur->a) {
						tsta[cou1] = 2;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node3;
				for (int i = 0; i < 29; i++) {
					if (start == cur->a) {
						tsta[cou1] = 3;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node4;
				for (int i = 0; i < 18; i++) {
					if (start == cur->a) {
						tsta[cou1] = 4;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node10;
				for (int i = 0; i < 14; i++) {
					if (start == cur->a) {
						tsta[cou1] = 5;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodeair;
				for (int i = 0; i < 8; i++) {
					if (start == cur->a) {
						tsta[cou1] = 6;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodehe;
				for (int i = 0; i < 19; i++) {
					if (start == cur->a) {
						tsta[cou1] = 7;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodeli;
				for (int i = 0; i < 10; i++) {
					if (start == cur->a) {
						tsta[cou1] = 8;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodetian;
				for (int i = 0; i < 17; i++) {
					if (start == cur->a) {
						tsta[cou1] = 9;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodes9;
				for (int i = 0; i < 6; i++) {
					if (start == cur->a) {
						tsta[cou1] = 10;
						cou1++;
						break;
					}
					else if (find_it(cur->a, start)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				if (cou > 0)
					cout << "请精确站点名称" << endl;
				else if (cou1 == 0)
					cout << "没有找到呢，再输入一次罢" << endl;
			}
			string terminal;
			cou = 0, cou1 = 0;
			while (cou1 == 0) {
				cout << "请输入终点站" << endl;
				cin >> terminal;
				cou = 0;
				node* cur = Node1;
				for (int i = 0; i < 27; i++) {
					if (terminal == cur->a) {
						term[cou1] = 1;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node2;
				for (int i = 0; i < 26; i++) {
					if (terminal == cur->a) {
						term[cou1] = 2;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node3;
				for (int i = 0; i < 29; i++) {
					if (terminal == cur->a) {
						term[cou1] = 3;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node4;
				for (int i = 0; i < 18; i++) {
					if (terminal == cur->a) {
						term[cou1] = 4;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Node10;
				for (int i = 0; i < 14; i++) {
					if (terminal == cur->a) {
						term[cou1] = 5;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodeair;
				for (int i = 0; i < 8; i++) {
					if (terminal == cur->a) {
						term[cou1] = 6;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodehe;
				for (int i = 0; i < 19; i++) {
					if (terminal == cur->a) {
						term[cou1] = 7;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodeli;
				for (int i = 0; i < 10; i++) {
					if (terminal == cur->a) {
						term[cou1] = 8;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodetian;
				for (int i = 0; i < 17; i++) {
					if (terminal == cur->a) {
						term[cou1] = 9;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				cur = Nodes9;
				for (int i = 0; i < 6; i++) {
					if (terminal == cur->a) {
						term[cou1] = 10;
						cou1++;
						break;
					}
					else if (find_it(cur->a, terminal)) {
						cou++;
						cout << cur->a << " ";
					}
					cur = cur->next;
				}
				if (cou > 0) {
					cout << endl;
					cout << "请精确站点名称" << endl;
				}
				else if (cou1 == 0)
					cout << "没有找到呢，再输入一次罢" << endl;
			}
			node* current = NULL;
			bool bre = 0;
			int tempno = 0;
			int distance1 = 0;
			int distance = 0;
			int s = 0;
			int coun = 0;
			int* ss = &s;
			int* dd = &distance;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (tsta[i] == term[j] && tsta[i] != 0) {
						cout << "直达，";
						bre = 1;
						tempno = i;
						switch (tsta[i]) {
						case 1: current = Node1; break;
						case 2: current = Node2; break;
						case 3: current = Node3; break;
						case 4: current = Node4; break;
						case 5: current = Node10; break;
						case 6: current = Nodeair; break;
						case 7: current = Nodehe; break;
						case 8: current = Nodeli; break;
						case 9: current = Nodetian; break;
						case 10: current = Nodes9; break;
						}
						distance = 0;
						s = 0;
						ss = &s;
						dd = &distance;
						line(start, terminal, current, ss, dd);
						switch (tsta[tempno]) {
						case 1: cout << "一号线"; break;
						case 2: cout << "二号线"; break;
						case 3: cout << "三号线"; break;
						case 4: cout << "四号线"; break;
						case 5: cout << "十号线"; break;
						case 6: cout << "机场线"; break;
						case 7: cout << "宁和线"; break;
						case 8: cout << "宁溧线"; break;
						case 9: cout << "宁天线"; break;
						case 10: cout << "s9号线"; break;
						}
						cout << "共" << s << "站：" << endl;
						distance1 = distance;
					}
				}
			}
			if (bre == 0) {
				if (tsta[0] > term[0]) {
					for (int i = 0; i < 4; i++) {
						int temp1 = tsta[i];
						tsta[i] = term[i];
						term[i] = temp1;
					}
					string temp = start;
					start = terminal;
					terminal = temp;
				}
				if (tsta[0] == 1 && term[0] == 2) {
					s = distance = 0;
					string c = "新街口";
					cout << "方案一" << endl;
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "二号线 ";
					line(c, terminal, Node2, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "南京站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "大行宫";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "二号线 ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "大行宫";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "二号线 ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案四" << endl;
					c = "鼓楼";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "金马路";
					cout << "四号线 ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "二号线 ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案五" << endl;
					c = "安德门";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "元通";
					cout << "十号线 ";
					line(c, d, Node10, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "二号线 ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案六" << endl;
					c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "油坊桥";
					cout << "宁和线 ";
					line(c, d, Nodehe, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "二号线 ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}
				if (tsta[0] == 1 && term[0] == 3) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京站";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "三号线 ";
					line(c, terminal, Node3, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = distance = 0;
					cout << "方案二 " << endl;
					c = "南京南站";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "三号线 ";
					line(c, terminal, Node3, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "新街口";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "大行宫";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "三号线 ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案四" << endl;
					c = "鼓楼";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "鸡鸣寺";
					cout << "四号线 ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "三号线 ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 4) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "鼓楼";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "四号线 ";
					line(c, terminal, Node4, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "新街口";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "金马路";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "南京站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "鸡鸣寺";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案四" << endl;
					c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "鸡鸣寺";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 5) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "安德门";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "十号线 ";
					line(c, terminal, Node10, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "新街口";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "元通";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}
				if (tsta[0] == 1 && term[0] == 6) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京南站";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "机场线 ";
					line(c, terminal, Nodeair, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}
				if (tsta[0] == 1 && term[0] == 7) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京南站";
					cout << "一号线 ";
					line(start, c, Node1, ss, dd);
					cout << "宁和线 ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "新街口";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "油坊桥";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "禄口机场";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 1 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "一号线 ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "翔宇路南";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 2 && term[0] == 3) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "大行宫";
					cout << "二号线 ";
					line(start, c, Node2, ss, dd);
					cout << "三号线 ";
					line(c, terminal, Node3, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二 " << endl;
					c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "三号线 ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三 " << endl;
					c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "南京站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "三号线 ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案四 " << endl;
					c = "金马路";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "鸡鸣寺";
					cout << "四号线 ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "三号线 ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 4) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "金马路";
					cout << "二号线 ";
					line(start, c, Node2, ss, dd);
					cout << "四号线 ";
					line(c, terminal, Node4, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二 " << endl;
					c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "鼓楼";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三 " << endl;
					c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "南京站";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案四 " << endl;
					c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "南京南站";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 5) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "元通";
					cout << "二号线 ";
					line(start, c, Node2, ss, dd);
					cout << "十号线 ";
					line(c, terminal, Node10, ss, dd);
					cout << "换乘1次" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "安德门";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "机场线 ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "南京南站";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "机场线 ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 7) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "油坊桥";
					cout << "二号线 ";
					line(start, c, Node2, ss, dd);
					cout << "宁和线 ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "禄口机场";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					e = "南京南站";
					cout << "三号线 ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "禄口机场";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 2 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "新街口";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "大行宫";
					if (start != c) {
						cout << "二号线 ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					e = "南京南站";
					cout << "三号线 ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 4) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "鸡鸣寺";
					cout << "三号线 ";
					line(start, c, Node3, ss, dd);
					cout << "四号线 ";
					line(c, terminal, Node4, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "南京站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "鼓楼";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "南京南站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "鼓楼";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "四号线 ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 5) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一 " << endl;
					string c = "南京站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "安德门";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二 " << endl;
					c = "南京南站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "安德门";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "大行宫";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "元通";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 6) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京南站";
					cout << "三号线 ";
					line(start, c, Node3, ss, dd);
					cout << "机场线 ";
					line(c, terminal, Nodeair, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 7) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京南站";
					cout << "三号线 ";
					line(start, c, Node3, ss, dd);
					cout << "宁和线 ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "禄口机场";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 9) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "泰冯路";
					cout << "三号线 ";
					line(start, c, Node3, ss, dd);
					cout << "宁天线 ";
					line(c, terminal, Nodetian, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "三号线 ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "翔宇路南";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 4 && term[0] == 5) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一 " << endl;
					string c = "鼓楼";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "安德门";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "金马路";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "元通";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "十号线 ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "鼓楼";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "机场线 ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "鸡鸣寺";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "南京南站";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "机场线 ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 7) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "金马路";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "油坊桥";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "鼓楼";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "鼓楼";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "禄口机场";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "鸡鸣寺";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					e = "南京南站";
					cout << "三号线 ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "禄口机场";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "鸡鸣寺";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 4 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "鼓楼";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "鸡鸣寺";
					if (start != c) {
						cout << "四号线 ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					e = "南京南站";
					cout << "三号线 ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "机场线 ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 5 && term[0] == 7) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string d = "南京南站";
					cout << "一号线 ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "元通";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					d = "油坊桥";
					cout << "二号线 ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁和线 ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "禄口机场";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 5 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "泰冯路";
					cout << "三号线 ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "方案二" << endl;
					c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					e = "南京站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					d = "泰冯路";
					cout << "三号线 ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "方案三" << endl;
					c = "元通";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					e = "大行宫";
					cout << "二号线 ";
					line(c, e, Node2, ss, dd);
					coun++;
					d = "泰冯路";
					cout << "三号线 ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "安德门";
					if (start != c) {
						cout << "十号线 ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "一号线 ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 7) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "南京南站";
					cout << "机场线 ";
					line(start, c, Nodeair, ss, dd);
					cout << "宁和线 ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 8) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "禄口机场";
					cout << "机场线 ";
					line(start, c, Nodeair, ss, dd);
					cout << "宁溧线 ";
					line(c, terminal, Nodeli, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "机场线 ";
						line(start, c, Nodeair, ss, dd);
						coun++;
					}
					string d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 10) {
					s = distance = 0;
					cout << "方案一 " << endl;
					string c = "翔宇路南";
					cout << "机场线 ";
					line(start, c, Nodeair, ss, dd);
					cout << "s9线 ";
					line(c, terminal, Nodes9, ss, dd);
					cout << "换乘1次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "宁和线 ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "禄口机场";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁溧线 ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "宁和线 ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "泰冯路";
					cout << "三号线 ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "南京南站";
					if (start != c) {
						cout << "宁和线 ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "翔宇路南";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 8 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "禄口机场";
					if (start != c) {
						cout << "宁溧线 ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "机场线 ";
					line(c, e, Nodeair, ss, dd);
					coun++;
					string d = "泰冯路";
					cout << "三号线 ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "宁天线 ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 8 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "禄口机场";
					if (start != c) {
						cout << "宁溧线 ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string d = "翔宇路南";
					cout << "机场线 ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 9 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "方案一" << endl;
					string c = "泰冯路";
					if (start != c) {
						cout << "宁天线 ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string e = "南京南站";
					cout << "三号线 ";
					line(c, e, Node3, ss, dd);
					coun++;
					string d = "翔宇路南";
					cout << "机场线 ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9线 ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "换乘" << coun << "次" << endl;
					cout << "共" << s << "站" << endl;
					distance1 = distance;
				}
			}
			int ticket = price(distance1);
			cout << "票价：" << ticket << "元" << endl;
		}
	}
	return 0;
}