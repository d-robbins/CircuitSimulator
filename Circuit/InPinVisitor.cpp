#include "InPinVisitor.h"

#include "PinnedComponent.h"

void CInPinVisitor::VisitPinnedComponent(CPinnedComponent* pinned)
{
	if (pinned->InPinHitTest(this->mCoord))
	{
		this->mPin = pinned->GetLIn();
	}
}
