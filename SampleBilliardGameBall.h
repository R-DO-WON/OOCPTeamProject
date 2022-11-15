#pragma once

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "SampleBilliardBall.h"

class SampleBilliardGameBall : public SampleBilliardBall
{
public: 
	using SampleBilliardBall::SampleBilliardBall;

	bool isIntersecting(sf::Vector2f point); //마우스의 현재위치

	bool isPlayable(void); //이공이 내가 끌수있는지
	void setPlayable(bool playable);

	void setOwner(std::string owner); //이공을 누가 가지고있는지, 
	bool isOwner(std::string owner);
	std::string getOwner(void);

	// 게임 공에 숫자를 그리기 위해 virtual 함수 재정의 
	void render(sf::RenderTarget& window);

private:
	bool playable;
	std::string owner;
};