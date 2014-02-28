// dllmain.h : Declaration of module class.

class CRadWshModule : public ATL::CAtlDllModuleT< CRadWshModule >
{
public :
	DECLARE_LIBID(LIBID_RadWshLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_RADWSH, "{4E360802-DB28-49AE-B987-E6BCCA71BB11}")
};

extern class CRadWshModule _AtlModule;
