#include "FLevel.h"
#include "EEndStatus.h"

int FLevel::StartLevel(sf::RenderWindow& window, int ChoosenLvl)
{
	// ToDo ������� ����� � ��������, ������� ����� ������ ������ �� ���������� ������ ��� ���������� ������
	// ��������� �������� ����
	bGameEnd = false;
	bGameWon = false;

	// ������ ������� ������, ���� �������
	StartPos.x = window.getSize().x / 2;
	StartPos.y = window.getSize().y / 2;

	PlayerPawn.CreatePawn(StartPos.x, StartPos.y);

	int EndStatus = EEndStatus::GameError;
	EndStatus = DrawCicle(window);

	return EndStatus;
}


int FLevel::DrawCicle(sf::RenderWindow& window)
{
	// ����� ���������� ������� ��������� ������, � ���������� ������� 
	while (!bGameEnd) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				bGameEnd = true;
				return EEndStatus::Exit;
			}
			
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					bGameEnd = true;
					return EEndStatus::Menu;
				}
			}
		}

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

		window.clear(sf::Color::Yellow);
		PlayerPawn.DrawPawn(window);

		window.display();
	}
	return EEndStatus::Menu;
}

void FLevel::GameSummar(sf::RenderWindow& window)
{
	if (bGameWon)
		printf("������");
	else
		printf("���� ������ ����");
}

