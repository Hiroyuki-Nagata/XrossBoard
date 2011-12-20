#include "ExtractBoardList.h"

ExtractBoardList::ExtractBoardList()
{
	//　コンストラクタ
	htmlDocPtr m_doc;

	// ファイル名とエンコードの設定
	char* file = "./dat/BoardListUTF8.html";
	char* enc = "utf-8";

	wxArrayString array;

	// xmlの読み込み
	if (m_doc = htmlReadFile(file, enc, 1)) {
  	htmlNodePtr root = xmlDocGetRootElement(m_doc);
        if(root != NULL){
            ExtractBoardList::FindBoardInfo(root, array);
        }
        xmlFreeDoc(m_doc);
        m_doc = NULL;
	}

	xmlCleanupParser();
	xmlCleanupCharEncodingHandlers();

	this->m_list = array;
}

void ExtractBoardList::FindBoardInfo(xmlNode*& element, wxArrayString& array){
	// 板一覧の配列
	for(htmlNodePtr node = element; node != NULL; node = node->next){
		if(node->type == XML_ELEMENT_NODE){
			/** もしノードの中身が「B」タグだったら:カテゴリ名 */
			if(xmlStrcasecmp(node->name, (const xmlChar*)"B") == 0){
				// 配列に要素を詰め込む
				wxString wxNode( (char*)node->children->content, wxConvUTF8 );
				wxString category = "category:";
				category += wxNode;
				array.Add(category);
			}
			/** もしノードの中身が「A」タグだったら：板名 */
			if(xmlStrcasecmp(node->name, (const xmlChar*)"A") == 0){
				for(xmlAttrPtr attr = node->properties; attr != NULL; attr = attr->next){
					if(xmlStrcasecmp(attr->name, (const xmlChar*)"HREF") == 0){
						// 配列に要素を詰め込む
						wxString wxNode( (char*)node->children->content, wxConvUTF8 );
						array.Add(wxNode);
					}
				}
			}
            if(node->children != NULL)
            {
                ExtractBoardList::FindBoardInfo(node->children, array);
            }
		}
	}
}

wxArrayString ExtractBoardList::GetBoardList()
{
	return this->m_list;
}