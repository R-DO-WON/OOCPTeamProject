#include "SampleGame.h"
#include "SampleBilliardBoard.h"
#include "SampleBilliardGameBall.h"
#include "SampleBilliardObject.h"

SampleGame::SampleGame(int width, int height, int fpsLimit)
	:BaseGame(width, height, fpsLimit), isDraggingBall(false), draggedBall(nullptr)
{
	// SampleGame을 위한 인터페이스 생성 및 등록 

	// SampleGame을 위한 당구대 생성 및 등록 
	gameObjects.push_back(new SampleBilliardBoard()); //당구대하나만들기

	// SampleGame을 위한 당구공 생성 및 등록 
	SampleBilliardGameBall* ball0 = new SampleBilliardGameBall(sf::Vector2f(800, 500), 10, sf::Color::White); // 움직일수있는공

	SampleBilliardGameBall* ball1 = new SampleBilliardGameBall(sf::Vector2f(800, 350), 10, sf::Color::Yellow);

	SampleBilliardGameBall* ball2 = new SampleBilliardGameBall(sf::Vector2f(815, 330), 10, sf::Color::Blue);
	SampleBilliardGameBall* ball3 = new SampleBilliardGameBall(sf::Vector2f(785, 330), 10, sf::Color::Red);

	SampleBilliardGameBall* ball4 = new SampleBilliardGameBall(sf::Vector2f(830, 310), 10, sf::Color::Magenta);
	SampleBilliardGameBall* ball5 = new SampleBilliardGameBall(sf::Vector2f(800, 310), 10, sf::Color(255,100,130));
	SampleBilliardGameBall* ball6 = new SampleBilliardGameBall(sf::Vector2f(770, 310), 10, sf::Color::Green);

	SampleBilliardGameBall* ball7 = new SampleBilliardGameBall(sf::Vector2f(845, 290), 10, sf::Color::Cyan);
	SampleBilliardGameBall* ball8 = new SampleBilliardGameBall(sf::Vector2f(815, 290), 10, sf::Color::Black); // 8번 공
	SampleBilliardGameBall* ball9 = new SampleBilliardGameBall(sf::Vector2f(785, 290), 10, sf::Color::Red);
	SampleBilliardGameBall* ball10 = new SampleBilliardGameBall(sf::Vector2f(755, 290), 10, sf::Color::Black);

	SampleBilliardGameBall* ball11 = new SampleBilliardGameBall(sf::Vector2f(860, 270), 10, sf::Color::Yellow);
	SampleBilliardGameBall* ball12 = new SampleBilliardGameBall(sf::Vector2f(830, 270), 10, sf::Color::White);
	SampleBilliardGameBall* ball13 = new SampleBilliardGameBall(sf::Vector2f(800, 270), 10, sf::Color::Blue);
	SampleBilliardGameBall* ball14 = new SampleBilliardGameBall(sf::Vector2f(770, 270), 10, sf::Color::Red);
	SampleBilliardGameBall* ball15 = new SampleBilliardGameBall(sf::Vector2f(740, 270), 10, sf::Color::Black);
	ball1->setOwner("1");
	ball2->setOwner("2");
	ball3->setOwner("3");
	ball4->setOwner("4");
	ball5->setOwner("5");
	ball6->setOwner("6");
	ball7->setOwner("7");
	ball8->setOwner("8");
	ball9->setOwner("9");
	ball10->setOwner("10");
	ball11->setOwner("11");
	ball12->setOwner("12");
	ball13->setOwner("13");
	ball14->setOwner("14");
	ball15->setOwner("15");
	ball0->setPlayable(true);
	ball1->setPlayable(false);
	ball2->setPlayable(false);
	ball3->setPlayable(false);
	ball4->setPlayable(false);
	ball5->setPlayable(false);
	ball6->setPlayable(false);
	ball7->setPlayable(false);
	ball8->setPlayable(false);
	ball9->setPlayable(false);
	ball10->setPlayable(false);
	ball11->setPlayable(false);
	ball12->setPlayable(false);
	ball13->setPlayable(false);
	ball14->setPlayable(false);
	ball15->setPlayable(false);
	gameObjects.push_back(ball0);
	gameObjects.push_back(ball1); 
	gameObjects.push_back(ball2);
	gameObjects.push_back(ball3);
	gameObjects.push_back(ball4);
	gameObjects.push_back(ball5);
	gameObjects.push_back(ball6);
	gameObjects.push_back(ball7);
	gameObjects.push_back(ball8);
	gameObjects.push_back(ball9);
	gameObjects.push_back(ball10);
	gameObjects.push_back(ball11);
	gameObjects.push_back(ball12);
	gameObjects.push_back(ball13);
	gameObjects.push_back(ball14);
	gameObjects.push_back(ball15);
	//오브젝트에 공 넣음 
}

SampleGame::~SampleGame(void)
{
	// UI 인스턴스 해제  

	// 게임 오브젝트들 해제 
	for (SampleBilliardObject* obj : gameObjects)
	{
		delete obj;
	}
}

sf::Font* SampleGame::font = nullptr;
const sf::Font& SampleGame::getFont(void)
{
	if (font == nullptr) {
		font = new sf::Font;
		font->loadFromFile("Arial.ttf");
	}
	return *font;
}

// 상속 클래스는 반드시 이벤트 핸들링 함수 구현해야 함 
void SampleGame::handle(sf::Event& ev)
{
	// SampleGame을 위한 입력 이벤트 처리 
	switch (ev.type)
	{
	case sf::Event::Closed:
		// 윈도우의 x 버튼 누르면 종료한다 
		window->close();
		break;
	case sf::Event::KeyPressed:
		// 키보드 이벤트 
		if (ev.key.code == sf::Keyboard::Escape)
		{
			// TODO: game paused 
			// TODO: call sample GUI 
		}
		break;
	case sf::Event::MouseMoved:
		// 마우스 움직임 이벤트 
		mouseXY.x = (float)ev.mouseMove.x;
		mouseXY.y = (float)ev.mouseMove.y; //마우스 xy좌표
		break;
	case sf::Event::MouseButtonPressed:
		// 마우스 버튼 누름 이벤트 
		if (ev.mouseButton.button == sf::Mouse::Left) //왼쪽버튼
		{
			for (SampleBilliardObject* obj : gameObjects)
			{
				// SampleBilliardBall의 인스턴스가 아닌 경우 pass
				SampleBilliardGameBall* gameBall = dynamic_cast<SampleBilliardGameBall*>(obj);
				if (gameBall == nullptr)
				{
					continue;
				}

				// 커서가 공의 내부가 아닌 경우 pass 
				if (!gameBall->isIntersecting(mouseXY))
				{
					continue;
				}

				// 공이 Playable이 아닌 경우 pass 
				if (!gameBall->isPlayable()) {
					continue;
				}

				// 드래그 가능한 공 임시 저장 
				draggedBall = gameBall;
				isDraggingBall = true;
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		// 마우스 버튼 뗌 이벤트 
		if (ev.mouseButton.button == sf::Mouse::Left && isDraggingBall)
		{
			isDraggingBall = false;
		}
		break;
	}
}

// 상속 클래스는 반드시 게임 상태 갱신 함수 구현해야 함 
void SampleGame::update(void)
{
	// 게임 오브젝트 업데이트 , 흐른시간만큼
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}

	// 게임 오브젝트 충돌 검사
	for (SampleBilliardObject* obj1 : gameObjects)
	{
		for (SampleBilliardObject* obj2 : gameObjects)
		{
			obj1->collide(*obj2);
		}
	}

	
	// 끌었다가 놓은 공에 속도를 지정하고 표시 해제 
	if (!isDraggingBall && draggedBall != nullptr)
	{
		draggedBall->setVelocity(draggedBall->getPosition().x - mouseXY.x, draggedBall->getPosition().y - mouseXY.y);
		draggedBall = nullptr;
	}

	// 다음 단위 시간을 위해 초기화 , 다음업데이트까지 시간을 
	clock.restart();
}

// 상속 클래스는 반드시 객체 렌더링 함수 구현해야 함 
void SampleGame::render(sf::RenderTarget& target)
{
	// 화면 클리어 
	window->clear(sf::Color(75, 103, 163));  //가지고잇는거 다 지우고

	// 게임 오브젝트 렌더링 
	for (SampleBilliardObject* obj : gameObjects)  //렌더를 하라고 호출 -> 화면 출력
	{
		obj->render(target); //가상함수
	}

	// 공을 드래그 하면 세기 표시 (길이 및 색)
	renderDragpower(target);

	// 게임 UI 렌더링 
}

void SampleGame::renderDragpower(sf::RenderTarget& target)
{
	if (isDraggingBall)
	{
		sf::Vector2f distance = (mouseXY - draggedBall->getPosition());
		float distanceBetween = sqrt(distance.x * distance.x + distance.y * distance.y);
		sf::Vector2f invert = distance / distanceBetween;
		sf::Color directionColor = sf::Color(255, (255 - ((int)distanceBetween / 2) % 255), 0);
		if (distanceBetween > 510)
		{
			directionColor = sf::Color::Red;
		}

		sf::Vector2f toSubtract(distanceBetween * invert.x, distanceBetween * invert.y);
		sf::Vertex start = sf::Vertex(draggedBall->getPosition(), directionColor);
		sf::Vertex end = sf::Vertex(draggedBall->getPosition() - toSubtract, directionColor);

		sf::VertexArray points; 
		points.setPrimitiveType(sf::LineStrip);
		points.append(start);
		points.append(end);

		target.draw(points);
	}
}
