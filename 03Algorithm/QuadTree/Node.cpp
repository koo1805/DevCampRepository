#include "Node.h"
#include "QuadTree.h"

Node::Node(const Bound& bound, int depth)
	: bound(bound), depth(depth)
{
}

Node::~Node()
{
	Clear();
}

bool Node::Insert(Node* node)
{
	// 예외 처리
	if (!node)
	{
		return false;
	}

	// 현재 영역에 포함되지 않으면 삽입 처리 안함
	if (!bound.Contains(node->GetBound()))
	{
		return false;
	}

	// 객체가 삽입이 될 4분면 확인
	NodeIndex result = TestRegion(node->GetBound());

	// 여러 사분면에 걸쳐있거나 더이상 나눌수 없으면 현재 노드에 저장
	if (result == NodeIndex::Straddling || !Subdivide())
	{
		points.emplace_back(node);
		return true;
	}

	// 완전히 포함되는 자식 노드에 삽입
	if (result == NodeIndex::TopLeft)
	{
		return topLeft->Insert(node);
	}
	else if(result == NodeIndex::TopRight)
	{
		return topRight->Insert(node);
	}
	else if(result == NodeIndex::BottomLeft)
	{
		return bottomLeft->Insert(node);
	}
	else if(result == NodeIndex::BottomRight)
	{
		return bottomRight->Insert(node);
	}

	return false;
}

void Node::Query(const Bound& queryBound, std::vector<Node*>& results) const
{
	// 검사 영역과 겹치지 않으면 더이상 검사 안함
	if (!bound.Interects(queryBound))
	{
		return;
	}

	// 현재 노드에 저장된 객체를 실제 영역과 비교
	for (Node* const point : points)
	{
		if (point && point->GetBound().Interects(queryBound))
		{
			results.emplace_back(point);
		}
	}

	// 분할된 경우라면 자식 노드까지 검사
	if (IsDivided())
	{
		topLeft->Query(queryBound, results);
		topRight->Query(queryBound, results);
		bottomLeft->Query(queryBound, results);
		bottomRight->Query(queryBound, results);
	}

}

void Node::Clear()
{
	// points에 추가된 노드는 외부에 존재하는 노드
	// 따라서 이 범위에서 메모리 관리하지 않음

	//리스트 정리
	points.clear();

	// 자식 노드는 직접 관리
	ClearChildren();
}

bool Node::Subdivide()
{
	// 최대 깊이 확인
	if (depth >= QuadTree::maxDepth)
	{
		return false;
	}

	// 분할 됐으면 반환
	if (IsDivided())
	{
		return true;
	}

	// 영역을 나누기 위한 값
	float x = static_cast<float>(bound.GetX());
	float y = static_cast<float>(bound.GetY());
	float halfWidth = bound.Getwidth() / 2.0f;
	float halfHeight = bound.Getheight() / 2.0f;

	// 4분할을 담당하는 객체 생성
	topLeft = new Node(Bound(x, y, halfWidth, halfHeight), depth + 1);
	topRight = new Node(Bound(x + halfWidth, y, halfWidth, halfHeight), depth + 1);
	bottomLeft = new Node(Bound(x, y + halfHeight, halfWidth, halfHeight), depth + 1);
	bottomRight = new Node(Bound(x + halfWidth, y + halfHeight, halfWidth, halfHeight), depth + 1);

	return true;
}

bool Node::IsDivided() const
{
	// 자손 노드 4개 중 하나라도 null이 아니면 분할됐다고 판단
	// == !!topLeft	-> !이 붙으면 boolean으로 변환됨 -> 한번더 !를 붙여서 boolean값을 또 뒤집어서 원하는 값으로 반환	| not not
	return topLeft != nullptr;
}

Node::NodeIndex Node::TestRegion(const Bound& targetBound) const
{
	// 현재 노드의 영역을 벗어난 경우 확인
	if (!bound.Contains(targetBound))
	{
		return NodeIndex::OutOfArea;
	}

	// 전달된 영역이어느 사분면에 포함되는지 확인
	std::vector<Node::NodeIndex> quads = GetQuads(targetBound);

	// 반환받은 배열의 요소 개수가 1개라면, 4분면 중 1개 영역에 완전 포함
	if (quads.size() == 1)
	{
		return quads[0];
	}

	// 여러 영역에 겹쳤다고 반환
	return NodeIndex::Straddling;
}

std::vector<Node::NodeIndex> Node::GetQuads(const Bound& targetBounds) const
{
	// 겹치는 영역을 포함한 배열
	std::vector<NodeIndex> quads;

	// 영역 계산에 필요한 변수
	float x = static_cast<float>(bound.GetX());
	float y = static_cast<float>(bound.GetY());
	float halfWidth = bound.Getwidth() / 2.0f;
	float halfHeight = bound.Getheight() / 2.0f;
	float centerX = x + halfWidth;
	float centerY = y + halfHeight;

	// 왼쪽 영역에 완전히 포함되는지 확인
	bool left = targetBounds.GetX() >= x && targetBounds.GetXMax() <= centerX;

	// 오른쪽 영역에 완전히 포함되는지 확인
	bool right = targetBounds.GetX() >= centerX && targetBounds.GetXMax() <= bound.GetXMax();

	// 위쪽 영역에 완전히 포함되는지 확인
	bool top = targetBounds.GetY() >= y && targetBounds.GetYMax() <= centerY;

	// 아래쪽 영역에 완전히 포함되는지 확인
	bool bottom = targetBounds.GetY() >= centerY && targetBounds.GetYMax() <= bound.GetYMax();

	if (top && left)
	{
		quads.emplace_back(NodeIndex::TopLeft);
	}
	else if (top && right)
	{
		quads.emplace_back(NodeIndex::TopRight);
	}
	else if (bottom && left)
	{
		quads.emplace_back(NodeIndex::BottomLeft);
	}
	else if (bottom && right)
	{
		quads.emplace_back(NodeIndex::BottomRight);
	}

	return std::vector<NodeIndex>();
}

void Node::ClearChildren()
{
	// 분할이 진행됐는지 확인
	if (IsDivided())
	{
		SafeDelete(topLeft);
		SafeDelete(topRight);
		SafeDelete(bottomLeft);
		SafeDelete(bottomRight);
	}
}
