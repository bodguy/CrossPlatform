// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#include "MSAATexture2D.h"

namespace Theodore {
  MSAATexture2D::MSAATexture2D() {
    mType = AssetType::TextureType;
    mDimension = TextureDimension::MSAATex2D;
  }

  MSAATexture2D::~MSAATexture2D() {}

  bool MSAATexture2D::LoadMultiSampleTexture(unsigned int width, unsigned int height, TextureFormat format, unsigned int sample) {
    glGenTextures(1, &mTextureID);
    glBindTexture(static_cast<GLenum>(mDimension), mTextureID);
    mWidth = width;
    mHeight = height;

    switch (format) {
      case TextureFormat::RGBA32:
        glTexImage2DMultisample(static_cast<GLenum>(mDimension), sample, GL_RGBA8, mWidth, mHeight, GL_TRUE);
        break;
      case TextureFormat::RGB24:
        glTexImage2DMultisample(static_cast<GLenum>(mDimension), sample, GL_RGB, mWidth, mHeight, GL_TRUE);
        break;
      case TextureFormat::Red8:
        glTexImage2DMultisample(static_cast<GLenum>(mDimension), sample, GL_RED, mWidth, mHeight, GL_TRUE);
        break;
      case TextureFormat::Green8:
        glTexImage2DMultisample(static_cast<GLenum>(mDimension), sample, GL_GREEN, mWidth, mHeight, GL_TRUE);
        break;
      case TextureFormat::Blue8:
        glTexImage2DMultisample(static_cast<GLenum>(mDimension), sample, GL_BLUE, mWidth, mHeight, GL_TRUE);
        break;
      default:
        return false;
    }

    glBindTexture(static_cast<GLenum>(mDimension), static_cast<GLuint>(NULL));

    return true;
  }
}  // namespace Theodore
