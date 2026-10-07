/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "functionObjectTemplate.H"
#define namespaceFoam  // Suppress <using namespace Foam;>
#include "fvCFD.H"
#include "unitConversion.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(computeVelocityGradientMagFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    computeVelocityGradientMagFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 86e058c56627e1e758a1298682e8a07a91401ac9
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void computeVelocityGradientMag_86e058c56627e1e758a1298682e8a07a91401ac9(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode

} // End namespace Foam


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

const Foam::fvMesh&
Foam::computeVelocityGradientMagFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
computeVelocityGradientMagFunctionObject::
computeVelocityGradientMagFunctionObject
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    functionObjects::regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
computeVelocityGradientMagFunctionObject::
~computeVelocityGradientMagFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool
Foam::
computeVelocityGradientMagFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        printMessage("read computeVelocityGradientMag");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool
Foam::
computeVelocityGradientMagFunctionObject::execute()
{
    if (false)
    {
        printMessage("execute computeVelocityGradientMag");
    }

//{{{ begin code
    #line 81 "/home/alessio/Desktop/OF/Test/V2206/CylinderGradientAMR/OpenFOAM-2112/REF/system/controlDict.functions.calcGradient"
const volVectorField& U  =  mesh().lookupObject<volVectorField>("U");

            static autoPtr<volScalarField> velocityGradientMagPtr;
            if(!velocityGradientMagPtr.valid()) {
              Info << "Creating velocityGradientMag" << nl;

              velocityGradientMagPtr.set
              (
                  new volScalarField
                  (
                    IOobject
                    (
                        "velocityGradientMag",
                        time_.timeName(),
                        U.mesh(),
                        IOobject::NO_READ,
                        IOobject::AUTO_WRITE
                    ),
                    mag(fvc::grad(U))
                  )
              );
            }
            volScalarField &velocityGradientMag = velocityGradientMagPtr();
            velocityGradientMag.checkIn();
            velocityGradientMag = mag(fvc::grad(U));
            Info << " max velocityGradientMag " << max(velocityGradientMag) << nl;
//}}} end code

    return true;
}


bool
Foam::
computeVelocityGradientMagFunctionObject::write()
{
    if (false)
    {
        printMessage("write computeVelocityGradientMag");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool
Foam::
computeVelocityGradientMagFunctionObject::end()
{
    if (false)
    {
        printMessage("end computeVelocityGradientMag");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


// ************************************************************************* //

