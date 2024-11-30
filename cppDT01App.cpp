/***************************************************************
 * Name:      cppDT01App.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 10 November 2024 06:37:06
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:
 **************************************************************/

/**
 * @file cppDT01App.cpp
 * @brief Implementation of the main application class for cppDT01.
 *
 * This file contains the entry point and initialization logic for the cppDT01 application.
 */

#include "cppDT01App.h"

//(*AppHeaders
#include "cppDT01Main.h"
#include <wx/image.h>
//*)

/**
 * @brief Implements the main application class.
 *
 * This macro generates the necessary code to initialize and run the application.
 */
IMPLEMENT_APP(cppDT01App);

/**
 * @brief Initializes the application.
 *
 * This function initializes all required image handlers and sets up the main frame of the application.
 *
 * @return `true` if initialization was successful; otherwise, `false`.
 */
bool cppDT01App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();  ///< Initialize all image handlers for wxWidgets.
    if ( wxsOK )
    {
        cppDT01Frame* Frame = new cppDT01Frame(0);  ///< Create the main application frame.
        Frame->Show();                                    ///< Display the main frame.
        SetTopWindow(Frame);                              ///< Set the main frame as the top window.
    }
    //*)
    return wxsOK;
}

