// RadFixedCollection.h : Declaration of the CRadFixedCollection

#pragma once
#include "resource.h"       // main symbols



#include "RadWsh_i.h"
#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CRadFixedCollection

class ATL_NO_VTABLE CRadFixedCollection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRadFixedCollection, &CLSID_RadFixedCollection>,
	public IDispatchImpl<IRadFixedCollection, &IID_IRadFixedCollection, &LIBID_RadWshLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CRadFixedCollection()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RADFIXEDCOLLECTION)


BEGIN_COM_MAP(CRadFixedCollection)
	COM_INTERFACE_ENTRY(IRadFixedCollection)
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
    std::vector<CComVariant> m_vars;
public:

    void Init(const std::vector<CComVariant>& vars)
    {
        m_vars = vars;
    }


    static CRadFixedCollection* Create(const std::vector<CComVariant>& vars)
    {
        CComObject<CRadFixedCollection>* pRadWindow;
        CComObject<CRadFixedCollection>::CreateInstance(&pRadWindow);

        pRadWindow->AddRef();
        pRadWindow->Init(vars);

        return pRadWindow;
    }

    STDMETHOD(get_Count)(LONG* pVal);
    STDMETHOD(get__NewEnum)(IUnknown** pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(RadFixedCollection), CRadFixedCollection)
