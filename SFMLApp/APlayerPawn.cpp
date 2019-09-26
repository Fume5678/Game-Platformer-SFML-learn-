#include "APlayerPawn.h"

APlayerPawn::APlayerPawn(float x, float y)
{
	// ������������� �������� ���������� �����
	this->pos[0] = x;
	this->pos[1] = y;
	this->Health = 3;
	this->bAlive = true;
	this->Speed = 3;

	// �������� �������� �������
	ATexture.loadFromFile("..\\Resource\\Boy_Sprites.png");
	ASprite.setTexture(ATexture);
	// ToDo ��������� ������ ����� � ����������, ��� �������� ��������� �������
	ASprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

	CurrPose[0] = 0;
	CurrPose[1] = 0;
}

int APlayerPawn::PawnDrawCicle(sf::RenderWindow& window)
{
	window.draw(ASprite);  // ToDo �������� ��������� � ����� ������ ���������� � ������ ������
	return 0;
}

void APlayerPawn::SetPose(EActionList Action)
{
	// ToDo �������� ������ ������� �� �������� ������
	ASprite.setTextureRect(sf::IntRect(64 * CurrPose[0], 64 * CurrPose[1], 64, 64));
}
