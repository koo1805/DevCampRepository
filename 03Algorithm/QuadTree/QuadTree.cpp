#include "QuadTree.h"

QuadTree::QuadTree(const Bound& bounds)
    : root(new Node(bounds))
{ }

QuadTree::~QuadTree()
{
    // 루트 노드 삭제
    SafeDelete(root);
}

bool QuadTree::Insert(Node* node)
{
    if (!node)
    {
        return false;
    }

    return root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
    if (!queryNode)
    {
        return { };
    }

    // 검색 영역과 겹치는 노드 검색
    std::vector<Node*> intersects;
    root->Query(queryNode->GetBound(), intersects);

    // 검사한 결과 반환
    return intersects;
}
