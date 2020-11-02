/**********************************************************************************
// InputDemo (Código Fonte)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Exemplo de interface menu
//
**********************************************************************************/

#include "Engine.h"
#include "Mario.h"
#include "Menu.h"

// ------------------------------------------------------------------------------

Game *  Mario::level = nullptr;
bool    Mario::viewBBox = false;
Mouse * Mario::mouse = nullptr;
Scene * Mario::scene = nullptr;
Audio * Mario::audio = nullptr;
// ------------------------------------------------------------------------------

void Mario::Init()
{
	// cria sistema de audio
	audio = new Audio();
	audio->Add(MENU, "Resources/menu.wav");
	audio->Add(FASE1, "Resources/faseUm.wav");
	audio->Add(GAMEOVER, "Resources/gameOver.wav");
	audio->Add(PULO, "Resources/jump.wav");
	audio->Add(MAJUDA, "Resources/ajuda.wav");
	audio->Add(MOEDA, "Resources/moeda.wav");
	audio->Add(COGUMEL, "Resources/cogumelo.wav");
	audio->Add(TIRO, "Resources/tiro.wav");
	
	// cria gerenciador de cena
	scene = new Scene();

	// cria mouse
	mouse = new Mouse();
	viewBBox = false;
	ctrlKey = true;
	level = new Menu();
	level->Init();

}

// ------------------------------------------------------------------------------

void Mario::Update(float gameTime)
{
	// habilita/desabilita visualização da bounding box
	if (window->KeyUp('B'))
		ctrlKey = true;
	if (ctrlKey && window->KeyDown('B'))
	{
		viewBBox = !viewBBox;
		ctrlKey = false;
	}

	// atualiza nível
	level->Update(gameTime);
}

// ------------------------------------------------------------------------------

void Mario::Draw()
{
	// desenha nível
	level->Draw();
}

// ------------------------------------------------------------------------------

void Mario::Finalize()
{
	level->Finalize();
	delete level;
	delete audio;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Engine * engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(800, 600);
	engine->window->Color(150, 150, 150);
	engine->window->Title("Super Mario");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gráfico
	//engine->graphics->VSync(true);

	// inicia o jogo
	engine->Start(new Mario());

	delete engine;
	return 0;
}

// ----------------------------------------------------------------------------

