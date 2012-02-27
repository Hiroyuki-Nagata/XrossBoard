/*
 * SQLiteBundle.h
 *
 *  Created on: 2012/01/09
 *      Author: learning
 */

#ifndef SQLITEBUNDLE_H_
#define SQLITEBUNDLE_H_

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/dir.h>
#include <wx/aui/auibook.h>
#include "wx/wxsqlite3.h"

/*
 * SQLiteBundle�N���X
 * wxSQLite3Database���p�������[�U�[���ȑO�Ɍ�����
 * �X���Ȃǂ𒀎��L�^����B
 */

class SQLiteBundle : public wxSQLite3Database {

 public:
  // �R���X�g���N�^�ł��낢�돉�������s��
  SQLiteBundle();

  // JaneClone�I�����Ƀ��[�U���J���Ă����ꗗ��SQLite�ɓo�^���鏈��
  void UserLookingBoardRegister(wxAuiNotebook* boardNoteBook);
  // JaneClone�J�n���Ƀ��[�U���ȑO�J���Ă����ꗗ��Notebook�ɐݒ肷�鏈��
  void UserLookingBoardSetter(wxAuiNotebook* boardNoteBook);
  // �ꗗ�X�V���ɔ���URL�A��(ascii)�̃f�[�^��ێ������e�[�u�������
  void URLvsBoardNameTableSetter();

};

#endif /* SQLITEBUNDLE_H_ */
