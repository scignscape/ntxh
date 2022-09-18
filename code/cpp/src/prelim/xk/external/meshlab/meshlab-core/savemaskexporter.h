/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef __VCGLIB_SAVEMASK_EXPORT
#define __VCGLIB_SAVEMASK_EXPORT

#include <QDialog>

#include <wrap/io_trimesh/io_mask.h>

#include "rich_parameter_gui/richparameterlistframe.h"
#include <common/filter_parameter/rich_parameter_list.h>
#include "glarea.h"
//
// Each file format exposes:
//  a capability bit vector with all the things that it can save (the bits are the one indicated in the IOM_XXX bit mask) ; 
//  a default bit vector that indicate what things are saved by defaults (eg. by default normals and flags are not saved in ply)
//  a vector of optional parameters (like for example a bool for ascii/binary, a bool for choosing what  
// This dialog allows one to select what things actually save. 
// 
// 
// 

namespace Ui 
{
	class MaskExporterDialog;
} 

class SaveMaskExporterDialog : public QDialog
{
	Q_OBJECT
public:
	SaveMaskExporterDialog(QWidget *parent, MeshModel *m, int capability, int defaultBits, RichParameterList *par,GLArea* glar = NULL);
	~SaveMaskExporterDialog();
	
	void InitDialog();
	void SetTextureName();
	int GetNewMask();
	void SetMaskCapability();
	void updateMask();

public slots:
	void on_check_help_stateChanged(int);
	void SlotOkButton();
	void SlotCancelButton();
	void SlotRenameTexture();
	void SlotSelectionTextureName();
	void SlotSelectionNoneButton();
	void SlotSelectionAllButton();
private:
	Ui::MaskExporterDialog* ui;
	MeshModel *m;
	int mask;
	int type;
	int capability;
	int defaultBits;
    RichParameterList *parSet;
	RichParameterListFrame *stdParFrame;
	GLArea* glar;
	
	void checkAndEnable(QCheckBox *qcb,int bit, int capabilityBits, int defaultBits);
	bool shouldBeEnabled(int bit, int capabilityBits, int defaultBits);
	bool shouldBeChecked(int bit, int capabilityBits, int defaultBits);
};//end class

#endif
