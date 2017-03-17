/**************************************************************************
 * Copyright (C) 2017 Rendease Co., Ltd.
 * All rights reserved.
 *
 * This program is commercial software: you must not redistribute it 
 * and/or modify it without written permission from Rendease Co., Ltd.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * End User License Agreement for more details.
 *
 * You should have received a copy of the End User License Agreement along 
 * with this program.  If not, see <http://www.rendease.com/licensing/>
 *************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ESSLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ESSLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
//#ifdef ESSLIB_EXPORTS
//#define ESSLIB_API __declspec(dllexport)
//#else
//#define ESSLIB_API __declspec(dllimport)
//#endif

#pragma once

#include <vector>
#include <eiVector.h>
#include "esswriter.h"
#include "ElaraHomeAPI.h"

class EssExporter {
	std::vector<std::string> mElInstances;
	std::vector<std::string> mElMaterials;
	std::string mCamName;
	std::vector<std::string> mDefaultWallMatName;
	std::vector<std::string> mDefaultMatName;
	std::string mEnvName;
	std::string mRootPath;
	std::string mOptionName;
	EssWriter mWriter;
	int mLightSamples;
	bool mCheckNormal;
	
public:
	EssExporter(void);
	~EssExporter();
	bool BeginExport(std::string &filename, const bool encoding, const bool check_normal);
	void SetLightSamples(const int samples);
	bool AddCamera(EH_Camera &cam, bool panorama, int panorama_size);
	bool AddMesh(EH_Mesh& model, const std::string &modelName) ;
	bool AddLight(EH_Light& light, std::string &lightName);
	bool AddMaterial(EH_Material& mat, std::string &matName);
	void AddDefaultOption();
	bool AddDefaultMaterial();
	bool AddBackground(const float intensity, const float haze, const eiVector &sun_dir, const bool use_sky, const std::string &hdri_name, const float rotation, const float hdri_intensity);
	bool AddSun(const eiVector &dir, const float intensity, const eiVector &sky_color, const float hardness);
	void SetTexPath(std::string &path);
	void EndExport();
};
