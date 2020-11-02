/**********************************************************************************
// MenuItem (Arquivo de Cabeçalho)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define um item de menu
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
	TileSet   * tileset;				// folha de sprites da animação
	
public:
	Animation * animation;				// animação do menu
	Item(float posX, float posY, uint menuId, string imgFile);
	~Item();

	void Select();						// seleciona menu
	void UnSelect();					// desmarca seleção

	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto

}; 

// ---------------------------------------------------------------------------------

#endif