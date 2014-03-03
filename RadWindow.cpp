// RadWindow.cpp : Implementation of CRadWindow

#include "stdafx.h"
#include "RadWindow.h"

#include "RadFixedCollection.h"

// CRadWindow

static BOOL CALLBACK EnumChildWindowsProc(HWND hWnd, LPARAM lParam)
{
    std::vector<CComVariant>* wnds = (std::vector<CComVariant>*) lParam;
    wnds->push_back(CComVariant(CRadWindow::Create(hWnd)));
    return TRUE;
}

CRadWindow::CacheT CRadWindow::s_cache;

STDMETHODIMP CRadWindow::get_hWnd(ULONGLONG* pVal)
{
    *pVal = (ULONGLONG) m_hWnd;

    return S_OK;
}


STDMETHODIMP CRadWindow::get_Text(BSTR* pVal)
{
    wchar_t sText[1024];
    int len = ::GetWindowText(m_hWnd, sText, 1024);
#if 0
    SysFreeString(*pVal);
    *pVal = SysAllocStringLen(sText, len);
#else
    if (!SysReAllocStringLen(pVal, sText, len))
        return STG_E_INSUFFICIENTMEMORY;
#endif

    return S_OK;
}


STDMETHODIMP CRadWindow::put_Text(BSTR newVal)
{
    // TODO: Add your implementation code here

    return S_OK;
}


STDMETHODIMP CRadWindow::get_Long(LONG index, LONG* pVal)
{
    *pVal = GetWindowLong(m_hWnd, index);
    if (*pVal == 0)
        return HRESULT_FROM_WIN32(GetLastError());
    else
        return S_OK;
}


STDMETHODIMP CRadWindow::put_Long(LONG index, LONG newVal)
{
    if (SetWindowLong(m_hWnd, index, newVal) == 0)
        return HRESULT_FROM_WIN32(GetLastError());
    else
        return S_OK;
}


STDMETHODIMP CRadWindow::get_Class(BSTR* pVal)
{
    wchar_t sClass[1024];
    int len = ::GetClassName(m_hWnd, sClass, 1024);
#if 0
    SysFreeString(*pVal);
    *pVal = SysAllocStringLen(sClass, len);
#else
    if (!SysReAllocStringLen(pVal, sClass, len))
        return STG_E_INSUFFICIENTMEMORY;
#endif

    return S_OK;
}

STDMETHODIMP CRadWindow::get_Children(IUnknown** ppUnk)
{
    std::vector<CComVariant> wnds;

    EnumChildWindows(m_hWnd, EnumChildWindowsProc, (LPARAM) &wnds);

    *ppUnk = CRadFixedCollection::Create(wnds);

    return S_OK;
}

STDMETHODIMP CRadWindow::get_Parent(IRadWindow** pVal)
{
    *pVal = CRadWindow::Create(GetParent(m_hWnd));

    return S_OK;
}

STDMETHODIMP CRadWindow::get_Style(LONG* pVal)
{
    return get_Long(GWL_STYLE, pVal);
}

STDMETHODIMP CRadWindow::put_Style(LONG newVal)
{
    return put_Long(GWL_STYLE, newVal);
}

STDMETHODIMP CRadWindow::get_ExStyle(LONG* pVal)
{
    return get_Long(GWL_EXSTYLE, pVal);
}

STDMETHODIMP CRadWindow::put_ExStyle(LONG newVal)
{
    return put_Long(GWL_EXSTYLE, newVal);
}
