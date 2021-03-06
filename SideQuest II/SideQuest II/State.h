#pragma once
#include <SFML/Graphics.hpp>
class App;
class State : public sf::Drawable
{
public:
	State(App& app)
		: m_app(app)
	{}
	virtual ~State(){}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void update(){}

	virtual void onEnter(){};
	virtual void onExit(){};

	virtual void handleEvent(sf::Event& event){}
protected:
	App& m_app;
};