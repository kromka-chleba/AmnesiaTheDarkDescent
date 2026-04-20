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

#ifndef HPL_MESH_LOADER_GLTF_H
#define HPL_MESH_LOADER_GLTF_H

#include "resources/MeshLoader.h"

namespace hpl {

	class cMesh;
	class cAnimation;
	class cMeshLoaderMSH;

	//--------------------------------------------

	class cMeshLoaderGLTF : public iMeshLoader
	{
	public:
		cMeshLoaderGLTF(iLowLevelGraphics *apLowLevelGraphics, cMeshLoaderMSH *apMeshLoaderMSH);
		~cMeshLoaderGLTF();

		cMesh* LoadMesh(const tWString& asFile, tMeshLoadFlag aFlags);
		bool SaveMesh(cMesh* apMesh,const tWString& asFile);

		cAnimation* LoadAnimation(const tWString& asFile);
		bool SaveAnimation(cAnimation* apAnimation, const tWString& asFile);

	private:
		cMeshLoaderMSH *mpMeshLoaderMSH;
	};

};
#endif // HPL_MESH_LOADER_GLTF_H
