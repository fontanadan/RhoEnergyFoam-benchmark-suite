To suppres the warning of maxDeltaT not used you need to go in the src folder of openfoam e look for this file: src/finiteVolume/lnInclude/createTimeControls.H
inside createTimeControls.H I added [[maybe_unused]] to maxDeltaT

also inside readThermophysicalProperties.H you need to delete .lookup("Pr")
