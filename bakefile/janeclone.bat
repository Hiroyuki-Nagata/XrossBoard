powershell Set-ExecutionPolicy RemoteSigned

@echo ==========================================================================
@echo JaneClone��VisualStudio�Ńr���h���邽�߂̊������܂��B
@echo �����ǐ���VC++�Ƃ������N�\����߂�MinGW���g�����ق��������Ǝv����B
@echo ==========================================================================

powershell %~dp0janeclone.ps1

powershell Set-ExecutionPolicy Restricted

@rem
@rem wxWidgets�Ɉړ�
@rem
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

@rem bakefile.bat���Ă�
cd %~dp
call ".\bakefile.bat"