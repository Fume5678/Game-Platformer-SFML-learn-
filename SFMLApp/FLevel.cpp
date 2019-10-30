#include "Headers\FLevel.h"


FLevel::FLevel()
{
	LocalTime = 0;
	bGameEnd = true;
	bGameWon = false;
}

sf::Int32 FLevel::StartLevel(sf::RenderWindow& window, sf::Uint32 ChoosenLvl)
{
	Camera.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	// ToDo ������� ����� � ��������, ������� ����� ������ ������ �� ���������� ������ ��� ���������� ������


	// ��������� �������� ����
	bGameEnd = false;
	bGameWon = false;

	// ������������� ����� � ����
	PlayerPawn.CreatePawn(StartPos.x, StartPos.y);
	World.CreateWorld(ChoosenLvl);

	// ��������� ������� ������
	PlayerPawn.setPosition(World.GetStartPos());

	Sleep(1000);

	sf::Int32 EndStatus = EEndStatus::GameError;
	EndStatus = DrawCicle(window);

	return EndStatus;
}


sf::Int32 FLevel::DrawCicle(sf::RenderWindow& window)
{
	sf::Clock clock;
	float LastTime = 0;
	sf::Int32 delay = 0;

	// ����� ���������� ������� ��������� ������, � ���������� �������� ������
	while (!bGameEnd || !PlayerPawn.isAlive()) {

		 // ���������� ������ � �������
		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / currentTime;
		LastTime = currentTime;

		if (delay < 1000) {
			printf("fps: %d", (sf::Int32)fps);
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
		
		/*
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
			// ������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == -1)
				PlayerPawn.ChangeSelfSpeed(EActionList::Jump_Left);
			else if (PlayerPawn.GetXDirection() == 1)
				PlayerPawn.ChangeSelfSpeed(EActionList::Jump_Right);
			else
				return EEndStatus::GameError;
		}
		*/
		// ��������� ������ �� �������
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
			// ������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == EDirection::left)
				PlayerPawn.ChangeSelfSpeed(EActionList::Down_Left);
			else if (PlayerPawn.GetXDirection() == EDirection::right)
				PlayerPawn.ChangeSelfSpeed(EActionList::Down_Right);
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
			// ������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == EDirection::left)
				PlayerPawn.ChangeSelfSpeed(EActionList::Jump_Left);
			else if (PlayerPawn.GetXDirection() == EDirection::right)
				PlayerPawn.ChangeSelfSpeed(EActionList::Jump_Right);
		}
		else {
			// ������������ � ����������� �� �����������
			PlayerPawn.ChangeSelfSpeed(EActionList::Idle_Vertical);
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
			// ������ ������
			PlayerPawn.ChangeSelfSpeed(EActionList::Move_Right);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
			// ������ �����
			PlayerPawn.ChangeSelfSpeed(EActionList::Move_Left);
		}
		else {
			// ������������ � ����������� �� �����������
			if (PlayerPawn.GetXDirection() == EDirection::left)
				PlayerPawn.ChangeSelfSpeed(EActionList::Idle_Left);
			else if (PlayerPawn.GetXDirection() == EDirection::right)
				PlayerPawn.ChangeSelfSpeed(EActionList::Idle_Right);
		}

		// �������� ���������� �� �������� �������� // ToDo ������������� ������� �����.
		PlayerPawn.setSpeed(World.GetCorrectSpeed(PlayerPawn.GetXDirection(), PlayerPawn.GetYDirection(), PlayerPawn.GetSpeed(), PlayerPawn.GetPawnRect()));

		// ����� �������� �����
		PlayerPawn.MovePawn();

		// ��������� ������� ������ 
		setView(PlayerPawn.GetPos());

		/// ����� ��������� \\\
		// ������� ������ ��� ���������
		window.setView(Camera);
		window.clear();

		// �������� ���� ���������
		World.DrawWorld(window, Camera.getCenter(),Camera.getSize());
		PlayerPawn.DrawPawn(window);

		// ���������� ������. �������� � ���� ��������, ��������� �� FrameRate
		window.display();
	}
	return EEndStatus::Menu;
}

sf::View FLevel::setView(sf::Vector2f Pos) {
	// ToDo ����� � ���� ����� ������ 2 �����, �������� ���������� ��������� ������� ������, �� ���� ��������� ����� ���� �� �����.
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

