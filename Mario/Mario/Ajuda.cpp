/**********************************************************************************
// Ajuda (Arquivo de Cabeçalho)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Ajuda do jogo Super Mario
//
**********************************************************************************/

#include "Ajuda.h"

// ----------------------------------------------------------------------

void Ajuda::Init()
{
	fundo = new Sprite("Resources/Ajuda.jpg");
	voltar = new Item(250, 550, VOLTAR, "Resources/Voltar.png");
	Mario::audio->Play(MAJUDA, TRUE);
}

// ----------------------------------------------------------------------

void Ajuda::Update(float gameTime)
{
	Mario::mouse->Update(gameTime);
	voltar->Update(gameTime);

	bool selected = Mario::scene->Collision(Mario::mouse, voltar);

	if (selected)
		voltar->Select();
	else
		voltar->UnSelect();

	if (((selected) && (Mario::mouse->Clicked())) || window->KeyDown(VK_ESCAPE))
	{	
		Mario::audio->Stop(MAJUDA);
		Mario::NextLevel<Menu>();
	}
}

// ----------------------------------------------------------------------

void Ajuda::Draw()
{
	fundo->Draw(window->CenterX(), window->CenterY(), 0.9f);
	voltar->Draw();
}

// ----------------------------------------------------------------------

void Ajuda::Finalize()
{
	delete fundo;
	delete voltar;	
}

// ----------------------------------------------------------------------

