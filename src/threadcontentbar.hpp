/* JaneClone - a text board site viewer for 2ch
 * Copyright (C) 2012 Hiroyuki Nagata
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

// -*- C++ -*- generated by wxGlade 0.6.3 on Sat Dec 29 22:07:54 2012

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/aui/aui.h>
#include "enums.hpp"
#include "threadcontentwindow.hpp"

#ifndef THREADCONTENTBAR_HPP_
#define THREADCONTENTBAR_HPP_

// begin wxGlade: ::dependencies
// end wxGlade

// 各ウィジェットのサイズなど
static const wxSize   threadContentBarImgSize = wxSize(16, 16);
static const wxSize   searchWordComboSize     = wxSize(320, 32);

class ThreadContentBar: public wxPanel {

public:
     // begin wxGlade: ThreadContentBar::ids
     // end wxGlade
     ThreadContentBar(wxWindow* parent, int id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, 
		      long style=wxDEFAULT_FRAME_STYLE);

     // スレッドタイトルをクラスに設定する
     void SetTitle(const wxString& title);

     // スレッドの内容を設定する
     void SetThreadContentWindow(const wxString& threadContentPath);
     // スレッドの内容をリロードする
     void ReloadThreadContentWindow(const wxString& threadContentPath);

     // 開いているHTMLのスクロール位置を取得する
     void GetThreadContentWindowScrollPos(wxPoint* p) {
	  tcw->GetHtmlWindowScrollPos(p);
     };
     // スレッドをスクロールさせる
     void SetThreadContentWindowScroll(const wxPoint* p) {
	  tcw->ForceScroll(p);
     };

private:
     // begin wxGlade: ThreadContentBar::methods
     void set_properties();
     void do_layout();
     // end wxGlade

     wxPanel* threadContentPanel;
     // スレッドの内容を描画するクラス
     ThreadContentWindow* tcw;
     // 検索ワードの履歴管理用文字列
     wxString* searchWordCombo_choices;

protected:
     // begin wxGlade: ThreadContentBar::attributes
     wxStaticText* threadName;
     wxPanel* spacePanel1;

     wxAuiToolBar* threadToolbar1;
     wxAuiToolBar* threadToolbar2;

     wxPanel* threadContentsBarUpperSizer;
     wxBitmapButton* nomalSearchButton;
     wxComboBox* searchWordCombo;
     wxBitmapButton* backwardButton;
     wxBitmapButton* forwardButton;
     wxPanel* panel_2;
     wxBitmapButton* hideSearchBarButton;

     DECLARE_EVENT_TABLE()
     // end wxGlade
}; // wxGlade: end class


#endif // THREADCONTENTBAR_HPP_
