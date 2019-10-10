#include "UWorld.h" 

UWorld::~UWorld()
{
	delete[] Layers;
}

void UWorld::CreateWorld(sf::Uint32 LvlName)
{
	FParserXML ParserXML(std::to_string(LvlName));

	// ������ ������ ������
	LvlSize.x = ParserXML.getLvlSize().x;
	LvlSize.y = ParserXML.getLvlSize().y;

	// ������ ������ �����
	TileSize.x = ParserXML.getTileSize().x;
	TileSize.y = ParserXML.getTileSize().y;

	// ������ ������ ��������
	TileSetSize.x = ParserXML.getTileSetSize().x;
	TileSetSize.y = ParserXML.getTileSetSize().y;

	// ������ ������ ��� ������
	// ToDo ����������� �������� � ����������, � �������� ��� ����� ������
	BackgrTex.loadFromFile(SpritePath + "SpaceBack.jpg");
	Backgr.setTexture(BackgrTex);

	TileSetTex.loadFromFile(SpritePath + "StarShipTiles.png");

	this->AmountLayers = ParserXML.getAmountLayer();

	Layers = new self::FLayer[AmountLayers];
	for (int count = 0; count < AmountLayers; count++) {
		Layers[count].Blocks.resize(LvlSize.y);
		for (int i = 0; i < LvlSize.y; i++) {
			// �����, ����� � ���������� �� ������� � ������� ������� ��� �������.
			int tmpSize = 0;
			for (int j = 0; j < LvlSize.x; j++){
				if (ParserXML.getLayerElement(count, i, j) != 0) {
					tmpSize++;
				}
			}
			Layers[count].Blocks[i].resize(tmpSize);
		}
	}

	// ���� ���������� ����� ����������
	for (int count = 0; count < AmountLayers; count++) {
		for (int i = 0; i < LvlSize.y; i++) {
			for (int j = 0; j < LvlSize.x; j++) {
				int TileId = ParserXML.getLayerElement(count, i, j);
				if (TileId != 0) {
					TileId--;
					int XTileId, YTileId;
					YTileId = TileId / TileSetSize.x;
					XTileId = TileId - (YTileId * TileSetSize.x);

					sf::Sprite tmpSprite;
					
					tmpSprite.setTexture(TileSetTex);
					tmpSprite.setTextureRect(sf::IntRect(XTileId * TileSize.x, YTileId * TileSize.y, TileSize.x, TileSize.y));
					tmpSprite.setPosition(sf::Vector2f(j * TileSize.x, i * TileSize.y));

					Layers[count].Blocks[i].push_back(tmpSprite);
				}
			}
		}
	}
}

void UWorld::DrawWorld(sf::RenderWindow& window)
{
	window.draw(Backgr);

	for (int count = 0; count < AmountLayers; count++) {
		for (int i = 0; i < LvlSize.y; i++) {
			for (int j = 0; j < Layers[count].Blocks[i].size(); j++) {
				window.draw(Layers[count].Blocks[i][j]);
			}
		}
	}
}

