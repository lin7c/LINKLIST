#include <windows.h>
#include <string.h>
#include <stdio.h>
#define window1
#include "LinkListLib.h"
static int init = 0;
// 我们操作的链表
LinkList l;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#define IDC_MYBUTTON 1000
#define IDC_MYEDIT 2000
#define IDC_MYLABEL 3000
#define IDC_MYOUT 4000
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 窗口类的注册
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "MyWindowClass";

    if(!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 创建窗口
    HWND hWnd = CreateWindow(
        "MyWindowClass",               // 窗口类名
        "My First Window!",          // 窗口标题
        WS_OVERLAPPEDWINDOW,        // 窗口风格
        CW_USEDEFAULT, CW_USEDEFAULT,   // 初始位置
        CW_USEDEFAULT, CW_USEDEFAULT,   // 初始大小
        NULL, NULL, hInstance, NULL);

    if(hWnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 按钮的位置和大小
    int buttonWidth = 100;
    int buttonHeight = 30;
    int buttonX = 0;
    int buttonY = 30;
    char *BUTTONNAME[8] = {"Initialize","Length","Insert","Delete","Remove","Find","Sort","Travel"}; 
    // 创建按钮
    for(int i =0;i<8;i++){
        HWND hButton = CreateWindow(
            "BUTTON",                    // 控件类名
            BUTTONNAME[i],                 // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, // 样式
            buttonX, buttonY+(buttonHeight+3)*i,            // 位置
            buttonWidth, buttonHeight,    // 大小
            hWnd,                        // 父窗口句柄
            (HMENU)(IDC_MYBUTTON+i),         // 控件ID
            hInstance,                   // 实例句柄
            NULL);                       // 使用默认创建参数

        if (!hButton) {
            MessageBox(NULL, "Button creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
    }
    int EditWidth = 100;
    int EditHeight = 30;
    int EditX = 103;
    int EditY = 30;
    for(int i = 0;i<8;i++){
        HWND hEdit = CreateWindow(
            "EDIT",                    // 控件类名
            "",                        // 初始文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | ES_AUTOVSCROLL | ES_LEFT | ES_MULTILINE|WS_BORDER, // 样式
            EditX, EditY+(EditHeight+3)*i,                   // 位置（左上角）
            EditWidth, EditHeight,                 // 大小
            hWnd,                      // 父窗口句柄
            (HMENU)(IDC_MYEDIT+i),              // 控件ID
            hInstance,                 // 实例句柄
            NULL);                     // 使用默认创建参数

        if (!hEdit) {
            MessageBox(NULL, "Text box creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
    }
    // 创建标签
    char *LABELCONTENT[3]={"function","input","output"};
    int LABELWIDTH[3] = {0,103,300};
    for(int i = 0;i<3;i++){
        HWND hOutput = CreateWindow(
            "STATIC",                    // 控件类名
            LABELCONTENT[i],                 // 初始文本
            WS_VISIBLE | WS_CHILD | SS_LEFT, // 样式
            LABELWIDTH[i], 0,                   // 位置（左上角）
            100, 30,                 // 大小
            hWnd,                      // 父窗口句柄
            (HMENU)(IDC_MYLABEL+i),              // 控件ID
            hInstance,                 // 实例句柄
            NULL);                     // 使用默认创建参数

        if (!hOutput) {
            MessageBox(NULL, "Output box creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
    }
    // 创建输出框
     HWND hOutput = CreateWindow(
            "STATIC",                    // 控件类名
            "",                 // 初始文本
            WS_VISIBLE | WS_CHILD | SS_LEFT, // 样式
            300, 30,                   // 位置（中间）
            1000, 300,                 // 大小
            hWnd,                      // 父窗口句柄
            (HMENU)IDC_MYOUT,              // 控件ID
            hInstance,                 // 实例句柄
            NULL);                     // 使用默认创建参数

        if (!hOutput) {
            MessageBox(NULL, "Output box creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
    // 显示并更新窗口
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 消息循环
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// 回调函数处理窗口消息
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    switch(message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDC_MYBUTTON) { // 检查是否是我们的按钮
                init = 1;
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                InitLinkList(&l);
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), "The LinkList has been Initialize.\n"); // 替换为你的输出框ID
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+1){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+1);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                sprintf(buffer,"The Length of linklist is %d",Length(l));
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+2){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+2);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                if(length == 0){
                    MessageBox(NULL, "Please input the number such as 1 0 ", "Error!", MB_ICONEXCLAMATION | MB_OK);
                    break;
                }
                char *f,*s;
                ElemType x;
                int m;
                f = strtok(buffer," ");
                s = strtok((void*)0," ");
                if(sizeof(ElemType)==sizeof(int))x = atoi(f);
                m = atoi(s);
                Insert(&l,x,m);
                sprintf(buffer,"Insert data is %d,position is %d",x,m);
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+3){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+3);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                if(length == 0){
                    MessageBox(NULL, "Please input the number such as 1", "Error!", MB_ICONEXCLAMATION | MB_OK);
                    break;
                }
                ElemType x;
                if(sizeof(ElemType)==sizeof(int))x = atoi(buffer);
                Delete(&l,x);
                sprintf(buffer,"Delete data is %d",x);
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+4){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+4);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                if(length == 0){
                    MessageBox(NULL, "Please input the number such as 1", "Error!", MB_ICONEXCLAMATION | MB_OK);
                    break;
                }
                int x = atoi(buffer);
                Remove(&l,x);
                sprintf(buffer,"Remove data position is %d",x);
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+5){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+5);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                if(length == 0){
                    MessageBox(NULL, "Please input the number such as 1", "Error!", MB_ICONEXCLAMATION | MB_OK);
                    break;
                }
                ElemType x;
                if(sizeof(ElemType)==sizeof(int))x = atoi(buffer);
                int o = Find(l,x);
                if(o){
                    sprintf(buffer,"There is data!");
                }
                else{
                    sprintf(buffer,"There is no such data!");
                }
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if(LOWORD(wParam) == IDC_MYBUTTON+6){
                if(init == 0){
                    MessageBox(NULL, "LinkList has not initialized", "Error!", MB_ICONEXCLAMATION | MB_OK);
                }
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+6);
                const int bufferSize = 1024;
                wchar_t buffer[1024];
                int length = GetWindowText(hEdit, buffer, bufferSize);
                if(length == 0){
                    MessageBox(NULL, "Please input the number such as 1", "Error!", MB_ICONEXCLAMATION | MB_OK);
                    break;
                }
                int x = atoi(buffer);
                Sort(&l,x);
                if(x){
                    sprintf(buffer,"LinkList has been sorted with Previous",x);
                }
                else{
                    sprintf(buffer,"LinkList has been sorted with Reserve",x);
                }
                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), buffer); 
            }
            if (LOWORD(wParam) == IDC_MYBUTTON+7) {
                char TRAVELBUF[1024];
                init = 1;
                HWND hEdit = GetDlgItem(hWnd, IDC_MYEDIT+7);
                int len = Length(l);
                LinkList p = l->next;
                TRAVELBUF[0] = '\0'; 
                for (int i = 1; i < len; i++) {
                    char *X = malloc(10); 
                    sprintf(X, "%d->", p->data);
                    strcat(TRAVELBUF, X);
                    free(X); 
                    p = p->next;
                }

                SetWindowText(GetDlgItem(hWnd, IDC_MYOUT), TRAVELBUF);
                
            }
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}