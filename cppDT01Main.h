/***************************************************************
 * Name:      cppDT01Main.h
 * Purpose:   Defines Application Frame for the cppDT01 application
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 10 November 2024 06:37:06
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:   (Specify your license here, e.g., MIT, GPL, etc.)
 **************************************************************/

#ifndef CPPMYSKEL1MAIN_H
#define CPPMYSKEL1MAIN_H

// wxWidgets headers used for GUI components
//(*Headers(cppDT01Frame)
#include <wx/colordlg.h>
#include <wx/fontdlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include <wx/datectrl.h>
#include <wx/timectrl.h>

// Definition of the main frame class for the application
class cppDT01Frame: public wxFrame
{
public:
    // Constructor and Destructor
    cppDT01Frame(wxWindow* parent, wxWindowID id = -1); // Initializes the main frame
    virtual ~cppDT01Frame();                             // Cleans up resources

    wxColourData data;  // Stores color data used for color dialog
    wxColour color;     // Represents a selected color

private:
//     wxDatePickerCtrl m_datePicker = *pointerToDatePicker; // Dereference the pointer

    // Event handlers for user interactions
    //(*Handlers(cppDT01Frame)
    void OnQuit(wxCommandEvent& event);              // Handles "Quit" menu item
    void OnAbout(wxCommandEvent& event);             // Handles "About" menu item
    void OnmenChangeBkgSelected(wxCommandEvent& event);  // Changes background color
    void OnmenChgFontSelected(wxCommandEvent& event);    // Changes font style
    //*)

    // Identifiers for menu items and controls
    //(*Identifiers(cppDT01Frame)
    static const long ID_ChgCol;
    static const long ID_ChgFont;
    static const long idMenuQuit;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    // Declarations of GUI components
    //(*Declarations(cppDT01Frame)
    wxColourDialog* ColourDialog1;
    wxFontDialog* FontDialog1;
    wxMenuItem* menChangeBkg;
    wxMenuItem* menChgFont;
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE() // Macro for declaring the event table
};

#endif // CPPMYSKEL1MAIN_H


