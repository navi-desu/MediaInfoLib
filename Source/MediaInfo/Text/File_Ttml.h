/*  Copyright (c) MediaArea.net SARL. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Information about TTML files
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#ifndef MediaInfo_File_TtmlH
#define MediaInfo_File_TtmlH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "MediaInfo/File__Analyze.h"
#include "MediaInfo/TimeCode.h"
//---------------------------------------------------------------------------

namespace tinyxml2
{
    class XMLDocument;
    class XMLElement;
}

namespace MediaInfoLib
{

//***************************************************************************
// Class File_Sami
//***************************************************************************

class File_Ttml : public File__Analyze
{
public :
    File_Ttml();

    #if MEDIAINFO_EVENTS
        int8u   MuxingMode;
    #endif //MEDIAINFO_EVENTS

private :
    //Streams management
    void Streams_Accept();
    void Streams_Finish();

    //Buffer - File header
    bool FileHeader_Begin();

    //Buffer - Global
    void Read_Buffer_Unsynched();
    #if MEDIAINFO_SEEK
    size_t Read_Buffer_Seek (size_t Method, int64u Value, int64u ID);
    #endif //MEDIAINFO_SEEK
    void Read_Buffer_Continue();

    //Temp
    TimeCode Time_Start;
    TimeCode Time_End;
    int64u FrameCount;
    int64u LineCount;
    int64u LineMaxCountPerEvent;
    int64u FrameRate_Int;
    int64u FrameRateMultiplier_Num;
    int64u FrameRateMultiplier_Den;
    float64 FrameRate=0;
    bool FrameRate_Is1001=false;
};

} //NameSpace

#endif
