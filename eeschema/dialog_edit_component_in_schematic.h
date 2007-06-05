/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_edit_component_in_schematic.h
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     03/03/2006 15:02:54
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 03/03/2006 15:02:54

#ifndef _DIALOG_EDIT_COMPONENT_IN_SCHEMATIC_H_
#define _DIALOG_EDIT_COMPONENT_IN_SCHEMATIC_H_

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
class wxNotebook;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define ID_SCHEDIT_NOTEBOOK 10001
#define ID_PANEL_BASIC 10002
#define ID_RADIOBOX_UNIT 10004
#define ID_RADIOBOX_ORIENT 10005
#define ID_RADIOBOX_MIRROR 10007
#define ID_CHECKBOX 10008
#define ID_TEXTCTRL 10009
#define ID_PANEL_FIELD 10003
#define ID_CHECKBOX_SHOW_FILED 10010
#define ID_CHECKBOX_FILED_ORIENT 10011
#define ID_RESTORE_CMP_DEFAULTS 10006
#define SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_TITLE _("Component properties")
#define SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_IDNAME ID_DIALOG
#define SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_SIZE wxSize(400, 300)
#define SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * WinEDA_ComponentPropertiesFrame class declaration
 */

class WinEDA_ComponentPropertiesFrame: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( WinEDA_ComponentPropertiesFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    WinEDA_ComponentPropertiesFrame( );
    WinEDA_ComponentPropertiesFrame( WinEDA_SchematicFrame* parent,
		EDA_SchComponentStruct * cmp,
		wxWindowID id = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_SIZE, long style = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_SIZE, long style = SYMBOL_WINEDA_COMPONENTPROPERTIESFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin WinEDA_ComponentPropertiesFrame event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CLOSE
    void OnCloseClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESTORE_CMP_DEFAULTS
    void OnRestoreCmpDefaultsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

////@end WinEDA_ComponentPropertiesFrame event handler declarations

////@begin WinEDA_ComponentPropertiesFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end WinEDA_ComponentPropertiesFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

	void InitBuffers(void);
	void BuildPanelBasic(void);
	void BuildPanelFields(void);
	void ComponentPropertiesAccept(wxCommandEvent& event);
	void SetInitCmp( wxCommandEvent& event );
	void CopyDataToPanelField(void);
	void CopyPanelFieldToData(void);
	void SelectNewField(wxCommandEvent& event);

////@begin WinEDA_ComponentPropertiesFrame member variables
    wxBoxSizer* m_GeneralBoxSizer;
    wxNotebook* m_NoteBook;
    wxPanel* m_PanelBasic;
    wxRadioBox* m_SelectUnit;
    wxRadioBox* m_OrientUnit;
    wxRadioBox* m_MirrorUnit;
    wxStaticText* m_MsgPartLocked;
    wxCheckBox* m_ConvertButt;
    wxTextCtrl* m_RefInLib;
    wxPanel* m_PanelField;
    wxCheckBox* m_ShowFieldTextCtrl;
    wxCheckBox* m_VorientFieldText;
    wxBoxSizer* m_FieldDatasBoxSizer;
    wxBoxSizer* m_FieldSelectionBoxSizer;
////@end WinEDA_ComponentPropertiesFrame member variables

	WinEDA_SchematicFrame * m_Parent;
	EDA_SchComponentStruct * m_Cmp;
	EDA_LibComponentStruct * m_LibEntry;
	int m_CurrentFieldId;

	wxRadioBox * m_FieldSelection;
	WinEDA_GraphicTextCtrl * m_FieldTextCtrl;
	WinEDA_EnterText * m_FieldNameCtrl;
	WinEDA_PositionCtrl * m_FieldPositionCtrl;
	wxString m_FieldText[NUMBER_OF_FIELDS];
	wxString m_FieldName[NUMBER_OF_FIELDS];
	wxPoint m_FieldPosition[NUMBER_OF_FIELDS];
	int m_FieldSize[NUMBER_OF_FIELDS];
	int m_FieldFlags[NUMBER_OF_FIELDS];
	int m_FieldOrient[NUMBER_OF_FIELDS];
};

#endif
    // _DIALOG_EDIT_COMPONENT_IN_SCHEMATIC_H_
