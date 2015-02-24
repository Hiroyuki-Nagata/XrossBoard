﻿/* XrossBoard - a text board site viewer for open BBS
 * Copyright (C) 2011-2015 Hiroyuki Nagata
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Contributor:
 *	Hiroyuki Nagata <newserver002@gmail.com>
 */

#include <babel.h>
#include <wx/html/winpars.h>
#include <wx/valgen.h>
#include <wx/tokenzr.h>
#include "wx/html/m_templ.h"

#include "enums.hpp"
#include "responsewindow.hpp"
#include "xrossboarduiutil.hpp"

#ifndef __WXMSW__
   #include"../rc/xrossboard.xpm"
#endif

BEGIN_EVENT_TABLE(ResponseWindow, wxDialog)
   EVT_BUTTON(ID_PostResponse,                   ResponseWindow::OnPostResponse)
   EVT_BUTTON(ID_QuitResponseWindow,             ResponseWindow::QuitResponseWindow)
   EVT_BUTTON(ID_PostConfirmForm,                ResponseWindow::PostConfirmForm)
   EVT_NOTEBOOK_PAGE_CHANGING(ID_ResponseWindow, ResponseWindow::OnChangeResponseTab)
   EVT_HTML_LINK_CLICKED(wxID_ANY,               ResponseWindow::OnLinkClocked)
   EVT_CHECKBOX(ID_ResponseWindowSageChk,        ResponseWindow::OnChangeSageChk)
   EVT_CHECKBOX(ID_ResponseWindowBeChk,          ResponseWindow::OnChangeBeChk)
END_EVENT_TABLE()

// I refered custom tags implementation. Thanks!
// here https://groups.google.com/forum/?fromgroups=#!topic/wx-users/brDgsxuuR0k

// <form> tags
TAG_HANDLER_BEGIN(FORM, "FORM")
TAG_HANDLER_CONSTR(FORM){}
TAG_HANDLER_PROC(tag) {
     m_WParser->CloseContainer();
     m_WParser->OpenContainer();
     ParseInner(tag);
     return true;
}
TAG_HANDLER_END(FORM)

// <select> tags
TAG_HANDLER_BEGIN(SELECT, "SELECT, OPTION")
     TAG_HANDLER_CONSTR(SELECT) {
     m_pComboBox = NULL;
     m_iNumber = 0;
}

TAG_HANDLER_VARS
wxComboBox *m_pComboBox;
int m_iNumber;

TAG_HANDLER_PROC(tag) {
     if (m_pComboBox && tag.GetName() == wxT("OPTION")) {
	  if (tag.HasParam(wxT("VALUE"))) {
	       wxString strValue = tag.GetParam(wxT("VALUE"));
	       wxString strName  = tag.GetName();
#if !wxUSE_UNICODE
	       wxCSConv conv(m_WParser->GetInputEncoding());
	       strName = wxString(strName.wc_str(conv), wxConvLocal);
#endif

	       m_WParser->GetEntitiesParser()->Parse(strName);

	       m_pComboBox->Append(strName, &strValue);
	       if (!m_iNumber) m_pComboBox->SetValue(strName);
	       m_iNumber++;
	  }
	  return true;
     } else if (tag.GetName() == wxT("SELECT")) {
	  int fl = 0;
	  wxComboBox *pOldBox = m_pComboBox;
	  int iOldNumber = m_iNumber;

	  m_pComboBox = new wxComboBox(m_WParser->GetWindowInterface()->GetHTMLWindow(), wxID_ANY, _(""), wxPoint(0,0), wxDefaultSize, 0, NULL, wxCB_READONLY  | wxCB_DROPDOWN);
	  m_pComboBox->Show(true);

	  ParseInner(tag);


	  m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(m_pComboBox, fl));

	  m_pComboBox = pOldBox;
	  m_iNumber = iOldNumber;
	  return true;

     }
     return false;
}

TAG_HANDLER_END(SELECT)

// <input> tags
TAG_HANDLER_BEGIN(INPUT, "INPUT")
     TAG_HANDLER_CONSTR(INPUT){}
/**
 * 本来はHTMLのsubmitボタンは一般的なものであるが
 * ここではクッキー情報が得られていない状態での投稿確認ボタン専用とする
 */
TAG_HANDLER_PROC(tag) {
     if (tag.HasParam(wxT("TYPE"))) {
	  if (!tag.GetParam(wxT("TYPE")).CmpNoCase(wxT("SUBMIT"))) {
	       int fl = 0;
	       wxButton *pButton;
	       // 投稿時のボタン専用として使う
	       pButton = new wxButton(m_WParser->GetWindowInterface()->GetHTMLWindow(), ID_PostConfirmForm, tag.GetParam(wxT("VALUE")), wxPoint(0,0), wxDefaultSize);
	       pButton->Show(true);

	       m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(pButton, fl));
	  } else if (!tag.GetParam(wxT("TYPE")).CmpNoCase(wxT("TEXT"))) {
	       int fl = 0;
	       wxTextCtrl *pText;

	       pText = new wxTextCtrl(m_WParser->GetWindowInterface()->GetHTMLWindow(), wxID_ANY, tag.GetParam(wxT("VALUE")), wxPoint(0,0), wxDefaultSize);
	       pText->Show(true);

	       m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(pText, fl));
	  }
     }
     return true;
}

TAG_HANDLER_END(SELECT)

// <form> tags
TAGS_MODULE_BEGIN(Form)

     TAGS_MODULE_ADD(FORM)
     TAGS_MODULE_ADD(SELECT)
     TAGS_MODULE_ADD(INPUT)

TAGS_MODULE_END(Form)

// スレッドタイトル
wxString ResponseWindow::threadTitle = wxEmptyString;

ResponseWindow::ResponseWindow(wxWindow* parent, wxString& title, URLvsBoardName& boardInfoHash, 
			       ThreadInfo& threadInfoHash, wxPoint& point, wxTextCtrl* logCtrl) :
     wxDialog(parent, wxID_ANY, wxEmptyString, point, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER) {

     // アイコンの設定を行う
#ifdef __WXMSW__
     SetIcon(wxICON(wxicon));
#else
     SetIcon(wxICON(xrossboard));
#endif

     // 構造体をローカルに格納する
     m_boardInfo  = boardInfoHash;
     m_threadInfo = threadInfoHash;

     // begin wxGlade: ResponseWindow::ResponseWindow
     resNoteBook = new wxNotebook(this, ID_ResponseWindow, wxDefaultPosition, wxDefaultSize, 0);
     settingPane = new wxPanel(resNoteBook, wxID_ANY);
     localRulePane = new wxPanel(resNoteBook, wxID_ANY);
     previewPane = new wxPanel(resNoteBook, wxID_ANY);
     resPane = new wxPanel(resNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL);

     // レス用ウィンドウの情報表示
     const wxString boardName = boardInfoHash.boardName;
     threadTitle = threadInfoHash.title;
     const wxString responseInfo    = wxString::Format(wxT("【%s】 - %s"), boardName.c_str(), threadTitle.c_str());
     boardNameTitle = new wxStaticText(resPane, wxID_ANY, responseInfo);

     name = new wxStaticText(resPane, wxID_ANY, wxT("名前："));
     const wxString *nameCombo_choices = NULL;
     nameCombo = new wxComboBox(resPane, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, nameCombo_choices, wxCB_DROPDOWN);
     mail = new wxStaticText(resPane, wxID_ANY, wxT("メール"));
     const wxString *mailCombo_choices = NULL;
     mailCombo = new wxComboBox(resPane, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, mailCombo_choices, wxCB_DROPDOWN);
     sageCheck = new wxCheckBox(resPane, ID_ResponseWindowSageChk, wxT("sage"));
     kakikoTextCtrl = new wxTextCtrl(resPane, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxHSCROLL);
     previewWindow = new wxHtmlWindow(previewPane, wxID_ANY);
     localRuleWindow = new wxHtmlWindow(localRulePane, wxID_ANY);
     settingText = new wxTextCtrl(settingPane, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
     handleCheck = new wxCheckBox(this, wxID_ANY, wxT("コテハン記憶"));
     frontCheck = new wxCheckBox(this, wxID_ANY, wxT("最前面"));
     formatCheck = new wxCheckBox(this, wxID_ANY, wxT("末尾整形"));
     beCheck = new wxCheckBox(this, ID_ResponseWindowBeChk, wxT("BE"));
     const wxString *beMailCombo_choices = NULL;
     beMailCombo = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, beMailCombo_choices, wxCB_DROPDOWN);
     proxyCheck = new wxCheckBox(this, wxID_ANY, wxT("Proxy"));
     const wxString *proxyCombo_choices = NULL;
     proxyCombo = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, proxyCombo_choices, wxCB_DROPDOWN);
     space = new wxPanel(this, wxID_ANY);
     postButton = new wxButton(this, ID_PostResponse, wxT("書き込み"));
     quitButton = new wxButton(this, ID_QuitResponseWindow, wxT("やめる"));

     set_properties(title);
     do_layout();
     // end wxGlade
}


void ResponseWindow::set_properties(const wxString& title) {

     // begin wxGlade: ResponseWindow::set_properties
     SetTitle(wxT("『") + title + wxT("』にレス"));
     SetSize(wxSize(640, 480));
     // end wxGlade

     wxString widgetsName = wxEmptyString;
     bool     widgetsInfo = false;

     // sageチェック
     const std::string &str = EnumString<XROSSBOARD_ENUMS>::From( static_cast<XROSSBOARD_ENUMS>(ID_ResponseWindowSageChk) );
     widgetsName = wxString((const char*)str.c_str(), wxConvUTF8);
     XrossBoardUtil::GetXrossBoardProperties(widgetsName, &widgetsInfo);

     if ( widgetsInfo ) {
	  // チェックされている
	  sageCheck->SetValue(widgetsInfo);
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  mailCombo->SetValue(wxT("sage"));
     } else {
	  // チェックされていない
	  sageCheck->SetValue(widgetsInfo);
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  mailCombo->SetValue(wxEmptyString);
     }

     // BEログインチェック
     const std::string &str2 = EnumString<XROSSBOARD_ENUMS>::From( static_cast<XROSSBOARD_ENUMS>(ID_ResponseWindowBeChk) );
     widgetsName = wxString((const char*)str2.c_str(), wxConvUTF8);
     XrossBoardUtil::GetXrossBoardProperties(widgetsName, &widgetsInfo);

     if ( beCheck->IsChecked() ) {
	  // チェックされている
	  widgetsInfo = true;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);

	  wxString addr = wxEmptyString;
	  XrossBoardUtil::GetXrossBoardProperties(wxT("ID_BEMailAddress"), &addr);
	  beMailCombo->SetValue(addr);

     } else {
	  // チェックされていない
	  widgetsInfo = false;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  beMailCombo->SetValue(wxEmptyString);

     }     
}


void ResponseWindow::do_layout() {
    // begin wxGlade: ResponseWindow::do_layout
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* hboxOther2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* hboxOther1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* settingVbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* localRuleVbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* previewVbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* resVbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    resVbox->Add(boardNameTitle, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 0);
    hbox1->Add(name, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    hbox1->Add(nameCombo, 1, 0, 0);
    hbox1->Add(mail, 0, wxALIGN_CENTER_VERTICAL, 0);
    hbox1->Add(mailCombo, 0, 0, 0);
    hbox1->Add(sageCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
    resVbox->Add(hbox1, 0, wxEXPAND, 0);
    resVbox->Add(kakikoTextCtrl, 1, wxEXPAND, 0);
    resPane->SetSizer(resVbox);
    previewVbox->Add(previewWindow, 1, wxEXPAND, 0);
    previewPane->SetSizer(previewVbox);
    localRuleVbox->Add(localRuleWindow, 1, wxEXPAND, 0);
    localRulePane->SetSizer(localRuleVbox);
    settingVbox->Add(settingText, 1, wxEXPAND, 0);
    settingPane->SetSizer(settingVbox);
    resNoteBook->AddPage(resPane, wxT("書き込み"));
    resNoteBook->AddPage(previewPane, wxT("プレビュー"));
    resNoteBook->AddPage(localRulePane, wxT("ローカルルール"));
    resNoteBook->AddPage(settingPane, wxT("SETTING.TXT"));
    vbox->Add(resNoteBook, 1, wxEXPAND, 0);
    hboxOther1->Add(handleCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
    hboxOther1->Add(frontCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
    hboxOther1->Add(formatCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
    hboxOther1->Add(beCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
    hboxOther1->Add(beMailCombo, 0, wxALIGN_CENTER_VERTICAL, 0);
    vbox->Add(hboxOther1, 0, wxEXPAND, 0);
    hboxOther2->Add(proxyCheck, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    hboxOther2->Add(proxyCombo, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    hboxOther2->Add(space, 1, wxEXPAND, 0);
    hboxOther2->Add(postButton, 0, wxALIGN_RIGHT, 0);
    hboxOther2->Add(quitButton, 0, wxALIGN_RIGHT, 0);
    vbox->Add(hboxOther2, 0, wxEXPAND, 0);
    SetSizer(vbox);
    Layout();
    // end wxGlade
}
/**
 * レスを投稿するイベント
 */
void ResponseWindow::OnPostResponse(wxCommandEvent &event) {

     // ソケット通信用のクラスのインスタンスを用意する
     std::unique_ptr<SocketCommunication> socketCommunication(new SocketCommunication());
     // クッキーの状態チェック
     int cookieStatus = CheckCookie();

     if (cookieStatus == NO_COOKIE) {
	  // クッキーがない状態
	  const wxString message = wxT("初回書き込みを実行\n");
	  XrossBoardUiUtil::SendLoggingHelper(message);
	  
	  PostFirstResponse(socketCommunication);
     } else if (cookieStatus == HAS_COOKIE_HIDDEN) {
	  // 最初のレスの後クッキーのみもらった状態
	  const wxString message = wxT("2chの規約に許諾後の書き込みを実行\n");
	  XrossBoardUiUtil::SendLoggingHelper(message);

	  PostConfirm(socketCommunication);
     } else if (cookieStatus == HAS_PREN) {
	  // PRENをもらった状態；通常の書き込み
	  const wxString message = wxT("通常書き込みを実行\n");
	  XrossBoardUiUtil::SendLoggingHelper(message);

	  PostResponse(socketCommunication);
     }

     // 書き込み後にスレッドを更新する
     XrossBoardUiUtil::QueueEventHelper(wxEVT_COMMAND_TEXT_UPDATED, ID_ReloadThreadByName, threadTitle);
}
/**
 * クッキーがない状態
 */
void ResponseWindow::PostFirstResponse(std::unique_ptr<SocketCommunication>& sock) {

     // 書き込み内容を構造体に設定する
     std::unique_ptr<PostContent> post(new PostContent);
     // babel
     const std::string stdName = babel::utf8_to_sjis(std::string(nameCombo->GetValue().mb_str()));
     const std::string stdMail = babel::utf8_to_sjis(std::string(mailCombo->GetValue().mb_str()));

     // 改行コードを含んでいる場合は分けてエンコード
     if (kakikoTextCtrl->GetValue().Contains(wxT("\n"))) {

	  std::string stdKakikomi, urlEnced;

	  for (int i = 0; i < kakikoTextCtrl->GetNumberOfLines(); i++) {

	       wxString tmp = kakikoTextCtrl->GetLineText(i);
	       if (tmp == wxEmptyString) {
		    urlEnced    += "%0D%0A";
		    continue;
	       }
	       stdKakikomi  = babel::utf8_to_sjis(std::string(tmp.mb_str()));
	       urlEnced    += XrossBoardUtil::UrlEncode(stdKakikomi);
	       urlEnced    += "%0D%0A";
	  }

	  post->kakikomi = wxString(urlEnced.c_str(), wxConvUTF8);

     } else {
	  const std::string stdKakikomi = babel::utf8_to_sjis(std::string(kakikoTextCtrl->GetValue().mb_str()));
	  post->kakikomi = wxString(XrossBoardUtil::UrlEncode(stdKakikomi).c_str(), wxConvUTF8);
     }

     // 投稿用の構造体にURLエンコードされた文字列を格納
     post->name = wxString(XrossBoardUtil::UrlEncode(stdName).c_str(), wxConvUTF8);
     post->mail = wxString(XrossBoardUtil::UrlEncode(stdMail).c_str(), wxConvUTF8);

     sock->SetPostContent(post);
     wxString result = sock->PostFirstToThread(m_boardInfo, m_threadInfo, NO_COOKIE);

     // m_postContentにデータを設定する
     m_postContent = std::move(post);

     if (result.StartsWith(wxT("<html>"))) {
	  // 返り値が<html>タグから始まっていれば書込は失敗
	  // wxHtmlWindowに結果を表示する	  
	  resNoteBook->ChangeSelection(PREVIEW_PAGE);
	  previewWindow->SetPage(result);
	  return;
     }
     
     // 失敗でなければ確認画面を表すヘッダファイルへのパスなので
     // ユーザーに確認させるため表示する
     // wxStringにバッファするサイズを計測する
     size_t fileSize = XrossBoardUtil::GetFileSize(result);
     if (fileSize == 0) {
	  // wxHtmlWindowに結果を表示する
	  resNoteBook->ChangeSelection(PREVIEW_PAGE);
	  previewWindow->SetPage(FAIL_TO_POST);
	  return;
     }
     // 取得サイズ分だけwxStringを確保する
     wxString htmlSource;
     htmlSource.Alloc(fileSize);
     // テキストファイルの読み込み
     ReadResponseHtml(result, htmlSource);
     // wxHtmlWindowに結果を表示する
     resNoteBook->ChangeSelection(PREVIEW_PAGE);
     previewWindow->SetPage(htmlSource);
}
/**
 * 最初のレスの後クッキーのみもらった状態
 */
void ResponseWindow::PostConfirm(std::unique_ptr<SocketCommunication>& sock) {


     // 投稿内容作成
     std::unique_ptr<PostContent> m_postContent(new PostContent);
     // babel
     const std::string stdName = babel::utf8_to_sjis(std::string(nameCombo->GetValue().mb_str()));
     const std::string stdMail = babel::utf8_to_sjis(std::string(mailCombo->GetValue().mb_str()));
     // 改行コードを含んでいる場合は分けてエンコード
     if (kakikoTextCtrl->GetValue().Contains(wxT("\n"))) {

	  std::string stdKakikomi, urlEnced;

	  for (int i = 0; i < kakikoTextCtrl->GetNumberOfLines(); i++) {

	       wxString tmp = kakikoTextCtrl->GetLineText(i);
	       if (tmp == wxEmptyString) {
		    urlEnced    += "%0D%0A";
		    continue;
	       }
	       stdKakikomi  = babel::utf8_to_sjis(std::string(tmp.mb_str()));
	       urlEnced    += XrossBoardUtil::UrlEncode(stdKakikomi);
	       urlEnced    += "%0D%0A";
	  }

	  m_postContent->kakikomi = wxString(urlEnced.c_str(), wxConvUTF8);

     } else {
	  const std::string stdKakikomi = babel::utf8_to_sjis(std::string(kakikoTextCtrl->GetValue().mb_str()));
	  m_postContent->kakikomi = wxString(XrossBoardUtil::UrlEncode(stdKakikomi).c_str(), wxConvUTF8);
     }

     // 投稿用の構造体にURLエンコードされた文字列を格納
     m_postContent->name = wxString(XrossBoardUtil::UrlEncode(stdName).c_str(), wxConvUTF8);
     m_postContent->mail = wxString(XrossBoardUtil::UrlEncode(stdMail).c_str(), wxConvUTF8);

     if (m_postContent->kakikomi.IsEmpty()) {
     	  // 内容が無ければエラー
     	  const wxString message = wxT("内部エラー…(ヽ´ん`)…やり直してみて…\n");
	  XrossBoardUiUtil::SendLoggingHelper(message);

     	  return;
     }

     sock->SetPostContent(m_postContent);

     if (m_boardInfo.boardName.Len() == 0 || m_threadInfo.title.Len() == 0) {
     	  const wxString message = wxT("内部エラー…(ヽ´ん`)……板情報とスレッド情報がおかしいです\n");
	  XrossBoardUiUtil::SendLoggingHelper(message);

     	  return;
     }
     
     // 返り値は書き込み結果を示すHTMLファイル
     wxString result = sock->PostConfirmToThread(m_boardInfo, m_threadInfo, HAS_COOKIE_HIDDEN);
     
     // 失敗でなければ確認画面を表すヘッダファイルへのパスなので
     // ユーザーに確認させるため表示する
     // wxStringにバッファするサイズを計測する
     size_t fileSize = XrossBoardUtil::GetFileSize(result);
     if (fileSize == 0) {
	  // wxHtmlWindowに結果を表示する
	  resNoteBook->ChangeSelection(PREVIEW_PAGE);
	  previewWindow->SetPage(FAIL_TO_POST);
	  return;
     }
     // 取得サイズ分だけwxStringを確保する
     wxString htmlSource;
     htmlSource.Alloc(fileSize);
     // テキストファイルの読み込み
     ReadResponseHtml(result, htmlSource);
     resNoteBook->ChangeSelection(PREVIEW_PAGE);
     previewWindow->SetPage(htmlSource);
}
/**
 * PRENをもらった状態；通常の書き込み
 */
void ResponseWindow::PostResponse(std::unique_ptr<SocketCommunication>& sock) {

     // 書き込み内容を構造体に設定する
     std::unique_ptr<PostContent> post(new PostContent);
     // babel
     const std::string stdName = babel::utf8_to_sjis(std::string(nameCombo->GetValue().mb_str()));
     const std::string stdMail = babel::utf8_to_sjis(std::string(mailCombo->GetValue().mb_str()));
     // 改行コードを含んでいる場合は分けてエンコード
     if (kakikoTextCtrl->GetValue().Contains(wxT("\n"))) {

	  std::string stdKakikomi, urlEnced;

	  for (int i = 0; i < kakikoTextCtrl->GetNumberOfLines(); i++) {

	       wxString tmp = kakikoTextCtrl->GetLineText(i);
	       if (tmp == wxEmptyString) {
		    urlEnced    += "%0D%0A";
		    continue;
	       }
	       stdKakikomi  = babel::utf8_to_sjis(std::string(tmp.mb_str()));
	       urlEnced    += XrossBoardUtil::UrlEncode(stdKakikomi);
	       urlEnced    += "%0D%0A";
	  }
	  
	  post->kakikomi = wxString(urlEnced.c_str(), wxConvUTF8);

     } else {
	  const std::string stdKakikomi = babel::utf8_to_sjis(std::string(kakikoTextCtrl->GetValue().mb_str()));
	  post->kakikomi = wxString(XrossBoardUtil::UrlEncode(stdKakikomi).c_str(), wxConvUTF8);
     }

     // 投稿用の構造体にURLエンコードされた文字列を格納
     post->name = wxString(XrossBoardUtil::UrlEncode(stdName).c_str(), wxConvUTF8);
     post->mail = wxString(XrossBoardUtil::UrlEncode(stdMail).c_str(), wxConvUTF8);

     sock->SetPostContent(post);
     wxString result = sock->PostResponseToThread(m_boardInfo, m_threadInfo, HAS_PREN);

     if (result.StartsWith(wxT("<html>"))) {
	  // 返り値が<html>タグから始まっていれば書込は失敗
	  // wxHtmlWindowに結果を表示する
	  resNoteBook->ChangeSelection(PREVIEW_PAGE);
	  previewWindow->SetPage(result);
	  return;
     }
     
     // 失敗でなければ確認画面を表すヘッダファイルへのパスなので
     // ユーザーに確認させるため表示する
     // wxStringにバッファするサイズを計測する
     size_t fileSize = XrossBoardUtil::GetFileSize(result);
     if (fileSize == 0) {
	  // wxHtmlWindowに結果を表示する
	  resNoteBook->ChangeSelection(PREVIEW_PAGE);
	  previewWindow->SetPage(FAIL_TO_POST);
	  return;
     }
     // 取得サイズ分だけwxStringを確保する
     wxString htmlSource;
     htmlSource.Alloc(fileSize);
     // テキストファイルの読み込み
     ReadResponseHtml(result, htmlSource);
     // wxHtmlWindowに結果を表示する
     resNoteBook->ChangeSelection(PREVIEW_PAGE);
     previewWindow->SetPage(htmlSource);
}
/**
 * レス用ウィンドウを閉じるイベント
 */
void ResponseWindow::QuitResponseWindow(wxCommandEvent &event) {

     Close(true);
}
/**
 *  投稿確認ボタンイベント
 */
void ResponseWindow::PostConfirmForm(wxCommandEvent &event) {

     // 書き込みイベントに制御を渡す
     OnPostResponse(event);
 }
/**
 * クッキーの状態チェック
 */
int ResponseWindow::CheckCookie() {

     wxString configFile = ::wxGetHomeDir() + wxFILE_SEP_PATH + XROSSBOARD_DIR 
	  + wxFILE_SEP_PATH + wxT("prop") + wxFILE_SEP_PATH + COOKIE_CONFIG_FILE;

     if (!wxFile::Exists(configFile))
	  return NO_COOKIE;

     // 内部にある要素を調べる
     wxString hiddenName = wxEmptyString, hiddenVal = wxEmptyString, cookie = wxEmptyString, pren = wxEmptyString;
     XrossBoardUtil::GetXrossBoardProperties(wxT("HiddenName"), &hiddenName);
     XrossBoardUtil::GetXrossBoardProperties(wxT("HiddenValue"), &hiddenVal);
     XrossBoardUtil::GetXrossBoardProperties(wxT("Cookie-PON"), &cookie);
     XrossBoardUtil::GetXrossBoardProperties(wxT("PREN"), &pren);

     // もしクッキーと隠し要素１がなければクッキーがないのと同じなのでNO_COOKIEを返す
     if (hiddenName.IsEmpty() || hiddenVal.IsEmpty() || cookie.IsEmpty()) {
	  return NO_COOKIE;
     }
	  
     // PRENがあればHAS_PREN、なければHAS_COOKIE_HIDDEN
     if (!pren.IsEmpty()) {
	  return HAS_PREN;
     }

     return HAS_COOKIE_HIDDEN;
}
/**
 *  2chのサーバから受け取ったHTMLファイルを読み取りwxStringに格納する
 */
void ResponseWindow::ReadResponseHtml(const wxString& resultHtmlPath, wxString& htmlSource) {

     std::ifstream ifs(resultHtmlPath.mb_str());

     if (ifs) {
	  std::string line;
	  
	  while (ifs) {
	       getline(ifs, line);
	       wxString wxLine(line.c_str(), wxConvUTF8);

	       if (std::string::npos != line.find("charset=")) {
		    wxLine.Replace(wxT("charset=x-sjis"), wxT("charset=utf-8"));
		    wxLine.Replace(wxT("charset=shift_jis"), wxT("charset=utf-8"));
	       }

	       htmlSource.Append(wxLine);
	  }

     } else {
	  // エラー
	  return;
     }
}
/*
 * レス投稿時にテキスト情報を付加する
 */
void ResponseWindow::AddKakikomiText(const wxString& text) {

     kakikoTextCtrl->Clear();
     kakikoTextCtrl->SetValue(text);
}
/*
 * レス書き込み用ウィンドウのタブが切り替わった時の処理
 */
void ResponseWindow::OnChangeResponseTab(wxNotebookEvent& event) {

     switch(event.GetSelection()) {

     case KAKIKO_PAGE:
	  break;
	  
     case PREVIEW_PAGE:
	  ResponseWindow::SetPreviewWindow(event);
	  break;

     case LOCAL_RULE_PAGE:
	  break;

     case SETTING_PAGE:
	  break;

     default:
	  break;
     }

     event.Skip();
}
/*
 * プレビュー画面に書き込み内容のプレビューを表示する
 */
void ResponseWindow::SetPreviewWindow(wxNotebookEvent& event) {

     if (!previewWindow->SetPage(wxEmptyString)) {
	  wxMessageBox(wxT("エラー, 書き込み内容のプレビューに失敗しました."), 
		       wxT("レス書き込み用ウィンドウ"), wxICON_ERROR);
	  return;
     }

     wxString original        = kakikoTextCtrl->GetValue();
     wxString default_nanashi = nameCombo->GetValue();
     wxString mail            = mailCombo->GetValue();
     wxString day_and_ID      = wxT("yyyy/MM/dd(E) HH:mm:ss.SSSS ID:XXXXXXXXX");

     wxString htmlSource;
     htmlSource += HTML_HEADER;

     // ひとかたまりのHTMLソースにまとめる
     wxString lumpOfHTML = wxT("<dt>");
     wxString num        = wxT("x");
     wxString link       = wxT("<a href=\"#") + num + wxT("\">") + num + wxT("</a>");
     htmlSource += link;

     // レスの最初に<table>タグを入れる
     wxString res = wxEmptyString;
     res.Append(wxT("<table border=0 id=\"") + num + wxT("\">"));

     // 改行コードで区切る
     wxStringTokenizer tkz(original, wxT("\n"));
     while (tkz.HasMoreTokens()) {
	  res.Append(tkz.GetNextToken());
	  res.Append(wxT("<br>"));
     }
     // 画像があれば<img>タグをつける
     XrossBoardUtil::AddImgTag(res);
     res.Append(wxT("</table>"));
     // レス内部のURLに<a>タグをつける
     res = XrossBoardUtil::ReplaceURLText(res);
     // アンカーを処理する
     res = XrossBoardUtil::AddAnchorTag(res);
     // レスの最後に改行
     res.Append(wxT("<br>"));

     if (mail != wxEmptyString) {
	  // もしメ欄になにか入っているならば
	  htmlSource += wxT(" 名前：<a href=\"mailto:");
	  htmlSource += mail;
	  htmlSource += wxT("\"><b>");
	  htmlSource += default_nanashi;
	  htmlSource += wxT("</b></a>");
	  htmlSource += day_and_ID;
	  htmlSource += wxT("<dd>");
	  htmlSource += res;
     } else {
	  // 空の場合
	  htmlSource += wxT(" 名前：<font color=green><b>");
	  htmlSource += default_nanashi;
	  htmlSource += wxT("</b></font>");
	  htmlSource += day_and_ID;
	  htmlSource += wxT("<dd>");
	  htmlSource += res;
     }

     if (!previewWindow->SetPage(htmlSource)) {
	  wxMessageBox(wxT("エラー, 書き込み内容のプレビューに失敗しました."), 
		       wxT("レス書き込み用ウィンドウ"), wxICON_ERROR);
	  return;
     }     
}
/**
 * 書き込み画面のsageチェックが押された時の処理
 */
void ResponseWindow::OnChangeSageChk(wxCommandEvent& event) {

     wxString widgetsName = wxEmptyString;
     bool     widgetsInfo = false;

     const std::string &str = EnumString<XROSSBOARD_ENUMS>::From( static_cast<XROSSBOARD_ENUMS>(event.GetId()) );
     widgetsName = wxString((const char*)str.c_str(), wxConvUTF8);

     if ( sageCheck->IsChecked() ) {
	  // チェックされている
	  widgetsInfo = true;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  mailCombo->SetValue(wxT("sage"));

     } else {
	  // チェックされていない
	  widgetsInfo = false;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  mailCombo->SetValue(wxEmptyString);

     }
}
/**
 * 書き込み画面のBEチェックが押された時の処理
 */
void ResponseWindow::OnChangeBeChk(wxCommandEvent& event) {

     wxString widgetsName = wxEmptyString;
     bool     widgetsInfo = false;

     const std::string &str = EnumString<XROSSBOARD_ENUMS>::From( static_cast<XROSSBOARD_ENUMS>(event.GetId()) );
     widgetsName = wxString((const char*)str.c_str(), wxConvUTF8);

     if ( beCheck->IsChecked() ) {
	  // チェックされている
	  widgetsInfo = true;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);

	  wxString addr = wxEmptyString;
	  XrossBoardUtil::GetXrossBoardProperties(wxT("ID_BEMailAddress"), &addr);
	  beMailCombo->SetValue(addr);

     } else {
	  // チェックされていない
	  widgetsInfo = false;
	  XrossBoardUtil::SetXrossBoardProperties(widgetsName, widgetsInfo);
	  beMailCombo->SetValue(wxEmptyString);

     }
}
