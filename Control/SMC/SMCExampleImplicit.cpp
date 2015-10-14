/* Siconos-sample , Copyright INRIA 2005-2012.
 * Siconos is a program dedicated to modeling, simulation and control
 * of non smooth dynamical systems.
 * Siconos is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * Siconos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Siconos; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Contact: Vincent ACARY vincent.acary@inrialpes.fr
 */

/* !\file SMCExampleImplicit.cpp
  \brief Two independent systems of dimension one controlled to slide
  on \f$x = 0\f$. An implicit scheme is used
  O. Huber
  */

#include "SiconosKernel.hpp"
#include "SiconosControl.hpp"
using namespace std;

// main program
int main(int argc, char* argv[])
{
  // User-defined parameters
  unsigned int ndof = 2;          // Number of degrees of freedom of your system
  double t0 = 0.0;                // Starting time
  double T = 1;                   // Total simulation time
  double h = 1.0e-4;              // Time step for simulation
  double hControl = 1.0e-2;       // Time step for control
  double Xinit = 1.0;

  if (h > hControl)
  {
    RuntimeException::selfThrow("hControl must be bigger than h");
  }

  // ================= Creation of the model =======================
  // Steps:
  // - create a Dynamical System
  // - add a Simulation to the model

  // -------------------------
  // --- Dynamical systems ---
  // -------------------------

  // First System:
  // dx/dt = Ax + u(t) + r
  // x(0) = x0
  // Note: r = Blambda, B defines in relation below.

  // Matrix declaration
  SP::SiconosMatrix A(new SimpleMatrix(ndof, ndof, 0));
  SP::SiconosVector x0(new SiconosVector(ndof));
  (*x0)(0) = Xinit;
  (*x0)(1) = -Xinit;
  SP::SimpleMatrix sensorC(new SimpleMatrix(2, 2));
  sensorC->eye();
  SP::SimpleMatrix sensorD(new SimpleMatrix(2, 2, 0));
  SP::SimpleMatrix Csurface(new SimpleMatrix(1, 2, 0));
  (*Csurface)(0, 1) = 1;
  SP::SimpleMatrix Brel(new SimpleMatrix(2, 1, 0));
  (*Brel)(1, 0) = 2;

  // Dynamical Systems
  SP::FirstOrderLinearDS processDS(new FirstOrderLinearDS(x0, A));
  processDS->setComputebFunction("RelayPlugin", "computeB");
  // -------------
  // --- Model process ---
  // -------------
  SP::ControlSimulation sim(new ControlZOHSimulation(t0, T, h));
  sim->setSaveOnlyMainSimulation(true);
  sim->addDynamicalSystem(processDS);

  // ------------------
  // --- Simulation ---
  // ------------------
  // Control stuff
  // use a controlSensor
  SP::LinearSensor sens(new LinearSensor(processDS, sensorC));
  sim->addSensor(sens, hControl);
  // add the sliding mode controller
  SP::LinearSMC act(new LinearSMC(sens));
  act->setCsurface(Csurface);
  act->setB(Brel);
  sim->addActuator(act, hControl);
  // =========================== End of model definition ===========================

  // ================================= Computation =================================

  // --- Simulation initialization ---

  cout << "====> Simulation initialisation ..." << endl << endl;
  // initialise the process and the ControlManager
  sim->initialize();

  // ==== Simulation loop =====
  cout << "====> Start computation ... " << endl << endl;
  sim->run();
  // --- Output files ---
  cout << "====> Output file writing ..." << endl;
  SimpleMatrix& dataPlot = *sim->data();
  ioMatrix::write("SMCExampleImplicit.dat", "ascii", dataPlot, "noDim");

  // Comparison with a reference file
  SimpleMatrix dataPlotRef(dataPlot);
  dataPlotRef.zero();
  ioMatrix::read("SMCExampleImplicit.ref", "ascii", dataPlotRef);
  std::cout << (dataPlot - dataPlotRef).normInf() << std::endl;

  if ((dataPlot - dataPlotRef).normInf() > 1e-12)
  {
    std::cout << "Warning. The results is rather different from the reference file." << std::endl;
    return 1;
  }

}
