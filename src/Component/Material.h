// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#ifndef Material_h
#define Material_h

#include "Math/Color.h"
#include "Graphics/Enumeration.h"
#include <string>

namespace Theodore {
  class Pipeline;
  class Texture;
  class Material {
  public:
  	Material();
    Material(Pipeline* program);
    Material(Color ambient, Color diffuse, Color specular, float shininess);
    ~Material();

		std::string name;
    Color ambient;
    Color diffuse;
    Color specular;
		Color transmittance;
		Color emission;
    float shininess;
		float indexOfRefrection;
		float dissolve; // 1 == opaque; 0 == fully transparent
		int illuminationModel;
		unordered_map<TextureType, Texture*> textureMap;
		Pipeline* pipeline;

		static const Material emerald;
		static const Material jade;
		static const Material obsidian;
		static const Material pearl;
		static const Material ruby;
		static const Material turquoise;
		static const Material brass;
		static const Material bronze;
		static const Material chrome;
		static const Material copper;
		static const Material gold;
		static const Material silver;
		static const Material blackPlastic;
		static const Material blackRubber;
  };
}  // namespace Theodore

#endif /* Material_h */