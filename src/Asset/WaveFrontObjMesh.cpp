// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#include "WaveFrontObjMesh.h"

#include <cstdio>
#include <cstring>

#include "Helper/Debug.h"
#include "Platform/Time.h"

namespace Theodore {
  WaveFrontObjMesh::WaveFrontObjMesh() : Mesh() {}

  WaveFrontObjMesh::~WaveFrontObjMesh() {}

  bool WaveFrontObjMesh::LoadObj(const std::string& filepath) {
    FILE* file = fopen(filepath.c_str(), "r");
    if (file == NULL) {
      return false;
    }

    std::vector<Vector2d> temp_uvs;
    std::vector<Vector3d> temp_normals;
    States states = States::NONE;
    mSemantic = mSemantic | VertexSemantic::SemanticPosition;

    TimePoint start = Time::GetTime();
    while (true) {
      char word[256];
      int res = fscanf(file, "%s", word);
      if (res == EOF) {
        break;
      }

      if (strcmp(word, "v") == 0) {
        Vector3d vertex;
        fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
        mVertices.push_back(vertex);
      } else if (strcmp(word, "vt") == 0) {
        Vector2d uv;
        mSemantic = mSemantic | VertexSemantic::SemanticTexCoord;
        fscanf(file, "%f %f\n", &uv.x, &uv.y);
        temp_uvs.push_back(uv);
      } else if (strcmp(word, "vn") == 0) {
        Vector3d normal;
        mSemantic = mSemantic | VertexSemantic::SemanticNormal;
        fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
        temp_normals.push_back(normal);
      } else if (strcmp(word, "f") == 0) {
        mSemantic = mSemantic | VertexSemantic::SemanticFaces;
        if (mSemantic & VertexSemantic::SemanticTexCoord) {
          mUvs.resize(mVertices.size());
          states = States::ONLY_A;
        }

        if (mSemantic & VertexSemantic::SemanticNormal) {
          mNormals.resize(mVertices.size());
          states = States::ONLY_B;
        }

        if (mSemantic & VertexSemantic::SemanticTexCoord && mSemantic & VertexSemantic::SemanticNormal) {
          states = States::BOTH;
        }

        ProcessVertex(file, temp_uvs, temp_normals, states);
        break;
      }
    }

    while (true) {
      char word[256];
      int res = fscanf(file, "%s", word);
      if (res == EOF) {
        break;
      }

      if (strcmp(word, "f") == 0) {
        ProcessVertex(file, temp_uvs, temp_normals, states);
      }
    }

    TimePoint end = Time::GetTime();
    Debug::Trace("Model loading: %s", filepath.c_str());
    Debug::Log("Elapsed time: %fsec", Time::GetInterval(start, end) / 1000.f);
    Debug::Log("Material count: %d", 0);
    Debug::Log("Vertex count: %d", GetVertexCount());
    Debug::Log("Uv count: %d", GetUvCount());
    Debug::Log("Normal count: %d", GetNormalCount());
    Debug::Log("Triangle count: %d", GetFaceCount() / 3);

    fclose(file);
    return true;
  }

  void WaveFrontObjMesh::ProcessVertex(FILE* file, const std::vector<Vector2d>& uvsIn, const std::vector<Vector3d>& normalsIn, States states) {
    unsigned int vertexIndex[3];
    unsigned int uvIndex[3];
    unsigned int normalIndex[3];

    // I know this is UGLY, but this code shows quite good performance.
    if (states == States::NONE) {
      fscanf(file, "%d %d %d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
    } else if (states == States::ONLY_A) {
      fscanf(file, "%d/%d %d/%d %d/%d\n", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);
      // flip the uv coordinate
      mUvs[vertexIndex[0] - 1] = Vector2d(uvsIn[uvIndex[0] - 1].x, 1.f - uvsIn[uvIndex[0] - 1].y);
      mUvs[vertexIndex[1] - 1] = Vector2d(uvsIn[uvIndex[1] - 1].x, 1.f - uvsIn[uvIndex[1] - 1].y);
      mUvs[vertexIndex[2] - 1] = Vector2d(uvsIn[uvIndex[2] - 1].x, 1.f - uvsIn[uvIndex[2] - 1].y);
    } else if (states == States::ONLY_B) {
      fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
      mNormals[vertexIndex[0] - 1] = normalsIn[normalIndex[0] - 1];
      mNormals[vertexIndex[1] - 1] = normalsIn[normalIndex[1] - 1];
      mNormals[vertexIndex[2] - 1] = normalsIn[normalIndex[2] - 1];
    } else if (states == States::BOTH) {
      fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
      // flip the uv coordinate
      mUvs[vertexIndex[0] - 1] = Vector2d(uvsIn[uvIndex[0] - 1].x, 1.f - uvsIn[uvIndex[0] - 1].y);
      mUvs[vertexIndex[1] - 1] = Vector2d(uvsIn[uvIndex[1] - 1].x, 1.f - uvsIn[uvIndex[1] - 1].y);
      mUvs[vertexIndex[2] - 1] = Vector2d(uvsIn[uvIndex[2] - 1].x, 1.f - uvsIn[uvIndex[2] - 1].y);

      mNormals[vertexIndex[0] - 1] = normalsIn[normalIndex[0] - 1];
      mNormals[vertexIndex[1] - 1] = normalsIn[normalIndex[1] - 1];
      mNormals[vertexIndex[2] - 1] = normalsIn[normalIndex[2] - 1];
    }

    mFaces.push_back(vertexIndex[0] - 1);
    mFaces.push_back(vertexIndex[1] - 1);
    mFaces.push_back(vertexIndex[2] - 1);
  }
}  // namespace Theodore