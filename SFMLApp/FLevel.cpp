#include "FLevel.h"
#include "EEndStatus.h"

int ULevelStarter::StartLevel(sf::RenderWindow& window, int ChoosenLvl)
{
	// ��������� �������� ����
	bGameEnd = false;
	bGameWon = false;

	// ������ ������� ������, ���� �������
	StartPos.x = window.getSize().x;
	StartPos.y = window.getSize().y;

	PlayerPawn.CreatePawn(StartPos.x, StartPos.y);

	return EEndStatus::GameError;
}


void ULevelStarter::DrawLevel(sf::RenderWindow& window)
{
	while (bGameEnd) {

	}
}

void ULevelStarter::GameSummar(sf::RenderWindow& window)
{
	if (bGameWon)
		printf("������");
	else
		printf("���� ������ ����");
}

