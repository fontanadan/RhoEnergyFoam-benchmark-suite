# 🚀 OpenFOAM Benchmark Suite: `rhoEnergyFoam` vs `rhoCentralFoam`

![OpenFOAM](https://img.shields.io/badge/OpenFOAM-v2606-blue.svg)
![License](https://img.shields.io/badge/License-GPL--3.0-green.svg)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange.svg)

This repository contains a comprehensive suite of **test cases and numerical benchmarks** developed in **OpenFOAM** to evaluate and compare the performance, accuracy, and numerical dissipation of the high-fidelity solver **`rhoEnergyFoam`** (`rhoEnergyFoamOriginalOpt`) against the standard OpenFOAM solver **`rhoCentralFoam`**.

---

## 📌 Table of Contents
- [Solver Overview](#-solver-overview)
- [Test Cases & Benchmarks](#-test-cases--benchmarks)
  - [1. Sod Shock Tube](#1-sod-shock-tube)
  - [2. Subsonic Turbulent Cylinder](#2-subsonic-turbulent-cylinder-m_infty--01-re_d--106)
  - [3. Transonic ONERA M6 Wing](#3-transonic-onera-m6-wing-inviscid)
  - [4. 2D Cylinder with Adaptive Mesh Refinement (AMR)](#4-2d-cylinder-with-adaptive-mesh-refinement-amr)
- [📂 Repository Structure](#-repository-structure)
- [🛠️ Requirements & Installation](#️-requirements--installation)
- [📖 References](#-references)

---

## ⚡ Solver Overview

`rhoEnergyFoam` is a high-fidelity, low-dissipative CFD solver for the compressible Navier-Stokes equations on unstructured meshes. It combines discrete kinetic energy conservation for convective terms with selective AUSM-like numerical diffusion controlled by a Ducros shock sensor.

### Operational Modes

| Mode | Name | Description |
| :--- | :--- | :--- |
| **Mode A** | Fully Resolved | For fully resolved smooth flows (DNS). No artificial diffusion. |
| **Mode B** | Unresolved Smooth | For unresolved smooth flows (LES/URANS). AUSM pressure diffusion activated only. |
| **Mode C** | Shocked Flows | For flows with discontinuities and shocks. Full AUSM diffusion active near shocks. |

* **Time Integration**: 3rd-order, 3-stage low-storage Runge-Kutta scheme, providing high computational efficiency and low memory consumption.

---

## 🧪 Test Cases & Benchmarks

### 1. Sod Shock Tube
* **Directory**: `01_SodShockTube/`
* **Solver Mode**: `Mode C`
* **Objective**: Evaluate the solver's capability in capturing moving and stationary discontinuities (shock wave, contact discontinuity, rarefaction wave).

| Parameter | Details |
| :--- | :--- |
| **Flow Type** | 1D Inviscid |
| **Setup** | Matching runtime parameters (CFL, time step, mesh) for both solvers |

> **Results**: `rhoEnergyFoam` cleanly captures the shock wave without spurious numerical oscillations, which are clearly visible in the `rhoCentralFoam` solution.

---

### 2. Subsonic Turbulent Cylinder ($M_\infty = 0.1, Re_D = 10^6$)
* **Directory**: `02_Cylinder_Subsonic_Turbulent/`
* **Solver Mode**: `Mode B`
* **Objective**: Investigation of high-Reynolds-number turbulent flow over a circular cylinder.

| Parameter | Value |
| :--- | :--- |
| **Mach Number ($M_\infty$)** | 0.1 |
| **Reynolds Number ($Re_D$)** | $10^6$ |
| **Turbulence Models** | URANS and DES (Spalart-Allmaras) |
| **DES Mesh** | O-type mesh $256 \times 256 \times 48$ ($y^+ \approx 150-200$) |

> **Results**: Evaluation of drag coefficient $C_D$, pressure coefficient $C_p$ distribution, and coherent vortex structures (Q-criterion isosurfaces) compared against experimental and numerical literature.

---

### 3. Transonic ONERA M6 Wing (Inviscid)
* **Directory**: `03_OneraM6_Inviscid/`
* **Solver Mode**: `Mode C`
* **Objective**: Validation of complex 3D shock wave structures ($\lambda$/A-shock pattern).

| Parameter | Value |
| :--- | :--- |
| **Mach Number ($M_\infty$)** | 0.8395 |
| **Angle of Attack ($\alpha$)** | $3.06^\circ$ |
| **Mesh** | Unstructured tetrahedral mesh (341,797 cells) |

> **Results**: `rhoEnergyFoam` accurately predicts the shock position and intensity matching experimental AGARD data, significantly outperforming `rhoCentralFoam` which exhibits excessive numerical smearing.

---

### 4. 2D Cylinder with Adaptive Mesh Refinement (AMR)
* **Directory**: `04_Cylinder_2D_AMR/`
* **Solver Mode**: `Mode A`
* **Objective**: Demonstrate seamless integration with native OpenFOAM Adaptive Mesh Refinement (AMR).

| Parameter | Value |
| :--- | :--- |
| **Mach Number ($M_\infty$)** | 0.1 |
| **Reynolds Number ($Re_D$)** | 100 |
| **AMR Criterion** | Local velocity gradient ($\nabla U$) |

> **Results**: High-resolution capturing of von Kármán vortex shedding with dynamic, localized mesh adaptation in high-gradient flow regions.

---

## 📂 Repository Structure

```text
.
├── 01_SodShockTube/                 # Case 1: 1D Sod Shock Tube
├── 02_Cylinder_Subsonic_Turbulent/  # Case 2: Cylinder M=0.1, Re=1e6 (URANS/DES)
├── 03_OneraM6_Inviscid/             # Case 3: 3D ONERA M6 Transonic Wing
├── 04_Cylinder_2D_AMR/              # Case 4: 2D Cylinder with AMR
├── rhoEnergyFoamOriginalOpt/        # Source code for the rhoEnergyFoam solver
└── README.md                        # Repository documentation
```

---

## 🛠️ Requirements & Installation

### 1. Prerequisites

* **Operating System**: Unix-like OS (Linux / macOS)
* **CFD Framework**: OpenFOAM v2606 (must be downloaded and installed prior to compilation)
* **Compiler**: `g++` / `wmake`

### 2. Building `rhoEnergyFoam`

1. Source the OpenFOAM environment configuration file:

   ```bash
   source /path/to/openfoam-v2606/etc/bashrc
   ```

2. Copy the `rhoEnergyFoamOriginalOpt` source directory into the OpenFOAM compressible solvers directory:

   ```bash
   cp -r rhoEnergyFoamOriginalOpt $WM_PROJECT_DIR/applications/solvers/compressible/
   ```

3. Navigate into the solver directory inside `$WM_PROJECT_DIR`:

   ```bash
   cd $WM_PROJECT_DIR/applications/solvers/compressible/rhoEnergyFoamOriginalOpt
   ```

4. Compile the solver executable using `wmake`:

   ```bash
   wmake
   ```

---

## 📖 References

### Primary Publications

1. **Fontana, D., Piccolo, A., Spisso, I., Guerrero Rivas, J. E., & Pirozzoli, S.**
   *rhoEnergyFoam: A High-Fidelity, Low-Dissipative Solver for Compressible Navier-Stokes Equations in OpenFOAM*.
   *OpenFOAM Journal*.
2. **Modesti, D., & Pirozzoli, S. (2017)**.
   *A low-dissipative solver for turbulent compressible flows on unstructured meshes, with OpenFOAM implementation*.
   *Computers & Fluids*, 152, 14–23. https://doi.org/10.1016/j.compfluid.2017.04.012

### Key Numerical & Methodological References

* **Energy-Preserving Central Flux**: Pirozzoli, S. (2010). *Generalized conservative approximations of split convective derivative operators*. *Journal of Computational Physics*, 229(19), 7180–7190.
* **AUSM Flux Splitting**: Liou, M. S., & Steffen, C. (1993). *A new flux splitting scheme*. *Journal of Computational Physics*, 107(1), 23–39.
* **Ducros Shock Sensor**: Ducros, F., Ferrand, V., Nicoud, F., Weber, C., Darracq, D., Gacherieu, C., & Poinsot, T. (1999). *Large-eddy simulation of the shock/turbulence interaction*. *Journal of Computational Physics*, 152(2), 517–549.
