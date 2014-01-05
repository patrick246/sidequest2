#include "App.h"
#include "Config.h"
#include "CircleState.h"
#include "RectState.h"
#include "StartupState.h"
#include "MainMenuState.h"

App::App(Config& c)
	: m_accumulator(0)
	, timestep(1.f / 60.f)
	, statemanager(*this)
	, inputmanager(this->window)
{
	window.create(sf::VideoMode(c.get<unsigned int>("windowsize_x"), c.get<unsigned int>("windowsize_y")), "SideQuest II");
	window.setVerticalSyncEnabled(c.get<bool>("vsync"));
	window.clear();
	window.display();

	statemanager.registerState("circle", std::unique_ptr<State>(new CircleState(*this)));
	statemanager.registerState("rect", std::unique_ptr<State>(new RectState(*this)));
	statemanager.registerState("startup", std::unique_ptr<State>(new StartupState(*this)));
	statemanager.registerState("mainmenu", std::unique_ptr<State>(new MainMenuState(*this)));
	statemanager.pushState("startup");
}

void App::run()
{
	while (window.isOpen() && statemanager.isRunning())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		float frametime = m_clock.restart().asSeconds();
		m_accumulator += frametime;

		

		while (m_accumulator >= timestep)
		{
			m_accumulator -= timestep;
			window.setTitle("SideQuest II - Frametime: " + toString(frametime) + " - FPS: " + toString(1 / frametime));
			inputmanager.update();
			update();
		}	
		render();
	}
}

void App::update()
{
	statemanager.update();
}

void App::render()
{
	window.clear();
	window.draw(statemanager);
	window.display();
}