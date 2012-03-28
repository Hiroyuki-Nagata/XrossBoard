/*
 * DataType.h
 *
 *  Created on: 2012/01/05
 *      Author: learning
 */

#ifndef DATATYPE_H_
#define DATATYPE_H_

// wxHashMap�p�̃N���X -- 2ch�̔���URL��Ή�������
class URLvsBoardName
{
public:
  wxString BoardName;
  wxString BoardURL;
  wxString BoardNameAscii;
};

// �X���b�h�ꗗ�p�̃N���X
class ThreadList
{
public:
  // �L�[�l(�z�X�g���ɂ��̔ԍ������邱�ƂŃX���b�h��URL�ɂȂ�)
  wxString oid;
  // �ԍ�(�P�Ɏ擾����dat�t�@�C���̏�������)
  int number;
  // �^�C�g��
  wxString title;
  // ���X
  int response;
  // �擾
  int cachedResponseNumber;
  // �V��
  int newResponseNumber;
  // �����X
  int increaseResponseNumber;
  // ����
  int momentum;
  // �ŏI�擾
  wxString lastUpdate;
  // since
  wxString since;
  // ��
  wxString boardName;
};

#endif /* DATATYPE_H_ */
