const bool pressArtDiff [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("pressArtDiff", false);

const bool convArtDiff [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("convArtDiff", false);

scalar sigma [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("sigma",1.);

scalar kp [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("kp",0.);

scalar ku [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("ku",0.);

scalar ducLevelPress [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("ducLevelPress",1.5);

scalar ducLevelConv [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("ducLevelConv",1.5);

scalar minfty [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("minfty", 1.0);

scalar rm [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("rm", 1.0);

scalar Tbulk_target [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("Tbulk_target", 300.0);
scalar epsilon [[maybe_unused]] =
    runTime.controlDict().lookupOrDefault("epsilon",0.);
