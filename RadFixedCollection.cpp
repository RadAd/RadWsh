// EnumWindows.cpp : Implementation of CEnumWindows

#include "stdafx.h"
#include "RadFixedCollection.h"

#include "RadWindow.h"

//http://msdn.microsoft.com/en-us/library/x416d0xc%28VS.80%29.aspx

// From http://msdn.microsoft.com/en-us/library/7k0az35b.aspx
template <class EnumType, class CollType>
HRESULT CreateSTLEnumerator(IUnknown** ppUnk, IUnknown* pUnkForRelease, CollType& collection)
{
   if (ppUnk == NULL)
      return E_POINTER;
   *ppUnk = NULL;

   CComObject<EnumType>* pEnum = NULL;
   HRESULT hr = CComObject<EnumType>::CreateInstance(&pEnum);

   if (FAILED(hr))
      return hr;

   hr = pEnum->Init(pUnkForRelease, collection);

   if (SUCCEEDED(hr))
      hr = pEnum->QueryInterface(ppUnk);

   if (FAILED(hr))
      delete pEnum;

   return hr;
} // CreateSTLEnumerator

// CEnumWindows


STDMETHODIMP CRadFixedCollection::get_Count(LONG* pVal)
{
    *pVal = (LONG) m_vars.size();

    return S_OK;
}


STDMETHODIMP CRadFixedCollection::get__NewEnum(IUnknown** pVal)
{
    return CreateSTLEnumerator< CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>, std::vector<CComVariant> > >(pVal, this, m_vars);
}
