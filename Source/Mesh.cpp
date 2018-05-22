#include "Mesh.h"
#include "Utility.h"

namespace Quark {
	Mesh::Mesh() : mFormat(IndexFormat::UInt32), mSemantic(VertexSemantic::SemanticNone), mUsage(BufferUsage::StaticDraw) {
		mType = AssetType::MeshType;
		mVertices.clear();
		mUvs.clear();
		mUvs2.clear();
		mUvs3.clear();
		mUvs4.clear();
		mNormals.clear();
		mTangents.clear();
		mFaces.clear();
		mBoneWeights.clear();
		mBindposes.clear();
	}

	Mesh::~Mesh(){
		
	}

	void Mesh::SetVertices(const std::vector<Vector3d>& verts) {
		mSemantic = mSemantic | VertexSemantic::SemanticPosition;

		for (auto& i : verts) {
			mVertices.push_back(i);
		}
	}

	void Mesh::SetUvs(const std::vector<Vector2d>& uvs) {
		mSemantic = mSemantic | VertexSemantic::SemanticTexCoord;

		for (auto& i : uvs) {
			mUvs.push_back(i);
		}
	}

	void Mesh::SetNormals(const std::vector<Vector3d>& normals) {
		mSemantic = mSemantic | VertexSemantic::SemanticNormal;

		for (auto& i : normals) {
			mNormals.push_back(i);
		}
	}

	void Mesh::SetTriangles(const std::vector<unsigned int>& faces) {
		for (auto& i : faces) {
			mFaces.push_back(i);
		}
	}

	void Mesh::SetBoneWeight(BoneWeight* bw) {
	
	}

	void Mesh::RecalculateNormals() {
		mSemantic = mSemantic | VertexSemantic::SemanticNormal;

		unsigned int stride = 3;
		for (unsigned int i = 0; i < mFaces.size() / stride; i++) {
			mNormals.push_back(Vector3d::CrossProduct(Vector3d(mVertices.at(mFaces[i * stride + 1]) - mVertices.at(mFaces[i * stride])),
													  Vector3d(mVertices.at(mFaces[i * stride + 2]) - mVertices.at(mFaces[i * stride]))).Normalize());
		}
	}

	void Mesh::RecalculateBounds() {
		/*
		// Create local variables for the vertices of the model.
		VertexFormat* vertexArray = model->Vertices();
		int numVertexArray = model->NumVertices();

		// Create a temporary AABB that uses vec4 for the purposes of matrix multiplication.
		CalculatorAABB newBox;

		// Set the min and max equal to the first vertex in the object times the transformation matrix.
		newBox.min = transformation * glm::vec4(vertexArray[0].position, 1.0f);
		newBox.max = newBox.min;

		// Loop through the rest of the vertices.
		for (int i = 1; i < numVertexArray; i++)
		{
			// Create a temporary vertex that is the vertices at index i turned into a vector4 and modified by the transformation matrix.
			glm::vec4 tempVert = transformation * glm::vec4(vertexArray[i].position, 1.0f);

			// If this vertex has a value larger than the max value of our newBox, replace the newBox max value with that value.
			if (tempVert.x > newBox.max.x)
			{
				newBox.max.x = tempVert.x;
			}
			if (tempVert.y > newBox.max.y)
			{
				newBox.max.y = tempVert.y;
			}
			if (tempVert.z > newBox.max.z)
			{
				newBox.max.z = tempVert.z;
			}

			// Do the same for the minimum value.
			if (tempVert.x < newBox.min.x)
			{
				newBox.min.x = tempVert.x;
			}
			if (tempVert.y < newBox.min.y)
			{
				newBox.min.y = tempVert.y;
			}
			if (tempVert.z < newBox.min.z)
			{
				newBox.min.z = tempVert.z;
			}
		}

		// Now set the actual AABB min/max (vec3 instead of vec4) to be stored in this GameObject.
		box.min.x = newBox.min.x;
		box.min.y = newBox.min.y;
		box.min.z = newBox.min.z;
		box.max.x = newBox.max.x;
		box.max.y = newBox.max.y;
		box.max.z = newBox.max.z;
		*/
	}

	void Mesh::MarkDynamic() {
		mUsage = BufferUsage::DynamicDraw;
	}
}