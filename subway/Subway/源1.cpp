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
//0 = ��ɫ 8 = ��ɫ
//1 = ��ɫ 9 = ����ɫ
//2 = ��ɫ 10 = ����ɫ
//3 = ǳ��ɫ 11 = ��ǳ��ɫ
//4 = ��ɫ 12 = ����ɫ
//5 = ��ɫ 13 = ����ɫ
//6 = ��ɫ 14 = ����ɫ
//7 = ��ɫ 15 = ����ɫ

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
}//��s1����s2

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

	colorprint("�Ͼ�����Ʊ��ϵͳ", 2);
	cout << endl;
	int a = 0, b1 = 0;
	while (1) {
		a = -1, b1 = 0;
		cout << "����0�˳�" << endl;
		while (a != 1 && a != 2 && a != 0) {
			colorprint("������Ϣ��ѯ��������1", 9);
			cout << endl;
			colorprint("����Ʊ���ѯ��������2", 9);
			cout << endl;
			cin >> a;
		}
		if (a == 0)
			break;
		if (a == 1) {
			while (b1 != 1 && b1 != 2) {
				colorprint("��·��ѯ��������1", 13);
				cout << endl;
				colorprint("վ���ѯ��������2", 13);
				cout << endl;
				cin >> b1;
			}
			if (b1 == 1) {
				int b = 0;
				while (b > 10 || b < 1) {
					cout << "��������Ҫ��ѯ����·��һ����������1��������������2��������������3���ĺ���������4��ʮ����������5��������������6��������������7��������������8��������������9��s9��������10" << endl;
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
					cout << "������վ������" << endl;
					cin >> c1;
					node* cur = Node1;
					cou = 0;
					for (int i = 0; i < 27; i++) {
						if (c1 == cur->a) {
							cout << "һ���� ";
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
							cout << "������ ";
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
							cout << "������ ";
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
							cout << "�ĺ��� ";
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
							cout << "ʮ���� ";
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
							cout << "������ ";
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
							cout << "������ ";
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
							cout << "������ ";
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
							cout << "������ ";
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
							cout << "s9�� ";
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
						cout << "�뾫ȷվ������" << endl;
					else if (cou1 == 0)
						cout << "û���ҵ��أ�������һ�ΰ�" << endl;
				}
			}
		}
		//Ʊ���ѯ
		if (a == 2) {
			int cou = 0, cou1 = 0;
			int tsta[4] = { 0 };
			int term[4] = { 0 };
			string start;
			while (cou1 == 0) {
				cout << "���������վ" << endl;
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
					cout << "�뾫ȷվ������" << endl;
				else if (cou1 == 0)
					cout << "û���ҵ��أ�������һ�ΰ�" << endl;
			}
			string terminal;
			cou = 0, cou1 = 0;
			while (cou1 == 0) {
				cout << "�������յ�վ" << endl;
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
					cout << "�뾫ȷվ������" << endl;
				}
				else if (cou1 == 0)
					cout << "û���ҵ��أ�������һ�ΰ�" << endl;
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
						cout << "ֱ�";
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
						case 1: cout << "һ����"; break;
						case 2: cout << "������"; break;
						case 3: cout << "������"; break;
						case 4: cout << "�ĺ���"; break;
						case 5: cout << "ʮ����"; break;
						case 6: cout << "������"; break;
						case 7: cout << "������"; break;
						case 8: cout << "������"; break;
						case 9: cout << "������"; break;
						case 10: cout << "s9����"; break;
						}
						cout << "��" << s << "վ��" << endl;
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
					string c = "�½ֿ�";
					cout << "����һ" << endl;
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "������ ";
					line(c, terminal, Node2, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ�վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "���й�";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "���й�";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "��¥";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "����·";
					cout << "�ĺ��� ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "������";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "Ԫͨ";
					cout << "ʮ���� ";
					line(c, d, Node10, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "�ͷ���";
					cout << "������ ";
					line(c, d, Nodehe, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node2, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}
				if (tsta[0] == 1 && term[0] == 3) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ�վ";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "������ ";
					line(c, terminal, Node3, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = distance = 0;
					cout << "������ " << endl;
					c = "�Ͼ���վ";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "������ ";
					line(c, terminal, Node3, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "���й�";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "��¥";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "������";
					cout << "�ĺ��� ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 4) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "��¥";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "�ĺ��� ";
					line(c, terminal, Node4, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "����·";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ�վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "������";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "������";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 5) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "������";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "ʮ���� ";
					line(c, terminal, Node10, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "Ԫͨ";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}
				if (tsta[0] == 1 && term[0] == 6) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ���վ";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodeair, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}
				if (tsta[0] == 1 && term[0] == 7) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ���վ";
					cout << "һ���� ";
					line(start, c, Node1, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "�ͷ���";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "»�ڻ���";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 1 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ�վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 1 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "һ���� ";
						line(start, c, Node1, ss, dd);
						coun++;
					}
					string d = "����·��";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 2 && term[0] == 3) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "���й�";
					cout << "������ ";
					line(start, c, Node2, ss, dd);
					cout << "������ ";
					line(c, terminal, Node3, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "�Ͼ�վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "����·";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "������";
					cout << "�ĺ��� ";
					line(c, d, Node4, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Node3, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 4) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "����·";
					cout << "������ ";
					line(start, c, Node2, ss, dd);
					cout << "�ĺ��� ";
					line(c, terminal, Node4, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "��¥";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "�Ͼ�վ";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "�Ͼ���վ";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 5) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "Ԫͨ";
					cout << "������ ";
					line(start, c, Node2, ss, dd);
					cout << "ʮ���� ";
					line(c, terminal, Node10, ss, dd);
					cout << "����1��" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "������";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					d = "�Ͼ���վ";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 7) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�ͷ���";
					cout << "������ ";
					line(start, c, Node2, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "»�ڻ���";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "»�ڻ���";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 2 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 2 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�½ֿ�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node2, ss, dd);
						coun++;
					}
					e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 4) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "������";
					cout << "������ ";
					line(start, c, Node3, ss, dd);
					cout << "�ĺ��� ";
					line(c, terminal, Node4, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ�վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "��¥";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "��¥";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "�ĺ��� ";
						line(d, terminal, Node4, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 5) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ " << endl;
					string c = "�Ͼ�վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "������";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������ " << endl;
					c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "������";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "���й�";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					d = "Ԫͨ";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 3 && term[0] == 6) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ���վ";
					cout << "������ ";
					line(start, c, Node3, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodeair, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 7) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ���վ";
					cout << "������ ";
					line(start, c, Node3, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "»�ڻ���";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 9) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "̩��·";
					cout << "������ ";
					line(start, c, Node3, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodetian, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 3 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Node3, ss, dd);
						coun++;
					}
					string d = "����·��";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 4 && term[0] == 5) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ " << endl;
					string c = "��¥";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "������";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "����·";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "Ԫͨ";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "ʮ���� ";
						line(d, terminal, Node10, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "��¥";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "������";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "�Ͼ���վ";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 7) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "����·";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "�ͷ���";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "��¥";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "��¥";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "»�ڻ���";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "������";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "»�ڻ���";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 4 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 4 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "��¥";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "������";
					if (start != c) {
						cout << "�ĺ��� ";
						line(start, c, Node4, ss, dd);
						coun++;
					}
					e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Node3, ss, dd);
					coun++;
					d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 6) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeair, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 5 && term[0] == 7) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string d = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, d, Node1, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "Ԫͨ";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					d = "�ͷ���";
					cout << "������ ";
					line(c, d, Node2, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodehe, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "»�ڻ���";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 5 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "̩��·";
					cout << "������ ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					e = "�Ͼ�վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					d = "̩��·";
					cout << "������ ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);

					s = 0, distance = 0, coun = -1;
					cout << "������" << endl;
					c = "Ԫͨ";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					e = "���й�";
					cout << "������ ";
					line(c, e, Node2, ss, dd);
					coun++;
					d = "̩��·";
					cout << "������ ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = mymin(distance1, distance);
				}

				if (tsta[0] == 5 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "������";
					if (start != c) {
						cout << "ʮ���� ";
						line(start, c, Node10, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "һ���� ";
					line(c, e, Node1, ss, dd);
					coun++;
					string d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 7) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "�Ͼ���վ";
					cout << "������ ";
					line(start, c, Nodeair, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodehe, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 8) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "»�ڻ���";
					cout << "������ ";
					line(start, c, Nodeair, ss, dd);
					cout << "������ ";
					line(c, terminal, Nodeli, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodeair, ss, dd);
						coun++;
					}
					string d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 6 && term[0] == 10) {
					s = distance = 0;
					cout << "����һ " << endl;
					string c = "����·��";
					cout << "������ ";
					line(start, c, Nodeair, ss, dd);
					cout << "s9�� ";
					line(c, terminal, Nodes9, ss, dd);
					cout << "����1��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 8) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "»�ڻ���";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodeli, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "̩��·";
					cout << "������ ";
					line(c, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 7 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "�Ͼ���վ";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodehe, ss, dd);
						coun++;
					}
					string d = "����·��";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 8 && term[0] == 9) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "»�ڻ���";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Nodeair, ss, dd);
					coun++;
					string d = "̩��·";
					cout << "������ ";
					line(e, d, Node3, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "������ ";
						line(d, terminal, Nodetian, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 8 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "»�ڻ���";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string d = "����·��";
					cout << "������ ";
					line(c, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}

				if (tsta[0] == 9 && term[0] == 10) {
					s = 0, distance = 0, coun = -1;
					cout << "����һ" << endl;
					string c = "̩��·";
					if (start != c) {
						cout << "������ ";
						line(start, c, Nodeli, ss, dd);
						coun++;
					}
					string e = "�Ͼ���վ";
					cout << "������ ";
					line(c, e, Node3, ss, dd);
					coun++;
					string d = "����·��";
					cout << "������ ";
					line(e, d, Nodeair, ss, dd);
					coun++;
					if (d != terminal) {
						cout << "s9�� ";
						line(d, terminal, Nodes9, ss, dd);
						coun++;
					}
					cout << "����" << coun << "��" << endl;
					cout << "��" << s << "վ" << endl;
					distance1 = distance;
				}
			}
			int ticket = price(distance1);
			cout << "Ʊ�ۣ�" << ticket << "Ԫ" << endl;
		}
	}
	return 0;
}