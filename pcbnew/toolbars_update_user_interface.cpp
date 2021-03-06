/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2012 Jean-Pierre Charras, jean-pierre.charras@ujf-grenoble.fr
 * Copyright (C) 2012 SoftPLC Corporation, Dick Hollenbeck <dick@softplc.com>
 * Copyright (C) 2012 Wayne Stambaugh <stambaughw@verizon.net>
 * Copyright (C) 2012-2016 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file toolbars_update_user_interface.cpp
 * @brief Function to update toolbars UI after changing parameters.
 */

#include <fctsys.h>
#include <pgm_base.h>
#include <class_drawpanel.h>
#include <wxPcbStruct.h>
#include <dialog_helpers.h>
#include <class_board.h>
#include <pcbnew.h>
#include <pcbnew_id.h>
#include <drc_stuff.h>
#include <class_pcb_layer_box_selector.h>


void PCB_EDIT_FRAME::OnUpdateLayerPair( wxUpdateUIEvent& aEvent )
{
    PrepareLayerIndicator();
}


void PCB_EDIT_FRAME::OnUpdateSelectTrackWidth( wxUpdateUIEvent& aEvent )
{
    if( aEvent.GetId() == ID_AUX_TOOLBAR_PCB_TRACK_WIDTH )
    {
        if( m_SelTrackWidthBox->GetSelection() != (int) GetDesignSettings().GetTrackWidthIndex() )
            m_SelTrackWidthBox->SetSelection( GetDesignSettings().GetTrackWidthIndex() );
    }
    else
    {
        bool check = ( ( ( ID_POPUP_PCB_SELECT_WIDTH1 +
                           (int) GetDesignSettings().GetTrackWidthIndex() ) == aEvent.GetId() ) &&
                               !GetDesignSettings().m_UseConnectedTrackWidth &&
                               !GetDesignSettings().UseCustomTrackViaSize() );

        aEvent.Check( check );
    }
}


void PCB_EDIT_FRAME::OnUpdateSelectAutoTrackWidth( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( GetDesignSettings().m_UseConnectedTrackWidth &&
            !GetDesignSettings().UseCustomTrackViaSize() );
}


void PCB_EDIT_FRAME::OnUpdateSelectCustomTrackWidth( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( GetDesignSettings().UseCustomTrackViaSize() );
}


void PCB_EDIT_FRAME::OnUpdateSelectViaSize( wxUpdateUIEvent& aEvent )
{
    if( aEvent.GetId() == ID_AUX_TOOLBAR_PCB_VIA_SIZE )
    {
        if( m_SelViaSizeBox->GetSelection() != (int) GetDesignSettings().GetViaSizeIndex() )
            m_SelViaSizeBox->SetSelection( GetDesignSettings().GetViaSizeIndex() );
    }
    else
    {
        bool check = ( ( ( ID_POPUP_PCB_SELECT_VIASIZE1 +
                           (int) GetDesignSettings().GetViaSizeIndex() ) == aEvent.GetId() ) &&
                       !GetDesignSettings().m_UseConnectedTrackWidth &&
                       !GetDesignSettings().UseCustomTrackViaSize() );

        aEvent.Check( check );
    }
}


void PCB_EDIT_FRAME::OnUpdateLayerSelectBox( wxUpdateUIEvent& aEvent )
{
    m_SelLayerBox->SetLayerSelection( GetActiveLayer() );
}


#if defined( KICAD_SCRIPTING_WXPYTHON )

// Used only when the DKICAD_SCRIPTING_WXPYTHON option is on
void PCB_EDIT_FRAME::OnUpdateScriptingConsoleState( wxUpdateUIEvent& aEvent )
{
    wxMiniFrame * pythonPanelFrame = (wxMiniFrame *) findPythonConsole();
    bool pythonPanelShown = pythonPanelFrame ? pythonPanelFrame->IsShown() : false;
    aEvent.Check( pythonPanelShown );
}

#endif


void PCB_EDIT_FRAME::OnUpdateZoneDisplayStyle( wxUpdateUIEvent& aEvent )
{
    int selected = aEvent.GetId() - ID_TB_OPTIONS_SHOW_ZONES;
    auto displ_opts = (PCB_DISPLAY_OPTIONS*)GetDisplayOptions();

    if( aEvent.IsChecked() && ( displ_opts->m_DisplayZonesMode == selected ) )
        return;

    aEvent.Check( displ_opts->m_DisplayZonesMode == selected );
}


void PCB_EDIT_FRAME::OnUpdateDrcEnable( wxUpdateUIEvent& aEvent )
{
    bool state = !Settings().m_legacyDrcOn;
    aEvent.Check( state );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_DRC_OFF,
                                        Settings().m_legacyDrcOn ?
                                        _( "Disable design rule checking while routing/editing tracks" ) :
                                        _( "Enable design rule checking while routing/editing tracks" ) );
}

void PCB_EDIT_FRAME::OnUpdateShowBoardRatsnest( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( GetBoard()->IsElementVisible( LAYER_RATSNEST ) );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_SHOW_RATSNEST,
                                        GetBoard()->IsElementVisible( LAYER_RATSNEST ) ?
                                        _( "Hide board ratsnest" ) :
                                        _( "Show board ratsnest" ) );
}


void PCB_EDIT_FRAME::OnUpdateAutoDeleteTrack( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( Settings().m_legacyAutoDeleteOldTrack );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_AUTO_DEL_TRACK,
                                        Settings().m_legacyAutoDeleteOldTrack ?
                                        _( "Disable auto delete old track" ) :
                                        _( "Enable auto delete old track" ) );
}


void PCB_EDIT_FRAME::OnUpdateViaDrawMode( wxUpdateUIEvent& aEvent )
{
    auto displ_opts = (PCB_DISPLAY_OPTIONS*)GetDisplayOptions();
    aEvent.Check( !displ_opts->m_DisplayViaFill );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_SHOW_VIAS_SKETCH,
                                        displ_opts->m_DisplayViaFill ?
                                        _( "Show vias in outline mode" ) :
                                        _( "Show vias in fill mode" ) );
}


void PCB_EDIT_FRAME::OnUpdateTraceDrawMode( wxUpdateUIEvent& aEvent )
{
    auto displ_opts = (PCB_DISPLAY_OPTIONS*)GetDisplayOptions();
    aEvent.Check( !displ_opts->m_DisplayPcbTrackFill );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_SHOW_TRACKS_SKETCH,
                                        displ_opts->m_DisplayPcbTrackFill ?
                                        _( "Show tracks in outline mode" ) :
                                        _( "Show tracks in fill mode" ) );
}


void PCB_EDIT_FRAME::OnUpdateHighContrastDisplayMode( wxUpdateUIEvent& aEvent )
{
    auto displ_opts = (PCB_DISPLAY_OPTIONS*)GetDisplayOptions();
    aEvent.Check( displ_opts->m_ContrastModeDisplay );
    m_optionsToolBar->SetToolShortHelp( ID_TB_OPTIONS_SHOW_HIGH_CONTRAST_MODE,
                                        displ_opts->m_ContrastModeDisplay ?
                                        _( "Normal contrast display mode" ) :
                                        _( "High contrast display mode" ) );
}


void PCB_EDIT_FRAME::OnUpdateShowLayerManager( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( m_auimgr.GetPane( wxT( "m_LayersManagerToolBar" ) ).IsShown() );
}

void PCB_EDIT_FRAME::OnUpdateShowMicrowaveToolbar( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( m_auimgr.GetPane( wxT( "m_microWaveToolBar" ) ).IsShown() );
}


void PCB_EDIT_FRAME::OnUpdateSave( wxUpdateUIEvent& aEvent )
{
    aEvent.Enable( GetScreen()->IsModify() );
}


void PCB_EDIT_FRAME::OnUpdateVerticalToolbar( wxUpdateUIEvent& aEvent )
{
    aEvent.Check( GetToolId() == aEvent.GetId() );
}

void PCB_EDIT_FRAME::OnUpdateMuWaveToolbar( wxUpdateUIEvent& aEvent )
{
    if( aEvent.GetEventObject() == m_microWaveToolBar )
        aEvent.Check( GetToolId() == aEvent.GetId() );
}


void PCB_EDIT_FRAME::OnUpdateAutoPlaceTracksMode( wxUpdateUIEvent& aEvent )
{
    //Nothing to do.
}


void PCB_EDIT_FRAME::OnUpdateAutoPlaceModulesMode( wxUpdateUIEvent& aEvent )
{
    //Nothing to do.
}
