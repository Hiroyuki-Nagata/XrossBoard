@echo off
@rem 
@rem �Ǘ��Ҍ����悱��
@rem reference: http://stackoverflow.com/a/18037959
@rem 

:checkPrivileges
NET FILE 1>NUL 2>NUL
if '%errorlevel%' == '0' ( goto gotPrivileges ) else ( goto getPrivileges )

:getPrivileges
if '%1'=='ELEV' (shift & goto gotPrivileges)
ECHO.
ECHO **************************************
ECHO �Ǘ��Ҍ��������������܂�
ECHO **************************************

setlocal DisableDelayedExpansion
set "batchPath=%~0"
setlocal EnableDelayedExpansion
ECHO Set UAC = CreateObject^("Shell.Application"^) > "%temp%\OEgetPrivileges.vbs"
ECHO UAC.ShellExecute "!batchPath!", "ELEV", "", "runas", 1 >> "%temp%\OEgetPrivileges.vbs"
"%temp%\OEgetPrivileges.vbs"
exit /B

:gotPrivileges
setlocal & pushd .

@echo ==========================================================================
@echo JaneClone��VisualStudio�Ńr���h���邽�߂̊������܂��B
@echo �����ǐ���VC++�Ƃ������N�\����߂�MinGW���g�����ق��������Ǝv����B
@echo ==========================================================================

powershell Set-ExecutionPolicy RemoteSigned
powershell %~dp0janeclone.ps1
powershell Set-ExecutionPolicy Restricted

@echo ==========================================================================
@echo wxWidgets�Ɉړ�
@echo ==========================================================================
cd %~dp0wxWidgets-WX_3_0_2\build\msw

@rem Remove the existing destination folders if the exist so that a complete rebuild occurs.

@rmdir vc120_mswuddll /s /q       >NUL 2>&1
@rmdir vc120_mswuddll_x64 /s /q   >NUL 2>&1
@rmdir vc120_mswudll /s /q        >NUL 2>&1
@rmdir vc120_mswudll_x64 /s /q    >NUL 2>&1

@rmdir ..\..\lib\vc120_dll /s /q      >NUL 2>&1
@rmdir ..\..\lib\vc120_x64_dll /s /q  >NUL 2>&1

@rem Delete the build output files from the last run, if any.

@del 2013x86_Debug.txt    >NUL 2>&1
@del 2013x86_Release.txt  >NUL 2>&1
@del 2013x64_Debug.txt    >NUL 2>&1
@del 2013x64_Release.txt  >NUL 2>&1

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\x86_amd64\vcvarsx86_amd64.bat"

@echo ==========================================================================
@echo wxWidgets���r���h���܂��B���\���Ԃ�������܂��B
@echo ==========================================================================

@rem 64 bit release build
@rem ------------------
nmake -f makefile.vc BUILD=release SHARED=1 COMPILER_VERSION=120 OFFICIAL_BUILD=1 TARGET_CPU=AMD64 >> 2013x64_Release.txt

@rem �f�o�b�O�r���h�͂��Ȃ�
@rem 64 bit debug build
@rem ------------------
@rem nmake -f makefile.vc BUILD=debug SHARED=1 COMPILER_VERSION=120 OFFICIAL_BUILD=1 TARGET_CPU=AMD64 >> 2013x64_Debug.txt

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\vcvars32.bat"

@rem 32 bit release build
@rem ------------------
nmake -f makefile.vc BUILD=release SHARED=1 COMPILER_VERSION=120 OFFICIAL_BUILD=1 >> 2013x86_Release.txt

@rem �f�o�b�O�r���h�͂��Ȃ�
@rem 32 bit debug build
@rem ------------------
@rem nmake -f makefile.vc BUILD=debug SHARED=1 COMPILER_VERSION=120 OFFICIAL_BUILD=1 >> 2013x86_Debug.txt

@echo ==========================================================================
@echo bakefile���N������VisualStudio�̃v���W�F�N�g�t�@�C�����쐬���܂�
@echo ==========================================================================
call "%~dp0bakefile.bat"
exit