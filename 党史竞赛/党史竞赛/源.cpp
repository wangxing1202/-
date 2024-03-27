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

int mystrlen(string a) {
	int i = 0;
	while (a[i])
		i++;
	i--;
	return i;
}

struct node {
	string ID;
	string password;
	int exam;
	//0 未做 1 已做
}user[20];

struct ques {
	string problem;
	string right;
	string A;
	string B;
	string C;
}question[200];

struct ranks {
	string ID;
	string score;
	string time;
}rankl[20];

void menu();
void Register();
void Signin();
void loading();
void hall();
void exam();
void practice();
void imitate();
void quesload();
void rankload();
int random();
void ranklist();

int main() {
	loading();
	quesload();
	rankload();
	initgraph(1080, 850);
	menu();
	return 0;
}

void menu() {
	closegraph();
	initgraph(1080, 720);
	IMAGE img;
	loadimage(&img, "1.jpeg",1080,720);
	setbkmode(TRANSPARENT);
	putimage(0, 0, &img);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 70;
		settextcolor(YELLOW);
		settextstyle(&f);
		outtextxy(300, 165, _T("党史知识竞赛"));
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(150, 450, _T("新用户注册"));
		outtextxy(550, 450, _T("老用户登录"));
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
	}
}

void loading() {
	ifstream in_file("user.txt", ios::in);
	int i = 0;
	while (!in_file.fail())
	{
		in_file >> user[i].ID;
		in_file >> user[i].password;
		in_file >> user[i].exam;
		i++;
	}
	in_file.close();
}

void quesload() {
	ifstream in_file("problem.txt", ios::in);
	int i = 0;
	while (!in_file.fail())
	{
		in_file >> question[i].problem;
		in_file >> question[i].right;
		in_file >> question[i].A;
		in_file >> question[i].B;
		in_file >> question[i].C;
		i++;
	}
	in_file.close();
}

void Register() {
	char ID[20] = { 0 };
	bool ph = 0;
	node* account = new node;
	while (ph == 0) {
		int phyes = InputBox(ID, 12, "请输入ID", "新用户注册", "", 0, 0, false);
		if (phyes == 0)
			menu();
		for (int i = 0; i < 20; i++) {
			if (ID == user[i].ID) {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "该用户名已被注册", "Error", MB_OKCANCEL);
				break;
			}
			else if (i == 19) {
				ph = 1;
			}
		}
	}
	char password[20] = { 0 };
	char repass[20] = { 0 };
	bool pass = 0;
	while (1) {
		while (pass == 0) {
			int passyes = InputBox(password, 19, "请输入密码（至少8位）", "新用户注册", "", 0, 0, false);
			if (passyes == 0)
				menu();
			for (int i = 0; i < 8; i++) {
				if (password[i] == 0) {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "密码输入错误", "Error", MB_OKCANCEL);
					break;
				}
				else if (i == 7)
					pass = 1;
			}
		}
		int repassyes = InputBox(repass, 19, "请再次输入密码", "新用户注册", "", 0, 0, false);
		if (repassyes == 0)
			menu();
		if (strcmp(repass, password) == 0) {
			account->password = password;
			break;
		}
		else {
			HWND hnd = GetHWnd();
			int is_ok = MessageBox(hnd, "密码输入错误", "Error", MB_OKCANCEL);
			pass = 0;
		}
	}
	int i = 0;
	while (user[i].ID[0])
		i++;
	account->ID = ID;
	account->password = password;
	account->exam = 0;
	ofstream out_file("user.txt", ios::out);
	if (!out_file)
		exit(-1);
	j = 0;
	while (user[j].ID[0]) {
		out_file << user[j].ID << " " << user[j].password << " " << user[j].exam << endl;
		j++;
	}
	user[j] = *account;
	out_file << user[j].ID << " " << user[j].password << " " << user[j].exam << endl;
	hall();
}

void Signin() {
	bool OK = 0;
	while (1) {
			char ID[20] = { 0 };
			bool id = 0;
			int i = 0;
			while (id == 0) {
				int idyes = InputBox(ID, 12, "请输入ID", "", "", 0, 0, false);
				if (idyes == 0)
					break;
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
					int is_ok = MessageBox(hnd, "ID错误", "Error", MB_OKCANCEL);
				}
			}
			bool pass = 0;
			char password[20] = { 0 };
			while (pass == 0) {
				int pyes = InputBox(password, 19, "请输入密码", "", "", 0, 0, false);
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
					int is_ok = MessageBox(hnd, "密码错误", "Error", MB_OKCANCEL);
				}
			}
			j = i;
			break;
		}
	if (OK == 1) {
		hall();
	}
	else if (OK == 0) {
		menu();
	}
}

void hall() {
	closegraph();
	initgraph(1080, 720);
	IMAGE img;
	loadimage(&img, "2.jpg", 1080, 720);
	setbkmode(TRANSPARENT);
	putimage(0, 0, &img);
	while (1) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 40;
		settextcolor(YELLOW);
		settextstyle(&f);
		outtextxy(150, 250, _T("练习"));
		outtextxy(500, 250, _T("模拟竞赛"));
		outtextxy(150, 500, _T("正式竞赛"));
		outtextxy(500, 500, _T("排行榜"));
		f.lfHeight = 40;
		settextstyle(&f);
		settextcolor(BLACK);
		outtextxy(900, 650, _T("退出"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 250 && m.y <= 350) {
			practice();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 250 && m.y <= 350) {
			imitate();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 400 && m.y >= 500 && m.y <= 600) {
			if (user[j].exam == 0) {
				exam();
				break;
			}
			else {
				HWND hnd = GetHWnd();
				int is_ok = MessageBox(hnd, "不能重复参与！", " ", MB_OKCANCEL);
			}
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 750 && m.y >= 500 && m.y <= 600) {
			ranklist();
			break;
		}
		if (m.message == WM_LBUTTONDOWN && m.x >= 850 && m.y >= 630) {
			menu();
			break;
		}
	}
}

void rankload() {
	ifstream in_file("rank.txt", ios::in);
	int i = 0;
	while (!in_file.fail())
	{
		in_file >> rankl[i].ID;
		in_file >> rankl[i].score;
		in_file >> rankl[i].time;
		i++;
	}
	in_file.close();
}

void ranklist() {
	closegraph();
	initgraph(1080, 850);
	IMAGE img;
	loadimage(&img, "4.png", 1080, 850);
	setbkmode(TRANSPARENT);
	putimage(0, 0, &img);
	while (1) {
		int w = 0;
		while (rankl[w].ID[0]) {
			char tim[3] = { 0 };
			sprintf_s(tim, "%d", w+1);
			LOGFONT f;
			gettextstyle(&f);
			settextcolor(WHITE);
			f.lfHeight = 35;
			settextstyle(&f);
			outtextxy(20, 30 + w * 35, tim);
			outtextxy(65, 30 + w * 35, rankl[w].ID.c_str());
			outtextxy(300, 30 + w * 35, rankl[w].score.c_str());
			outtextxy(500, 30 + w * 35, rankl[w].time.c_str());
			w++;
		}
		LOGFONT f;
		gettextstyle(&f);
		settextcolor(WHITE);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(900, 800, _T("退出"));
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && m.x >= 850 && m.y >= 800) {
			hall();
			break;
		}
	}
}

void practice() {
	cleardevice();
	bool leave = 0;
	while (leave == 0) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 30;
		settextcolor(WHITE);
		settextstyle(&f);
		IMAGE img;
		loadimage(&img, "3.jpeg", 1080, 720);
		setbkmode(TRANSPARENT);
		putimage(0, 0, &img);

		int no = random();
		string choice;

		RECT R1{ 50, 50, 1000, 350 };
		//left top right bottom
		drawtext(question[no].problem.c_str(), &R1, DT_VCENTER | DT_WORDBREAK);
		RECT R2{ 50,400,300,550 };
		drawtext(question[no].A.c_str(), &R2, DT_VCENTER | DT_WORDBREAK);
		RECT R3{ 350,400,600,550 };
		drawtext(question[no].B.c_str(), &R3, DT_VCENTER | DT_WORDBREAK);
		RECT R4{ 650,400,900,550 };
		drawtext(question[no].C.c_str(), &R4, DT_VCENTER | DT_WORDBREAK);

		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("退出"));

		while (1){
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			if (m.message == WM_LBUTTONDOWN && m.x >= 50 && m.x <= 300 && m.y >= 400 && m.y <= 550) {
				choice = "A";
				if (choice == question[no].right) {
					int pyes = InputBox(NULL, 0, "回答正确。是否继续？", "", "", 0, 0, false);
					if (pyes == 0) {
						leave = 1;
						break;
					}
				}
				else {
					if (question[no].right == "B") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是B。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
					if (question[no].right == "C") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是C。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
				}
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 600 && m.y >= 400 && m.y <= 550) {
				choice = "B";
				if (choice == question[no].right) {
					int pyes = InputBox(NULL, 0, "回答正确。是否继续？", "", "", 0, 0, false);
					if (pyes == 0) {
						leave = 1;
						break;
					}
				}
				else {
					if (question[no].right == "A") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是A。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
					if (question[no].right == "C") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是C。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
				}
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 650 && m.x <= 900 && m.y >= 400 && m.y <= 550) {
				choice = "C";
				if (choice == question[no].right) {
					int pyes = InputBox(NULL, 0, "回答正确。是否继续？", "", "", 0, 0, false);
					if (pyes == 0) {
						leave = 1;
						break;
					}
				}
				else {
					if (question[no].right == "B") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是B。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
					if (question[no].right == "A") {
						int pyes = InputBox(NULL, 0, "回答错误，正确答案是A。是否继续？", "", "", 0, 0, false);
						if (pyes == 0) {
							leave = 1;
							break;
						}
					}
				}
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 630) {
				leave = 1;
				break;
			}
		}
	}
	hall();
}

void imitate() {
	cleardevice();
	int t0 = time(NULL);
	bool leave = 0;
	int correct = 0;
	int qu = 0;
	int err[10] = { 0 };
	int er = 0;
	while (leave == 0) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 30;
		settextcolor(WHITE);
		settextstyle(&f);
		IMAGE img;
		loadimage(&img, "3.jpeg", 1080, 720);
		setbkmode(TRANSPARENT);
		putimage(0, 0, &img);

		int no = random();
		string choice;

		RECT R1{ 50, 50, 1000, 350 };
		//left top right bottom
		drawtext(question[no].problem.c_str(), &R1, DT_VCENTER | DT_WORDBREAK);
		RECT R2{ 50,400,300,550 };
		drawtext(question[no].A.c_str(), &R2, DT_VCENTER | DT_WORDBREAK);
		RECT R3{ 350,400,600,550 };
		drawtext(question[no].B.c_str(), &R3, DT_VCENTER | DT_WORDBREAK);
		RECT R4{ 650,400,900,550 };
		drawtext(question[no].C.c_str(), &R4, DT_VCENTER | DT_WORDBREAK);

		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("退出"));

		while (time(NULL) < t0 + 31 && qu < 10) {
			int t1 = time(NULL) - t0;
			char s[3] = { 0 };
			sprintf_s(s, "%d", t1);
			clearrectangle(1000, 50, 1030, 80);
			outtextxy(1000, 50, s);
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			if (m.message == WM_LBUTTONDOWN && m.x >= 50 && m.x <= 300 && m.y >= 400 && m.y <= 550) {
				choice = "A";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 600 && m.y >= 400 && m.y <= 550) {
				choice = "B";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 650 && m.x <= 900 && m.y >= 400 && m.y <= 550) {
				choice = "C";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 630) {
				leave = 1;
				break;
			}
		}
		if (time(NULL) >= t0 + 31 || qu >= 10)
			leave = 1;
	}
	char c[3] = { 0 };
	sprintf_s(c, "%d", correct);
	string a = "答题结束，您答对了";
	a = a + c;
	a = a + "道题";
	HWND hnd = GetHWnd();
	int is_ok = MessageBox(hnd, a.c_str(), " ", MB_OKCANCEL);
	int i = 0;
	bool lea = 0;
	while (er > 0) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 30;
		settextcolor(WHITE);
		IMAGE img;
		loadimage(&img, "3.jpeg", 1080, 720);
		setbkmode(TRANSPARENT);
		putimage(0, 0, &img);
		settextstyle(&f);
		RECT R1{ 50, 50, 1000, 350 };
		//left top right bottom
		drawtext(question[err[i]].problem.c_str(), &R1, DT_VCENTER | DT_WORDBREAK);
		RECT R2{ 50,400,300,550 };
		drawtext(question[err[i]].A.c_str(), &R2, DT_VCENTER | DT_WORDBREAK);
		RECT R3{ 350,400,600,550 };
		drawtext(question[err[i]].B.c_str(), &R3, DT_VCENTER | DT_WORDBREAK);
		RECT R4{ 650,400,900,550 };
		drawtext(question[err[i]].C.c_str(), &R4, DT_VCENTER | DT_WORDBREAK);
		outtextxy(1020, 50, question[err[i]].right.c_str());

		outtextxy(200, 650, _T("上一题"));
		outtextxy(500, 650, _T("下一题"));
		outtextxy(800, 650, _T("退出"));
		while (1) {
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			//comment
			if (m.message == WM_LBUTTONDOWN && m.x >= 400 && m.x <= 600 && m.y >= 600 && m.y <= 700) {
				if (i + 1 < er) {
					cleardevice();
					i++;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "已经是最后一题了", " ", MB_OKCANCEL);
				}
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 600 && m.y <= 700) {
				if (i > 0) {
					cleardevice();
					i--;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "已经是第一题了", " ", MB_OKCANCEL);
				}
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 650) {
				lea = 1;
				break;
			}
		}
		if (lea == 1)
			break;
	}
	hall();
}

void exam() {
	user[j].exam = 1;
	ofstream out_file("user.txt", ios::out);
	if (!out_file)
		exit(-1);
	int i1 = 0;
	while (user[i1].ID[0]) {
		out_file << user[i1].ID << " " << user[i1].password << " " << user[i1].exam << endl;
		i1++;
	}
	out_file.close();
	cleardevice();
	int t0 = time(NULL);
	bool leave = 0;
	int correct = 0;
	int qu = 0;
	int err[10] = { 0 };
	int er = 0;
	int t1 = time(NULL) - t0;
	char ti[3] = { 0 };
	while (leave == 0) {
		IMAGE img;
		loadimage(&img, "3.jpeg", 1080, 720);
		setbkmode(TRANSPARENT);
		putimage(0, 0, &img);
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 30;
		settextcolor(WHITE);
		settextstyle(&f);
		int no = random();
		string choice;

		RECT R1{ 50, 50, 1000, 350 };
		//left top right bottom
		drawtext(question[no].problem.c_str(), &R1, DT_VCENTER | DT_WORDBREAK);
		RECT R2{ 50,400,300,550 };
		drawtext(question[no].A.c_str(), &R2, DT_VCENTER | DT_WORDBREAK);
		RECT R3{ 350,400,600,550 };
		drawtext(question[no].B.c_str(), &R3, DT_VCENTER | DT_WORDBREAK);
		RECT R4{ 650,400,900,550 };
		drawtext(question[no].C.c_str(), &R4, DT_VCENTER | DT_WORDBREAK);

		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(800, 680, _T("退出"));

		while (time(NULL) < t0 + 31 && qu < 10) {
			t1 = time(NULL) - t0;
			for (int k = 0; k < 3; k++)
				ti[k] = 0;
			sprintf_s(ti, "%d", t1);
			clearrectangle(1000, 50, 1030, 80);
			outtextxy(1000, 50, ti);
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			if (m.message == WM_LBUTTONDOWN && m.x >= 50 && m.x <= 300 && m.y >= 400 && m.y <= 550) {
				choice = "A";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 600 && m.y >= 400 && m.y <= 550) {
				choice = "B";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 650 && m.x <= 900 && m.y >= 400 && m.y <= 550) {
				choice = "C";
				if (choice == question[no].right) {
					correct++;
				}
				else {
					err[er] = no;
					er++;
				}
				qu++;
				cleardevice();
				break;
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 630) {
				leave = 1;
				break;
			}
		}
		if (time(NULL) >= t0 + 31 || qu >= 10)
			leave = 1;
	}
	char c[3] = { 0 };
	sprintf_s(c, "%d", correct);
	string a = "答题结束，您答对了";
	a = a + c;
	a = a + "道题";
	HWND hnd = GetHWnd();
	int is_ok = MessageBox(hnd, a.c_str(), " ", MB_OKCANCEL);

	ranks* sc = new ranks;
	sc->ID = user[j].ID;
	sc->score = c;
	sc->time = ti;
	for (int i = 0; i < 20; i++) {
		if (mystrlen(sc->score) > mystrlen(rankl[i].score)) {
			for (int k = 19; k > i; k--) {
				rankl[k] = rankl[k - 1];
			}
			rankl[i] = *sc;
			break;
		}
		else if (sc->score > rankl[i].score || (sc->score == rankl[i].score && sc->time < rankl[i].time)) {
			for (int k = 19; k > i; k--) {
				rankl[k] = rankl[k - 1];
			}
			rankl[i] = *sc;
			break;
		}
		else if (rankl[i].ID[0] == 0) {
			rankl[i] = *sc;
			break;
		}
	}
	ofstream out_file1("rank.txt", ios::out);
	if (!out_file1)
		exit(-1);
	int i2 = 0;
	while (rankl[i2].ID[0]) {
		out_file1 << rankl[i2].ID << " " << rankl[i2].score << " " << rankl[i2].time << endl;
		i2++;
	}
	out_file1.close();
	int i = 0;
	bool lea = 0;
	while (er > 0) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 30;
		settextcolor(WHITE);
		IMAGE img;
		loadimage(&img, "3.jpeg", 1080, 720);
		setbkmode(TRANSPARENT);
		putimage(0, 0, &img);
		settextstyle(&f);
		RECT R1{ 50, 50, 1000, 350 };
		//left top right bottom
		drawtext(question[err[i]].problem.c_str(), &R1, DT_VCENTER | DT_WORDBREAK);
		RECT R2{ 50,400,300,550 };
		drawtext(question[err[i]].A.c_str(), &R2, DT_VCENTER | DT_WORDBREAK);
		RECT R3{ 350,400,600,550 };
		drawtext(question[err[i]].B.c_str(), &R3, DT_VCENTER | DT_WORDBREAK);
		RECT R4{ 650,400,900,550 };
		drawtext(question[err[i]].C.c_str(), &R4, DT_VCENTER | DT_WORDBREAK);
		outtextxy(1020, 50, question[err[i]].right.c_str());

		outtextxy(200, 650, _T("上一题"));
		outtextxy(500, 650, _T("下一题"));
		outtextxy(800, 650, _T("退出"));
		while (1) {
			ExMessage m;
			m = getmessage(EX_MOUSE | EX_KEY);
			//comment
			if (m.message == WM_LBUTTONDOWN && m.x >= 400 && m.x <= 600 && m.y >= 600 && m.y <= 700) {
				if (i + 1 < er) {
					cleardevice();
					i++;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "已经是最后一题了", " ", MB_OKCANCEL);
				}
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 100 && m.x <= 300 && m.y >= 600 && m.y <= 700) {
				if (i > 0) {
					cleardevice();
					i--;
					break;
				}
				else {
					HWND hnd = GetHWnd();
					int is_ok = MessageBox(hnd, "已经是第一题了", " ", MB_OKCANCEL);
				}
			}
			if (m.message == WM_LBUTTONDOWN && m.x >= 800 && m.y >= 650) {
				lea = 1;
				break;
			}
		}
		if (lea == 1)
			break;
	}

	hall();
}

int random() {
	int a = 0;
	srand((unsigned int)time(NULL));
	a = ((int)rand()+114-1919) % 200;
	return a;
}