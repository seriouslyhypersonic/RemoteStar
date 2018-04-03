/*
 * CLASS MightyMacro
 *
 * DESCRIPTION
 *
 *
 *          Creator: Nuno Alves de Sousa
 *           E-mail: nunoalvesdesousa@me.com
 *
 */
#ifndef MIGHTYMACRO_H
#define MIGHTYMACRO_H

#include <string>
#include <fstream>
#include <vector>
#include "MightyConstants.h"
#include "../StarJob.h"
#include "Import.h"
#include "AutoSave.h"
#include "Aircraft.h"
#include "Domain.h"
#include "MeshContinuum.h"
#include "VolumetricControls.h"
#include "PhysicsContinuum.h"
#include "ShowDomain.h"
#include "MeshValues.h"
#include "PhysicsValues.h"
#include "SolverOptions.h"
#include "SolutionMonitors.h"
#include "StoppingCriteria.h"
#include "ExportResults.h"
#include "CloseSim.h"
#include "MightyScene.h"

class MightyMacro {
private:
    std::string      macroFilePath;     // File path to the macro
    std::ofstream    macroFile;         // To write
    bool             hasInitialization; // An initialization file has been provided
    bool             newMesh;           // Check the need to mesh

    StarJob            *currentStarJob;
    Import             import;
    AutoSave           autoSave;
    Aircraft           aircraft;
    Domain             domain;
    MeshContinuum      meshContinuum;
    PhysicsContinuum   physicsContinuum;
    ShowDomain         showDomain;
    MeshValues         meshValues;
    VolumetricControls volumetricControls;
    PhysicsValues      physicsValues;
    SolverOptions      solverOptions;
    SolutionMonitors   solutionMonitors;
    MightyScene        mightyScene;
    StoppingCriteria   stoppingCriteria;
    ExportResults      exportResults;
    CloseSim           closeSim;

public:
    // Constructor
    explicit MightyMacro(StarJob *_currentStarJob = nullptr);

    // Member functions
    void writeMacro();

private:
    std::ofstream openMightyMacroFile();
    void          writeToFile(const std::vector<std::string>& _code);
    void          writeImport();
    void          beginStarMacro();
    void          endStarMacro();
    void          writeExecute();
    void          writeAutoSave();
    void          writeAircraft();
    void          writeDomain();
    void          writeRegion();
    void          writeMeshContinuum();
    void          writePhysicsContinuum();
    void          writeShowDomain();
    void          writeMeshValues();
    void          writeVolumetricControls();
    void          writePhysicsValues();
    void          writeSolverOptions();
    void          writeSolutionMonitors();
    void          writeStoppingCriteria();
    void          writeGenerateMesh();
    void          writeMightyScene();
    void          writeRunSimulation();
    void          writeExportResults();
    void          writeCloseSim();
    void          writeSimCleanup();

};
#endif //MIGHTYMACRO_H
