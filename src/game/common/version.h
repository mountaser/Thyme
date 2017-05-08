////////////////////////////////////////////////////////////////////////////////
//                               --  THYME  --                                //
////////////////////////////////////////////////////////////////////////////////
//
//  Project Name:: Thyme
//
//          File:: VERSION.H
//
//        Author:: OmniBlade
//
//  Contributors:: 
//
//   Description:: Stores information about the current build.
//
//       License:: Thyme is free software: you can redistribute it and/or 
//                 modify it under the terms of the GNU General Public License 
//                 as published by the Free Software Foundation, either version 
//                 2 of the License, or (at your option) any later version.
//
//                 A full copy of the GNU General Public License can be found in
//                 LICENSE
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef VERSION_H
#define VERSION_H

#include "asciistring.h"
#include "unicodestring.h"

#define TheVersion (Make_Global<Version *>(0x00A29BA0))

class Version
{
    public:
        Version();

        void Set_Version(
            int maj, int min, int build, int local_build, 
            AsciiString location, AsciiString user, AsciiString time, AsciiString date);
        
        int Get_Version_Number() { return m_minor | (m_major << 16); }
        int Get_Build_Number() { return m_buildNum; }
        int Get_Local_Build_Number() { return m_localBuildNum; }

        AsciiString Get_Ascii_Version();
        AsciiString Get_Ascii_Branch() { return m_branch; }
        AsciiString Get_Ascii_Commit_Hash() { return m_commitHash; }
        AsciiString Get_Ascii_Build_Time();

        // TODO unicode implementation rely on GameTextManager
        UnicodeString Get_Unicode_Version();
        UnicodeString Get_Full_Unicode_Version();
        UnicodeString Get_Unicode_Branch();
        UnicodeString Get_Unicode_Commit_Hash();
        UnicodeString Get_Unicode_Build_Time();

        // Some functions check this bool to decide what format the
        // printed version string should take.
        void Set_Use_Full_Version(bool cmd_line) { m_useFullVersion = cmd_line; }
        bool Using_Full_Version() { return m_useFullVersion; }

    private:
        int m_major;
        int m_minor;
        int m_buildNum;
        int m_localBuildNum;
        AsciiString m_branch;       // Was Location in orignal
        AsciiString m_commitHash;   // Was User in original
        AsciiString m_buildTime;
        AsciiString m_buildDate;
        bool m_useFullVersion;
};

#endif // _VERSION_H
