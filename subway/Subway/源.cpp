//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<graphics.h>
//using namespace std;
//
//void infosearch() {
//	initgraph(1024, 512);
//	settextstyle(30, 0, "����");
//	outtextxy(300, 200, "������Ϣ��ѯ");
//	settextstyle(20, 0, "����");
//	outtextxy(350, 250, "��·��ѯ");
//	outtextxy(350, 300, "վ���ѯ");
//}
//void ticketsearch() {
//	initgraph(1024, 512);
//	settextstyle(30, 0, "����");
//	outtextxy(300, 200, "����Ʊ���ѯ");
//	settextstyle(20, 0, "����");
//	wchar_t a[50];
//	InputBox(a, 10, L"������뾶");
//}
//
//
//int main() {
//	initgraph(1024, 512);
//	settextstyle(30, 0,"����");
//	outtextxy(300, 200, "�Ͼ�����Ʊ��ϵͳ");
//	settextstyle(20, 0, "����");
//	outtextxy(350, 250, "������Ϣ��ѯ");
//	outtextxy(350, 300, "����Ʊ���ѯ");
//	ExMessage m;
//	while (1)
//	{
//		while (1) {
//			m = getmessage();
//			if (m.x >= 300 && m.y >= 250 && m.y < 300) {
//				if (m.message == WM_LBUTTONDOWN) {
//					initgraph(1024, 512);
//					settextstyle(30, 0, "����");
//					outtextxy(300, 200, "������Ϣ��ѯ");
//					break;
//				}
//			}
//			if (m.x >= 300 && m.y >= 300 && m.y < 350) {
//				if (m.message == WM_LBUTTONDOWN) {
//					initgraph(1024, 512);
//					settextstyle(30, 0, "����");
//					outtextxy(300, 200, "����Ʊ���ѯ");
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}