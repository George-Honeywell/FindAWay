// Fill out your copyright notice in the Description page of Project Settings.


#include "CrosshairHUD.h"

void ACrosshairHUD::DrawHUD()
{
    Super::DrawHUD();

    if(Crosshair)
    {
        // Find the centre of our canvas
        FVector2D Centre(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

        // Offset by half of the textures dimensions
        FVector2D CrosshairDrawPos(Centre.X - (Crosshair->GetSurfaceWidth() * 0.5f), Centre.Y - (Crosshair->GetSurfaceHeight() * 0.5));

        // Draw the crosshair
        FCanvasTileItem TileItem(CrosshairDrawPos, Crosshair->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}
