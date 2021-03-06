// Copyright 2016 Pixela Labs. All Rights Reserved.
#pragma once

#include "UvrNodeCtrlBase.h"


class UvrNodeCtrlStandalone : public UvrNodeCtrlBase
{
public:
	UvrNodeCtrlStandalone(const FString& ctrlName, const FString& nodeName);
	virtual ~UvrNodeCtrlStandalone();

public:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// IPUvrNodeController
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool IsSlave() const override final
	{ return false; }

	virtual bool IsStandalone() const override final
	{ return true; }

public:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// IPUvrClusterSyncProtocol
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual void WaitForGameStart() override;
	virtual void WaitForFrameStart() override;
	virtual void WaitForFrameEnd() override;
	virtual void WaitForTickEnd() override;
	virtual void GetDeltaTime(float& deltaTime) override;
	virtual void GetSyncData(UvrMessage::DataType& data)  override;
	virtual void GetInputData(UvrMessage::DataType& data) override;

public:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// IPUvrSwapSyncProtocol
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual void WaitForSwapSync(double* pThreadWaitTime, double* pBarrierWaitTime) override;

protected:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// UvrNodeCtrlBase
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool InitializeStereo() override;
};
