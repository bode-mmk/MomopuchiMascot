// MomoPuchiMascot.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "MomoPuchiMascot.h"
#include "Object.h"
#include "Scene.h"
#include "SuperVisor.h"
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/filesystem.hpp>

#define MAX_LOADSTRING 100

// �O���[�o���ϐ�:
HINSTANCE hInst;                                // ���݂̃C���^�[�t�F�C�X
WCHAR szTitle[MAX_LOADSTRING];                  // �^�C�g�� �o�[�̃e�L�X�g
WCHAR szWindowClass[MAX_LOADSTRING];            // ���C�� �E�B���h�E �N���X��

// ���̃R�[�h ���W���[���Ɋ܂܂��֐��̐錾��]�����܂�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//GDI+�I�u�W�F�N�g
Gdiplus::GdiplusStartupInput gdiSI;
ULONG_PTR gdiToken;

//App SuperVisor
SuperVisor super_visor;

//�E�B���h�E�T�C�Y( �b�� )
constexpr auto WINDOW_WIDTH = 500u;
constexpr auto WINDOW_HEIGHT = 500u;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �����ɃR�[�h��}�����Ă��������B
	Gdiplus::GdiplusStartup(&gdiToken, &gdiSI, NULL);

	//momoka�̓o�^
	auto momoka = std::make_shared<Scene>();
	momoka->registeration_object("C:\\left");
	super_visor.registeration_scene(std::move(momoka));

    // �O���[�o������������������Ă��܂��B
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MOMOPUCHIMASCOT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // �A�v���P�[�V�����̏����������s���܂�:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MOMOPUCHIMASCOT));

    MSG msg;

	// �������ꂽ���C�����[�v
	while (true) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE)) {
			if (!GetMessage(&msg, nullptr, 0, 0)) {
				break; // quit 
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// game main
			{
				// next_frame
				super_visor.next_frame_all_animation();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(16));

			InvalidateRect(msg.hwnd, nullptr, FALSE);
		}
	}

	Gdiplus::GdiplusShutdown(gdiToken);

    return (int) msg.wParam;
}



//
//  �֐�: MyRegisterClass()
//
//  �ړI: �E�B���h�E �N���X��o�^���܂��B
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = 0; // CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MOMOPUCHIMASCOT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = 0; // MAKEINTRESOURCEW(IDC_MOMOPUCHIMASCOT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    return RegisterClassExW(&wcex);
}

//
//   �֐�: InitInstance(HINSTANCE, int)
//
//   �ړI: �C���X�^���X �n���h����ۑ����āA���C�� �E�B���h�E���쐬���܂��B
//
//   �R�����g:
//
//        ���̊֐��ŁA�O���[�o���ϐ��ŃC���X�^���X �n���h����ۑ����A
//        ���C�� �v���O���� �E�B���h�E���쐬����ѕ\�����܂��B
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �O���[�o���ϐ��ɃC���X�^���X�������i�[���܂��B

   HWND hWnd = CreateWindowExW(WS_EX_LAYERED, szWindowClass, szTitle, WS_POPUP | WS_VISIBLE, /* WS_OVERLAPPEDWINDOW, */
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   MoveWindow(hWnd, 1000, 500, 500, 500, TRUE);
   SetLayeredWindowAttributes(hWnd, RGB(255, 254, 255), 255, LWA_COLORKEY);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �֐�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �ړI:    ���C�� �E�B���h�E�̃��b�Z�[�W���������܂��B
//
//  WM_COMMAND  - �A�v���P�[�V���� ���j���[�̏���
//  WM_PAINT    - ���C�� �E�B���h�E�̕`��
//  WM_DESTROY  - ���~���b�Z�[�W��\�����Ė߂�
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �I�����ꂽ���j���[�̉��:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_PAINT:
	{
		// ready to draw for double buffer
		auto buffer_bitmap = std::make_unique<Gdiplus::Bitmap>(WINDOW_WIDTH, WINDOW_HEIGHT);
		auto buffer_graphics = std::make_unique<Gdiplus::Graphics>(buffer_bitmap.get());

		// fill background for translation by translation color
		auto brush = std::make_unique<Gdiplus::SolidBrush>(Gdiplus::Color::Color(255, 254, 255));
		buffer_graphics->FillRectangle(brush.get(), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

		// draw super visor
		super_visor.paint_all(*buffer_graphics.get());

		// draw screen
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(buffer_bitmap.get(), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:
		::OutputDebugString(_T("Lbutton"));
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �o�[�W�������{�b�N�X�̃��b�Z�[�W �n���h���[�ł��B
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
