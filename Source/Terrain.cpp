#include "Terrain.h"
#include "TerrainConfig.h"
#include "TerrainQuadtree.h"
#include "Utility.h"

namespace Quark {
	Terrain::Terrain() :mConfig(NULL) {

	}

	Terrain::~Terrain() {
		SafeDealloc(mConfig);
	}

	void Terrain::init(const std::string& fileName) {
		mConfig = new TerrainConfig();
		mConfig->LoadFile(fileName);

		AddChild(new TerrainQuadtree(mConfig));
	}

	void Terrain::UpdateQuadtree() {
		// ī�޶� ���������� ���� ������.
		std::list<Node*>::iterator iter = GetChildren().begin();
		static_cast<TerrainQuadtree*>(*iter)->UpdateQuadtree();
	}
}