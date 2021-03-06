// Copyright 2016 Pixela Labs. All Rights Reserved.
#pragma once

#include "UvrNodeCtrlBase.h"


class UvrClusterNodeCtrlBase : public UvrNodeCtrlBase
{
public:
	UvrClusterNodeCtrlBase(const FString& ctrlName, const FString& nodeName);
	virtual ~UvrClusterNodeCtrlBase() = 0;

public:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// IPUvrNodeController
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool IsStandalone() const override final
	{ return false; }

protected:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// UvrNodeCtrlBase
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool InitializeStereo() override;
};

