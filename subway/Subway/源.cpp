//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<graphics.h>
//using namespace std;
//
//void infosearch() {
//	initgraph(1024, 512);
//	settextstyle(30, 0, "宋体");
//	outtextxy(300, 200, "地铁信息查询");
//	settextstyle(20, 0, "宋体");
//	outtextxy(350, 250, "线路查询");
//	outtextxy(350, 300, "站点查询");
//}
//void ticketsearch() {
//	initgraph(1024, 512);
//	settextstyle(30, 0, "宋体");
//	outtextxy(300, 200, "地铁票务查询");
//	settextstyle(20, 0, "宋体");
//	wchar_t a[50];
//	InputBox(a, 10, L"请输入半径");
//}
//
//
//int main() {
//	initgraph(1024, 512);
//	settextstyle(30, 0,"宋体");
//	outtextxy(300, 200, "南京地铁票务系统");
//	settextstyle(20, 0, "宋体");
//	outtextxy(350, 250, "地铁信息查询");
//	outtextxy(350, 300, "地铁票务查询");
//	ExMessage m;
//	while (1)
//	{
//		while (1) {
//			m = getmessage();
//			if (m.x >= 300 && m.y >= 250 && m.y < 300) {
//				if (m.message == WM_LBUTTONDOWN) {
//					initgraph(1024, 512);
//					settextstyle(30, 0, "宋体");
//					outtextxy(300, 200, "地铁信息查询");
//					break;
//				}
//			}
//			if (m.x >= 300 && m.y >= 300 && m.y < 350) {
//				if (m.message == WM_LBUTTONDOWN) {
//					initgraph(1024, 512);
//					settextstyle(30, 0, "宋体");
//					outtextxy(300, 200, "地铁票务查询");
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}