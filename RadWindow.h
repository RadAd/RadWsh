// RadWindow.h : Declaration of the CRadWindow

#pragma once
#include "resource.h"       // main symbols



#include "RadWsh_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CRadWindow

class ATL_NO_VTABLE CRadWindow :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRadWindow, &CLSID_RadWindow>,
	public IDispatchImpl<IRadWindow, &IID_IRadWindow, &LIBID_RadWshLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CRadWindow()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RADWINDOW)


BEGIN_COM_MAP(CRadWindow)
	COM_INTERFACE_ENTRY(IRadWindow)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



private:
    HWND m_hWnd;
public:

    void Init(HWND hWnd)
    {
        m_hWnd = hWnd;
    }

    static CRadWindow* Create(HWND hWnd)
    {
        if (hWnd != NULL)
        {
            CComObject<CRadWindow>* pRadWindow;
            CComObject<CRadWindow>::CreateInstance(&pRadWindow);

            pRadWindow->AddRef();
            pRadWindow->Init(hWnd);

            return pRadWindow;
        }
        else
            return nullptr;
    }

    STDMETHOD(get_hWnd)(ULONGLONG* pVal);
    STDMETHOD(get_Text)(BSTR* pVal);
    STDMETHOD(put_Text)(BSTR newVal);
    STDMETHOD(get_Long)(LONG index, LONG* pVal);
    STDMETHOD(put_Long)(LONG index, LONG newVal);
    STDMETHOD(get_Class)(BSTR* pVal);
    STDMETHOD(get_Children)(IUnknown** ppUnk);
};

OBJECT_ENTRY_AUTO(__uuidof(RadWindow), CRadWindow)
