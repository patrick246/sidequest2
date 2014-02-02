#include "PlayState.h"
#include "App.h"

PlayState::PlayState(App& app)
: State(app)
, m_tilemap(app)
{
	m_tilemap.loadFromFile("Assets/Game/Maps/debug_playground.tmx");
}

void PlayState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_tilemap);
}

void PlayState::update()
{

}