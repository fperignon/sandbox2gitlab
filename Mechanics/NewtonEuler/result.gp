#set  term X11
resultfile = 'resultNETS.ref'
resultfile = 'resultNETS-WITHPROJ.ref'
resultfile = 'result.dat'
plot \
resultfile every ::2 u 1:2 t "Ball position" w l,\
resultfile every ::2 u 1:3 t "Ball Velocity" w l,\
resultfile every ::2 u 1:4 t "Reaction force" w l


