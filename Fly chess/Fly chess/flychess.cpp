#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include"flychess.h"
using namespace std;

int l1[22] = { 0 }, l2[22] = { 0 }, l3[22] = { 0 }, l4[22] = { 0 }, l5[22] = { 0 };
int count1 = 4, count2 = 4, c1 = 0, c2 = 0, cou1 = 0, cou2 = 0, a = 0, choose, m;
int count3 = 4, c3 = 0, cou3 = 0;
int count4 = 4, c4 = 0, cou4 = 0;
int count5 = 4, c5 = 0, cou5 = 0;
int temp[5] = { 0 }, temp1[5] = { 0 }, tem[5] = { 0 }, tem1[5] = { 0 }, tem2[5] = { 0 };
int cheat = 0;
//1 玩家1 2 电脑1 3 玩家2 4 电脑2 5 电脑3
//count1:机库;c1:在场;cou1:完成

int main() {
    int num = 0;
    int n = 0;
    cout << "规则：玩家2-4人，其中人类玩家1-2个，电脑玩家1-3个" << endl;
    while (num < 2 || num > 4) {
        cout << "输入玩家数量" << endl;
        cin >> num;
    }
    while (n < 1 || n > 2 || n >= num) {
        cout << "输入人类玩家数量" << endl;
        cin >> n;
    }
    cout << "输入1开启外挂模式控制点数" << endl;
    cin >> cheat;
    while (1) {
        P1();
        if (cou1 == 4)
            break;
        if (n == 1) {
            C1();
            if (cou2 == 4)
                break;
            if (num >= 3) {
                C2();
                if (cou4 == 4)
                    break;
                if (num == 4) {
                    C3();
                    if (cou5 == 4)
                        break;
                }
            }
        }
        else if (n == 2) {
            P2();
            if (cou3 == 4)
                break;
            C1();
            if (cou2 == 4)
                break;
            if (num == 4) {
                C2();
                if (cou4 == 4)
                    break;
            }
        }
    }
}


void crashp1() {
    count2 += l2[temp[c1]];
    count3 += l3[temp[c1]];
    count4 += l4[temp[c1]];
    count5 += l5[temp[c1]];
    c2 -= l2[temp[c1]];
    c3 -= l3[temp[c1]];
    c4 -= l4[temp[c1]];
    c5 -= l5[temp[c1]];
    l2[temp[c1]] = 0;
    l3[temp[c1]] = 0;
    l4[temp[c1]] = 0;
    l5[temp[c1]] = 0;
    for (int i = 1; i < 5; i++) {
        if (tem[i] == temp[c1])
            tem[i] = 0;
        if (tem1[i] == temp[c1])
            tem1[i] = 0;
        if (tem2[i] == temp[c1])
            tem2[i] = 0;
        if (temp1[i] == temp[c1])
            temp1[i] = 0;
    }
}
void crashp2() {
    count2 += l2[temp1[c3]];
    count1 += l1[temp1[c3]];
    count4 += l4[temp1[c3]];
    count5 += l5[temp1[c3]];
    c2 -= l2[temp1[c3]];
    c1 -= l1[temp1[c3]];
    c4 -= l4[temp1[c3]];
    c5 -= l5[temp1[c3]];
    l2[temp1[c3]] = 0;
    l1[temp1[c3]] = 0;
    l4[temp1[c3]] = 0;
    l5[temp1[c3]] = 0;
    for (int i = 1; i < 5; i++) {
        if (tem[i] == temp1[c3])
            tem[i] = 0;
        if (tem1[i] == temp1[c3])
            tem1[i] = 0;
        if (tem2[i] == temp1[c3])
            tem2[i] = 0;
        if (temp[i] == temp1[c3])
            temp[i] = 0;
    }
}
void crashc1() {
    count1 += l1[tem[c2]];
    count3 += l3[tem[c2]];
    count4 += l4[tem[c2]];
    count5 += l5[tem[c2]];
    c1 -= l1[tem[c2]];
    c3 -= l3[tem[c2]];
    c4 -= l4[tem[c2]];
    c5 -= l5[tem[c2]];
    l1[tem[c2]] = 0;
    l3[tem[c2]] = 0;
    l4[tem[c2]] = 0;
    l5[tem[c2]] = 0;
    for (int i = 1; i < 5; i++) {
        if (temp[i] == tem[c2])
            temp[i] = 0;
        if (tem1[i] == tem[c2])
            tem1[i] = 0;
        if (tem2[i] == tem[c2])
            tem2[i] = 0;
        if (temp1[i] == tem[c2])
            temp1[i] = 0;
    }
}
void crashc2() {
    count1 += l1[tem1[c4]];
    count3 += l3[tem1[c4]];
    count2 += l2[tem1[c4]];
    count5 += l5[tem1[c4]];
    c1 -= l1[tem1[c4]];
    c3 -= l3[tem1[c4]];
    c2 -= l2[tem1[c4]];
    c5 -= l5[tem1[c4]];
    l1[tem1[c4]] = 0;
    l3[tem1[c4]] = 0;
    l2[tem1[c4]] = 0;
    l5[tem1[c4]] = 0;
    for (int i = 1; i < 5; i++) {
        if (tem[i] == tem1[c4])
            tem[i] = 0;
        if (temp[i] == tem1[c4])
            temp[i] = 0;
        if (tem2[i] == tem1[c4])
            tem2[i] = 0;
        if (temp1[i] == tem1[c4])
            temp1[i] = 0;
    }
}
void crashc3() {
    count1 += l1[tem2[c5]];
    count3 += l3[tem2[c5]];
    count4 += l4[tem2[c5]];
    count2 += l2[tem2[c5]];
    c1 -= l1[tem2[c5]];
    c3 -= l3[tem2[c5]];
    c4 -= l4[tem2[c5]];
    c2 -= l2[tem2[c5]];
    l1[temp[c5]] = 0;
    l3[temp[c5]] = 0;
    l4[temp[c5]] = 0;
    l2[temp[c5]] = 0;
    for (int i = 1; i < 5; i++) {
        if (tem[i] == tem2[c5])
            tem[i] = 0;
        if (tem1[i] == tem2[c5])
            tem1[i] = 0;
        if (temp[i] == tem2[c5])
            temp[i] = 0;
        if (temp1[i] == tem2[c5])
            temp1[i] = 0;
    }
}

void sortarr(int a[]) {
    for (int i = 2; i <= 4; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] != 0 && a[i] != 21 && a[j] == 0) {
                a[j] = a[i];
                a[i] = 0;
            }
        }
    }
}

void random() {
    a = 0;
    if (cheat != 1) {
        srand((unsigned int)time(NULL));
        a = (int)rand() % 6 + 1;
    }
    else
        while (a < 1 || a>6) {
            cout << "输入骰子点数";
            cin >> a;
        }
}

void printarr(int a[], int b, int c) {
    for (int i = 1; i <= 21; i++) {
        cout << a[i];
    }
    cout << endl << "未起飞:" << b << "已到达:" << c << endl;
}

void P1() {
    sortarr(temp);
    cout << "玩家1的情况" << endl;
    printarr(l1, count1, cou1);
    cout << "按回车键掷骰子";
    getchar();
    random();
    cout << "玩家1的点数为:" << a << endl;
    //起飞
    if (a == 6 && count1 > 0) {
        cout << "按回车键再掷一次";
        getchar();
        random();
        cout << "玩家1的点数为:" << a << endl;
        l1[a]++;
        c1++;
        temp[c1] = a;
        crashp1();
        count1--;
    }
    //飞行
    else if (c1 != 0) {
        if (c1 == 1) {
            l1[temp[1]] = 0;
            temp[1] += a;
            if (temp[1] < 16) {
                crashp1();
            }
            else if (temp[1] > 21) {
                temp[1] = 42 - temp[1];
            }
            l1[temp[1]] ++;
        }
        else if (c1 > 1) {
            choose = 0;
            bool A = false;
            while (A == false) {
                cout << "请选择棋子:";
                for (int i = 1; i <= c1; i++) {
                    cout << temp[i] << " ";
                }
                cout << endl;
                cin >> choose;
                for (m = 1; m <= c1; m++) {
                    if (choose == temp[m]) {
                        A = true;
                        break;
                    }
                }
            }
            l1[temp[m]]--;
            temp[m] += a;
            if (temp[m] < 16) {
                int t = c1;
                c1 = m;
                crashp1();
                c1 = t;
            }
            if (temp[m] > 21)
                temp[m] = 42 - temp[m];
            l1[temp[m]]++;
        }
    }
    if (l1[21] == 1) {
        l1[21] = 0;
        cou1++;
        c1--;
        if (cou1 <= 3) {
            cout << "玩家1有"<<cou1<<"枚棋子已到达" << endl;
            for (int i = 1; i < 5 - cou1; i++) {
                if (temp[i] == 21) {
                    temp[i] = temp[5 - cou1];
                    temp[5 - cou1] = 21;
                    break;
                }
            }
        }
        else if (cou1 == 4) {
            cout << "Player1 Win!" << endl;
        }
    }
    if (cou1 != 4) {
        cout << "玩家1的情况" << endl;
        printarr(l1, count1, cou1);
    }
}


void C1() {
    sortarr(tem);
    cout << "电脑1的情况" << endl;
    printarr(l2, count2, cou2);
    cout << "按回车后电脑1开始操作";
    getchar();
    random();
    cout << "电脑1掷骰子的点数为:" << a << endl;
    //起飞
    if (a == 6 && count2 > 0) {
        cout << "按回车电脑1再掷一次";
        getchar();
        random();
        cout << "电脑1的点数为:" << a << endl;
        l2[a]++;
        c2++;
        tem[c2] = a;
        crashc1();
        count2--;
    }
    //飞行
    else if (c2 != 0) {
        if (c2 == 1) {
            l2[tem[1]] --;
            tem[1] += a;
            if (tem[1] < 16)
                crashc1();
            if (tem[1] > 21)
                tem[1] = 42 - tem[1];
            l2[tem[1]] ++;
        }

        else if (c2 >= 2) {
            bool A = false;
            for (m = 1; m <= c2; m++) {
                if ((l1[tem[m] + a] != 0 || l3[tem[m] + a] != 0 || l4[tem[m] + a] != 0 || l5[tem[m] + a] != 0) && tem[m] + a <= 15) {
                    l2[tem[m]] --;
                    tem[m] += a;
                    l2[tem[m]]++;
                    int t = c2;
                    c2 = m;
                    crashc1();
                    c2 = t;
                    A = true;
                    break;
                }
            }
            if (A == false) {
                for (m = 1; m <= c2; m++) {
                    if (tem[m] + a == 21) {
                        l2[tem[m]] --;
                        tem[m] += a;
                        l2[tem[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            if (A == false) {
                for (m = 1; m <= c2; m++) {
                    if (tem[m] <= 15) {
                        l2[tem[m]] --;
                        tem[m] += a;
                        l2[tem[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            else {
                l2[tem[1]] --;
                tem[1] += a;
                if (tem[1] > 21)
                    tem[1] = 42 - tem[1];
                l2[tem[1]]++;
            }
        }
    }
    if (l2[21] == 1) {
        l2[21] = 0;
        cou2++;
        c2--;
        if (cou2 <= 3) {
            cout << "电脑1有" << cou2 << "枚棋子已到达" << endl;
            for (int i = 1; i < 5 - cou2; i++) {
                if (tem[i] == 21) {
                    tem[i] = tem[5 - cou2];
                    tem[5 - cou2] = 21;
                    break;
                }
            }
        }
        else if (cou2 == 4) {
            cout << "Computer1 Win!" << endl;
        }
    }
    if (cou2 != 4) {
        cout << "电脑1的情况" << endl;
        printarr(l2, count2, cou2);
    }
}

void P2() {
    sortarr(temp1);
    cout << "玩家2的情况" << endl;
    printarr(l3, count3, cou3);
    cout << "按回车键掷骰子";
    getchar();
    random();
    cout << "玩家2的点数为:" << a << endl;
    //起飞
    if (a == 6 && count1 > 0) {
        cout << "按回车键再掷一次";
        getchar();
        random();
        cout << "玩家2的点数为:" << a << endl;
        l3[a]++;
        c3++;
        temp1[c3] = a;
        crashp2();
        count3--;
    }
    //飞行
    else if (c3 != 0) {
        if (c3 == 1) {
            l3[temp1[1]] = 0;
            temp1[1] += a;
            if (temp1[1] < 16)
                crashp2();
            if (temp1[1] > 21)
                temp1[1] = 42 - temp1[1];
            l3[temp1[1]] ++;
        }
        else if (c3 >= 2) {
            choose = 0;
            bool A = false;
            while (A == false) {
                cout << "请选择棋子:";
                for (int i = 1; i <= c1; i++) {
                    cout << temp1[i] << " ";
                }
                cout << endl;
                cin >> choose;
                for (m = 1; m <= c1; m++) {
                    if (choose == temp1[m]) {
                        A = true;
                        break;
                    }
                }
            }
            l3[temp1[m]]--;
            temp1[m] += a;
            if (temp1[m] < 16) {
                int t = c3;
                c3 = m;
                crashp2();
                c3 = t;
            }
            if (temp1[m] > 21)
                temp1[m] = 42 - temp1[m];
            l3[temp1[m]]++;
        }
    }
    if (l3[21] == 1) {
        l3[21] = 0;
        cou3++;
        c3--;
        if (cou3 <= 3) {
            cout << "玩家2有" << cou3 << "枚棋子已到达" << endl;
            for (int i = 1; i < 5 - cou3; i++) {
                if (temp1[i] == 21) {
                    temp1[i] = temp1[5 - cou3];
                    temp1[5 - cou3] = 21;
                    break;
                }
            }
        }
        else if (cou3 == 4) {
            cout << "Player2 Win!" << endl;
        }
    }
    if (cou3 != 4) {
        cout << "玩家2的情况" << endl;
        printarr(l3, count3, cou3);
    }
}

void C3() {
    sortarr(tem2);
    cout << "电脑3的情况" << endl;
    printarr(l5, count5, cou5);
    cout << "按回车后电脑3开始操作";
    getchar();
    random();
    cout << "电脑3掷骰子";
    cout << endl << "未起飞:" << count5 << "已到达:" << cou5 << endl;
    //起飞
    if (a == 6 && count5 > 0) {
        cout << "按回车电脑3再掷一次";
        getchar();
        random();
        cout << "电脑3的点数为:" << a << endl;
        l5[a]++;
        c5++;
        tem[c5] = a;
        crashc3();
        count5--;
    }
    //飞行
    else if (c5 != 0) {
        if (c5 == 1) {
            l5[tem2[1]] --;
            tem2[1] += a;
            if (tem2[1] < 16)
                crashc3();
            if (tem2[1] > 21)
                tem2[1] = 42 - tem2[1];
            l5[tem2[1]] ++;
        }

        else if (c5 >= 2) {
            bool A = false;
            for (m = 1; m <= c5; m++) {
                if ((l1[tem2[m] + a] != 0 || l2[tem2[m] + a] != 0 || l3[tem2[m] + a] != 0 || l4[tem2[m] + a] != 0) && tem2[m] + a <= 15) {
                    l5[tem2[m]] --;
                    tem2[m] += a;
                    l5[tem2[m]]++;
                    int t = c5;
                    c5 = m;
                    crashc3();
                    c5 = t;
                    A = true;
                    break;
                }
            }
            if (A == false) {
                for (m = 1; m <= c5; m++) {
                    if (tem2[m] + a == 21) {
                        l5[tem2[m]] --;
                        tem2[m] += a;
                        l5[tem2[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            if (A == false) {
                for (m = 1; m <= c5; m++) {
                    if (tem2[m] <= 15) {
                        l5[tem2[m]] --;
                        tem2[m] += a;
                        l5[tem2[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            else {
                l5[tem2[1]] --;
                tem2[1] += a;
                if (tem2[1] > 21)
                    tem2[1] = 42 - tem2[1];
                l5[tem2[1]]++;
            }
        }
    }
    if (l5[21] == 1) {
        l5[21] = 0;
        cou5++;
        c5--;
        if (cou5 <= 3) {
            cout << "电脑3有" << cou5 << "枚棋子已到达" << endl;
            for (int i = 1; i < 5 - cou5; i++) {
                if (tem2[i] == 21) {
                    tem2[i] = tem2[5 - cou5];
                    tem2[5 - cou5] = 21;
                    break;
                }
            }
        }
        else if (cou5 == 4) {
            cout << "Computer3 Win!" << endl;
        }
    }
    if (cou5 != 4) {
        cout << "电脑3的情况" << endl;
        printarr(l5, count5, cou5);
    }
}

void C2() {
    sortarr(tem1);
    printarr(l4, count4, cou4);
    cout << "按回车后电脑2开始操作";
    getchar();
    random();
    cout << "电脑2掷骰子的点数为:" << a << endl;
    //起飞
    if (a == 6 && count4 > 0) {
        cout << "按回车电脑2再掷一次";
        getchar();
        random();
        cout << "电脑2的点数为:" << a << endl;
        l4[a]++;
        c4++;
        tem1[c4] = a;
        crashc2();
        count4--;
    }
    //飞行
    else if (c4 != 0) {
        if (c4 == 1) {
            l4[tem1[1]] --;
            tem1[1] += a;
            if (tem[4] < 16)
                crashc2();
            if (tem1[1] > 21)
                tem1[1] = 42 - tem1[1];
            l4[tem1[1]] ++;
        }

        else if (c4 >= 2) {
            bool A = false;
            for (m = 1; m <= c2; m++) {
                if ((l1[tem1[m] + a] != 0 || l2[tem1[m] + a] != 0 || l3[tem1[m] + a] != 0 || l5[tem1[m] + a] != 0) && tem1[m] + a <= 15) {
                    l4[tem1[m]] --;
                    tem1[m] += a;
                    l4[tem1[m]]++;
                    int t = c4;
                    c4 = m;
                    crashc2();
                    c4 = t;
                    A = true;
                    break;
                }
            }
            if (A == false) {
                for (m = 1; m <= c2; m++) {
                    if (tem1[m] + a == 21) {
                        l4[tem1[m]] --;
                        tem1[m] += a;
                        l4[tem1[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            if (A == false) {
                for (m = 1; m <= c2; m++) {
                    if (tem1[m] <= 15) {
                        l4[tem1[m]] --;
                        tem1[m] += a;
                        l4[tem1[m]]++;
                        A = true;
                        break;
                    }
                }
            }
            else {
                l4[tem1[1]] --;
                tem1[1] += a;
                if (tem1[1] > 21)
                    tem1[1] = 42 - tem1[1];
                l4[tem1[1]]++;
            }
        }
    }
    if (l4[21] == 1) {
        l4[21] = 0;
        cou4++;
        c4--;
        if (cou4 <= 3) {
            cout << "电脑2有" << cou4 << "枚棋子已到达" << endl;
            for (int i = 1; i < 5 - cou4; i++) {
                if (tem1[i] == 21) {
                    tem1[i] = tem1[5 - cou4];
                    tem1[5 - cou4] = 21;
                    break;
                }
            }
        }
        else if (cou4 == 4) {
            cout << "Computer2 Win!" << endl;
        }
    }
    if (cou4 != 4) {
        cout << "电脑2的情况" << endl;
        printarr(l4, count4, cou4);
    }
}