// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#ifndef Material_h
#define Material_h

#include <vector>

#include "Math/Color.h"

namespace Theodore {
  class Pipeline;
  class Texture;
  class FrameBuffer;
  class Material {
  public:
    Material(Pipeline* program);
    Material(Color ambient, Color diffuse, Color specular, float shininess);
    ~Material();

    Pipeline* GetShader() const;
    Texture* GetTexture0() const;
    Texture* GetTexture1() const;
    Texture* GetTexture2() const;
    Texture* GetTexture3() const;
    Texture* GetTexture4() const;
    FrameBuffer* GetRenderTexture() const;
    Color GetAmbient() const;
    Color GetDiffuse() const;
    Color GetSpecular() const;
    float GetShininess() const;

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
    static const Material black_plastic;
    static const Material black_rubber;

  private:
    Pipeline* shader;
    Texture* texture0;
    Texture* texture1;
    Texture* texture2;
    Texture* texture3;
    Texture* texture4;
    FrameBuffer* renderTexture;

    Color ambient;
    Color diffuse;
    Color specular;
    float shininess;
  };
}  // namespace Theodore

#endif /* Material_h */