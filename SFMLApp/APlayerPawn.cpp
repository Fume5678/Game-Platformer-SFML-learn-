#include "APlayerPawn.h"


void APlayerPawn::BeginPawn(sf::RenderWindow& window, float x, float y)
{
	// ������������� �������� ���������� �����
	this->ASprite.setPosition(x, y);
	this->Health = 3;
	this->bAlive = true;
	this->Speed = 3;
	this->delay = 100;

	// �������� �������� �������
	ATexture.loadFromFile("..\\Resource\\Boy_Sprites.png");
	ASprite.setTexture(ATexture);
	// ToDo ��������� ������ ����� � ����������, ��� �������� ��������� �������
	ASprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

	CurrPose = 0;

	Clock.restart();
}

void APlayerPawn::DrawPawn(sf::RenderWindow& window)
{
	window.draw(ASprite);  // ToDo �������� ��������� � ����� ������ ���������� � ������ ������
	
}

void APlayerPawn::SetPose(EActionList Action)
{
	// ToDo �������� ������ ������� �� �������� ������
	switch (Action) {
	case EActionList::Move_Left:
		// ����� �������� ����� � ����������� �� �������
		if (Clock.getElapsedTime().asMilliseconds() > delay) {
			Clock.restart();
		}

		ASprite.setTextureRect(sf::IntRect(64 * CurrPose, 64 * 2, 64, 64));
		break;

	case EActionList::Move_Right:
		// ����� �������� ����� � ����������� �� �������
		if (Clock.getElapsedTime().asMilliseconds() > delay) {
			CurrPose = (CurrPose + 1) % (ATexture.getSize().x / 64);
			Clock.restart();
		}

		ASprite.setTextureRect(sf::IntRect(64 * CurrPose, 64 * 1, 64, 64));
		break;

	case EActionList::Jump_Left:                 
		ASprite.setTextureRect(sf::IntRect(192, 0, 64, 64));
		break;

	case EActionList::Jump_Right:
		ASprite.setTextureRect(sf::IntRect(128, 0, 64, 64));
		break;

	case EActionList::Idle_Left:
		ASprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
		CurrPose = 0;
		break;

	case EActionList::Idle_Right:
		ASprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		CurrPose = 0;
		break;
	}
}

bool APlayerPawn::isAlive()
{
	if (Health > 0)
		return true;
	return false;
}

const sf::Sprite& APlayerPawn::GetSprite()
{
	return ASprite;
}

const sf::Texture& APlayerPawn::GetTexture()
{
	return ATexture;
}

const sf::Vector2f& APlayerPawn::GetPos()
{
	return ASprite.getPosition();
}

int APlayerPawn::GetHealth()
{
	return Health;
}

float APlayerPawn::GetSpeed()
{
	return Speed;
}
