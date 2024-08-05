#include "WindowsFileDialogBPLibrary.h"
#include "WindowsFileDialog.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"    // allows the use of Windows-specific data types
#include <commdlg.h>                              //
#include "Windows/HideWindowsPlatformTypes.h"     // hides the Windows-specific data types included by the previous header file. This is done to prevent conflicts with Unreal Engine's data types.
#endif

UWindowsFileDialogBPLibrary::UWindowsFileDialogBPLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

FString UWindowsFileDialogBPLibrary::OpenFileDialog(const FString& DefaultPath, const FString& DefaultFileName)
{
#if PLATFORM_WINDOWS

    // The sz prefix stands for "string zero-terminated", which means that the string is null-terminated, i.e., it ends with a null character ('\0').
    // OPENFILENAME is a structure defined in the Windows API that contains information about the file open dialog box.
    TCHAR szFile[MAX_PATH] = { 0 };                                      
    OPENFILENAME OpenFileName = { 0 };                                   

    // Setting lStructSize to the size of the OPENFILENAME structure ensures that the GetOpenFileName function can properly read and interpret the structure. 
    // If you omit this line, the GetOpenFileName function may not work correctly, or it may crash.
    OpenFileName.lStructSize = sizeof(OpenFileName);          
 
    OpenFileName.hwndOwner = NULL;               // It means that the file open dialog box will have no owner window.
    OpenFileName.lpstrFile = szFile;             // store the path of the selected file.
    OpenFileName.nMaxFile = MAX_PATH;            // maximum length of a file path.
 
    FString InitialDirectory = *DefaultPath;
    if (InitialDirectory.IsEmpty()) 
        InitialDirectory = FPaths::ProjectDir();
    
    // For this to work on Windows, forward slashes must be replaced by backslashes
    InitialDirectory.ReplaceCharInline(TEXT('/'), TEXT('\\'));
    OpenFileName.lpstrInitialDir = *InitialDirectory;
    
    // default file name to be displayed in the file open dialog box (when saving).
    OpenFileName.lpstrFileTitle = (LPWSTR)TCHAR_TO_WCHAR(DefaultFileName.GetCharArray().GetData());     
    
    // OFN_PATHMUSTEXIST - user must select a valid path
    // OFN_FILEMUSTEXIST - user must select a valid file
    // OFN_NOCHANGEDIR   - file open dialog box will not change the current directory
    OpenFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;                   

    if (GetOpenFileName(&OpenFileName))
    {
        return FString(szFile);
    }
#endif
    return FString();
}