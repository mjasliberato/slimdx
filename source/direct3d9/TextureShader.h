/*
* Copyright (c) 2007-2008 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

namespace SlimDX
{
	namespace Direct3D9
	{
		public ref class TextureShader : public ComObject
		{
			COMOBJECT(ID3DXTextureShader);

		internal:
			TextureShader( ID3DXTextureShader* pointer );

		public:
			TextureShader( System::IntPtr pointer );
			TextureShader( DataStream^ stream );
			virtual ~TextureShader() { Destruct(); }

			EffectHandle^ GetConstant( EffectHandle^ parent, int index );
			EffectHandle^ GetConstant( EffectHandle^ parent, System::String^ name );
			EffectHandle^ GetConstantElement( EffectHandle^ handle, int index );

			ConstantDescription GetConstantDescription( EffectHandle^ handle );
			array<ConstantDescription>^ GetConstantDescriptionArray( EffectHandle^ handle );

			DataStream^ GetConstantBuffer();
			DataStream^ GetFunctionStream();

			Result SetValue( EffectHandle^ parameter, bool value );
			Result SetValue( EffectHandle^ parameter, array<bool>^ values );
			Result SetValue( EffectHandle^ parameter, int value );
			Result SetValue( EffectHandle^ parameter, array<int>^ values );
			Result SetValue( EffectHandle^ parameter, float value );
			Result SetValue( EffectHandle^ parameter, array<float>^ values );
			Result SetValue( EffectHandle^ parameter, Vector4 value );
			Result SetValue( EffectHandle^ parameter, array<Vector4>^ values );
			Result SetValue( EffectHandle^ parameter, Color4 value );
			Result SetValue( EffectHandle^ parameter, array<Color4>^ values );
			Result SetValue( EffectHandle^ parameter, Matrix value );
			Result SetValue( EffectHandle^ parameter, array<Matrix>^ values );
			Result SetValueTranspose( EffectHandle^ parameter, Matrix value );
			Result SetValueTranspose( EffectHandle^ parameter, array<Matrix>^ values );

			Result SetDefaults();

			property ConstantTableDescription Description
			{
				ConstantTableDescription get();
			}
		};
	}
}