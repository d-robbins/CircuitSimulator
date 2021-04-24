#include "OutPinVisitor.h"

#include "PinnedComponent.h"

void COutPinVisitor::VisitPinnedComponent(CPinnedComponent* pinned)
{
	if (pinned->OutPinHitTest(this->mCoord))
	{
		this->mPin = pinned->GetLOut();
	}
}
