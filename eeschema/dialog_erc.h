/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_erc.h
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     12/02/2006 17:08:38
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 12/02/2006 17:08:38

#ifndef _DIALOG_ERC_H_
#define _DIALOG_ERC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dialog_erc.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/valgen.h"
#include "wx/statline.h"
////@end includes

/* Variable locales */
extern int WriteFichierERC;
/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxBoxSizer;
class wxStaticLine;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define ID_ERC_NOTEBOOK 10001
#define ID_PANEL 10004
#define ID_CHECKBOX 10006
#define ID_ERC_CMP 10002
#define ID_ERASE_DRC_MARKERS 10003
#define ID_PANEL1 10005
#define ID_RESET_MATRIX 10007
// #define SYMBOL_WINEDA_ERCFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WINEDA_ERCFRAME_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WINEDA_ERCFRAME_TITLE _("EESchema Erc")
#define SYMBOL_WINEDA_ERCFRAME_IDNAME ID_DIALOG
#define SYMBOL_WINEDA_ERCFRAME_SIZE wxDefaultSize
#define SYMBOL_WINEDA_ERCFRAME_POSITION wxDefaultPosition
////@end control identifiers
#define ID_MATRIX_0 1800

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * WinEDA_ErcFrame class declaration
 */

class WinEDA_ErcFrame: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( WinEDA_ErcFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    WinEDA_ErcFrame( );
    WinEDA_ErcFrame( WinEDA_SchematicFrame* parent, wxWindowID id = SYMBOL_WINEDA_ERCFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_ERCFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_ERCFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_ERCFRAME_SIZE, long style = SYMBOL_WINEDA_ERCFRAME_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_ERCFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_ERCFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_ERCFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_ERCFRAME_SIZE, long style = SYMBOL_WINEDA_ERCFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin WinEDA_ErcFrame event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ERC_CMP
    void OnErcCmpClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ERASE_DRC_MARKERS
    void OnEraseDrcMarkersClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_EXIT
    void OnExitClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESET_MATRIX
    void OnResetMatrixClick( wxCommandEvent& event );

////@end WinEDA_ErcFrame event handler declarations

////@begin WinEDA_ErcFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end WinEDA_ErcFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

	void DelERCMarkers(wxCommandEvent& event);
	void TestErc(wxCommandEvent& event);
	void SelLocal(wxCommandEvent& event);
	void SelNewCmp(wxCommandEvent& event);
	void ResetDefaultERCDiag(wxCommandEvent& event);
	void ChangeErrorLevel(wxCommandEvent& event);
	void ReBuildMatrixPanel();

////@begin WinEDA_ErcFrame member variables
    wxNotebook* m_NoteBook;
    wxPanel* m_PanelERC;
    wxBoxSizer* m_PanelERCSizer;
    wxStaticText* ErcTotalErrors;
    wxStaticText* WarnErcErrors;
    wxStaticText* ErcErrors;
    wxStaticText* m_TotalErrCount;
    wxStaticText* m_LastWarningCount;
    wxStaticText* m_LastErrCount;
    wxCheckBox* m_WriteResultOpt;
    wxPanel* m_PanelERCOptions;
    wxBoxSizer* m_PanelMatrixSizer;
    wxButton* m_ResetOptButton;
    wxStaticLine* m_SeparatorLine;
    wxBoxSizer* m_MatrixSizer;
////@end WinEDA_ErcFrame member variables

	WinEDA_SchematicFrame * m_Parent;
	wxBitmapButton * m_ButtonList[PIN_NMAX][PIN_NMAX];
	bool m_Initialized;
};

#endif
    // _DIALOG_ERC_H_
