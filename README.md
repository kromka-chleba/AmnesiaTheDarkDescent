Amnesia: The Dark Descent Source Code
=======================

glTF assets (`.gltf`, `.glb`, `.gltf_anim`) are supported through cached runtime data (`.msh`, `.anm`) in the same path and with the same basename.

FBX support is optional and disabled by default (`HPL2_USE_FBX=OFF`) so the project can be configured without the proprietary Autodesk FBX SDK.

If you want FBX import support, enable `HPL2_USE_FBX=ON` and provide FBX SDK 2012 (`fbxsdk-2012.2-static`) in the dependency library path.


Other than that, here is almost everything you need to build Amnesia: The Dark Descent. Included are project files for Visual Studio 2010 and CMake for Linux & macOS. 

Contributing Code
-----------------
We encourage everyone to contribute code to this project, so just sign up for a github account, create a fork and hack away at the codebase.

License Information
-------------------
All code is under the GPL Version 3 license. Read the LICENSE file for terms of use of the license.
