#ifndef CHUNK_MESH_H
#define CHUNK_MESH_H

#include <mesh.hpp>
#include <block.hpp>
#include <glm/glm.hpp>

const VertexAttribList chunkMeshVertexAttribList = {
  VEC3_VERTEX_ATTRIB, // vertex
  VEC2_VERTEX_ATTRIB, // uv coords
  VEC3_VERTEX_ATTRIB  // normal
};

class ChunkMesh : public Mesh {
  public:
    ChunkMesh(ChunkData cd);
  private:
    void generate();

    std::vector<float> generateFace(glm::vec3, BlockSide);
    std::vector<BlockSide> neededSidesAt(glm::vec3);
    bool emptyToThe(glm::vec3, BlockSide);

    ChunkData chunkData;
};

#endif
