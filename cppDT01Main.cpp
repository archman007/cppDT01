/***************************************************************
 * Name:      cppDT01Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 10 November 2024 06:37:06
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:
 **************************************************************/

/**
 * @file cppDT01Main.cpp
 * @brief Main application frame for cppDT01 using wxWidgets framework.
 *
 * This file contains the main frame class, event table, and functions for handling
 * basic menu events such as "Quit" and "About" in a wxWidgets GUI application.
 */

#include "cppDT01Main.h"
#include <wx/msgdlg.h>
#include <wx/wx.h>
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>


//(*InternalHeaders(cppDT01Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

/**
 * @enum wxbuildinfoformat
 * Defines formats for wxWidgets build information.
 */
enum wxbuildinfoformat
{
    short_f, /**< Short format */
    long_f   /**< Long format */
};

/**
 * @brief Retrieves wxWidgets build information.
 *
 * @param format Specifies whether to return short or long format build info.
 * @return wxString Build information string.
 */
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif
    }

    return wxbuild;
}

//(*IdInit(cppDT01Frame)
const long cppDT01Frame::ID_ChgCol = wxNewId();
const long cppDT01Frame::ID_ChgFont = wxNewId();
const long cppDT01Frame::idMenuQuit = wxNewId();
const long cppDT01Frame::idMenuAbout = wxNewId();
const long cppDT01Frame::ID_STATUSBAR1 = wxNewId();
//*)

/**
 * @brief Event table for cppDT01Frame.
 * Maps events to their corresponding event handlers.
 */
BEGIN_EVENT_TABLE(cppDT01Frame, wxFrame)
    //(*EventTable(cppDT01Frame)
    //*)
END_EVENT_TABLE()

/**
 * @brief Constructor for cppDT01Frame.
 *
 * Initializes menu items and connects events for the main application frame.
 *
 * @param parent Parent window.
 * @param id Window ID.
 */
cppDT01Frame::cppDT01Frame(wxWindow* parent, wxWindowID id)
{
    //(*Initialize(cppDT01Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menChangeBkg = new wxMenuItem(Menu1, ID_ChgCol, _("Change Background Color"), _("Change Background Color"), wxITEM_NORMAL);
    Menu1->Append(menChangeBkg);
    menChgFont = new wxMenuItem(Menu1, ID_ChgFont, _("Change Font"), _("Change Font Now"), wxITEM_NORMAL);
    Menu1->Append(menChgFont);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ColourDialog1 = new wxColourDialog(this);
    wxFontData fontData_1;
    fontData_1.SetInitialFont(*wxNORMAL_FONT);
    FontDialog1 = new wxFontDialog(this, fontData_1);

    Connect(ID_ChgCol,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppDT01Frame::OnmenChangeBkgSelected);
    Connect(ID_ChgFont,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppDT01Frame::OnmenChgFontSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppDT01Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppDT01Frame::OnAbout);
    //*)

    // Create a Date Picker Control (for date selection)

    wxDatePickerCtrl* m_datePicker = new wxDatePickerCtrl(this, id, wxDefaultDateTime, wxPoint(20, 20), wxSize(200, -1));

    wxTimePickerCtrl* timePicker2 = new wxTimePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxPoint(20,52)) ;

    // Create a Button to show selected date and time
    wxButton* m_showButton = new wxButton(this, wxID_ANY,  "Accept", wxPoint(20,85)) ;
    wxButton* m_cancel = new wxButton(this, wxID_ANY,  "Cancel", wxPoint(110,85)) ;
//    m_showButton = new wxButton(this, wxID_ANY, "Show Date & Time");

}

/**
 * @brief Destructor for cppDT01Frame.
 */
cppDT01Frame::~cppDT01Frame()
{
    //(*Destroy(cppDT01Frame)
    //*)
}

/**
 * @brief Handles the "Quit" menu item event.
 *
 * Closes the application when triggered.
 *
 * @param event wxCommandEvent object containing event data.
 */
void cppDT01Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/**
 * @brief Handles the "About" menu item event.
 *
 * Displays a message box with wxWidgets build information.
 *
 * @param event wxCommandEvent object containing event data.
 */
void cppDT01Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

/**
 * @brief Event handler for changing the background color.
 *
 * This function is triggered when the "Change Background" menu item is selected.
 * It opens a color picker dialog, allowing the user to select a new background color.
 * If the user confirms the selection, the background color of the frame is updated.
 *
 * @param event The wxCommandEvent triggered by selecting the menu item.
 */
void cppDT01Frame::OnmenChangeBkgSelected(wxCommandEvent& event)
{
    // Create a color dialog with the current color data.
    wxColourDialog colorDialog(this, &data);

    // Show the dialog and check if the user clicked OK.
    if (colorDialog.ShowModal() == wxID_OK)
    {
        // Retrieve the selected color data.
        wxColourData retData = colorDialog.GetColourData();

        // Extract the selected color from the color data.
        color = retData.GetColour();

        // Set the frame's background color to the selected color.
        this->SetBackgroundColour(color);
    }
}

/**
 * @brief Handles the event triggered when a font change menu item is selected.
 *
 * This method displays a font selection dialog, allowing the user to choose a new font.
 * If the user confirms their selection, the font of the current window is updated
 * to the selected font.
 *
 * @param event The wxCommandEvent triggered by the menu item selection.
 */
void cppDT01Frame::OnmenChgFontSelected(wxCommandEvent& event)
{
    wxFontData fontData;
    fontData.EnableEffects(true);             // Allow effects like underline, color, etc.
    fontData.SetInitialFont(this->GetFont()); // Set the initial font to the current font of the frame.

    wxFontDialog fontDialog(this, fontData);  // Create the font dialog with initial data.

    if (fontDialog.ShowModal() == wxID_OK)    // Show the dialog and check if the user clicked OK.
    {
        wxFontData retData = fontDialog.GetFontData(); // Retrieve the chosen font data.
        wxFont font = retData.GetChosenFont();         // Extract the selected font.
        this->SetFont(font);                           // Apply the new font to the frame.
    }
}

