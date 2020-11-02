/**********************************************************************************
// Item (Código Fonte)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define um item de menu
//
**********************************************************************************/

#include "Item.h"

// ---------------------------------------------------------------------------------

Item::Item(float posX, float posY, uint menuId, string imgFile)
{
	tileset = new TileSet(imgFile, 275, 75, 1, 4);
	animation = new Animation(tileset, 0.150f, true); 

	uint selected[4] = {1,2,3,2};
	animation->Add(SELECTED, selected, 4);

	uint notselected[1] = {0};
	animation->Add(NOTSELECTED, notselected, 1);

	// cria bounding box
	bbox = new Rect(x - tileset->TileWidth() / 2.0f,
		            y - tileset->TileHeight() / 2.0f,
					x + tileset->TileWidth() / 2.0f,
					y + tileset->TileHeight() / 2.0f);

	MoveTo(posX, posY, 0.0f);
	type = menuId;
}

// ---------------------------------------------------------------------------------

Item::~Item()
{
	delete bbox;
	delete animation;
	delete tileset;	
}

// -------------------------------------------------------------------------------

void Item::Select()
{
	animation->Select(SELECTED);
}

// -------------------------------------------------------------------------------

void Item::UnSelect()
{
	animation->Select(NOTSELECTED);
}

// -------------------------------------------------------------------------------

void Item::Update(float gameTime)
{
	// atualiza animação
	animation->NextFrame();
}

// -------------------------------------------------------------------------------

void Item::Draw()
{
	animation->Draw(x, y, z);
}


// -------------------------------------------------------------------------------