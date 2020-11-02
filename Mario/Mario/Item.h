/**********************************************************************************
// MenuItem (Arquivo de Cabe�alho)
// 
// Cria��o:		14 Mai 2012
// Atualiza��o:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define um item de menu
//
**********************************************************************************/

#ifndef _MARIO_ITEM_H_
#define _MARIO_ITEM_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Types.h"

// ---------------------------------------------------------------------------------

enum MenuState {SELECTED, NOTSELECTED};

// ---------------------------------------------------------------------------------

class Item : public Object
{
private:
	TileSet   * tileset;				// folha de sprites da anima��o
	
public:
	Animation * animation;				// anima��o do menu
	Item(float posX, float posY, uint menuId, string imgFile);
	~Item();

	void Select();						// seleciona menu
	void UnSelect();					// desmarca sele��o

	void Update(float gameTime);		// atualiza��o do objeto
	void Draw();						// desenho do objeto

}; 

// ---------------------------------------------------------------------------------

#endif