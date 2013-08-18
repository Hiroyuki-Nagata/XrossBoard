// -*- C++ -*- generated by wxGlade 0.6.5 on Wed May 22 03:50:59 2013

#include "otherpanels.hpp"
#include "wx/dynarray.h"

/**
 * イベントテーブル
 */
BEGIN_EVENT_TABLE(PathSettingPanel, wxPanel)
   EVT_CHECKBOX(ID_BrowserCheck, PathSettingPanel::OnBrowserCheck)
   EVT_DIRPICKER_CHANGED(ID_DirPickerBrowser, PathSettingPanel::OnChangeDirPickerBrowser)
   EVT_DIRPICKER_CHANGED(ID_DirPickerBoardList, PathSettingPanel::OnChangeDirPickerBoardList)
   EVT_DIRPICKER_CHANGED(ID_DirPickerSkin, PathSettingPanel::OnChangeDirPickerSkin)
   EVT_BUTTON(ID_ClearBrowserPath, PathSettingPanel::ClearPathSetting)
   EVT_BUTTON(ID_ClearBoardListPath, PathSettingPanel::ClearPathSetting)
   EVT_BUTTON(ID_ClearSkinPath, PathSettingPanel::ClearPathSetting)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(ColorFontSettingPanel, wxPanel)
   EVT_BUTTON(ID_TreeFontButton,          ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ThreadListFontButton,    ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ExtractFontButton,       ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_LogWindowFontButton,     ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ThreadTitleFontButton,   ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_KakikoFontButton,        ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_MemoFontButton,          ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_HintFontButton,          ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_LinkFontButton,          ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_OthersFontButton,        ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_AllFontButton,           ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_BoardListBGColorButton,  ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ThreadListBGColorButton, ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_LogWindowBGColorButton,  ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ThreadTitleBGColorButton,ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_ThreadViewBGColorButton, ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_MemoBGColorButton,       ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_HintBGColorButton,       ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_PopupBGColorButton,      ColorFontSettingPanel::OnClickColorFontSettingButton) 
   EVT_BUTTON(ID_AllBGColorButton,        ColorFontSettingPanel::OnClickColorFontSettingButton) 
END_EVENT_TABLE()


/**
 * 各種ネットワーク設定用画面
 */
NetworkSettingPanel::NetworkSettingPanel(wxWindow* parent, const wxPoint& pos, const wxSize& size, long style):
     wxPanel(parent, ID_NetworkPanel, pos, size, wxTAB_TRAVERSAL) {

     // begin wxGlade: NetworkSettingPanel::NetworkSettingPanel
     panel_5 = new wxPanel(this, wxID_ANY);
     panel_4 = new wxPanel(this, wxID_ANY);
     panel_3 = new wxPanel(this, wxID_ANY);
     panel_2 = new wxPanel(this, wxID_ANY);
     panel_1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL);
     panel_7 = new wxPanel(panel_1, wxID_ANY);
     panel_9 = new wxPanel(panel_7, wxID_ANY);
     panel_8 = new wxPanel(panel_7, wxID_ANY);
     panel_6 = new wxPanel(panel_1, wxID_ANY);
#ifndef __WXMAC__
     proxyUseCheck = new wxCheckBox(panel_6, wxID_ANY, wxT("Proxyを使用する"));
     proxyCacheUseCheck = new wxCheckBox(panel_6, wxID_ANY, wxT("Proxy使用時にキャッシュを使用しない"));
#endif
     label_6 = new wxStaticText(panel_7, wxID_ANY, wxT("使用するProxyのアドレス"));
     label_7 = new wxStaticText(panel_7, wxID_ANY, wxT("ポート"));
     label_8 = new wxStaticText(panel_7, wxID_ANY, wxT("受信用"));
     recProxyAddrTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     recProxyPortTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     label_9 = new wxStaticText(panel_7, wxID_ANY, wxT("送信用"));
     sedProxyAddrTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     sedProxyPortTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     label_10 = new wxStaticText(panel_7, wxID_ANY, wxT("SSL（認証用）"));
     authSSLAddrTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     authSSLPortTC = new wxTextCtrl(panel_7, wxID_ANY, wxEmptyString);
     label_11 = new wxStaticText(panel_7, wxID_ANY, wxT("Basic認証"));
     label_12 = new wxStaticText(panel_8, wxID_ANY, wxT("UserName:"));
     basicAuthUserNameTC = new wxTextCtrl(panel_8, wxID_ANY, wxEmptyString);
     label_13 = new wxStaticText(panel_9, wxID_ANY, wxT("Password:"));
     basicAuthPasswordTC = new wxTextCtrl(panel_9, wxID_ANY, wxEmptyString);
     label_4 = new wxStaticText(panel_2, wxID_ANY, wxT("受信タイムアウト（ミリ秒）"));
     receiveTimeoutTC = new wxTextCtrl(panel_2, wxID_ANY, wxT("30000"));
     label_5 = new wxStaticText(panel_3, wxID_ANY, wxT("接続タイムアウト（ミリ秒）"));
     connectTimeoutTC = new wxTextCtrl(panel_3, wxID_ANY, wxT("10000"));
     label_3 = new wxStaticText(panel_4, wxID_ANY, wxT("ボード一覧取得URL"));
     boardListURLTC = new wxTextCtrl(panel_4, wxID_ANY, wxT("http://menu.2ch.net/bbsmenu.html"));
     label_1 = new wxStaticText(panel_5, wxID_ANY, wxT("受信バッファサイズ（KB）"));
     receiveBufferSizeTC = new wxTextCtrl(panel_5, wxID_ANY, wxT("32"));
     label_2 = new wxStaticText(panel_5, wxID_ANY, wxT("最大接続数"));
     maxConnSC = new wxSpinCtrl(panel_5, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100);

     set_properties();
     do_layout();
     // end wxGlade

#ifdef __WXMAC__
     // メインスレッドに更新してもらう
     SendUIUpdateEvent();
#endif

}


void NetworkSettingPanel::set_properties() {
     // begin wxGlade: NetworkSettingPanel::set_properties
     // end wxGlade
}


void NetworkSettingPanel::do_layout() {

     // begin wxGlade: NetworkSettingPanel::do_layout
     wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
     wxBoxSizer* sizer_5 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
     wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
     wxGridSizer* grid_sizer_1 = new wxGridSizer(5, 3, 0, 0);
     wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_6 = new wxBoxSizer(wxHORIZONTAL);
#ifndef __WXMAC__
     sizer_6->Add(proxyUseCheck, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(proxyCacheUseCheck, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
#endif
     panel_6->SetSizer(sizer_6);
     sizer_4->Add(panel_6, 0, wxEXPAND, 0);
     grid_sizer_1->Add(20, 20, 0, wxEXPAND, 0);
     grid_sizer_1->Add(label_6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(label_7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(label_8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(recProxyAddrTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(recProxyPortTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(label_9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(sedProxyAddrTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(sedProxyPortTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(label_10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(authSSLAddrTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(authSSLPortTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     grid_sizer_1->Add(label_11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_7->Add(label_12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_7->Add(basicAuthUserNameTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     panel_8->SetSizer(sizer_7);
     grid_sizer_1->Add(panel_8, 0, wxEXPAND, 0);
     sizer_8->Add(label_13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_8->Add(basicAuthPasswordTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     panel_9->SetSizer(sizer_8);
     grid_sizer_1->Add(panel_9, 0, wxEXPAND, 0);
     panel_7->SetSizer(grid_sizer_1);
     sizer_4->Add(panel_7, 0, wxALL|wxEXPAND, 5);
     panel_1->SetSizer(sizer_4);
     vbox->Add(panel_1, 0, wxALL|wxEXPAND, 5);
     sizer_3->Add(label_4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_3->Add(receiveTimeoutTC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     panel_2->SetSizer(sizer_3);
     vbox->Add(panel_2, 0, wxEXPAND, 0);
     sizer_2->Add(label_5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_2->Add(connectTimeoutTC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     panel_3->SetSizer(sizer_2);
     vbox->Add(panel_3, 0, wxEXPAND, 0);
     sizer_1->Add(label_3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_1->Add(boardListURLTC, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
     panel_4->SetSizer(sizer_1);
     vbox->Add(panel_4, 0, wxEXPAND, 0);
     sizer_5->Add(label_1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_5->Add(receiveBufferSizeTC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_5->Add(label_2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_5->Add(maxConnSC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
     panel_5->SetSizer(sizer_5);
     vbox->Add(panel_5, 0, wxEXPAND, 0);
     SetSizer(vbox);
     vbox->Fit(this);
     // end wxGlade
}

/**
 * 各種パス設定用画面
 */
PathSettingPanel::PathSettingPanel(wxWindow* parent, const wxPoint& pos, const wxSize& size, long style):
wxPanel(parent, ID_PathSettingPanel, pos, size, wxTAB_TRAVERSAL) {

     // begin wxGlade: PathSettingPanel::PathSettingPanel
     browserCheck = new wxCheckBox(this, ID_BrowserCheck, wxT("ブラウザを指定する"));
     label_1 = new wxStaticText(this, wxID_ANY, wxT("ブラウザのパス"));

#ifdef __WXGTK__
     browserPathTC = new wxTextCtrl(this, 
				    ID_BrowserPathTC, 
				    wxEmptyString, 
				    wxDefaultPosition, 
				    wxDefaultSize,
				    wxTE_READONLY);
#endif
     dirPicker1 = new wxDirPickerCtrl(this, ID_DirPickerBrowser);
     clearButton_1 = new wxButton(this, ID_ClearBrowserPath, wxT("設定のクリア"));

     label_2 = new wxStaticText(this, wxID_ANY, wxT("ログとボード一覧のフォルダ（次回起動時から有効）"));
#ifdef __WXGTK__
     boardListTC = new wxTextCtrl(this, 
				  ID_BoardListTC, 
				  wxEmptyString,
				  wxDefaultPosition, 
				  wxDefaultSize,
				  wxTE_READONLY);
#endif
     dirPicker2 = new wxDirPickerCtrl(this, ID_DirPickerBoardList);
     clearButton_2 = new wxButton(this, ID_ClearBoardListPath, wxT("設定のクリア"));

     label_3 = new wxStaticText(this, wxID_ANY, wxT("スキンのフォルダ（次回起動時から有効）"));
#ifdef __WXGTK__
     skinPathTC = new wxTextCtrl(this, 
			       ID_SkinPathTC, 
			       wxEmptyString,
			       wxDefaultPosition, 
			       wxDefaultSize,
			       wxTE_READONLY);
#endif
     dirPicker3 = new wxDirPickerCtrl(this, ID_DirPickerSkin);
     clearButton_3 = new wxButton(this, ID_ClearSkinPath, wxT("設定のクリア"));

     set_properties();
     do_layout();
     // end wxGlade
}


void PathSettingPanel::set_properties() {
     bool specifyBrowser = false;
     wxString browserPath, boardListPath, skinPath;
     JaneCloneUtil::GetJaneCloneProperties(wxT("SPECIFY_DEFAULT_BROWSER"), &specifyBrowser);
     JaneCloneUtil::GetJaneCloneProperties(wxT("DEFAULT_BROWSER_PATH"), &browserPath);
     JaneCloneUtil::GetJaneCloneProperties(wxT("DEFAULT_BOARDLIST_PATH"), &boardListPath);
     JaneCloneUtil::GetJaneCloneProperties(wxT("DEFAULT_SKINFILE_PATH"), &skinPath);
     browserCheck->SetValue(specifyBrowser);

#ifdef __WXGTK__
     browserPathTC->SetValue(browserPath);
     boardListTC->SetValue(boardListPath);
     skinPathTC->SetValue(skinPath);
#else
     dirPicker1->SetPath(browserPath);
     dirPicker2->SetPath(boardListPath);
     dirPicker3->SetPath(skinPath);
#endif
}

/**
 * Linux(GTK) vs Windows & MacOSX で
 * ファイル選択用UIの形が異なるためここで調整をしている
 */
void PathSettingPanel::do_layout() {
    // begin wxGlade: PathSettingPanel::do_layout
#ifdef __WXGTK__
    wxGridSizer* grid_sizer_1 = new wxGridSizer(7, 2, 0, 0);
#else
    wxGridSizer* grid_sizer_1 = new wxGridSizer(7, 3, 0, 0);
#endif
    grid_sizer_1->Add(browserCheck, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(20, 20, 0, wxEXPAND, 0);

#ifdef __WXGTK__
    grid_sizer_1->Add(label_1, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(browserPathTC, 0, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(dirPicker1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(clearButton_1, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#else
    grid_sizer_1->Add(20, 20, 0, wxEXPAND, 0);
    grid_sizer_1->Add(label_1, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(dirPicker1, 1, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(clearButton_1, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#endif

#ifdef __WXGTK__
    grid_sizer_1->Add(label_2, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(boardListTC, 0, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(dirPicker2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(clearButton_2, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#else
    grid_sizer_1->Add(label_2, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(dirPicker2, 1, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(clearButton_2, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#endif

#ifdef __WXGTK__
    grid_sizer_1->Add(label_3, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(skinPathTC, 0, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(dirPicker3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(clearButton_3, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#else
    grid_sizer_1->Add(label_3, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(dirPicker3, 1, wxALL|wxEXPAND, 5);
    grid_sizer_1->Add(clearButton_3, 2, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
#endif

    SetSizer(grid_sizer_1);
    grid_sizer_1->Fit(this);
    // end wxGlade
}

/**
 * 各種動作設定用画面
 */
BehaviorPanel::BehaviorPanel(wxWindow* parent, const wxPoint& pos, const wxSize& size, long style):
    wxPanel(parent, ID_BehaviorPanel, pos, size, wxTAB_TRAVERSAL)
{
    // begin wxGlade: BehaviorPanel::BehaviorPanel
    panel_5 = new wxPanel(this, wxID_ANY);
    panel_4 = new wxPanel(this, wxID_ANY);
    panel_7 = new wxPanel(panel_4, wxID_ANY);
    panel_3 = new wxPanel(this, wxID_ANY);
    panel_6 = new wxPanel(panel_3, wxID_ANY);
    panel_2 = new wxPanel(this, wxID_ANY);
    sizer_3_staticbox = new wxStaticBox(panel_3, -1, wxT("スレ一覧"));
    sizer_5_staticbox = new wxStaticBox(panel_4, -1, wxT("スレ"));
    sizer_7_staticbox = new wxStaticBox(panel_5, -1, wxT("お気に入り"));
    sizer_2_staticbox = new wxStaticBox(panel_2, -1, wxT("板一覧"));
    openBNewTabCheck = new wxCheckBox(panel_2, ID_OpenBNewTabCheck, wxT("新しいタブで板を開く"));
    onlyOneCategoryCheck = new wxCheckBox(panel_2, ID_OnlyOneCategoryCheck, wxT("カテゴリを一つしか開かない"));
    openTNewTabCheck = new wxCheckBox(panel_6, ID_OpenTNewTabCheck, wxT("新しいタブでスレを開く"));
    const wxString threadNewTabCombo_choices[] = {
        wxT("常に最大化"),
        wxT("常に通常サイズ")
    };
    threadNewTabCombo = new wxComboBox(panel_6, ID_ThreadNewTabCombo, wxT(""), wxDefaultPosition, wxDefaultSize, 2, threadNewTabCombo_choices, wxCB_DROPDOWN|wxCB_READONLY);
    lastReadThreadPosCheck = new wxCheckBox(panel_3, ID_LastReadThreadPosCheck, wxT("最後に見たスレの位置にジャンプ"));
    const wxString threadJumpSettingRadio_choices[] = {
        wxT("見ていたところにジャンプする"),
        wxT("新着にジャンプする")
    };
    threadJumpSettingRadio = new wxRadioBox(panel_4, ID_ThreadJumpSetting, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, threadJumpSettingRadio_choices, 0, wxRA_SPECIFY_ROWS);
    redrawNewThreadCheck = new wxCheckBox(panel_4, ID_RedrawNewThreadCheck, wxT("新着チェック時に既得レスを描き直す"));
    label_1 = new wxStaticText(panel_7, wxID_ANY, wxT("既得スレの表示レス数"));
    const wxString showResponseCombo_choices[] = {
        wxT("全レス表示"),
        wxT("最新50レス"),
        wxT("最新100レス"),
        wxT("最新250レス"),
        wxT("最新500レス")
    };
    showResponseCombo = new wxComboBox(panel_7, ID_ShowResponseCombo, wxT(""), wxDefaultPosition, wxDefaultSize, 5, showResponseCombo_choices, wxCB_DROPDOWN|wxCB_READONLY);
    favoriteNewTabCheck = new wxCheckBox(panel_5, ID_FavoriteNewTabCheck, wxT("新しいタブで開く"));
    favoriteOnlyOneFolderCheck = new wxCheckBox(panel_5, ID_FavoriteOnlyOneFolder, wxT("フォルダを一つしか開かない"));

    set_properties();
    do_layout();
    // end wxGlade
}


void BehaviorPanel::set_properties()
{
     // begin wxGlade: BehaviorPanel::set_properties
     threadNewTabCombo->SetSelection(0);
     threadJumpSettingRadio->SetSelection(0);
     showResponseCombo->SetSelection(-1);
     // end wxGlade
}


void BehaviorPanel::do_layout()
{
     // begin wxGlade: BehaviorPanel::do_layout
     wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
     wxStaticBoxSizer* sizer_7 = new wxStaticBoxSizer(sizer_7_staticbox, wxVERTICAL);
     wxStaticBoxSizer* sizer_5 = new wxStaticBoxSizer(sizer_5_staticbox, wxVERTICAL);
     wxBoxSizer* sizer_6 = new wxBoxSizer(wxHORIZONTAL);
     wxStaticBoxSizer* sizer_3 = new wxStaticBoxSizer(sizer_3_staticbox, wxVERTICAL);
     wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
     wxStaticBoxSizer* sizer_2 = new wxStaticBoxSizer(sizer_2_staticbox, wxVERTICAL);
     sizer_2->Add(openBNewTabCheck, 1, wxEXPAND, 0);
     sizer_2->Add(onlyOneCategoryCheck, 1, wxEXPAND, 0);
     panel_2->SetSizer(sizer_2);
     sizer_1->Add(panel_2, 0, wxEXPAND, 0);
     sizer_4->Add(openTNewTabCheck, 1, wxEXPAND, 0);
     sizer_4->Add(threadNewTabCombo, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     panel_6->SetSizer(sizer_4);
     sizer_3->Add(panel_6, 1, wxEXPAND, 0);
     sizer_3->Add(lastReadThreadPosCheck, 0, wxALIGN_CENTER_VERTICAL, 0);
     panel_3->SetSizer(sizer_3);
     sizer_1->Add(panel_3, 0, wxEXPAND, 0);
     sizer_5->Add(threadJumpSettingRadio, 0, 0, 0);
     sizer_5->Add(redrawNewThreadCheck, 0, 0, 0);
     sizer_6->Add(label_1, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 0);
     sizer_6->Add(showResponseCombo, 1, 0, 0);
     panel_7->SetSizer(sizer_6);
     sizer_5->Add(panel_7, 1, wxEXPAND, 0);
     panel_4->SetSizer(sizer_5);
     sizer_1->Add(panel_4, 0, wxEXPAND, 0);
     sizer_7->Add(favoriteNewTabCheck, 0, 0, 0);
     sizer_7->Add(favoriteOnlyOneFolderCheck, 0, 0, 0);
     panel_5->SetSizer(sizer_7);
     sizer_1->Add(panel_5, 0, wxEXPAND, 0);
     SetSizer(sizer_1);
     sizer_1->Fit(this);
     // end wxGlade
}

/**
 * 色・フォント設定用画面
 */
// begin wxGlade: ::extracode
// end wxGlade
ColorFontSettingPanel::ColorFontSettingPanel(wxWindow* parent, const wxPoint& pos, const wxSize& size, long style):
     wxPanel(parent, ID_ColorFontSettingPanel, pos, size, wxTAB_TRAVERSAL)
{
     // begin wxGlade: ColorFontSettingPanel::ColorFontSettingPanel
     panel_3 = new wxPanel(this, wxID_ANY);
     panel_2 = new wxPanel(this, wxID_ANY);
     panel_6 = new wxPanel(panel_2, wxID_ANY);
     panel_13 = new wxPanel(panel_6, wxID_ANY);
     panel_5 = new wxPanel(panel_2, wxID_ANY);
     panel_12 = new wxPanel(panel_5, wxID_ANY);
     panel_11 = new wxPanel(panel_5, wxID_ANY);
     panel_10 = new wxPanel(panel_5, wxID_ANY);
     panel_4 = new wxPanel(panel_2, wxID_ANY);
     panel_9 = new wxPanel(panel_4, wxID_ANY);
     panel_8 = new wxPanel(panel_4, wxID_ANY);
     sizer_4_staticbox = new wxStaticBox(panel_4, -1, wxT("プレビュー"));
     sizer_5_staticbox = new wxStaticBox(panel_5, -1, wxT("フォント"));
     sizer_6_staticbox = new wxStaticBox(panel_6, -1, wxT("背景色"));
     panel_7 = new wxPanel(panel_4, wxID_ANY);
     treeSampleLabel = new wxStaticText(panel_4, ID_TreeSampleLabel, wxT("ツリー"));
     threadListSampleLabel = new wxStaticText(panel_7, ID_ThreadListSampleLabel, wxT("スレ覧"));
     extractSampleLabel = new wxStaticText(panel_7, ID_ExtractSampleLabel, wxT("抽出"));
     logWindowSampleLabel = new wxStaticText(panel_4, ID_LogWindowSampleLabel, wxT("ログ出力画面"));
     threadTitleSampleLabel = new wxStaticText(panel_4, ID_ThreadTitleSampleLabel, wxT("スレタイトル"));
     threadViewSampleLabel = new wxStaticText(panel_4, ID_ThreadViewSampleLabel, wxT("スレビュー"));
     kakikoSampleLabel = new wxStaticText(panel_8, ID_KakikoSampleLabel, wxT("書込み"));
     memoSampleLabel = new wxStaticText(panel_8, ID_MemoSampleLabel, wxT("メモ欄"));
     hintSampleLabel = new wxStaticText(panel_9, ID_HintSampleLabel, wxT("ヒント"));
     linkSampleLabel = new wxStaticText(panel_9, ID_LinkSampleLabel, wxT("Link"));
     othersSampleLabel = new wxStaticText(panel_4, ID_OthersSampleLabel, wxT("その他"));
     treeFontButton = new wxButton(panel_5, ID_TreeFontButton, wxT("ツリー"));
     threadListFontButton = new wxButton(panel_10, ID_ThreadListFontButton, wxT("スレ欄"));
     extractFontButton = new wxButton(panel_10, ID_ExtractFontButton, wxT("抽出"));
     logWindowFontButton = new wxButton(panel_5, ID_LogWindowFontButton, wxT("ログ出力画面"));
     threadTitleFontButton = new wxButton(panel_5, ID_ThreadTitleFontButton, wxT("スレタイトル"));
     kakikoFontButton = new wxButton(panel_11, ID_KakikoFontButton, wxT("書込み"));
     memoFontButton = new wxButton(panel_11, ID_MemoFontButton, wxT("メモ"));
     hintFontButton = new wxButton(panel_12, ID_HintFontButton, wxT("ヒント"));
     linkFontButton = new wxButton(panel_12, ID_LinkFontButton, wxT("Link"));
     otherFontButton = new wxButton(panel_5, ID_OthersFontButton, wxT("その他"));
     allFontButton = new wxButton(panel_5, ID_AllFontButton, wxT("すべて"));
     treeBGColorButton = new wxButton(panel_6, ID_BoardListBGColorButton, wxT("ツリー"));
     threadListBGColorButton = new wxButton(panel_6, ID_ThreadListBGColorButton, wxT("スレ覧"));
     logWindowBGColorButton = new wxButton(panel_6, ID_LogWindowBGColorButton, wxT("ログ出力画面"));
     threadTitleBGColorButton = new wxButton(panel_6, ID_ThreadTitleBGColorButton, wxT("スレタイトル"));
     threadViewBGColorButton = new wxButton(panel_6, ID_ThreadViewBGColorButton, wxT("スレビュー"));
     memoBGColorButton = new wxButton(panel_6, ID_MemoBGColorButton, wxT("メモ欄"));
     hintBGColorButton = new wxButton(panel_13, ID_HintBGColorButton, wxT("ヒント"));
     popupBGColorButton_copy_1 = new wxButton(panel_13, ID_PopupBGColorButton, wxT("ポップアップ"));
     allBGColorButton = new wxButton(panel_6, ID_AllBGColorButton, wxT("すべて"));
     label_1 = new wxStaticText(panel_3, wxID_ANY, wxT("※スレビューのフォントの種類はスキン、大きさは表示メニューで設定"));

     set_properties();
     do_layout();
     // end wxGlade
}


void ColorFontSettingPanel::set_properties()
{
     // ウィジェットとウィジェット名のペアを作成
     static const int STATIC_TEXT_NUMBER = 11;
     
     std::pair <wxString, wxStaticText*> *pArray = new std::pair<wxString, wxStaticText*>[STATIC_TEXT_NUMBER];
     pArray[0]  = std::make_pair(wxT("ID_TreeFontButton"),        treeSampleLabel);
     pArray[1]  = std::make_pair(wxT("ID_ThreadListFontButton"),  threadListSampleLabel);  
     pArray[2]	= std::make_pair(wxT("ID_ExtractFontButton"),	  extractSampleLabel);	 
     pArray[3]	= std::make_pair(wxT("ID_LogWindowFontButton"),	  logWindowSampleLabel);	 
     pArray[4]	= std::make_pair(wxT("ID_ThreadTitleFontButton"), threadTitleSampleLabel);
     pArray[5]	= std::make_pair(wxT("ID_KakikoFontButton"),	  threadViewSampleLabel); 
     pArray[6]	= std::make_pair(wxT("ID_MemoFontButton"),	  kakikoSampleLabel);	 
     pArray[7]	= std::make_pair(wxT("ID_HintFontButton"),	  memoSampleLabel);	 
     pArray[8]	= std::make_pair(wxT("ID_LinkFontButton"),	  hintSampleLabel);	 
     pArray[9]	= std::make_pair(wxT("ID_OthersFontButton"),	  linkSampleLabel);	 
     pArray[10] = std::make_pair(wxT("ID_AllFontButton"),	  othersSampleLabel);	 

     for (int i = 0; i < STATIC_TEXT_NUMBER; i++ )
     {
	  wxString widgetsName = pArray[i].first;
	  wxString widgetsInfo = wxEmptyString;
	  JaneCloneUtil::GetJaneCloneProperties(widgetsName, &widgetsInfo);

	  if (widgetsInfo != wxEmptyString) 
	  {
	       wxFont font;
	       bool ret = font.SetNativeFontInfoUserDesc(widgetsInfo);
	       if(ret) pArray[i].second->SetFont(font);
	  }
     }

     delete[] pArray;
}


void ColorFontSettingPanel::do_layout()
{
     // begin wxGlade: ColorFontSettingPanel::do_layout
     wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
     wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
     wxStaticBoxSizer* sizer_6 = new wxStaticBoxSizer(sizer_6_staticbox, wxVERTICAL);
     wxBoxSizer* sizer_13 = new wxBoxSizer(wxHORIZONTAL);
     wxStaticBoxSizer* sizer_5 = new wxStaticBoxSizer(sizer_5_staticbox, wxVERTICAL);
     wxBoxSizer* sizer_12 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_11 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_10 = new wxBoxSizer(wxHORIZONTAL);
     wxStaticBoxSizer* sizer_4 = new wxStaticBoxSizer(sizer_4_staticbox, wxVERTICAL);
     wxBoxSizer* sizer_9 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
     sizer_4->Add(treeSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_7->Add(threadListSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_7->Add(extractSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     panel_7->SetSizer(sizer_7);
     sizer_4->Add(panel_7, 1, wxEXPAND, 0);
     sizer_4->Add(logWindowSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_4->Add(threadTitleSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_4->Add(threadViewSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_8->Add(kakikoSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_8->Add(memoSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     panel_8->SetSizer(sizer_8);
     sizer_4->Add(panel_8, 1, wxEXPAND, 0);
     sizer_9->Add(hintSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     sizer_9->Add(linkSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     panel_9->SetSizer(sizer_9);
     sizer_4->Add(panel_9, 1, wxEXPAND, 0);
     sizer_4->Add(othersSampleLabel, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
     panel_4->SetSizer(sizer_4);
     sizer_3->Add(panel_4, 1, wxEXPAND, 0);
     sizer_5->Add(treeFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_10->Add(threadListFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_10->Add(extractFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_10->SetSizer(sizer_10);
     sizer_5->Add(panel_10, 1, wxEXPAND, 0);
     sizer_5->Add(logWindowFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_5->Add(threadTitleFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_11->Add(kakikoFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_11->Add(memoFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_11->SetSizer(sizer_11);
     sizer_5->Add(panel_11, 1, wxEXPAND, 0);
     sizer_12->Add(hintFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_12->Add(linkFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_12->SetSizer(sizer_12);
     sizer_5->Add(panel_12, 1, wxEXPAND, 0);
     sizer_5->Add(otherFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_5->Add(allFontButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_5->SetSizer(sizer_5);
     sizer_3->Add(panel_5, 1, wxEXPAND, 0);
     sizer_6->Add(treeBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(threadListBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(logWindowBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(threadTitleBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(threadViewBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_6->Add(memoBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_13->Add(hintBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     sizer_13->Add(popupBGColorButton_copy_1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_13->SetSizer(sizer_13);
     sizer_6->Add(panel_13, 1, wxEXPAND, 0);
     sizer_6->Add(allBGColorButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
     panel_6->SetSizer(sizer_6);
     sizer_3->Add(panel_6, 1, wxEXPAND, 0);
     panel_2->SetSizer(sizer_3);
     sizer_1->Add(panel_2, 1, wxEXPAND, 0);
     sizer_2->Add(label_1, 0, 0, 0);
     panel_3->SetSizer(sizer_2);
     sizer_1->Add(panel_3, 0, wxEXPAND, 0);
     SetSizer(sizer_1);
     sizer_1->Fit(this);
     // end wxGlade
}

/*
 * 色選択/フォント選択用ダイアログを表示させる
 */
void ColorFontSettingPanel::OnClickColorFontSettingButton(wxCommandEvent& event)
{
     // イベントで取得したIDはなにか
     // switch文で書きたいけどうまく行かないのでif文
     const int id = event.GetId();

     if (id == ID_TreeFontButton        ||	// ツリーフォント設定ボタン	     
	 id == ID_ThreadListFontButton	||	// スレ欄フォント設定ボタン	     
	 id == ID_ExtractFontButton	||	// 抽出フォント設定ボタン		 
	 id == ID_LogWindowFontButton	||	// ログ出力画面フォント設定ボタン    
	 id == ID_ThreadTitleFontButton ||	// スレッドタイトルフォント設定ボタン
	 id == ID_KakikoFontButton	||	// 書き込みフォント設定ボタン	     
	 id == ID_MemoFontButton        ||	// メモ欄フォント設定ボタン	     
	 id == ID_HintFontButton	||	// ヒントフォント設定ボタン	     
	 id == ID_LinkFontButton	||	// リンクフォント設定ボタン	     
	 id == ID_OthersFontButton      ||	// その他フォント設定ボタン	     
	 id == ID_AllFontButton			// すべてフォント設定ボタン
	  ) {
          /**		  
	   * フォント設定 
	   */
	  const std::string &str = EnumString<JANECLONE_ENUMS>::From( static_cast<JANECLONE_ENUMS>(id) );
	  const wxString font = wxString((const char*)str.c_str(), wxConvUTF8);
	  bool needToChangeFont = this->SetEachFontSetting(font);

	  if (needToChangeFont)
	  {
	       SetSampleFontSetting(id);
	  }

     } else if (
	  id == ID_BoardListBGColorButton   ||	// スレ欄背景色設定ボタン	    
	  id == ID_ThreadListBGColorButton  ||	// 抽出背景色設定ボタン		    
	  id == ID_LogWindowBGColorButton   ||	// ログ出力画面背景色設定ボタン	    
	  id == ID_ThreadTitleBGColorButton ||	// スレッドタイトル背景色設定ボタン 
	  id == ID_ThreadViewBGColorButton  ||	// スレビュー背景色設定ボタン	    
	  id == ID_MemoBGColorButton        ||	// メモ欄背景色設定ボタン	    
	  id == ID_HintBGColorButton	    ||	// ヒント背景色設定ボタン	    
	  id == ID_PopupBGColorButton	    ||	// ポップアップ背景色設定ボタン	    
	  id == ID_AllBGColorButton		// すべての背景色設定ボタン	    
	  ) {
	  /**
	   * 背景色設定
	   */
	  const std::string &str = EnumString<JANECLONE_ENUMS>::From( static_cast<JANECLONE_ENUMS>(id) );
	  const wxString bgColor = wxString((const char*)str.c_str(), wxConvUTF8);

#ifndef __WXMAC__
	  bool needToChangeBGColor = this->SetEachBGColorSetting(bgColor);

	  if (needToChangeBGColor)
	  {
	       SetSampleBGColorSetting(id);
	  }

     }
     
#else
     // メインスレッドに更新してもらう
     m_id = id;
     SendUIUpdateEvent();

     }

#endif
}
/**
 * 各部位のフォントを設定し、プロパティファイルに書き出す
 * @param  各部位の名称の文字列型
 * @return 変更があればtrueを返す
 */
bool ColorFontSettingPanel::SetEachFontSetting(const wxString& font)
{
     wxFontData data;
     wxFont canvasFont;
     data.SetInitialFont(canvasFont);
     wxFontDialog dialog(this, data);

     if ( wxID_OK == dialog.ShowModal() ) 
     {
     	  // フォント設定用データを用意する
     	  wxFontData retData = dialog.GetFontData();
     	  canvasFont = retData.GetChosenFont();

     	  // 結果を受け取る
     	  const wxString fontInfo  = canvasFont.GetNativeFontInfoUserDesc();
     	  // プロパティファイルに格納
     	  JaneCloneUtil::SetJaneCloneProperties(font, fontInfo);
     	  return true;
     }

     return false;
}
/**
 * 色・フォント設定用画面のサンプル部分のフォントを変更する
 */
void ColorFontSettingPanel::SetSampleFontSetting(const int id)
{

     int wannaChangeID = -1;

     if (id == ID_TreeFontButton) {
	  wannaChangeID = ID_TreeSampleLabel;	  
     } else if (id == ID_ThreadListFontButton) {
	  wannaChangeID = ID_ThreadListSampleLabel;	  
     } else if (id == ID_ExtractFontButton) {
	  wannaChangeID = ID_ExtractSampleLabel;	  
     } else if (id == ID_LogWindowFontButton) {
	  wannaChangeID = ID_LogWindowSampleLabel;	  
     } else if (id == ID_ThreadTitleFontButton) {
	  wannaChangeID = ID_ThreadTitleSampleLabel;	  
     } else if (id == ID_KakikoFontButton) {
	  wannaChangeID = ID_KakikoSampleLabel;	  
     } else if (id == ID_MemoFontButton) {
	  wannaChangeID = ID_MemoSampleLabel;	  
     } else if (id == ID_HintFontButton) {
	  wannaChangeID = ID_HintSampleLabel;	  
     } else if (id == ID_LinkFontButton) {
	  wannaChangeID = ID_LinkSampleLabel;	  
     } else if (id == ID_OthersFontButton) {
	  wannaChangeID = ID_OthersSampleLabel;	  
     } else if (id == ID_AllFontButton) {
	  wannaChangeID = ID_AllSampleLabel;
     }

     if (wannaChangeID < 0)
	  return;

     wxWindow* window = FindWindowById(static_cast<long>(wannaChangeID), this);
     if ( wxStaticText* st = dynamic_cast<wxStaticText*>(window))
     {
	  wxString widgetsName = wxEmptyString;
	  wxString widgetsInfo = wxEmptyString;
	  const std::string &str = EnumString<JANECLONE_ENUMS>::From( static_cast<JANECLONE_ENUMS>(id) );
	  widgetsName = wxString((const char*)str.c_str(), wxConvUTF8);
	  JaneCloneUtil::GetJaneCloneProperties(widgetsName, &widgetsInfo);

	  if (widgetsInfo != wxEmptyString)
	  {
	       wxFont font;
	       bool ret = font.SetNativeFontInfoUserDesc(widgetsInfo);
	       if(ret) st->SetFont(font);

	       this->Refresh();
	       this->Update();
	  }

     } else {
	  wxMessageBox(wxT("内部エラー, フォントの変更に失敗しました."), wxT("設定画面"), wxICON_ERROR);
	  return;
     }
}
/**
 * 各部位の背景色を設定し、プロパティファイルに書き出す
 * @param  各部位の名称を文字列で
 * @return 変更があればtrueを返す
 */
bool ColorFontSettingPanel::SetEachBGColorSetting(const wxString& bgColor)
{
     wxColourData data;
     data.SetChooseFull(true);
     for (int i = 0; i < 16; i++)
     {
	  wxColour colour(i*16, i*16, i*16);
	  data.SetCustomColour(i, colour);
     }

     wxColourDialog dialog(this, &data);
     if (dialog.ShowModal() == wxID_OK)
     {
	  wxColourData retData = dialog.GetColourData();
	  wxColour col = retData.GetColour();
	  // 結果を受け取る
	  const wxString colorInfo = col.GetAsString();
	  // フォント,色情報 の順でプロパティファイルに格納
	  JaneCloneUtil::SetJaneCloneProperties(bgColor, colorInfo);
	  return true;
     }

     return false;
}
/**
 * 色・フォント設定用画面のサンプル部分の背景色を変更する
 */
void ColorFontSettingPanel::SetSampleBGColorSetting(const int id)
{
     wxArrayInt iArray;

     if (id == ID_BoardListBGColorButton) {
	  iArray.Add(ID_TreeSampleLabel);	  
     } else if (id == ID_ThreadListBGColorButton) {
	  iArray.Add(ID_ThreadListSampleLabel);
	  iArray.Add(ID_ExtractSampleLabel);
     } else if (id == ID_LogWindowBGColorButton) {
	  iArray.Add(ID_LogWindowSampleLabel);	  
     } else if (id == ID_ThreadTitleBGColorButton) {
	  iArray.Add(ID_ThreadTitleSampleLabel);	  
     } else if (id == ID_MemoBGColorButton) {
	  iArray.Add(ID_KakikoSampleLabel);
	  iArray.Add(ID_MemoSampleLabel);	  
     } else if (id == ID_HintBGColorButton) {
	  iArray.Add(ID_HintSampleLabel);	  
     } else if (id == ID_PopupBGColorButton) {
	  iArray.Add(ID_LinkSampleLabel);	  
     } else if (id == ID_AllFontButton) {
	  iArray.Add(ID_TreeSampleLabel);
	  iArray.Add(ID_ThreadListSampleLabel);
	  iArray.Add(ID_ExtractSampleLabel);
	  iArray.Add(ID_LogWindowSampleLabel);
	  iArray.Add(ID_ThreadTitleSampleLabel);
	  iArray.Add(ID_ThreadViewSampleLabel);
	  iArray.Add(ID_KakikoSampleLabel);
	  iArray.Add(ID_MemoSampleLabel);
	  iArray.Add(ID_HintSampleLabel);
	  iArray.Add(ID_LinkSampleLabel);
	  iArray.Add(ID_OthersSampleLabel);
     }

     for (int i = 0; i < iArray.size(); i++ )
     {
	  wxWindow* window = FindWindowById(static_cast<long>(iArray[i]), this);
	  if ( wxStaticText* st = dynamic_cast<wxStaticText*>(window))
	  {
	       wxString widgetsName = wxEmptyString;
	       wxString widgetsInfo = wxEmptyString;
	       const std::string &str = EnumString<JANECLONE_ENUMS>::From( static_cast<JANECLONE_ENUMS>(id) );
	       widgetsName = wxString((const char*)str.c_str(), wxConvUTF8);
	       JaneCloneUtil::GetJaneCloneProperties(widgetsName, &widgetsInfo);

	       if (widgetsInfo != wxEmptyString)
	       {
		    wxColour bgColor;
		    bool ret = bgColor.Set(widgetsInfo);
		    /**
		     * FIXME:wxWidgets-2.9以上でないと背景色が変更できない
		     * wxStaticText -> wxGenericStaticText
		     */
		    if(ret) st->SetBackgroundColour(bgColor);

		    this->Refresh();
		    this->Update();
	       }

	  } else {
	       wxMessageBox(wxT("内部エラー, 背景色の変更に失敗しました."), wxT("設定画面"), wxICON_ERROR);
	       return;
	  }
     }
}

