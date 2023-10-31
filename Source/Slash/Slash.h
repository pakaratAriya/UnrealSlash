// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true)
#define DRAW_LINE(Location, Forward) if(GetWorld()) DrawDebugLine(GetWorld(), Location, Location + Forward, FColor::Red, true, -1.f, 0, 1.f)
#define DRAW_SPHERE_SINGLE_FRAME(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f)
#define DRAW_LINE_SINGLE_FRAME(Location, Forward) if(GetWorld()) DrawDebugLine(GetWorld(), Location, Location + Forward, FColor::Red, false, -1.f, 0, 1.f)
#define DRAW_VECTOR(Location, Forward)  \
	if(GetWorld()) {\
		DrawDebugPoint(GetWorld(), Location + Forward, 25.f, FColor::Red, false, -1.f);\
		DrawDebugLine(GetWorld(), Location, Location + Forward, FColor::Red, false, -1.f, 0, 1.f);\
	}