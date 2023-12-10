/*
(Beta) School Computer Tool 0.0.1-Code [2023-12-09]
*/
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool judge;
DWORD WINAPI wind(LPVOID lpParameter)
{
	bool f=1;
    if(0==RegisterHotKey(NULL,1,MOD_CONTROL|MOD_ALT,'D'))
	{
        cout<<"Register Hot Key Error  "<<GetLastError()<<endl;
    }
	if(0==RegisterHotKey(NULL,2,MOD_CONTROL|MOD_ALT,'F'))
	{
        cout<<"Register Hot Key Error  "<<GetLastError()<<endl;
    }
    MSG msg={0};
    while(GetMessage(&msg,NULL,0,0))
	{
		HWND window=GetConsoleWindow();
        switch(msg.message)
        {
        	case WM_HOTKEY:
        	{
            	if(1==msg.wParam)
				{
                	if(f)
					{
						ShowWindow(window,SW_MINIMIZE);
					}
					else
					{
						ShowWindow(window,SW_RESTORE);
					}
					f=1-f;
        		}
				if(2==msg.wParam)
				{
					HWND bdCst=FindWindow(NULL,"屏幕广播");
					PostMessage(bdCst,WM_COMMAND,WPARAM((BM_CLICK<<16)|1004),NULL);
				}
            	break;
        	}
            default:
            	break;
        }
    }
}
DWORD WINAPI mouse(LPVOID lpParameter)
{
    srand(time(0));
    while(1)
    {
		HWND window=GetConsoleWindow();
		SetWindowPos(window,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
    }
    return 0L;
}
HHOOK kbdHook;
LRESULT CALLBACK HookProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	return FALSE;
}
DWORD WINAPI KeyHookThreadProc(LPVOID lpParameter)
{
	while(true)
	{
		kbdHook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)HookProc,GetModuleHandle(NULL),0);
		_sleep(100);
		UnhookWindowsHookEx(kbdHook);
		HANDLE hDevice=CreateFile("\\\\.\\TDKeybd",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
		if(!GetLastError())
		{
			BOOL bEnable=TRUE;
			DeviceIoControl(hDevice,0x220000,&bEnable,4,NULL,0,NULL,NULL);
			CloseHandle(hDevice);
		}
	}
	return 0;
}
int main()
{
	HWND hwnd=GetConsoleWindow();
	SetWindowText(hwnd,"(Beta) School Computer Tool 0.0.1 [2023-12-09]");
	HANDLE hThread_1=CreateThread(NULL,0,mouse,NULL,0,NULL);
	HANDLE hThread_2=CreateThread(NULL,0,KeyHookThreadProc,NULL,0,NULL);
	HANDLE hThread_3=CreateThread(NULL,0,wind,NULL,0,NULL);
	for(int i=0;i<5;i++)
	{
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"Loading"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"Loading ."<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"Loading .o"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"Loading .o O"<<endl;
		Sleep(1000);
	}
	while(true)
	{
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"{ Warning }"<<endl<<endl;
		cout<<"It Is Prohibited To Use 'School Computer Tool' For Non Compliant Behavior."<<endl;
		cout<<"Any Consequences Caused By Unauthorized Use Shall Be Borne By Oneself."<<endl<<endl;
		cout<<"0  Determine"<<endl;
		cout<<"1  Cancel"<<endl;
		switch(_getch())
		{
    		case '0':
    			judge=true;
    	        break;
    	    case '1':
    	    	cout<<endl;
    	    	system("TASKKILL /F /IM Program.exe /T");
    	        break;
    	}
		if(judge)
    	{
    		judge=false;
    		break;
		}
	}
	while(true)
	{
		system("cls");
		cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
		cout<<"{ Functions }"<<endl<<endl;
		cout<<"0  Open Mythware"<<endl;
		cout<<"1  Close Mythware"<<endl;
		cout<<"2  Window Based Mythware"<<endl;
		cout<<"3  Open Drive Restriction"<<endl;
		cout<<"4  Close Drive Restriction"<<endl<<endl;
		cout<<"* Hot Keys"<<endl<<endl;
		cout<<"[Ctrl]+[Alt]+[D]  Open / Close Window"<<endl;
		cout<<"[Ctrl]+[Alt]+[F]  Window Based Mythware"<<endl;
		cout<<"[ESC]  Exit"<<endl;
		while(true)
		{
			switch(_getch())
			{
    			case '0':
    				judge=true;
    				system("cls");
					cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
					cout<<"{ Operate }"<<endl;
    				if(MessageBox(NULL,"Are You Sure To Execute 'Open Mythware'?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					system("START C:\Program Files (x86)\Mythware\极域课堂管理系统软件V6.0 2016 豪华版\StudentMain.exe");
    					Sleep(1000);
					}
            		break;
        		case '1':
        			judge=true;
        			system("cls");
					cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
					cout<<"{ Operate }"<<endl;
    				if(MessageBox(NULL,"Are You Sure To Execute 'Close Mythware'?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					system("TASKKILL /F /IM StudentMain.exe /T");
    					Sleep(1000);
					}
            		break;
            	case '2':
					judge=true;
					system("cls");
					cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
					cout<<"{ Operate }"<<endl;
    				if(MessageBox(NULL,"Are You Sure To Execute 'Window Based Mythware'?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					HWND bdCst=FindWindow(NULL,"屏幕广播");
						PostMessage(bdCst,WM_COMMAND,WPARAM((BM_CLICK<<16)|1004),NULL);
						Sleep(1000);
					}
            		break;
            	case '3':
					judge=true;
					system("cls");
					cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
					cout<<"{ Operate }"<<endl;
    				if(MessageBox(NULL,"Are You Sure To Execute 'Open Drive Restriction'?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					system("SC START TDFILEFILTER");
    					Sleep(1000);
					}
            		break;
            	case '4':
					judge=true;
					system("cls");
					cout<<"(Beta) School Computer Tool 0.0.1 [2023-12-09]"<<endl<<endl;
					cout<<"{ Operate }"<<endl;
    				if(MessageBox(NULL,"Are You Sure To Execute 'Close Drive Restriction'?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					system("SC STOP TDFILEFILTER");
    					Sleep(1000);
					}
            		break;
            	case 27:
					judge=true;
    				if(MessageBox(NULL,"Are You Sure To Exit?","(Beta) School Computer Tool 0.0.1 [2023-12-09]",MB_YESNO)==IDYES)
    				{
    					cout<<endl;
    					system("TASKKILL /F /IM Program.exe /T");
					}
            		break;
    		}
    		if(judge)
    		{
    			judge=false;
    			break;
			}
		}
	}
	return 0;
}
