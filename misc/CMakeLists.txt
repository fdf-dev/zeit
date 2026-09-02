
install(DIRECTORY applications DESTINATION share)
install(DIRECTORY pixmaps DESTINATION share)
install(FILES pixmaps/zeit.xpm
	DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/32x32/apps)
#install(DIRECTORY man DESTINATION share)
