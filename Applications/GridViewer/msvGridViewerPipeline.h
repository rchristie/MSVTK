/*==============================================================================

  Library: MSVTK

  Copyright (c) The University of Auckland

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __msvGridViewerPipeline_h
#define __msvGridViewerPipeline_h

// std includes
#include <map>
#include <string>
#include <vector>

// MSV includes
#include "msvGridViewerExport.h"

// VTK includes
// GRC review/reduce:
#include "vtkAlgorithm.h"
#include "vtkAxesActor.h"
#include "vtkMapper.h"
#include "vtkOrientationMarkerWidget.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"

class MSV_GridViewer_EXPORT msvGridViewerPipeline
{
typedef std::map<std::string,vtkSmartPointer<vtkObject> > vtkNameMap;

public:
  msvGridViewerPipeline();
  ~msvGridViewerPipeline();

  void clear();
  int readGridFile(const char *gridFileName);
  vtkAlgorithm *getEndMapper()
    { return this->endMapper; }
  void addToRenderWindow(vtkRenderWindow *renderWindow);

private:
  vtkObject *msvGridViewerPipeline::createReader(std::string &readerName);
  int checkOption(const char *token, std::string &name,
    std::vector<std::string> &options, int &i, int minArgs);
  vtkAlgorithm *checkAlgorithmOption(const char *token, std::string &name,
    std::vector<std::string> &options, int &i, vtkNameMap &objects);
  int readCommand(std::istream &gridFile,
    std::string &command, std::vector<std::string> &options);

  // Scene Rendering
  vtkSmartPointer<vtkRenderer> threeDRenderer;
  vtkSmartPointer<vtkAxesActor> axes;
  vtkSmartPointer<vtkOrientationMarkerWidget> orientationMarker;
  vtkSmartPointer<vtkMapper> endMapper;
};

#endif
