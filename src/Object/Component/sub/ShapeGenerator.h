// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#ifndef ShapeGenerator_h
#define ShapeGenerator_h

#include <map>
#include <vector>

#include "Math/Matrix4x4.h"
#include "Math/Vector2d.h"
#include "Math/Vector3d.h"
#include "Math/Vector4d.h"

namespace Theodore {
  class Mesh;
  class ShapeGenerator {
  public:
    static Mesh* GeneratePlane(unsigned int dimensions = 50);
    static Mesh* GenerateCube();
    static Mesh* GenerateIcoSphere(unsigned int subdivisions = 3);
    static Mesh* GenerateUVSphere();
    static Mesh* GenerateCapsule();
    static Mesh* GenerateCylinder();
    static Mesh* GenerateTorus(int numc = 8, int numt = 25);
    static Mesh* GenerateCone(float radius = 1.f, float height = 1.f);
    static Mesh* GenerateUtahTeapot(unsigned int tesselation = 10);
    static Mesh* GenerateKnots();

  private:
    ShapeGenerator() {}
    ~ShapeGenerator() {}

    static unsigned int Subdivide(unsigned int p1, unsigned int p2, std::vector<Vector3d>& positions);
    /*static void GeneratePatches(float * v, float * n, float * tc, unsigned short* el, int grid);
    static void MoveLid(int grid, float *v, Matrix4x4 lidTransform);
    static void BuildPatchReflect(int patchNum, float *B, float *dB, float *v, float *n, float *tc,
    unsigned short *el, int &index, int &elIndex, int &tcIndex, int grid, bool reflectX, bool
    reflectY);
    static void BuildPatch(Vector3d patch[][4], float *B, float *dB, float *v, float *n, float *tc,
    unsigned short *el, int &index, int &elIndex, int &tcIndex, int grid, glm::mat3 reflect, bool
    invertNormal);
    static void GetPatch(int patchNum, Vector3d patch[][4], bool reverseV);
    static void ComputeBasisFunctions(float * B, float * dB, int grid);
    static Vector3d Evaluate(int gridU, int gridV, float *B, Vector3d patch[][4]);
    static Vector3d EvaluateNormal(int gridU, int gridV, float *B, float *dB, Vector3d
    patch[][4]);*/
  };
}  // namespace Theodore

#endif /* ShapeGenerator_h */