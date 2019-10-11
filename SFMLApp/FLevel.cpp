#include "FLevel.h"
#include <windows.h>

int FLevel::StartLevel(sf::RenderWindow& window, sf::Uint32 ChoosenLvl)
{
	Camera.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	// ToDo ������� ����� � ��������, ������� ����� ������ ������ �� ���������� ������ ��� ���������� ������


	// ��������� �������� ����
	bGameEnd = false;
	bGameWon = false;

	// ������������� ����� � ����
	PlayerPawn.CreatePawn(StartPos.x, StartPos.y);
	World.CreateWorld(1);

	// ��������� ������� ������
	PlayerPawn.setPosition(World.getStartPos());

	Sleep(1000);

	int EndStatus = EEndStatus::GameError;
	EndStatus = DrawCicle(window);

	return EndStatus;
}


int FLevel::DrawCicle(sf::RenderWindow& window)
{
	sf::Clock clock;
	float LastTime = 0;
	int delay = 0;

	// ����� ���������� ������� ��������� ������, � ���������� �������� ������
	while (!bGameEnd) {
		
		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / currentTime;
		LastTime = currentTime;

		if (delay < 1000) {
			printf("fps: %d", (int)fps);
			delay = 0;
		}
		else {
			delay++;
		}
		

		// �������� ������� � ����
		sf::Event event;
		while (window.pollEvent(event)) {
			// ����� �� ����
			if (event.type == sf::Event::Closed) {
				bGameEnd = true;
				return EEndStatus::Exit;
			}
			
			// ����� � ����
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					bGameEnd = true;
					return EEndStatus::Menu;
				}
			}
		}

		// ��������� ������ �� �������
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
			// ������ ������
			PlayerPawn.SetStance(EActionList::Move_Right);
			PlayerPawn.MovePawn();	
		} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
			// ������ �����
			PlayerPawn.SetStance(EActionList::Move_Left);
			PlayerPawn.MovePawn();
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
			// ������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == -1)
				PlayerPawn.SetStance(EActionList::Jump_Left);
			else if (PlayerPawn.GetXDirection() == 1)
				PlayerPawn.SetStance(EActionList::Jump_Right);
			else
				return EEndStatus::GameError;
		}
		else {
			// ������������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == -1)
				PlayerPawn.SetStance(EActionList::Idle_Left);
			else if (PlayerPawn.GetXDirection() == 1)
				PlayerPawn.SetStance(EActionList::Idle_Right);
			else
				return EEndStatus::GameError;
		}
		// ��������� ������� ������ 
		setView(PlayerPawn.GetPos());

		// ������� ������ ��� ���������
		window.setView(Camera);
		window.clear();

		// �������� ���� ���������
		World.DrawWorld(window);
		PlayerPawn.DrawPawn(window);
		
		// ���������� ������. �������� � ���� ��������, ��������� �� FrameRate
		window.display();
	}
	return EEndStatus::Menu;
}

sf::View FLevel::setView(sf::Vector2f Pos) {
	Camera.setCenter(Pos.x + 100, Pos.y);
	return Camera;
}

void FLevel::GameSummar(sf::RenderWindow& window)
{
	if (bGameWon)
		printf("������");
	else
		printf("���� ������ ����");
}

