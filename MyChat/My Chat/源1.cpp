#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
using namespace std;

int j = 0;

bool find_it(string s1, string s2) {
	if (s1.find(s2) != string::npos && s1 != s2)
		return 1;
	else
		return 0;
}//��s1����s2;

int friends[10][10] = { 0 };

int random();
void loading();
void requestload();
void friendload();
void circleload();
void likeload();
void commentload();
void recordload();
void phonesearch();
void IDsearch();
void friendapply();
void addfriend();
void leavemessage();
void chatrecords();
void post();
void seecircle();
void friendcircle();
void searchway();
void friendway();
void circlescope();
void revise();
void setting();
void chathall();
void Register();
void Signin();
void menu();

struct node {
	string phone;
	string password;
	string ID;
	int uid;
	int setup;
	//1 ȫ�� 2 ��ֹ�ֻ� 3 ��ֹID 4 ȫban
	int cir;
	//0 �� 1 ��
	bool q;
	//0 �� 1 ��
	string question;
}user[20];

struct comment {
	int uid;
	string ID;
	string context;
}com[30];

struct request {
	string ID1;
	string ID2;
	string answer;
}re[20];

struct circle {
	string context;
	string ID;
	int uid;
}fc[20];

struct like {
	string ID;
	int uid;
}lik[50];

struct record {
	string ID1;
	string ID2;
	string message;
}record[50];

int main() {
	loading();
	requestload();
	friendload();
	circleload();
	commentload();
	likeload();
	recordload();
	initgraph(1080, 720);
	menu();
	return 0;
}

int random() {
	int a = 0;
	srand((unsigned int)time(NULL));
	a = (int)rand() % 10000 + 1000;
	return a;
}

void menu() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 70;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(350, 165, _T("My Chat"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(150, 450, _T("���û�ע��"));
		outtextxy(550, 450, _T("���û���¼"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		//register
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 450 && m.y <= 600) {
			Register();
		}
		//Sign in
		if (m.message == WM_LBUTTONDOWN && m.x >= 550 && m.x <= 800 && m.y >= 450 && m.y <= 600) {
			Signin();
		}
		//chathall
	}
}

void loading() {
	ifstream in_file("�û�.txt", ios::in);
	int i = 0;
	while (!in_file.fail())
	{
		in_file >> user[i].phone;
		in_file >> user[i].password;
		in_file >> user[i].ID;
		in_file >> user[i].uid;
		in_file >> user[i].setup;
		in_file >> user[i].cir;
		in_file >> user[i].q;
		in_file >> user[i].question;
		i++;
	}
	in_file.close();
}

void requestload() {
	ifstream in_file("request.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		in_file >> re[i].ID1;
		in_file >> re[i].ID2;
		in_file >> re[i].answer;
		i++;
	}
	in_file.close();
}

void friendload() {
	ifstream in_file("friend.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		for (int i1 = 0; i1 < 10; i1++) {
			for (int i2 = 0; i2 < 10; i2++) {
				in_file >> friends[i1][i2];
			}
		}
	}
	in_file.close();
}

void circleload() {
	ifstream in_file("circle.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		in_file >> fc[i].uid;
		in_file >> fc[i].ID;
		in_file >> fc[i].context;
		i++;
	}
}

void likeload() {
	ifstream in_file("like.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		in_file >> lik[i].uid;
		in_file >> lik[i].ID;
		i++;
	}
}

void commentload() {
	ifstream in_file("comment.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		in_file >> com[i].uid;
		in_file >> com[i].ID;
		in_file >> com[i].context;
		i++;
	}
}

void recordload() {
	ifstream in_file("record.txt", ios::in);
	int i = 0;
	while (!in_file.fail()) {
		in_file >> record[i].ID1;
		in_file >> record[i].ID2;
		in_file >> record[i].message;
		i++;
	}
}

void phonesearch() {
	char phone[13] = { 0 };
	int phyes = InputBox(phone, 12, "�������ֻ���", "", "", 0, 0, false);
	if (phyes == 1) {
		string pphone = phone;
		request* r = new request;
		bool psyes = 0;
		for (int i = 0; i < 20; i++) {
			if (pphone == user[i].phone && (user[i].setup == 1 || user[i].setup == 3)) {
				string a = "�Ƿ���Ӻ��� ";
				a += user[i].ID;
				int seyes = InputBox(NULL, 0, a.c_str(), "", "", 0, 0, false);
				char answer[20] = { 0 };
				if (seyes == 1) {
					if (user[i].q == 1) {
						int seyes = InputBox(answer, 19, user[i].question.c_str(), "", "", 0, 0, false);
						r->answer = answer;
					}
					else
						answer[0] = '0';
					r->ID1 = user[i].ID;
					r->ID2 = user[j].ID;
					r->answer = answer;
				}
				break;
			}
			else if (i == 19) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "δ�ҵ���Ӧ�û�", "Error", MB_OKCANCEL);
				break;
			}
		}
		int i = 0;
		while (re[i].ID1[0]) {
			i++;
		}
		re[i].ID1 = r->ID1;
		re[i].ID2 = r->ID2;
		re[i].answer = r->answer;
		ofstream out_file("request.txt", ios::out);
		if (!out_file)
			exit(-1);
		for (int k = 0; k <= i; k++) {
			out_file << re[k].ID1 << " " << re[k].ID2 << " " << re[k].answer << endl;
		}
	}
}

void IDsearch() {
	char ID[20] = { 0 };
	int phyes = InputBox(ID, 12, "������ID", "", "", 0, 0, false);
	if (phyes == 1) {
		string pphone = ID;
		request* r = new request;
		bool psyes = 0;
		for (int i = 0; i < 20; i++) {
			if (pphone == user[i].ID && (user[i].setup == 1 || user[i].setup == 2)) {
				string a = "�Ƿ���Ӻ��� ";
				a += user[i].ID;
				int seyes = InputBox(NULL, 0, a.c_str(), "", "", 0, 0, false);
				char answer[20] = { 0 };
				if (seyes == 1) {
					if (user[i].q == 1) {
						int seyes = InputBox(answer, 19, user[i].question.c_str(), "", "", 0, 0, false);
						r->answer = answer;
					}
					else
						answer[0] = '0';
					r->ID1 = user[i].ID;
					r->ID2 = user[j].ID;
					r->answer = answer;
				}
				break;
			}
			else if (i == 19) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "δ�ҵ���Ӧ�û�", "Error", MB_OKCANCEL);
				break;
			}
		}
		int i = 0;
		while (re[i].ID1[0]) {
			i++;
		}
		re[i].ID1 = r->ID1;
		re[i].ID2 = r->ID2;
		re[i].answer = r->answer;
		ofstream out_file("request.txt", ios::out);
		if (!out_file)
			exit(-1);
		for (int k = 0; k <= i; k++) {
			out_file << re[k].ID1 << " " << re[k].ID2 << " " << re[k].answer << endl;
		}
	}
}

void friendapply() {
	int i = 0;
	while (re[i].ID1[0]) {
		if (re[i].ID1 == user[j].ID) {
			if (user[j].q == 1) {
				InputBox(NULL, 0, re[i].answer.c_str(), "", "", 0, 0, false);
			}
			string a = "�Ƿ���Ӻ���:";
			a += re[i].ID2;
			int apply = InputBox(NULL, 0, a.c_str(), "", "", 0, 0, false);
			if (apply == 1) {
				int p = 0;
				int k = 0;
				for (k = 0; k < 10; k++) {
					if (user[k].ID == re[i].ID2)
						break;
				}
				friends[user[j].uid][user[k].uid] = 1;
				friends[user[k].uid][user[j].uid] = 1;
				ofstream out_file("friend.txt", ios::out);
				if (!out_file)
					exit(-1);
				for (int i1 = 0; i1 < 10; i1++) {
					for (int i2 = 0; i2 < 10; i2++) {
						out_file << friends[i1][i2] << " ";
					}
					out_file << endl;
				}
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "��ӳɹ�", " ", MB_OKCANCEL);
			}
			for (i; i < 19; i++) {
				re[i] = re[i + 1];
			}
			i--;
		}
		i++;
	}
	HWND hnd = GetHWnd();
	int is_ok = MessageBox(hnd, "������Ҫ���������", " ", MB_OKCANCEL);
	ofstream out_file("request.txt", ios::out);
	if (!out_file)
		exit(-1);
	for (int k = 0; k < 20; k++) {
		out_file << re[k].ID1 << " " << re[k].ID2 << endl;
	}
}

void addfriend() {
	closegraph();
	initgraph(1080, 720);
	requestload();
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 165, _T("��Ӻ���"));
		outtextxy(150, 350, _T("�ֻ�������"));
		outtextxy(500, 350, _T("ID����"));
		outtextxy(150, 550, _T("�鿴��������"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 600, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			phonesearch();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			IDsearch();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 550 && m.y <= 650) {
			friendapply();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 600) {
			break;
		}
	}
	chathall();
}

void leavemessage() {
	closegraph();
	initgraph(1080, 720);
	int p = 0;
	int k = -1;
	int temp[10] = { 0 };
	bool v = 0;
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		settextcolor(WHITE);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		f.lfHeight = 40;
		settextstyle(&f);
		k = -1;
		int w = 0;
		while (w < 10) {
			if (friends[j][w] == 1) {
				k++;
				temp[k] = w;
				if (k % 2 == 0) {
					outtextxy(100, 150 + k / 2 * 50, user[w].ID.c_str());			
				}
				if (k % 2 != 0) {
					outtextxy(500, 150 + k / 2 * 50, user[w].ID.c_str());
				}
			}
			w++;
		}
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 150) {
			p = (m.y - 150) / 50 * 2;
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 300) {
			p = (m.y - 150) / 50 * 2 + 1;
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 680) {
			v = 1;
			break;
		}
	}
	if (v == 0) {
		closegraph();
		initgraph(1080, 720);
		int l = 0;
		int q = 0;
		int temp1[10] = { 0 };
		for (int i = 0; i < 10; i++)
			temp1[i] = -1;
		while (record[l].ID1[0]) {
			if ((record[l].ID1 == user[j].ID && record[l].ID2 == user[temp[p]].ID) || (record[l].ID2 == user[j].ID && record[l].ID1 == user[temp[p]].ID)) {
				temp1[q] = l;
				q++;
			}
			l++;
		}
		while (1) {
			int w = 0;
			while (temp1[w] != -1) {
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(WHITE);
				f.lfHeight = 40;
				settextstyle(&f);
				outtextxy(50, 100 + w * 50, record[temp1[w]].ID1.c_str());
				outtextxy(300, 100 + w * 50, record[temp1[w]].message.c_str());
				w++;
			}
			LOGFONT f;
			gettextstyle(&f);
			settextcolor(WHITE);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(900, 100, _T("����"));
			outtextxy(900, 650, _T("�˳�"));
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			if (m.message == WM_LBUTTONDOWN && m.x >= 850 && m.y <= 200) {
				char message[50];
				int leyes = InputBox(message, 50, "����������", "", "", 0, 0, false);
				if (leyes == 1) {
					record[l].ID1 = user[j].ID;
					record[l].ID2 = user[temp[p]].ID;
					record[l].message = message;
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "���Գɹ�", " ", MB_OKCANCEL);
					l++;
					ofstream out_file("record.txt", ios::out);
					if (!out_file)
						exit(-1);
					for (int n = 0; n < l; n++) {
						out_file << record[n].ID1 << " " << record[n].ID2 << " " << record[n].message << endl;
					}
				}
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 850 && m.y >= 600) {
				break;
			}
		}
	}
	chathall();
}

void chatrecords() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		outtextxy(300, 100, _T("�����Ѳ����뵽���Թ���"));
		settextstyle(&f);
		outtextxy(300, 400, _T("���ؼ��ʲ���"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 600, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 400 && m.y >= 300 && m.y <= 500) {
			char message[50] = { 0 };
			int meme = InputBox(message, 50, "������ؼ���", "", "", 0, 0, false);
			if (meme == 0)
				continue;
			cleardevice();
			int i = 0;
			int t = 0;
			bool findyes = 0;
			while (i < 50) {
				if (record[i].ID1 == user[j].ID || record[i].ID2 == user[j].ID) {
					string mmes = message;
					if (find_it(record[i].message, mmes)) {
						outtextxy(50, 100 + t * 50, record[i].ID1.c_str());
						outtextxy(300, 100 + t * 50, record[i].message.c_str());
						t++;
						findyes = 1;
					}
				}
				else if (i == 19) {
					if (findyes == 0) {
						HWND hnd = GetHWnd();
						int is_ok = MessageBox(hnd, "δ�ҵ���Ӧ�����¼", " ", MB_OKCANCEL);
					}
					else if (findyes == 1) {
						HWND hnd = GetHWnd();
						int is_ok = MessageBox(hnd, "�������", " ", MB_OKCANCEL);
						cleardevice();
					}
				}
				i++;
			}
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 600) {
			break;
		}
	}
	chathall();
}

void post() {
	char message[50];
	int postyes = InputBox(message, 50, "����������", "", "", 0, 0, false);
	if (postyes == 1) {
		HWND hnd = GetHWnd();
		int is_ok = MessageBox(hnd, "�����ɹ�", " ", MB_OKCANCEL);
		int i = 0;
		while (fc[i].ID[0] != 0) {
			i++;
		}
		fc[i].uid = i;
		fc[i].context = message;
		fc[i].ID = user[j].ID;
		ofstream out_file("circle.txt", ios::out);
		if (!out_file)
			exit(-1);
		for (int k = 0; k <= i; k++) {
			out_file << fc[k].uid << " " << fc[k].ID << " " << fc[k].context << " " << endl;
		}
	}
}

void seecircle() {
	cleardevice();
	int i = 0;
	int temp[10] = { 0 };
	int k = 0;
	int op = 0;
	while (k < 30) {
		if (fc[k].ID == user[j].ID) {
			temp[op] = k;
			op++;
		}
		else if (fc[k].ID != user[j].ID) {
			for (int u = 0; u < 10; u++) {
				if (friends[j][u] == 1 && user[u].ID == fc[k].ID && user[u].cir == 0) {
					temp[op] = k;
					op++;
					break;
				}
			}
		}
		k++;
	}
	op = 0;
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(50, 50, fc[temp[op]].ID.c_str());
		outtextxy(150, 100, fc[temp[op]].context.c_str());
		outtextxy(150, 300, _T("����"));
		outtextxy(550, 300, _T("����"));
		outtextxy(150, 425, _T("�鿴����"));
		outtextxy(550, 425, _T("�鿴����"));
		outtextxy(150, 550, _T("��һ��"));
		outtextxy(550, 550, _T("��һ��"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 675, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		//comment
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 300 && m.y <= 400) {
			char message[50];
			int comyes = InputBox(message, 50, "��������������", "", "", 0, 0, false);
			if (comyes == 0)
				continue;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�����ɹ�", " ", MB_OKCANCEL);
			int nm = 0;
			while (com[nm].ID[0]) {
				nm++;
			}
			com[nm].ID = user[j].ID;
			com[nm].context = message;
			com[nm].uid = fc[temp[op]].uid;
			ofstream out_file("comment.txt", ios::out);
			if (!out_file)
				exit(-1);
			for (int k = 0; k <= nm; k++) {
				out_file << com[k].uid << " " << com[k].ID << " " << com[k].context << " " << endl;
			}
		}
		//like
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 700 && m.y >= 300 && m.y <= 400) {
			int nm = 0;
			bool likeit = 0;
			while (lik[nm].ID[0]) {
				if (lik[nm].ID == user[j].ID && lik[nm].uid == fc[temp[op]].uid) {
					likeit = 1;
				}
				nm++;
			}
			if (likeit == 0) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "���޳ɹ�", " ", MB_OKCANCEL);
				lik[nm].ID = user[j].ID;
				lik[nm].uid = fc[temp[op]].uid;
				ofstream out_file("like.txt", ios::out);
				if (!out_file)
					exit(-1);
				for (int k = 0; k <= nm; k++) {
					out_file << lik[k].uid << " " << lik[k].ID << " " << endl;
				}
			}
			else if (likeit == 1) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "���Ѿ��޹���Ŷ", " ", MB_OKCANCEL);
			}
		}
		//seecomment
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 425 && m.y <= 525) {
			closegraph();
			initgraph(1080, 720);
			while (1) {
				int k = 0;
				int t = 0;
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 40;
				settextcolor(WHITE);
				settextstyle(&f);
				while (com[k].context[0]) {
					if (com[k].uid == fc[temp[op]].uid) {
						outtextxy(50, 50 + t * 50, com[k].ID.c_str());
						outtextxy(250, 50 + t * 50, com[k].context.c_str());
						t++;
					}
					k++;
				}
				f.lfHeight = 30;
				settextstyle(&f);
				outtextxy(800, 600, _T("�˳�"));
				ExMessage mm;
				mm = getmessage(EX_MOUSE | EX_KEY);
				if (mm.message == WM_LBUTTONDOWN && mm.x >= 800 && mm.y >= 600) {
					cleardevice();
					break;
				}
			}
		}
		//seelike
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 700 && m.y >= 425 && m.y <= 525) {
			closegraph();
			initgraph(1080, 720);
			while (1) {
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 40;
				settextcolor(WHITE);
				settextstyle(&f);
				int k = 0;
				int t = 0;
				while (lik[k].ID[0]) {
					if (lik[k].uid == fc[temp[op]].uid) {
						outtextxy(100, 50 + t * 50, lik[k].ID.c_str());
						t++;
					}
					k++;
				}
				f.lfHeight = 30;
				settextstyle(&f);
				outtextxy(800, 600, _T("�˳�"));
				ExMessage mm;
				mm = getmessage(EX_MOUSE | EX_KEY);
				if (mm.message == WM_LBUTTONDOWN && mm.x >= 800 && mm.y >= 600) {
					cleardevice();
					break;
				}
			}
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 550 && m.y <= 650) {
			if (op > 0) {
				cleardevice();
				op--;
				continue;
			}
			else {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "�Ѿ��ǵ�һ����", " ", MB_OKCANCEL);
			}
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 700 && m.y >= 550 && m.y <= 650) {
			if (temp[op + 1] != 0) {
				cleardevice();
				op++;
				continue;
			}
			else {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "�Ѿ������һ����", " ", MB_OKCANCEL);
			}
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 675) {
			break;
		}
	}
	friendcircle();
}

void friendcircle() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 150, _T("�鿴����Ȧ"));
		outtextxy(150, 450, _T("��������Ȧ"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 600, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 150 && m.y <= 250) {
			seecircle();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 450 && m.y <= 550) {
			post();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 600) {
			break;
		}
	}
	chathall();
}

void searchway() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 165, _T("��ѡ�����뱻�������ķ�ʽ"));
		outtextxy(150, 350, _T("���ɱ�����"));
		outtextxy(500, 350, _T("����ͨ���ֻ���"));
		outtextxy(150, 550, _T("����ͨ���ǳ�"));
		outtextxy(500, 550, _T("���ɱ�����"));
		f.lfHeight =30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			user[j].setup = 1;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			user[j].setup = 2;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 550 && m.y <= 650) {
			user[j].setup = 3;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 550 && m.y <= 650) {
			user[j].setup = 4;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800&& m.y >= 680) {
			break;
		}
	}
	ofstream out_file("�û�.txt", ios::out);
	if (!out_file)
		exit(-1);
	int i = 0;
	while (user[i].phone[0]) {
		out_file << user[i].phone << " " << user[i].password << " " << user[i].ID << " " << user[i].uid << " " << user[i].cir << " " << user[i].setup << " " << user[i].q << " " << user[i].question << endl;
		i++;
	}
	setting();
}

void friendway() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 165, _T("�趨ͨ����������ķ�ʽ"));
		outtextxy(150, 350, _T("Ĭ��ͨ��"));
		outtextxy(500, 350, _T("��������֤"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			user[j].q = 0;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			user[j].q = 1;
			char ques[30];
			InputBox(ques, 50, "����������");
			user[j].question = ques;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 680) {
			break;
		}
	}
	ofstream out_file("�û�.txt", ios::out);
	if (!out_file)
		exit(-1);
	int i = 0;
	while (user[i].phone[0]) {
		out_file << user[i].phone << " " << user[i].password << " " << user[i].ID << " " << user[i].uid << " " << user[i].cir << " " << user[i].setup << " " << user[i].q << " " << user[i].question << endl;
		i++;
	}
	setting();
}

void circlescope() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 165, _T("�趨����Ȧչʾ��Χ"));
		outtextxy(150, 350, _T("���ѿɼ�"));
		outtextxy(500, 350, _T("���Լ��ɼ�"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			user[j].cir = 0;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			user[j].cir = 1;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 680) {
			break;
		}
	}
	ofstream out_file("�û�.txt", ios::out);
	if (!out_file)
		exit(-1);
	int i = 0;
	while (user[i].phone[0]) {
		out_file << user[i].phone << " " << user[i].password << " " << user[i].ID << " " << user[i].uid << " " << user[i].cir << " " << user[i].setup << " " << user[i].q << " " << user[i].question << endl;
		i++;
	}
	setting();
}

void revise() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 250, _T("�޸��ǳ�"));
		outtextxy(500, 250, _T("�޸�����"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 250 && m.y <= 350) {
			char ID[20] = { 0 };
			InputBox(ID, 20, "�������ǳ�");
			user[j].ID = ID;
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 250 && m.y <= 350) {
			char password[20] = { 0 };
			char repass[20] = { 0 };
			bool pass = 0;
			while (1) {
				while (pass == 0) {
					int passyes = InputBox(password, 19, "�����������루����8λ��", "", "", 0, 0, false);
					if (passyes == 0)
						continue;
					for (int i = 0; i < 8; i++) {
						if (password[i] == 0) {
							HWND hnd = GetHWnd();
							int is_ok = MessageBox(hnd, "�����������", "Error", MB_OKCANCEL);
							break;
						}
						else if (i == 7)
							pass = 1;
					}
				}
				int repassyes = InputBox(repass, 19, "���ٴ���������", "", "", 0, 0, false);
				if (repassyes == 0)
					continue;
				if (strcmp(repass, password) == 0) {
					user[j].password = password;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "�����������", "Error", MB_OKCANCEL);
					pass = 0;
				}
			}
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�޸ĳɹ�", " ", MB_OKCANCEL);
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 600) {
			break;
		}
	}
	ofstream out_file("�û�.txt", ios::out);
	if (!out_file)
		exit(-1);
	int i = 0;
	while (user[i].phone[0]) {
		out_file << user[i].phone << " " << user[i].password << " " << user[i].ID << " " << user[i].uid << " " << user[i].cir << " " << user[i].setup << " " << user[i].q << " " << user[i].question << endl;
		i++;
	}
}

void setting() {
	closegraph();
	initgraph(1080, 720);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 150, _T("�ɱ�������ʽ"));
		outtextxy(500, 150, _T("ͨ����������ʽ"));
		outtextxy(150, 350, _T("����Ȧչʾ��Χ"));
		outtextxy(500, 350, _T("�޸��ǳ�/����"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 150 && m.y <= 250) {
			searchway();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 150 && m.y <= 250) {
			friendway();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			circlescope();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			revise();
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 680) {
			break;
		}
	}
	chathall();
}

void chathall() {
	closegraph();
	initgraph(1080, 720);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 40;
	settextcolor(WHITE);
	settextstyle(&f);
	while (1) {
		outtextxy(150, 150, _T("��Ӻ���"));
		outtextxy(500, 150, _T("����"));
		outtextxy(150, 350, _T("�鿴�����¼"));
		outtextxy(500, 350, _T("����Ȧ"));
		outtextxy(150, 550, _T("����"));
		outtextxy(500, 550, _T("����"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 150 && m.y <= 250) {
			addfriend();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 150 && m.y <= 250) {
			leavemessage();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 350 && m.y <= 450) {
			chatrecords();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 350 && m.y <= 450) {
			friendcircle();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 550 && m.y <= 650) {
			setting();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 550 && m.y <= 650) {
			menu();
			break;
		}
	}
}

void Register() {
	char phone[13] = { 0 };
	bool ph = 0;
	node* account = new node;
	while (ph == 0) {
		int phyes = InputBox(phone, 12, "�������ֻ���", "���û�ע��", "", 0, 0, false);
		if (phyes == 0)
			menu();
		for (int i = 0; i < 11; i++) {
			if (phone[i] < '0' || phone[i]>'9' || phone[0] == '0') {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "�ֻ����������", "Error", MB_OKCANCEL);
				break;
			}
			else if (i == 10) {
				ph = 1;
				account->phone = phone;
			}
		}
	}
	char password[20] = { 0 };
	char repass[20] = { 0 };
	bool pass = 0;
	while (1) {
		while (pass == 0) {
			int passyes = InputBox(password, 19, "���������루����8λ��", "���û�ע��", "", 0, 0, false);
			if (passyes == 0)
				menu();
			for (int i = 0; i < 8; i++) {
				if (password[i] == 0) {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "�����������", "Error", MB_OKCANCEL);
					break;
				}
				else if (i == 7)
					pass = 1;
			}
		}
		int repassyes = InputBox(repass, 19, "���ٴ���������", "���û�ע��", "", 0, 0, false);
		if (repassyes == 0)
			menu();
		if (strcmp(repass, password) == 0) {
			account->password = password;
			break;
		}
		else {
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "�����������", "Error", MB_OKCANCEL);
			pass = 0;
		}
	}
	bool yanzheng = 0;
	while (yanzheng == 0) {
		char yzm[5] = { 0 };
		char yz[5] = { 0 };
		int a = random();
		for (int i = 0; i < 4; i++) {
			yz[i] = a % 10 + '0';
			a /= 10;
		}
		string tempyz = yz;
		string str = "��������֤��";
		str += tempyz;
		int yzyes = InputBox(yzm, 5, str.c_str(), "���û�ע��", "", 0, 0, false);
		if (yzyes == 0)
			menu();
		for (int i = 0; i < 4; i++) {
			if (yzm[i] != tempyz[i]) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "��֤���������", "Error", MB_OKCANCEL);
				break;
			}
			else if (i == 3)
				yanzheng = 1;
		}
	}
	char ID[20] = { 0 };
	int idyes = InputBox(ID, 20, "�������ǳ�", "���û�ע��", "", 0, 0, false);
	if (idyes == 0)
		menu();
	int i = 0;
	while (user[i].phone[0])
		i++;
	account->uid = i;
	account->ID = ID;
	account->setup = 1;
	account->cir = 0;
	account->q = 0;
	account->question = "0";
	ofstream out_file("�û�.txt", ios::out);
	if (!out_file)
		exit(-1);
	j = 0;
	while (user[j].phone[0]) {
		out_file << user[j].phone << " " << user[j].password << " " << user[j].ID << " " << user[j].uid << " " << user[j].setup << " " << user[j].cir << " " << user[j].q << " " << user[j].question << endl;
		j++;
	}
	user[j] = *account;
	out_file << account->phone << " " << account->password << " " << account->ID << " " << account->uid << " " << account->setup << " " << account->cir << " " << account->q << " " << account->question << endl;
	chathall();
}

void Signin() {
	closegraph;
	initgraph(1080, 720);
	bool OK = 0;
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(WHITE);
		settextstyle(&f);
		outtextxy(150, 150, _T("�ֻ��ŵ�¼"));
		outtextxy(500, 150, _T("ID��¼"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("�˳�"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		int i = 0;
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 150 && m.y <= 250) {
			char phone[13] = { 0 };
			bool ph = 0;
			i = 0;
			while (ph == 0) {
				int phyes = InputBox(phone, 12, "�������ֻ���", "", "", 0, 0, false);
				if (phyes == 0)
					break;
				i = 0;
				string pphone = phone;
				while (user[i].phone[0]) {
					if (pphone == user[i].phone) {
						ph = 1;
						break;
					}
					i++;
				}
				if (ph == 0) {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "�ֻ��Ŵ���", "Error", MB_OKCANCEL);
				}
			}
			bool pass = 0;
			char password[20] = { 0 };
			while (pass == 0) {
				int pyes = InputBox(password, 19, "����������", "", "", 0, 0, false);
				if (pyes == 0)
					break;
				string ppass = password;
				if (ppass == user[i].password) {
					pass = 1;
					OK = 1;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "�������", "Error", MB_OKCANCEL);
				}
			}
			j = i;
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 150 && m.y <= 250) {
			char ID[20] = { 0 };
			bool id = 0;
			i = 0;
			while (id == 0) {
				int idyes = InputBox(ID, 12, "������ID", "", "", 0, 0, false);
				if (idyes == 0)
					break;
				i = 0;
				string IID = ID;
				while (user[i].ID[0]) {
					if (IID == user[i].ID) {
						id = 1;
						break;
					}
					i++;
				}
				if (id == 0) {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "ID����", "Error", MB_OKCANCEL);
				}
			}
			bool pass = 0;
			char password[20] = { 0 };
			while (pass == 0) {
				int pyes = InputBox(password, 19, "����������", "", "", 0, 0, false);
				if (pyes == 0)
					break;
				string ppass = password;
				if (ppass == user[i].password) {
					pass = 1;
					OK = 1;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "�������", "Error", MB_OKCANCEL);
				}
			}
			j = i;
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 680) {
			break;
		}
	}
	if (OK == 1) {
		chathall();
	}
	else if (OK == 0) {
		menu();
	}
}