﻿
// ObjectLoacator.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//
#include <stdlib.h>
#include <crtdbg.h>

#include "pch.h"
#include "framework.h"
#include "Center.h"

#include "ObjectLoacator.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#else
#define DBG_NEW new
#endif

#define _CRTDBG_MAP_ALLOC

// CObjectLoacatorApp

BEGIN_MESSAGE_MAP(CObjectLoacatorApp, CWinApp)
	//ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CObjectLoacatorApp 생성

CObjectLoacatorApp::CObjectLoacatorApp()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CObjectLoacatorApp 개체입니다.

CObjectLoacatorApp theApp;


// CObjectLoacatorApp 초기화

BOOL CObjectLoacatorApp::InitInstance()
{
	//int dbgFlag = _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG | _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_DELAY_FREE_MEM_DF);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int dbgReport = _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	//_CrtSetBreakAlloc(1094);
	
	//_CrtSetBreakAlloc(981262);
	//_CrtSetBreakAlloc(164848);
	

	//_crtBreakAlloc = 249;
	//_CrtSetBreakAlloc(249);
	// 애플리케이션 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// MFC 컨트롤의 테마를 사용하기 위해 "Windows 원형" 비주얼 관리자 활성화
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	
	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 애플리케이션 마법사에서 생성된 애플리케이션"));

	//CObjectLoacatorDlg dlg;
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	
	//dlg.InsertColliderList(IDD_OBJECTLOACATOR_DIALOG);
	//dlg.ShowWindow(SW_SHOW);

	Center dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	//if (nResponse == IDOK)
	//{
	//}


	// 위에서 만든 셸 관리자를 삭제합니다.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif



	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고  응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
	return FALSE;
}






//BOOL CObjectLoacatorApp::PumpMessage()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//
//	return CWinApp::PumpMessage();
//}
