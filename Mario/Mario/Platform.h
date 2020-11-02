/**********************************************************************************
// Platform (Arquivo de Cabeçalho)
//
// Criação:		21 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _MARIO_PLATFORM_H_
#define _MARIO_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Sprite.h"						// background é composto por sprites
#include "Mario.h"

// ---------------------------------------------------------------------------------

//enum TYPES { SMALL, MEDIUM, BLOCO, CASTELO, CANO, CANO2, CASTELOFINAL, PORTA, CHAOCASTELO, PAREDE, MOEDAS};

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
	Sprite * platform;					// sprite da plataforma

public:
	Platform(float posX, float posY, uint platType);
	~Platform();

	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Platform::Draw()
{
	platform->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif