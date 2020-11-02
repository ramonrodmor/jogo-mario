/**********************************************************************************
// Sprite (Arquivo de Cabe�alho)
// 
// Cria��o:		11 Jul 2007
// Atualiza��o:	11 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define uma classe para representar um sprite
//
**********************************************************************************/

#ifndef _DESENVJOGOS_SPRITE_H_
#define _DESENVJOGOS_SPRITE_H_

// ---------------------------------------------------------------------------------

#include "Image.h"
#include "Types.h"

// ---------------------------------------------------------------------------------

class Sprite
{
private:
	SpriteInfo    spriteInfo;						// informa��es do sprite 
	bool          localImage;						// imagem local ou externa
	const Image * image;							// ponteiro para imagem

public:
	Sprite(string filename);						// constroi sprite a partir de um arquivo
	Sprite(const Image * img);						// constroi sprite a partir de imagem existente
	
	~Sprite();										// destrutor do sprite

	int Width();									// largura do sprite
	int Height();									// altura do sprite

	void Draw(										// desenha sprite
		float x, float y, float z = 0.5f,			// coordenadas da tela
		float scale = 1.0f, float rotation = 0.0f,  // escala e rota��o
		Color color = { 1, 1, 1, 1 });				// efeito de cor
};

// ---------------------------------------------------------------------------------
// Fun��es Inline

// retorna a largura do sprite
inline int Sprite::Width() 
{ return image->Width(); }

// retorna a altura do sprite
inline int Sprite::Height() 
{ return image->Height(); }

// ---------------------------------------------------------------------------------

#endif