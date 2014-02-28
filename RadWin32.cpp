// RadWin32.cpp : Implementation of CRadWin32

#include "stdafx.h"
#include "RadWin32.h"

#include "RadWindow.h"
#include "RadFixedCollection.h"

// CRadWin32

static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
    std::vector<CComVariant>* wnds = (std::vector<CComVariant>*) lParam;
    wnds->push_back(CComVariant(CRadWindow::Create(hWnd)));
    return TRUE;
}

STDMETHODIMP CRadWin32::get_ForegroundWindow(IRadWindow** pVal)
{
    *pVal = CRadWindow::Create(GetForegroundWindow());

    return S_OK;
}

STDMETHODIMP CRadWin32::get_Windows(IUnknown** ppUnk)
{
    std::vector<CComVariant> wnds;

    EnumWindows(EnumWindowsProc, (LPARAM) &wnds);

    *ppUnk = CRadFixedCollection::Create(wnds);

    return S_OK;
}
