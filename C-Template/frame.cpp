#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND,UINT,WPARAM,LPARAM);

char szWinName[]="MyWin";

int WINAPI WinMain(HINSTANCE hThisInst,HINSTANCE hPrevInst,
				   LPSTR lpszArgs,int nWinMode){
	HWND hwnd;
	MSG msg;
	WNDCLASS wc1;

	//����һ��������
	wc1.hInstance=hThisInst;        //��ʵ���ľ��
	wc1.lpszClassName=szWinName;    //�����������
	wc1.lpfnWndProc=WindowFunc;     //��������
	wc1.style=0;                    //Ĭ��ģʽ

	wc1.hIcon=LoadIcon(NULL,IDI_APPLICATION);   //ͼ��ģʽ
	wc1.hCursor=LoadCursor(NULL,IDC_ARROW);     //���ģʽ
	wc1.lpszMenuName=NULL;                      //û�в˵�

	wc1.cbClsExtra=0;
	wc1.cbWndExtra=0;

	//���ô��ڱ���Ϊ��ɫ
	wc1.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);

	//�ǼǴ�����
	if(!RegisterClass(&wc1)) return 0;

	//����һ������
	hwnd=CreateWindow(
		szWinName,              //��������
		"Windows 98 Framework", //����
		WS_OVERLAPPEDWINDOW,    //����ģʽ
		CW_USEDEFAULT,          // X ����
		CW_USEDEFAULT,          // Y ����
		CW_USEDEFAULT,          //���
		CW_USEDEFAULT,          //�߶�
		HWND_DESKTOP,           //û�и�����
		NULL,                   //û�в˵�
		hThisInst,              //�ó���ʵ���ľ��
		NULL
		);

	//��ʾ����
	ShowWindow(hwnd,nWinMode);
	UpdateWindow(hwnd);

	//������Ϣѭ��
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg); //����ʹ�ü���
		DispatchMessage(&msg);  //���ش��ڿ���
	}
	return msg.wParam;
}

//�ú����� Windows 98 ���ã����Դ���Ϣ�����д�����Ϣ
LRESULT CALLBACK WindowFunc(HWND hwnd,UINT message,
							WPARAM wParam,LPARAM lParam){
	switch(message){
	case WM_DESTROY: //��ֹ����
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,
			message,wParam,lParam);
	}
	return 0;
}