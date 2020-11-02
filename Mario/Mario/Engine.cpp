/**********************************************************************************
// Engine (C�digo Fonte)
//
// Cria��o:		15 Mai 2014
// Atualiza��o: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	A fun��o da Engine � rodar jogos criados a partir da classe
//              abstrata Game. Todo jogo deve ser uma classe derivada de Game
//              e portanto deve implementar as fun��es membro Init, Update, Draw
//              e Finalize, que ser�o chamadas pelo motor em um loop de tempo real.
//              Para usar a classe Engine, o programador deve criar uma inst�ncia
//              e chamar o m�todo Start(), passando um objeto derivado de Game.
//
**********************************************************************************/

#include "Engine.h"
#include <windows.h>
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------
// Inicializa��o de vari�veis est�ticas da classe

Game     * Engine::game     = nullptr;		// jogo em execu��o
Window   * Engine::window   = nullptr;		// janela do jogo
Graphics * Engine::graphics = nullptr;		// dispositivo gr�fico
Renderer * Engine::renderer = nullptr;		// renderizador de sprites 

bool Engine::gamePaused = false;			// estado do game loop
Timer Engine::timer;						// medidor de tempo

// -------------------------------------------------------------------------------

Engine::Engine()
{
	gamePaused = false;
	window     = new Window();
	graphics   = new Graphics();
	renderer   = new Renderer();
}

// -------------------------------------------------------------------------------

Engine::~Engine()
{
	if (game)
		delete game;

	delete renderer;
	delete graphics;
	delete window;
}

// -----------------------------------------------------------------------------

void Engine::Pause()
{
	gamePaused = true;
	timer.Stop();
}

// -----------------------------------------------------------------------------

void Engine::Resume()
{
	gamePaused = false;
	timer.Start();
}

// -----------------------------------------------------------------------------

int Engine::Start(Game * gameLevel)
{
	game = gameLevel;

	// cria janela do jogo
	window->Initialize();

	// inicializa dispositivo gr�fico
	graphics->Initialize(window);

	// inicializa renderizador de sprites
	renderer->Initialize(window, graphics);

	// ajusta a resolu��o do Sleep para 1 milisegundo
	// requer uso da biblioteca winmm.lib
	timeBeginPeriod(1);

	int exitCode = Run();

	// volta a resolu��o do Sleep ao valor original
	timeEndPeriod(1);

	return exitCode;
}

// -------------------------------------------------------------------------------

int Engine::Run()
{
	// inicializa��o do jogo
	game->Init();

	// mensagens do Windows
	MSG  msg = { 0 };

	// inicia contagem de tempo
	timer.Start();

	// loop principal do jogo
	do
	{
		// testa se tem mensagem do windows para tratar
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// -----------------------------------------------
			// Pausa/Resume Jogo
			// -----------------------------------------------

			if (window->KeyCtrl(VK_PAUSE))
			{
				gamePaused = !gamePaused;

				if (gamePaused)
					timer.Stop();
				else
					timer.Start();
			}

			// -----------------------------------------------

			if (!gamePaused)
			{
				// atualiza��o do jogo 
				game->Update(FrameTime());

				// limpa a tela para o pr�ximo quadro
				graphics->Clear();

				// desenha o jogo
				game->Draw();

				// renderiza sprites
				renderer->Render();

				// apresenta o jogo na tela (troca backbuffer/frontbuffer)
				graphics->Present();
			}
			else
			{
				game->OnPause();
			}

			// ----------------------------------------------
		}

	} while (msg.message != WM_QUIT);

	// finaliza��o do jogo
	game->Finalize();

	// encerra aplica��o
	return int(msg.wParam);
}

// -----------------------------------------------------------------------------

float Engine::FrameTime()
{
	static float frameTime = 0.0f;	// tempo transcorrido para o quadro atual

	// ----- START DEBUG ----------
#ifdef _DEBUG
	static float totalTime = 0.0f;	// tempo total transcorrido 
	static uint  frameCount = 0;	// contador de frames transcorridos
#endif
	// ------ END DEBUG -----------

	// tempo do frame atual
	frameTime = timer.Reset();

	// ----- START DEBUG ----------
#ifdef _DEBUG
	// tempo acumulado dos frames
	totalTime += frameTime;

	// incrementa contador de frames
	frameCount++;

	// a cada 200ms atualiza indicador de FPS na janela
	if (totalTime >= 0.200f)
	{
		stringstream text;			// fluxo de texto para mensagens
		text << std::fixed;			// sempre mostra a parte fracion�ria
		text.precision(3);			// tr�s casas depois da v�rgula

		text << window->Title().c_str() << "    "
			<< "FPS: " << int(frameCount / totalTime) << "    "
			<< "Frame Time: " << frameTime * 1000 << " (ms)";

		SetWindowText(window->Id(), text.str().c_str());

		frameCount = 0;
		totalTime = 0.0f;
	}
#endif
	// ------ END DEBUG ----------- 

	return frameTime;
}

// -----------------------------------------------------------------------------
