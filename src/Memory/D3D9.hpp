#ifndef DARKCORE_MEMORY_D3D9_HPP
#define DARKCORE_MEMORY_D3D9_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace D3D9
{
	bool Initialize();
	void Dispose();

	class IDirect3DDevice9
	{
	public:
		PVOID QueryInterface;               //0
		DWORD AddRef;                       //1
		DWORD Release;                      //2
		DWORD TestCooperativeLevel;         //3
		DWORD GetAvailableTextureMem;       //4
		DWORD EvictManagedResources;        //5
		DWORD GetDirect3D;                  //6
		DWORD GetDeviceCaps;                //7
		DWORD GetDisplayMode;               //8
		DWORD GetCreationParameters;        //9
		DWORD SetCursorProperties;          //10
		DWORD SetCursorPosition;            //11
		DWORD ShowCursor;                   //12
		DWORD CreateAdditionalSwapChain;    //13
		DWORD GetSwapChain;                 //14
		DWORD GetNumberOfSwapChains;        //15
		DWORD Reset;                        //16
		DWORD Present;                      //17
		DWORD GetBackBuffer;                //18
		DWORD GetRasterStatus;              //19
		DWORD SetDialogBoxMode;             //20
		DWORD SetGammaRamp;                 //21
		DWORD GetGammaRamp;                 //22
		DWORD CreateTexture;                //23
		DWORD CreateVolumeTexture;          //24
		DWORD CreateCubeTexture;            //25
		DWORD CreateVertexBuffer;           //26
		DWORD CreateIndexBuffer;            //27
		DWORD CreateRenderTarget;           //28
		DWORD CreateDepthStencilSurface;    //29
		DWORD UpdateSurface;                //30
		DWORD UpdateTexture;                //31
		DWORD GetRenderTargetData;          //32
		DWORD GetFrontBufferData;           //33
		DWORD StretchRect;                  //34
		DWORD ColorFill;                    //35
		DWORD CreateOffscreenPlainSurface;  //36
		DWORD SetRenderTarget;              //37
		DWORD GetRenderTarget;              //38
		DWORD SetDepthStencilSurface;       //39
		DWORD GetDepthStencilSurface;       //40
		DWORD BeginScene;                   //41
		DWORD EndScene;                     //42
		DWORD Clear;                        //43
		DWORD SetTransform;                 //44
		DWORD GetTransform;                 //45
		DWORD MultiplyTransform;            //46
		DWORD SetViewport;                  //47
		DWORD GetViewport;                  //48
		DWORD SetMaterial;                  //49
		DWORD GetMaterial;                  //50
		DWORD SetLight;                     //51
		DWORD GetLight;                     //52
		DWORD LightEnable;                  //53
		DWORD GetLightEnable;               //54
		DWORD SetClipPlane;                 //55
		DWORD GetClipPlane;                 //56
		DWORD SetRenderState;               //57
		DWORD GetRenderState;               //58
		DWORD CreateStateBlock;             //59
		DWORD BeginStateBlock;              //60
		DWORD EndStateBlock;                //61
		DWORD SetClipStatus;                //62
		DWORD GetClipStatus;                //63
		DWORD GetTexture;                   //64
		DWORD SetTexture;                   //65
		DWORD GetTextureStageState;         //66
		DWORD SetTextureStageState;         //67
		DWORD GetSamplerState;              //68
		DWORD SetSamplerState;              //69
		DWORD ValidateDevice;               //70
		DWORD SetPaletteEntries;            //71
		DWORD GetPaletteEntries;            //72
		DWORD SetCurrentTexturePalette;     //73
		DWORD GetCurrentTexturePalette;     //74
		DWORD SetScissorRect;               //75
		DWORD GetScissorRect;               //76
		DWORD SetSoftwareVertexProcessing;  //77
		DWORD GetSoftwareVertexProcessing;  //78
		DWORD SetNPatchMode;                //79
		DWORD GetNPatchMode;                //80
		DWORD DrawPrimitive;                //81
		DWORD DrawIndexedPrimitive;         //82
		DWORD DrawPrimitiveUP;              //83
		DWORD DrawIndexedPrimitiveUP;       //84
		DWORD ProcessVertices;              //85
		DWORD CreateVertexDeclaration;      //86
		DWORD SetVertexDeclaration;         //87
		DWORD GetVertexDeclaration;         //88
		DWORD SetFVF;                       //89
		DWORD GetFVF;                       //90
		DWORD CreateVertexShader;           //91
		DWORD SetVertexShader;              //92
		DWORD GetVertexShader;              //93
		DWORD SetVertexShaderConstantF;     //94
		DWORD GetVertexShaderConstantF;     //95
		DWORD SetVertexShaderConstantI;     //96
		DWORD GetVertexShaderConstantI;     //97
		DWORD SetVertexShaderConstantB;     //98
		DWORD GetVertexShaderConstantB;     //99
		DWORD SetStreamSource;              //100
		DWORD GetStreamSource;              //101
		DWORD SetStreamSourceFreq;          //102
		DWORD GetStreamSourceFreq;          //103
		DWORD SetIndices;                   //104
		DWORD GetIndices;                   //105
		DWORD CreatePixelShader;            //106
		DWORD SetPixelShader;               //107
		DWORD GetPixelShader;               //108
		DWORD SetPixelShaderConstantF;      //109
		DWORD GetPixelShaderConstantF;      //110
		DWORD SetPixelShaderConstantI;      //111
		DWORD GetPixelShaderConstantI;      //112
		DWORD SetPixelShaderConstantB;      //113
		DWORD GetPixelShaderConstantB;      //114
		DWORD DrawRectPatch;                //115
		DWORD DrawTriPatch;                 //116
		DWORD DeletePatch;                  //117
		DWORD CreateQuery;                  //118
	};
}

#endif /* DARKCORE_MEMORY_D3D9_HPP */