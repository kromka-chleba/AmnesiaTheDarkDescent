/*
 * Copyright © 2009-2020 Frictional Games
 * 
 * This file is part of Amnesia: The Dark Descent.
 * 
 * Amnesia: The Dark Descent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. 

 * Amnesia: The Dark Descent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Amnesia: The Dark Descent.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "impl/MeshLoaderGLTF.h"

#include "impl/MeshLoaderMSH.h"
#include "resources/Resources.h"
#include "system/LowLevelSystem.h"
#include "system/Platform.h"
#include "system/String.h"

#include "graphics/Mesh.h"
#include "graphics/Animation.h"

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cMeshLoaderGLTF::cMeshLoaderGLTF(iLowLevelGraphics *apLowLevelGraphics, cMeshLoaderMSH *apMeshLoaderMSH)
		: iMeshLoader(apLowLevelGraphics)
	{
		mpMeshLoaderMSH = apMeshLoaderMSH;

		AddSupportedExtension("gltf");
		AddSupportedExtension("glb");
		AddSupportedExtension("gltf_anim");
	}

	//-----------------------------------------------------------------------

	cMeshLoaderGLTF::~cMeshLoaderGLTF()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cMesh* cMeshLoaderGLTF::LoadMesh(const tWString& asFile, tMeshLoadFlag aFlags)
	{
		tWString sMSHFile = cString::SetFileExtW(asFile, _W("msh"));
		cDate currentDate = cPlatform::FileModifiedDate(asFile);
		cDate mshDate = cPlatform::FileModifiedDate(sMSHFile);

		if(cResources::GetForceCacheLoadingAndSkipSaving() ||
			mshDate > currentDate || cPlatform::FileExists(asFile)==false)
		{
			cMesh *pMesh = mpMeshLoaderMSH->LoadMesh(sMSHFile, aFlags);
			if(pMesh)
			{
				pMesh->SetFullPath(asFile);
				return pMesh;
			}
		}

		Error("No cached mesh '%s' found for glTF asset '%s'. Generate .msh/.anm data before loading glTF files.",
			cString::To8Char(sMSHFile).c_str(), cString::To8Char(asFile).c_str());
		return NULL;
	}

	//-----------------------------------------------------------------------

	bool cMeshLoaderGLTF::SaveMesh(cMesh* apMesh,const tWString& asFile)
	{
		return false;
	}

	//-----------------------------------------------------------------------

	cAnimation* cMeshLoaderGLTF::LoadAnimation(const tWString& asFile)
	{
		tWString sANMFile = cString::SetFileExtW(asFile, _W("anm"));
		cDate currentDate = cPlatform::FileModifiedDate(asFile);
		cDate anmDate = cPlatform::FileModifiedDate(sANMFile);

		if(cResources::GetForceCacheLoadingAndSkipSaving() ||
			anmDate > currentDate || cPlatform::FileExists(asFile)==false)
		{
			cAnimation *pAnim = mpMeshLoaderMSH->LoadAnimation(sANMFile);
			if(pAnim)
			{
				pAnim->SetFullPath(asFile);
				return pAnim;
			}
		}

		Error("No cached animation '%s' found for glTF animation '%s'. Generate .anm data before loading glTF animations.",
			cString::To8Char(sANMFile).c_str(), cString::To8Char(asFile).c_str());
		return NULL;
	}

	//-----------------------------------------------------------------------

	bool cMeshLoaderGLTF::SaveAnimation(cAnimation* apAnimation, const tWString& asFile)
	{
		return false;
	}

	//-----------------------------------------------------------------------
}
