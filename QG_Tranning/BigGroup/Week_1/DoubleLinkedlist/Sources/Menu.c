#include "Utils.h"
void HideCursor()
{
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo = { 0 };
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    SetConsoleCursorInfo(fd, &cinfo);  // ����/��ʾ����̨���
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y }; // ������ʾ��λ��
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos); //���������ֱ���ָ���ĸ����壬����λ��
}

void menu()
{

    printf("��ͨ���û�������Ӧ��ĸ���������+�س�ʵ�ֶ�Ӧ����\n");
    //printf("====================\n");
    printf("[A]\t����������\n");
    printf("[B]\tͷ�巨��������\n");
    printf("[C]\tβ�巨��������\n");

    printf("[D]\t��������\n");
    printf("[E]\tɾ������\n");
    printf("[F]\t��������\n");
    printf("[G]\t��������\n");
    printf("[H]\t�˳�����\n");

    printf("====================\n");
    printf("˫����ADT\n");
}

void show(int line)
{
    gotoxy(0, 0);
    menu();
    gotoxy(0, line);  // ѡ�еĸ�����ɫ
    if (line == 1)
        printf("\033[1;34;45m[A]\t����������\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45m[B]\tͷ�巨��������\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45m[C]\tβ�巨��������\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45m[D]\t��������\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45m[E]\tɾ������\n\033[0m");
    if (line == 6)
        printf("\033[1;34;45m[F]\t��������\n\033[0m");
    if (line == 7)
        printf("\033[1;34;45m[G]\t��������\n\033[0m");
    if (line == 8)
        printf("\033[1;34;45m[H]\t�˳�����\n\033[0m");

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

        system("cls");   //ϵͳ����
        system("color 79");  //���ÿ���̨����ɫ
        Beep(2000, 250); //ϵͳ���� 
        HideCursor();    //���ع��
        menu(); //��ʾ�˵�
        line = 1;
        gotoxy(0, line); //�ƶ���굽��һ�е���λ��
        printf("\033[1;34;45m[A]\t����������\n\033[0m"); //Ĭ�ϲ˵���һ�и�����ɫ

        for (; (c1 = _getch()) != '\r';)  // ��ȡ����ֵ������'\r'�س������
        { //ע���û���ͷ������������ַ�����:
          //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
            if (c1 == -32)
            {
                c2 = _getch(); //��ð����ĵڶ�����ֵ�������ݷ���ѡ��˵�����
                ch = c2;
                if (ch == upkey && line != 1)
                {
                    line--;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line != 8)
                {
                    line++;
                    show(line);
                    continue;
                }
                else if (ch == upkey && line == 1)
                {
                    line = 8;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line == 8)
                {
                    line = 1;
                    show(line);
                    continue;
                }
            }

            if (c1 == 'a' || c1 == 'A')
            {
                system("cls");   //ϵͳ����
                gotoxy(0, 0);    //���ص���ʼλ��
                InitDNode();   //����������
                line = 0;
                break;
            }
            else if (c1 == 'b' || c1 == 'B')
            {
                system("cls");
                gotoxy(0, 0);
                InsertHeadList();//ͷ�巨����ڵ�
                line = 0;
                break;
            }
            else if (c1 == 'c' || c1 == 'C')
            {
                system("cls");
                gotoxy(0, 0);
                InsertLastList();//β�巨��������
                line = 0;
                break;
            }
            else if (c1 == 'd' || c1 == 'D')
            {
                system("cls");
                gotoxy(0, 0);
                SearchDNode();//��������
                line = 0;
                break;
            }
            else if (c1 == 'e' || c1 == 'E')
            {
                system("cls");
                gotoxy(0, 0);
                DeleteDNode();//ɾ������
                line = 0;
                break;
            }
            else if (c1 == 'f' || c1 == 'F')
            {
                system("cls");
                gotoxy(0, 0);
                ErgodicDNode();//��������
                line = 0;
                break;
            }
            else if (c1 == 'g' || c1 == 'G')
            {
                system("cls");
                gotoxy(0, 0);
                DestroyDNode();//��������
                line = 0;
                break;
            }
            else if (c1 == 'h' || c1 == 'H')
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
            InitDNode();
        }
        else if (line == 2)
        {
            system("cls");
            gotoxy(0, 0);
            InsertHeadList();
        }
        else if (line == 3)
        {
            system("cls");
            gotoxy(0, 0);
            InsertLastList();
           
        }
        else if (line == 4)
        {
            system("cls");
            gotoxy(0, 0);
            SearchDNode();
        }
        else if (line == 5)
        {
            system("cls");
            gotoxy(0, 0);
            DeleteDNode();
        }
        else if (line == 6)
        {
            system("cls");
            gotoxy(0, 0);
            ErgodicDNode();
        }
        else if (line == 7)
        {
            system("cls");
            gotoxy(0, 0);
            DestroyDNode();

        }
        else if (line == 8)
        {
            system("cls");
            gotoxy(0, 0);
            exit(0);
        }


        /*j = pow(10, 10);
        while (j--); */

        time(&t); //��ȡʱ���
        lt = localtime(&t); // תΪʱ��ṹ
        sec = lt->tm_sec;
        // printf("time is: %d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour,lt->tm_min, lt->tm_sec);
        printf("�����Զ����ز˵�ҳ��...\n");
        printf("���������������...");
        do   // ��ʱһ��
        {
            time(&t); //��ȡʱ���
            lt = localtime(&t); // תΪʱ��ṹ
            j = lt->tm_sec - sec;
            if (j < 0) j = j + 60;
            //   printf("time is: %d-%d\n", lt->tm_sec, sec);
        } while (j < 4);
    }
}