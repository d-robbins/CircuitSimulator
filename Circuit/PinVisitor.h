#pragma once


class CPinnedComponent;

class CPinVisitor
{
public:
	virtual void VisitPinnedComponent(CPinnedComponent* pinned) {}
};

