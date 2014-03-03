// RadWin32.h : Declaration of the CRadWin32

#pragma once
#include "resource.h"       // main symbols



#include "RadWsh_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CRadWin32

class ATL_NO_VTABLE CRadWin32 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRadWin32, &CLSID_RadWin32>,
	public IDispatchImpl<IRadWin32, &IID_IRadWin32, &LIBID_RadWshLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CRadWin32()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RADWIN32)


BEGIN_COM_MAP(CRadWin32)
	COM_INTERFACE_ENTRY(IRadWin32)
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



    STDMETHOD(get_ForegroundWindow)(IRadWindow** pVal);
    STDMETHOD(get_Windows)(IUnknown** ppUnk);
};

OBJECT_ENTRY_AUTO(__uuidof(RadWin32), CRadWin32)
