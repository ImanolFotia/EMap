#include "EMap.h"

//(*InternalHeaders(EMap)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(EMap)
//*)

BEGIN_EVENT_TABLE(EMap,wxFrame)
	//(*EventTable(EMap)
	//*)
END_EVENT_TABLE()

EMap::EMap(wxWindow* parent)
{
	//(*Initialize(EMap)
	wxXmlResource::Get()->LoadObject(this,parent,_T("EMap"),_T("wxFrame"));
	//*)
}

EMap::~EMap()
{
	//(*Destroy(EMap)
	//*)
}

