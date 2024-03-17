#include "Utils.h"
void HideCursor()
{
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo = { 0 };
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    SetConsoleCursorInfo(fd, &cinfo);  // 隐藏/显示控制台光标
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y }; // 设置显示的位置
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos); //两个参数分别是指定哪个窗体，具体位置
}

void menu()
{
    
    printf("请通过敲击键盘相应字母按键或方向键+回车实现对应功能\n");
    //printf("====================\n");
    printf("[A]\t创建空链表\n");
    printf("[B]\t插入节点\n");
    printf("[C]\t查找数据\n");
    printf("[D]\t删除数据\n");
    printf("[E]\t遍历链表\n");
    printf("[F]\t销毁链表\n");
    printf("[G]\t判断链表是否成环\n");
    printf("[H]\t查找链表中间节点\n");
    printf("[I]\t交换奇偶节点数据\n");
    printf("[J]\t反转链表（非递归）\n");
    printf("[K]\t反转链表（递归）\n");
    printf("[L]\t退出程序\n");

    printf("====================\n");
    printf("单链表ADT\n");
}

void show(int line)
{
    gotoxy(0, 0);
    menu();
    gotoxy(0, line);  // 选中的高亮变色
    if (line == 1)
        printf("\033[1;34;45m[A]\t创建空链表\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45m[B]\t插入节点\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45m[C]\t查找数据\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45m[D]\t删除数据\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45m[E]\t遍历链表\n\033[0m");
    if (line == 6)
        printf("\033[1;34;45m[F]\t销毁链表\n\033[0m");
    if (line == 7)
        printf("\033[1;34;45m[G]\t判断链表是否成环\n\033[0m");
    if (line == 8)
        printf("\033[1;34;45m[H]\t查找链表中间节点\n\033[0m");
    if (line == 9)
        printf("\033[1;34;45m[I]\t交换奇偶节点数据\n\033[0m");
    if (line == 10)
        printf("\033[1;34;45m[J]\t反转链表（非递归）\n\033[0m");
    if (line == 11)
        printf("\033[1;34;45m[K]\t反转链表（递归）\n\033[0m");
    if (line == 12)
        printf("\033[1;34;45m[L]\t退出程序\n\033[0m");

}

void MenuControl()
{
    char c1, c2, ch;
    int line, sec;
    long long j;
    time_t t;
    struct tm* lt;

    while (1)
    {

        system("cls");   //系统清屏
        system("color 79");  //设置控制台的颜色
        Beep(2000, 250); //系统发声 
        HideCursor();    //隐藏光标
        menu(); //显示菜单
        line = 1;
        gotoxy(0, line); //移动光标到第一行的首位置
        printf("\033[1;34;45m[A]\t创建空链表\n\033[0m"); //默认菜单第一行高亮变色

        for (; (c1 = _getch()) != '\r';)  // 读取按键值，遇到'\r'回车则结束
        { //注意敲击箭头键会出现两个字符数据:
          //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
            if (c1 == -32)
            {
                c2 = _getch(); //获得按键的第二个键值，并根据方向选择菜单功能
                ch = c2;
                if (ch == upkey && line != 1)
                {
                    line--;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line != 12)
                {
                    line++;
                    show(line);
                    continue;
                }
                else if (ch == upkey && line == 1)
                {
                    line = 12;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line == 12)
                {
                    line = 1;
                    show(line);
                    continue;
                }
            }

            if (c1 == 'a' || c1 == 'A')
            {
                system("cls");   //系统清屏
                gotoxy(0, 0);    //光标回到初始位置
                InitList();   //创建空链表
                line = 0;
                break;
            }
            else if (c1 == 'b' || c1 == 'B')
            {
                system("cls");
                gotoxy(0, 0);
                InsertList();//插入节点
                line = 0;
                break;
            }
            else if (c1 == 'c' || c1 == 'C')
            {
                system("cls");
                gotoxy(0, 0);
                SearchList();//查找数据
                line = 0;
                break;
            }
            else if (c1 == 'd' || c1 == 'D')
            {
                system("cls");
                gotoxy(0, 0);
                DeleteList();//删除数据
                line = 0;
                break;
            }
            else if (c1 == 'e' || c1 == 'E')
            {
                system("cls");
                gotoxy(0, 0);
                ErgodicList();//遍历链表
                line = 0;
                break;
            }
            else if (c1 == 'f' || c1 == 'F')
            {
                system("cls");
                gotoxy(0, 0);
                DestroyList();//销毁链表
                line = 0;
                break;
            }
            else if (c1 == 'g' || c1 == 'G')
            {
                system("cls");
                gotoxy(0, 0);
                IsCircleList();//判断是否成环
                line = 0;
                break;
            }
            else if (c1 == 'h' || c1 == 'H')
            {
                system("cls");
                gotoxy(0, 0);
                MidNode();//查找中间节点
                line = 0;
                break;
            }
            else if (c1 == 'i' || c1 == 'I')
            {
                system("cls");
                gotoxy(0, 0);
                ExchangeNode();//交换奇偶节点数据
                line = 0;
                break;
            }
            else if (c1 == 'j' || c1 == 'J')
            {
                system("cls");
                gotoxy(0, 0);
                ReverseList();//反转链表（非递归）
                line = 0;
                break;
            }
            else if (c1 == 'K' || c1 == 'k')
            {
                system("cls");
                gotoxy(0, 0);

                Jump();//反转链表（递归）
                line = 0;
                break;
            }
            else if (c1 == 'L' || c1 == 'l')
            {
                system("cls");
                gotoxy(0, 0);
                exit(0);
                line = 0;
                break;
            }
        }

        if (line == 1)
        {
            system("cls");
            gotoxy(0, 0);
            InitList();
        }
        else if (line == 2)
        {
            system("cls");
            gotoxy(0, 0);
            InsertList();
        }
        else if (line == 3)
        {
            system("cls");
            gotoxy(0, 0);
            SearchList();
        }
        else if (line == 4)
        {
            system("cls");
            gotoxy(0, 0);
            DeleteList();
        }
        else if (line == 5)
        {
            system("cls");
            gotoxy(0, 0);
            ErgodicList();
        }
        else if (line == 6)
        {
            system("cls");
            gotoxy(0, 0);
            DestroyList();
        }
        else if (line == 7)
        {
            system("cls");
            gotoxy(0, 0);
            IsCircleList();//判断是否成环

        }
        else if (line == 8)
        {
            system("cls");
            gotoxy(0, 0);
            MidNode();//查找中间节点
        }
        else if (line == 9)
        {
            system("cls");
            gotoxy(0, 0);
            ExchangeNode();
            
        }
        else if (line == 10)
        {
            system("cls");
            gotoxy(0, 0);
            ReverseList();
        }
        else if (line == 11)
        {
            system("cls");
            gotoxy(0, 0);
            Jump();// RecurReverseList(head->next);
        }
        else if (line == 12)
        {
            system("cls");
            gotoxy(0, 0);
            exit(0);
        }


        /*j = pow(10, 10);
        while (j--); */

        time(&t); //获取时间戳
        lt = localtime(&t); // 转为时间结构
        sec = lt->tm_sec;
        // printf("time is: %d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour,lt->tm_min, lt->tm_sec);
        printf("即将自动返回菜单页面...\n");
        printf("请勿进行其他操作...");
        do   // 延时一会
        {
            time(&t); //获取时间戳
            lt = localtime(&t); // 转为时间结构
            j = lt->tm_sec - sec;
            if (j < 0) j = j + 60;
            //   printf("time is: %d-%d\n", lt->tm_sec, sec);
        } while (j < 4);
    }
}