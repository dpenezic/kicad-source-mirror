/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_find.h
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     16/02/2006 20:18:11
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 16/02/2006 20:18:11

#ifndef _DIALOG_FIND_H_
#define _DIALOG_FIND_H_

/*!
 * Includes
 */

////@begin includes
#include "wx/valtext.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define SYMBOL_WINEDA_FINDFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WINEDA_FINDFRAME_TITLE _("EESchema Locate")
#define SYMBOL_WINEDA_FINDFRAME_IDNAME ID_DIALOG
#define SYMBOL_WINEDA_FINDFRAME_SIZE wxSize(400, 300)
#define SYMBOL_WINEDA_FINDFRAME_POSITION wxDefaultPosition
#define ID_TEXTCTRL1 10008
#define FIND_SHEET 10001
#define FIND_HIERARCHY 10002
#define FIND_NEXT 10005
#define FIND_MARKERS 10003
#define FIND_NEXT_MARKER 10006
#define LOCATE_IN_LIBRARIES 10004
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * WinEDA_FindFrame class declaration
 */

class WinEDA_FindFrame: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( WinEDA_FindFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    WinEDA_FindFrame( );
    WinEDA_FindFrame( WinEDA_SchematicFrame* parent, wxWindowID id = SYMBOL_WINEDA_FINDFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_FINDFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_FINDFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_FINDFRAME_SIZE, long style = SYMBOL_WINEDA_FINDFRAME_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_FINDFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_FINDFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_FINDFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_FINDFRAME_SIZE, long style = SYMBOL_WINEDA_FINDFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin WinEDA_FindFrame event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for FIND_SHEET
    void OnFindSheetClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for FIND_HIERARCHY
    void OnFindHierarchyClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for FIND_NEXT
    void OnFindNextClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for FIND_MARKERS
    void OnFindMarkersClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for FIND_NEXT_MARKER
    void OnFindNextMarkerClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for LOCATE_IN_LIBRARIES
    void OnLocateInLibrariesClick( wxCommandEvent& event );

////@end WinEDA_FindFrame event handler declarations

////@begin WinEDA_FindFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end WinEDA_FindFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

	void FindSchematicItem(wxCommandEvent& event);
	void FindMarker(wxCommandEvent& event);
	void LocatePartInLibs(wxCommandEvent& event);
	int ExploreAllLibraries(const wxString & wildmask, wxString & FindList);

////@begin WinEDA_FindFrame member variables
    wxTextCtrl* m_NewTextCtrl;
////@end WinEDA_FindFrame member variables
	WinEDA_SchematicFrame * m_Parent;
};

#endif
    // _DIALOG_FIND_H_
