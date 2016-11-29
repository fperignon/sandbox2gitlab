#!/usr/bin/env python

#
# A simple walking mechanism (in progress, does not work!)
#

from siconos.mechanics.collision.tools import Contactor
from siconos.io.mechanics_io import Hdf5
import siconos.numerics as Numerics
import math

pi = math.pi

motor_id = None

# Creation of the hdf5 file for input/output
with Hdf5() as io:

    # Only touch the ground, ignore contacts between links of the robot
    io.addNewtonImpactFrictionNSL('contact',
                                  collision_group1 = 0,
                                  collision_group2 = 1,
                                  mu=0.3)

    # Definition of the ground shape
    io.addPrimitiveShape('Ground', 'Box', (100, 100, 2))
    io.addObject('ground', [Contactor('Ground', collision_group = 1)],
                 translation=[0, 0, -1])

    # Define shape of a bar-shaped link
    io.addPrimitiveShape('Bar1', 'Box', (10, 1, 1))

    io.addObject('bar1', [Contactor('Bar1'),
                          Contactor('Bar1',
                                    relative_translation=[5.5, 0, 0],
                                    relative_orientation=[(0,0,1), pi/2]),
                          Contactor('Bar1',
                                    relative_translation=[-5.5, 0, 0],
                                    relative_orientation=[(0,0,1), pi/2])],
                 translation=[0, 0, 11],
                 mass=1)

    io.addObject('bar2', [Contactor('Bar1')], translation=[5.5, 5.5, 6],
                 orientation=[(0,1,0), pi/2], mass=1)

    io.addObject('bar3', [Contactor('Bar1')], translation=[5.5, -5.5, 6],
                 orientation=[(0,1,0), pi/2], mass=1)

    io.addObject('bar4', [Contactor('Bar1')], translation=[-5.5, 5.5, 6],
                 orientation=[(0,1,0), pi/2], mass=1)

    io.addObject('bar5', [Contactor('Bar1')], translation=[-5.5, -5.5, 6],
                 orientation=[(0,1,0), pi/2], mass=1)

    io.addJoint('joint1', 'bar1', 'bar2', [5.5,  5.5, 11], [0, 1, 0], 'PivotJointR')
    io.addJoint('joint2', 'bar1', 'bar3', [5.5, -5.5, 11], [0, 1, 0], 'PivotJointR')
    io.addJoint('joint3', 'bar1', 'bar4', [5.5,  5.5, 11], [0, 1, 0], 'PivotJointR')
    io.addJoint('joint4', 'bar1', 'bar5', [5.5, -5.5, 11], [0, 1, 0], 'PivotJointR')

    # Harmonic oscillator on X-axis angular velocity = a+b*cos(omega*time+phi))
    freq = 0.5
    amp = 0.3
    io.addBoundaryCondition('vibration', 'bar1',
                            indices=[4], # X-angular axis (index into ds->v)
                            bc_class='HarmonicBC',
                            a =     [     0.0 ],
                            b =     [     amp ],
                            omega = [ pi*freq ],
                            phi =   [     0.0 ])

# Run the simulation from the inputs previously defined and add
# results to the hdf5 file. The visualisation of the output may be done
# with the vview command.
with Hdf5(mode='r+') as io:

    io.run(with_timer=False,
            time_stepping=None,
            space_filter=None,
            body_class=None,
            shape_class=None,
            face_class=None,
            edge_class=None,
            t0=0,
            T=10,
            h=0.01,
            multipoints_iterations=True,
            theta=0.50001,
            Newton_max_iter=1,
            set_external_forces=None, #lambda b: None, # ignore gravity
            solver=Numerics.SICONOS_FRICTION_3D_NSGS,
            itermax=1000,
            tolerance=1e-4,
            numerics_verbose=False,
            output_frequency=None)
