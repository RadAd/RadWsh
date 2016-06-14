// RadWindow.h : Declaration of the CRadWindow

#pragma once
#include "resource.h"       // main symbols



#include "RadWsh_i.h"

#include <map>


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

    ~CRadWindow()
    {
        s_cache.erase(m_hWnd);
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
    struct HwndLess
    {
        bool operator()(HWND a, HWND b) const
        {
            return (ULONGLONG) a < (ULONGLONG) b;
        }
    };

    typedef std::map<HWND, CRadWindow*, HwndLess> CacheT;
    static CacheT s_cache;
    HWND m_hWnd;
public:

    void Init(HWND hWnd)
    {
        s_cache.erase(m_hWnd);
        m_hWnd = hWnd;
        s_cache[m_hWnd] = this;
    }

    static CRadWindow* Create(HWND hWnd)
    {
        CacheT::const_iterator it = s_cache.find(hWnd);
        if (it != s_cache.end())
        {
            it->second->AddRef();
            return it->second;
        }
        else
        {
            CComObject<CRadWindow>* pRadWindow;
            CComObject<CRadWindow>::CreateInstance(&pRadWindow);

            pRadWindow->AddRef();
            pRadWindow->Init(hWnd);

            return pRadWindow;
        }
    }

    STDMETHOD(get_hWnd)(ULONGLONG* pVal);
    STDMETHOD(get_Text)(BSTR* pVal);
    STDMETHOD(put_Text)(BSTR newVal);
    STDMETHOD(get_Long)(LONG index, LONG* pVal);
    STDMETHOD(put_Long)(LONG index, LONG newVal);
    STDMETHOD(get_Class)(BSTR* pVal);
    STDMETHOD(get_Children)(IUnknown** ppUnk);
    STDMETHOD(get_Parent)(IRadWindow** pVal);
    STDMETHOD(get_Style)(LONG* pVal);
    STDMETHOD(put_Style)(LONG newVal);
    STDMETHOD(get_ExStyle)(LONG* pVal);
    STDMETHOD(put_ExStyle)(LONG newVal);
    STDMETHOD(get_pid)(ULONG* pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(RadWindow), CRadWindow)
