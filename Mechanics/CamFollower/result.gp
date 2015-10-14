set  term X11
!tail -n 100000 result.dat > result-gp.dat
plot\
"result-gp.dat" u 1:8 t "Follower position" w points,\
"result-gp.dat" u 1:6 t "Cam Position" w l

