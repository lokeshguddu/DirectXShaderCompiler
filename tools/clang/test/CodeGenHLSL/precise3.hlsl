// RUN: %dxc -E main -T vs_6_0 %s | FileCheck %s

// CHECK: fmul float
// CHECK: fadd float

//--------------------------------------------------------------------------------------
// File: BasicHLSL11_VS.hlsl
//
// The vertex shader file for the BasicHLSL11 sample.  
// 
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer cbPerObject : register( b0 )
{
	matrix		g_mWorldViewProjection	: packoffset( c0 );
	column_major  matrix		g_mWorld		: packoffset( c4 );
};

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct VS_INPUT
{
	float3 vPosition	: POSITION;
	float3 vNormal		: NORMAL;
 	float2 vTexcoord	: TEXCOORD0;
};


//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
precise float4 main( VS_INPUT Input ) : SV_Position
{	
	return mul( float4( Input.vPosition, 1.0 ), g_mWorldViewProjection );
}

