#include "Import.h"

Import::Import(const PrismLayer& _prismLayer) : prismLayer(_prismLayer) {}

std::vector<std::string> Import::importCode() {
    std::vector<std::string> code;
    std::vector<std::string> codeBuffer;

    // Imports required for the MightyMacro
    code = {
            "/*",
            " * STAR CCM+ macro generated by MightyMacroMaker",
            " */",
            "",
            "// This macro class belongs to macro package",
            "package macro;",
            "",
            "// Java facilities",
            "import java.util.*;",
            "",
            "// STAR-CCM+ specific",
            "import star.common.*;",
            "import star.base.neo.*;",
            "import star.vis.*;",
            "import star.meshing.*;",
            "",
            "// Mesh models",
            "import star.resurfacer.*;",
            "import star.dualmesher.*;",
            "import star.surfacewrapper.*;"
    };

    // Prism mesher
    if(prismLayer.numPrismLayers > 0)
        code.emplace_back("import star.prismmesher.*;");

    codeBuffer = {
            "",
            "// Physics",
            "import star.turbulence.*;",
            "import star.kwturb.*;",
            "import star.material.*;",
            "import star.flow.*;",
            "import star.coupledflow.*;",
            "import star.metrics.*;",
            "import star.energy.*;",
            "",
            "// Material Properties",
            "import star.material.*;",
            "",
            "// Reports",
            "import star.base.report.*;",
            ""
    };
    code.insert(code.end(), codeBuffer.begin(), codeBuffer.end());

    return code;
}