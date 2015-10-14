#!/usr/bin/env python

# Siconos-sample, Copyright INRIA 2005-2011.
# Siconos is a program dedicated to modeling, simulation and control
# of non smooth dynamical systems.
# Siconos is a free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# Siconos is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Siconos; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#
# Contact: Vincent ACARY, siconos-team@lists.gforge.fr
#

from siconos.kernel import LagrangianLinearTIDS, NewtonImpactNSL,\
    LagrangianLinearTIR, Interaction, Model, MoreauJeanOSI,\
    TimeDiscretisation, LCP, TimeStepping

from numpy import eye, empty

t0 = 0       # start time
T = 10       # end time
h = 0.005    # time step
r = 0.1      # ball radius
g = 9.81     # gravity
m = 1        # ball mass
e = 0.9      # restitution coeficient
theta = 0.5  # theta scheme

#
# dynamical system
#
x = [1, 0, 0]    # initial position
v = [0, 0, 0]    # initial velocity
mass = eye(3)  # mass matrix
mass[2, 2] = 2. / 5 * r * r

# the dynamical system
ball = LagrangianLinearTIDS(x, v, mass)

# set external forces
weight = [-m * g, 0, 0]
ball.setFExtPtr(weight)

#
# Interactions
#

# ball-floor
H = [[1, 0, 0]]

nslaw = NewtonImpactNSL(e)
relation = LagrangianLinearTIR(H)
inter = Interaction(nslaw, relation)

#
# Model
#
bouncingBall = Model(t0, T)

# add the dynamical system to the non smooth dynamical system
bouncingBall.nonSmoothDynamicalSystem().insertDynamicalSystem(ball)

# link the interaction and the dynamical system
bouncingBall.nonSmoothDynamicalSystem().link(inter, ball)


#
# Simulation
#

# (1) OneStepIntegrators
OSI = MoreauJeanOSI(ball, theta)

# (2) Time discretisation --
t = TimeDiscretisation(t0, h)

# (3) one step non smooth problem
osnspb = LCP()

# (4) Simulation setup with (1) (2) (3)
s = TimeStepping(t, OSI, osnspb)


# end of model definition

#
# computation
#

# simulation initialization
bouncingBall.initialize(s)


# the number of time steps
N = (T - t0) / h

# Get the values to be plotted
# ->saved in a matrix dataPlot

dataPlot = empty((N+1, 5))

#
# numpy pointers on dense Siconos vectors
#
q = ball.q()
v = ball.velocity()
p = ball.p(1)
lambda_ = inter.lambda_(1)


#
# initial data
#
dataPlot[0, 0] = t0
dataPlot[0, 1] = q[0]
dataPlot[0, 2] = v[0]
dataPlot[0, 3] = p[0]
dataPlot[0, 4] = lambda_[0]

k = 1

# time loop
while s.hasNextEvent():
    s.computeOneStep()

    dataPlot[k, 0] = s.nextTime()
    dataPlot[k, 1] = q[0]
    dataPlot[k, 2] = v[0]
    dataPlot[k, 3] = p[0]
    dataPlot[k, 4] = lambda_[0]

    k += 1
    s.nextStep()

#
# comparison with the reference file
#
from siconos.kernel import SimpleMatrix, getMatrix
from numpy.linalg import norm

ref = getMatrix(SimpleMatrix("result.ref"))

if (norm(dataPlot - ref) > 1e-12):
    print("Warning. The result is rather different from the reference file.")


#
# plots
#
import matplotlib.pyplot as plt
plt.ion()
plt.subplot(411)
plt.title('position')
plt.plot(dataPlot[:, 0], dataPlot[:, 1])
plt.grid()
plt.subplot(412)
plt.title('velocity')
plt.plot(dataPlot[:, 0], dataPlot[:, 2])
plt.grid()
plt.subplot(413)
plt.plot(dataPlot[:, 0], dataPlot[:, 3])
plt.title('reaction')
plt.grid()
plt.subplot(414)
plt.plot(dataPlot[:, 0], dataPlot[:, 4])
plt.title('lambda')
plt.grid()
plt.show()
